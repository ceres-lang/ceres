#pragma once

#include <iostream>
#include <string>

namespace ceres {
	enum TokenKind {
		// Operators
		OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_LPAREN, OP_RPAREN, OP_EQUAL, OP_SEMICOLON,

		// Atoms
		ATOM_NUMBER, ATOM_IDENTIFIER, ATOM_STRING, ATOM_BOOL,

		// Keywords
		KEYWORD,
	};

	struct Token {
		Token(int k, std::string d) : kind(k), data(d) {}

		int kind;
		std::string data;
	};

	inline void pretty_print_token(Token t) {
		// Pretty print the token type
		std::string pretty_kind;

		switch (t.kind) {
			// Operators
			case TokenKind::OP_ADD: pretty_kind = "ADD"; break;
			case TokenKind::OP_SUB: pretty_kind = "SUB"; break;
			case TokenKind::OP_MUL: pretty_kind = "MUL"; break;
			case TokenKind::OP_DIV: pretty_kind = "DIV"; break;
			case TokenKind::OP_LPAREN: pretty_kind = "LPAREN"; break;
			case TokenKind::OP_RPAREN: pretty_kind = "RPAREN"; break;
			case TokenKind::OP_EQUAL: pretty_kind = "EQUAL"; break;
			case TokenKind::OP_SEMICOLON: pretty_kind = "SEMICOLON"; break;

			// Atoms
			case TokenKind::ATOM_IDENTIFIER: pretty_kind = "IDENT"; break;
			case TokenKind::ATOM_NUMBER: pretty_kind = "NUM"; break;
			case TokenKind::ATOM_STRING: pretty_kind = "STRING"; break;
			
			// Keywords..
			case TokenKind::KEYWORD: pretty_kind = "KEYWORD"; break;
			default:
				// TODO: error out, but just print unknown for now
				pretty_kind = "UNKNOWN";
				break;
		}

		std::cout << pretty_kind << " = " << "\"" << t.data << "\"" << std::endl;
	}
}