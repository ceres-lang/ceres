#pragma once

#include <iostream>
#include <string>

namespace ceres {
	enum TokenKind {
		// Operators
		OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_LPAREN, OP_RPAREN, OP_EQUAL, OP_SEMICOLON,
		OP_TYPE_SPECIFIER,

		NUMBER,
		IDENTIFIER, 
		STRING_LIT, 
		CHAR_LIT,
		BOOL,

		// Keywords
		DEF,		// def
		IF,			// if
		ELSE_IF,	// elseif
		ELSE,		// else
		FOR,		// for
		FUN,		// fun
		WHILE,		// while
		LOOP,		// loop
		TRUE,		// true
		FALSE,		// false

		// Types
		TYPE_INT,	// 32 bit int type
		TYPE_CHAR,	// C char type
		TYPE_BOOL,	// true | false
		TYPE_STR,	// "string" | `string`
	};

	struct Token {
		Token(int k) : kind(k), data("") {}
		Token(int k, std::string d) : kind(k), data(d) {}

		int kind;
		std::string data;
	};

	inline void pretty_print_token(Token t) {
		// Pretty print the token type
		std::string pretty_kind;

		switch (t.kind) {
			// Operators
			case TokenKind::OP_ADD: pretty_kind = "ADD \"+\""; break;
			case TokenKind::OP_SUB: pretty_kind = "SUB \"-\""; break;
			case TokenKind::OP_MUL: pretty_kind = "MUL \"*\""; break;
			case TokenKind::OP_DIV: pretty_kind = "DIV \"/\""; break;
			case TokenKind::OP_LPAREN: pretty_kind = "LPAREN \"(\""; break;
			case TokenKind::OP_RPAREN: pretty_kind = "RPAREN \")\""; break;
			case TokenKind::OP_EQUAL: pretty_kind = "EQUAL \"=\""; break;
			case TokenKind::OP_SEMICOLON: pretty_kind = "SEMICOLON \";\""; break;
			case TokenKind::OP_TYPE_SPECIFIER: pretty_kind = "TYPE_SPECIFIER \":\""; break;

			case TokenKind::DEF: pretty_kind = "def"; break;
			case TokenKind::IF: pretty_kind = "if"; break;
			case TokenKind::ELSE_IF: pretty_kind = "elseif"; break;
			case TokenKind::ELSE: pretty_kind = "else"; break;
			case TokenKind::FOR: pretty_kind = "for"; break;
			case TokenKind::FUN: pretty_kind = "fun"; break;
			case TokenKind::WHILE: pretty_kind = "while"; break;
			case TokenKind::LOOP: pretty_kind = "loop"; break;

			case TokenKind::IDENTIFIER: pretty_kind = "IDENT"; break;
			case TokenKind::NUMBER: pretty_kind = "NUM"; break;
			case TokenKind::STRING_LIT: pretty_kind = "STRING"; break;
			case TokenKind::BOOL: pretty_kind = "BOOL"; break;
			
			// // Keywords..
			// case TokenKind::KEYWORD: pretty_kind = "KEYWORD"; break;
			// case TokenKind::TYPE: pretty_kind = "TYPE"; break;
			default:
				// TODO: error out, but just print unknown for now
				pretty_kind = "UNKNOWN";
				break;
		}

		if (t.data.length() > 0) {
			std::cout << pretty_kind << " = " << "\"" << t.data << "\"" << std::endl;
		}
		else {
			std::cout << pretty_kind << std::endl;
		}
	}
}