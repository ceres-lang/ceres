#include "../include/lexer.h"
#include "../include/error.h"

namespace ceres {
	Lexer::Lexer() {
		// Populate the list of reserved keywords

		keywords.insert({"case",			TokenKind::CASE});
		keywords.insert({"def", 			TokenKind::DEF});
		keywords.insert({"if", 				TokenKind::IF});
		keywords.insert({"elseif", 			TokenKind::ELSE_IF});
		keywords.insert({"else", 			TokenKind::ELSE});
		keywords.insert({"for", 			TokenKind::FOR});
		keywords.insert({"fun",				TokenKind::FUN});
		keywords.insert({"switch",			TokenKind::SWITCH});
		keywords.insert({"while",			TokenKind::WHILE});
		keywords.insert({"loop",			TokenKind::LOOP});
		keywords.insert({"true",			TokenKind::TRUE});
		keywords.insert({"false",			TokenKind::FALSE});

		keywords.insert({"int",				TokenKind::TYPE_INT});
		keywords.insert({"char",			TokenKind::TYPE_CHAR});
		keywords.insert({"bool",			TokenKind::TYPE_BOOL});
		keywords.insert({"str",				TokenKind::TYPE_STR});
	}

	std::vector<Token> Lexer::scan(const std::string& s) {
		this->src = s;

		while (!eof()) {
			switch (peek()) {
				case ' ': 
					advance();
					break;
				case '\n':
					advance();
					break;
				case '+':
					push_token(Token(TokenKind::OP_ADD));
					advance();
					break;
				case '-':
					push_token(Token(TokenKind::OP_SUB));
					advance();
					break;
				case '*':
					push_token(Token(TokenKind::OP_MUL));
					advance();
					break;
				case '/':
					advance();
					if (peek() == '/') {
						while (peek() != '\n') advance();
					}
					else {
						// Not a comment
						push_token(Token(TokenKind::OP_DIV));
					}
					break;
				case '(':
					push_token(Token(TokenKind::OP_LPAREN));
					advance();
					break;
				case ')':
					push_token(Token(TokenKind::OP_RPAREN));
					advance();
					break;
				case '=':
					push_token(Token(TokenKind::OP_EQUAL));
					advance();
					break;
				case ':':
					push_token(Token(TokenKind::OP_TYPE_SPECIFIER));
					advance();
					break;
				case ';':
					push_token(Token(TokenKind::OP_SEMICOLON));
					advance();
					break;
				case '\'':
					char_lit();
					break;
				case '"':
					string('"');
					break;
				case '`':
					string('`');
					break;
				default:
					if (isdigit(peek())) 
						number();
					else if (isalpha(peek()))
						identifier();
					else {
						print_error(Location(pos, 0), std::string("invalid character ") + peek());
						advance();
					}
					break;
			}
		}

		return tokens;
	}

	void Lexer::identifier() {
		// Consume the identifier
		std::string lexeme;
		while (isalnum(peek()) || peek() == '_' ) {
			lexeme += peek();
			advance();
		}

		if (keywords.count(lexeme) == 1) {
			// Keyword
			auto it = keywords.find(lexeme);
			TokenKind kind = it->second;

			push_token(Token(kind));
		}
		else {
			push_token(Token(TokenKind::IDENTIFIER, lexeme));
		}
	}

	void Lexer::number() {
		// Consume a number
		std::string lexeme;
		while (isdigit(peek())) {
			lexeme += peek();
			advance();
		}

		push_token(Token(TokenKind::NUMBER, lexeme));
		//advance();
	}

	void Lexer::char_lit() {
		// Consume a single character. If we consume more, error out
		std::string lexeme;

		advance();
		while (peek() != '\'') {
			// TODO: make this a method so we can implement for character literals
			if (peek() == '\\') {
				advance(); // skip over the slash
				switch (peek()) {
					case 'n':
						lexeme += '\n';
						break;
					case 'b':
						lexeme += '\b';
						break;
					case 't':
						lexeme += '\t';
						break;
					default:
						lexeme += peek();
						break;
				}
			}
			else {
				lexeme += peek();
			}
			advance();
		}

		// Check the length of the lexeme
		advance();
		if (lexeme.length() > 1) {
			print_error(Location(pos, 0), "unexpected string \"" + lexeme + "\" in character literal");
		}
		else {
			push_token(Token(TokenKind::CHAR_LIT, lexeme));
		}
	}

	void Lexer::string(char starting) {
		// Consume a string literal
		std::string lexeme;

		// Skip over the starting character
		advance(); 
		while (peek() != starting) {
			// TODO: make this a method so we can implement for character literals
			if (peek() == '\\') {
				advance(); // skip over the slash
				switch (peek()) {
					case 'n':
						lexeme += '\n';
						break;
					case 'b':
						lexeme += '\b';
						break;
					case 't':
						lexeme += '\t';
						break;
					default:
						lexeme += peek();
						break;
				}
			}
			else {
				lexeme += peek();
			}
			advance();
		}

		advance();
		push_token(Token(TokenKind::STRING_LIT, lexeme));
	}
}