#pragma once

#include <iostream>
#include <string>

namespace ceres {
	enum TokenKind {
		// Operators
		PLUS,
		MINUS,
		STAR,
		SLASH, 
		LPAREN, 
		RPAREN,
		LBRACE,
		RBRACE,
		EQUAL,
		SEMICOLON,
		ARROW,
		DOT,
		COLON,

		// Comparison and Bitwise operators
		NOT,
		LESS, 
		LESS_EQUAL,
		GREATER,
		GREATER_EQUAL,
		EQUAL_EQUAL, 
		NOT_EQUAL,

		NUMBER,
		IDENTIFIER, 
		STRING_LIT, 
		CHAR_LIT,
		BOOL,

		// Keywords
		CASE,		// case
		CONST,		// const
		DEF,		// def
		IF,			// if
		ELSE_IF,	// elseif
		ELSE,		// else
		FOR,		// for
		FN,			// fn
		SWITCH,		// switch
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

	inline std::string prettify_token_type(int kind) {
		switch (kind) {
			// Operators
			case PLUS: return "PLUS";
			case MINUS: return "MINUS";
			case STAR: return "STAR";
			case SLASH: return "SLASH";
			case LPAREN: return "LPAREN";
			case RPAREN: return "RPAREN";
			case LBRACE: return "LBRACE";
			case RBRACE: return "RBRACE";
			case COLON: return "COLON";
			case SEMICOLON: return "SEMICOLON";
			case ARROW: return "ARROW";
			case EQUAL: return "EQUAL";

			case EQUAL_EQUAL: return "EQUAL_EQUAL";
			case LESS: return "LESS";
			case LESS_EQUAL: return "LESS_EQUAL";
			case GREATER: return "GREATER";
			case GREATER_EQUAL: return "GREATER_EQUAL";
			case NOT: return "NOT";
			case NOT_EQUAL: return "NOT_EQUAL";

			case CASE: return "case";
			case CONST: return "const";
			case DEF: return "def";
			case IF: return "if";
			case ELSE_IF: return "else if";
			case ELSE: return "else";
			case FOR: return "for";
			case FN: return "fn";
			case SWITCH: return "switch";
			case WHILE: return "while";
			case LOOP: return "loop";
			case TRUE: return "true";
			case FALSE: return "false";

			case NUMBER: return "NUMBER";
			case IDENTIFIER: return "IDENTIFIER";
			case STRING_LIT: return "STRING_LIT";
			case CHAR_LIT: return "CHAR_LIT";
			case BOOL: return "BOOL";

			// Type
			case TYPE_INT: return "int";
			case TYPE_CHAR: return "char";
			case TYPE_BOOL: return "bool";
			case TYPE_STR: return "str";

			default: return "UNKNOWN_TOKEN";
		}
	}

	inline void pretty_print_token(Token t) {
		// Pretty print the token type
		std::string pretty_kind = prettify_token_type(t.kind);

		if (t.data.length() > 0) {
			std::cout << pretty_kind << " = " << "\"" << t.data << "\"" << std::endl;
		}
		else {
			std::cout << pretty_kind << std::endl;
		}
	}
}