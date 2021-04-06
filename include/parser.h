#pragma once

#include <stdio.h>
#include <iostream>
#include <exception>
#include <algorithm>
#include <string>
#include <vector>

#include "include/token.h"

namespace ceres {
	class Parser {
	public:
		inline bool eof() { return pos >= tokens.size(); }

		inline Token peek() {
			if (eof()) throw std::runtime_error("eof reached while peeking next token");
			return tokens[pos];
		}

		
	private:
		size_t pos;
		std::vector<Token> tokens;
	}
}