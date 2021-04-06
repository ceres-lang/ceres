#pragma once

#include <cstdio>
#include <iostream>
#include <exception>
#include <algorithm>
#include <string>
#include <vector>

#include "include/token.h"

namespace ceres {
	class Parser {
	public:
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
	private:
		size_t pos;
		std::vector<Token> tokens;
	}
}