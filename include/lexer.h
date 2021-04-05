#pragma once

#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

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

	class Lexer {
	public:
		inline bool eof() { return pos >= src.length(); }
		inline void advance() { pos++; }
		inline void push_token(Token t) {
			tokens.push_back(t);
			advance();
		}

		inline char peek() {
			if (eof()) return '\0';
			return src[pos];
		}

		std::vector<Token> scan(std::string s);
		void number();
		void identifier();

	private:
		size_t pos;
		std::string src;
		std::vector<Token> tokens;
	};
};
