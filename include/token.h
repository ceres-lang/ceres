#pragma once

#include <string>

namespace ceres {
	enum TokenKind {
		// Operators
		OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_LPAREN, OP_RPAREN, OP_EQUAL, OP_SEMICOLON,

		// Atoms
		ATOM_NUMBER, ATOM_IDENTIFIER,

		// Keywords
		KW_LET, KW_PRINT
	};

	struct Token {
		Token(int k, std::string d) : kind(k), data(d) {}

		int kind;
		std::string data;
	};
}