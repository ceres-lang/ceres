#include <iostream>
#include <stdio.h>
#include "../include/lexer.h"

int main() {
	std::printf("Ceres v0.0.1\n");

	auto lexer = new ceres::Lexer();
	//std::vector<ceres::Token> tokens = lexer->scan(R"(hello="hello \"world\"\\n")");

	auto tokens = lexer->scan(R"(def hello_world123 : bool = true;)");

	for (auto& token : tokens) {
		// Print the lexed output
		ceres::pretty_print_token(token);
	}
}