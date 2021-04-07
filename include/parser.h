#pragma once

#include <cstdio>
#include <iostream>
#include <exception>
#include <algorithm>
#include <string>
#include <vector>

#include "token.h"
#include "error.h"
#include "ast/node.h"
#include "ast/value.h"

namespace ceres {
	class Parser {
	public:
		std::vector<Token> tokens;

		inline void advance() { pos++; }
		inline bool eof() { return pos >= tokens.size(); }

		inline Token peek() {
			if (eof()) throw std::runtime_error("eof reached while peeking next token");
			return tokens[pos];
		}

		inline Token consume() {
			// Peek to get the next token, then advance so we consume it
			auto next_token = peek();
			advance();

			return next_token;
		}

		IdentifierNode parse_identifier();
		ValueNode parse_number();
		ValueNode parse_string();
	private:
		size_t pos;
	};
};