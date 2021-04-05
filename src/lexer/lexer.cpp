#include "include/lexer.h"

std::vector<ceres::Token> ceres::Lexer::scan(std::string s) {
	this->src = s;

	while (!eof()) {
		switch (peek()) {
			case ' ': 
				advance();
				break;
			case '\n':
				advance();
				break;
			case '#':
				// TODO: handle comments
				break;
			case '+':
				push_token(Token(TokenKind::OP_ADD, ""));
				break;
			case '-':
				push_token(Token(TokenKind::OP_SUB, ""));
				break;
			case '*':
				push_token(Token(TokenKind::OP_MUL, ""));
				break;
			case '/':
				push_token(Token(TokenKind::OP_DIV, ""));
				break;
			case '(':
				push_token(Token(TokenKind::OP_LPAREN, ""));
				break;
			case ')':
				push_token(Token(TokenKind::OP_RPAREN, ""));
				break;
			case '=':
				push_token(Token(TokenKind::OP_EQUAL, ""));
				break;
			case ';':
				push_token(Token(TokenKind::OP_SEMICOLON, ""));
				break;
			default:
				if (isdigit(peek())) 
					number();
				else if (isalpha(peek()))
					identifier();
				else
					std::printf("error: invalid character %c\n", peek());
				break;
		}
	}

	return tokens;
}

void ceres::Lexer::identifier() {
	// Consume the identifier
	std::string lexeme;
	while (isalpha(peek()) || peek() == '_') {
		lexeme += peek();
		advance();
	}

	push_token(Token(TokenKind::ATOM_IDENTIFIER, lexeme));
}

void ceres::Lexer::number() {
	// Consume a number
	std::string lexeme;
	while (isdigit(peek())) {
		lexeme += peek();
		advance();
	}

	push_token(Token(TokenKind::ATOM_NUMBER, lexeme));
}