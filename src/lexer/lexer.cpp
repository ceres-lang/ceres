#include "include/lexer.h"

ceres::Lexer::Lexer() {
	// Populate the list of reserved keywords
	reserved_kw.push_back("let");
	reserved_kw.push_back("if");
	reserved_kw.push_back("else");
	reserved_kw.push_back("func");
	reserved_kw.push_back("print");
}

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
				push_token(Token(TokenKind::OP_LPAREN, "("));
				break;
			case ')':
				push_token(Token(TokenKind::OP_RPAREN, ")"));
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
	// FIXME: ( and ) doesn't get tokenized properly
	// Consume the identifier
	std::string lexeme;
	while (isalpha(peek())) {
		lexeme += peek();
		advance();
	}

	// Check if reserved keyword
	if (std::find(reserved_kw.begin(), reserved_kw.end(), lexeme) != reserved_kw.end()) {
		push_token(Token(TokenKind::KEYWORD, lexeme));
	}
	else {
		push_token(Token(TokenKind::ATOM_IDENTIFIER, lexeme));
	}
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