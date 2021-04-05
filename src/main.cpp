#include <iostream>
#include <stdio.h>
#include "../include/lexer.h"

int main() {
	std::printf("Ceres v0.0.1\n");

	auto lexer = new ceres::Lexer();
	std::vector<ceres::Token> tokens = lexer->scan("1 + 2");

	for (auto token : tokens) {
		// Print the lexed output
		std::cout << token.kind << ": " << token.data << "\n";
	}
}