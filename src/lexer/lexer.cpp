#include "../../include/lexer.h"
#include "../../include/error.h"

namespace ceres {
	Lexer::Lexer() {
		// Populate the list of reserved keywords

		keywords.insert({"case",			TokenKind::CASE});
		keywords.insert({"const",			TokenKind::CONST});
		keywords.insert({"def", 			TokenKind::DEF});
		keywords.insert({"if", 				TokenKind::IF});
		keywords.insert({"elseif", 			TokenKind::ELSE_IF});
		keywords.insert({"else", 			TokenKind::ELSE});
		keywords.insert({"for", 			TokenKind::FOR});
		keywords.insert({"fn",				TokenKind::FN});
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

	void Lexer::scan_operator() {
		// Handle operators
		
		switch (peek()) {
			case '+':
				push_token(Token(TokenKind::PLUS));
				advance();
				break;
			case '-':
				push_token(Token(TokenKind::MINUS));
				advance();
				break;
			case '*':
				push_token(Token(TokenKind::STAR));
				advance();
				break;
			case '/':
				advance();
				if (peek() == '/') {
					while (peek() != '\n') advance();
				}
				else {
					// Not a comment
					push_token(Token(TokenKind::SLASH));
				}
				break;
			case '(':
				push_token(Token(TokenKind::LPAREN));
				advance();
				break;
			case ')':
				push_token(Token(TokenKind::RPAREN));
				advance();
				break;
			case '{':
				push_token(Token(TokenKind::LBRACE));
				advance();
				break;
			case '}':
				push_token(Token(TokenKind::RBRACE));
				advance();
				break;
			case '<':
				advance();
				if (peek() == '=') {
					push_token(Token(TokenKind::LESS_EQUAL));
					advance();
				}
				else {
					push_token(Token(TokenKind::LESS));
				}
			case '>':
				advance();
				if (peek() == '=') {
					push_token(Token(TokenKind::GREATER_EQUAL));
					advance();
				}
				else {
					push_token(Token(TokenKind::GREATER));
				}
			case '!':
				advance();
				if (peek() == '=') {
					push_token(Token(TokenKind::NOT_EQUAL));
					advance();
				}
				else {
					push_token(Token(TokenKind::NOT));
				}
			case '=':
				advance();
				if (peek() == '=') {
					push_token(Token(TokenKind::EQUAL_EQUAL));
					advance();
				}
				else {
					push_token(Token(TokenKind::EQUAL));
				}
				break;
			case '.':
				push_token(Token(TokenKind::DOT));
				advance();
				break;
			case ':':
				push_token(Token(TokenKind::COLON));
				advance();
				break;
			case ';':
				push_token(Token(TokenKind::SEMICOLON));
				advance();
				break;
			case '\'':
				scan_char_lit();
				break;
			case '"':
				scan_string('"');
				break;
			case '`':
				scan_string('`');
				break;
			default: break;
		}
	}

	std::vector<Token> Lexer::scan(const std::string& s) {
		this->src = s;

		while (!eof()) {
			// TODO: change this to use a mapping instead of a giant switch
			scan_operator();

			// Skip over any useless whitespace
			if (isspace(peek()))
				advance();

			if (isalpha(peek())) {
				scan_identifier();
			}

			if (isdigit(peek())) {
				scan_number();
			}
		}

		return tokens;
	}

	void Lexer::scan_identifier() {
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

	void Lexer::scan_number() {
		// Consume a number
		std::string lexeme;
		while (isdigit(peek())) {
			lexeme += peek();
			advance();
		}

		push_token(Token(TokenKind::NUMBER, lexeme));
		//advance();
	}

	void Lexer::scan_char_lit() {
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

	void Lexer::scan_string(char starting) {
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