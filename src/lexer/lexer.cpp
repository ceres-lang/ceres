#include "include/lexer.h"
#include "include/error.h"

namespace ceres {
	Lexer::Lexer() {
		// Populate the list of reserved keywords
		reserved_kw = {"def", "if", "else", "for", "proc"};
		reserved_types = {"int", "bool", "str"};
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
				case ':': {
					push_token(Token(TokenKind::OP_TYPE_SPECIFIER));
					break;
				}
				case ';':
					push_token(Token(TokenKind::OP_SEMICOLON));
					advance();
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

		// Check if reserved keyword
		if (std::find(reserved_kw.begin(), reserved_kw.end(), lexeme) != reserved_kw.end()) {
			push_token(Token(TokenKind::KEYWORD, lexeme));
		}
		else if (std::find(reserved_types.begin(), reserved_types.end(), lexeme) != reserved_types.end()) {
			// Reserved type
			push_token(Token(TokenKind::TYPE, lexeme));
		}
		else if (lexeme == "true" || lexeme == "false") {
			// Boolean, not a keyword or identifier
			push_token(Token(TokenKind::ATOM_BOOL, lexeme));
		}
		else {
			push_token(Token(TokenKind::ATOM_IDENTIFIER, lexeme));
		}
	}

	void Lexer::number() {
		// Consume a number
		std::string lexeme;
		while (isdigit(peek())) {
			lexeme += peek();
			advance();
		}

		push_token(Token(TokenKind::ATOM_NUMBER, lexeme));
		//advance();
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
		push_token(Token(TokenKind::ATOM_STRING, lexeme));
		//std::cout << "STRING " << lexeme << std::endl;
	}
}