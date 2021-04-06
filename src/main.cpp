#include <iostream>
#include <stdio.h>
#include "../include/lexer.h"

int main() {
	std::printf("Ceres v0.0.1\n");

	auto lexer = new ceres::Lexer();// big gay\nhello(\"hello world\")
	std::vector<ceres::Token> tokens = lexer->scan("hello=`hello`;");

	for (auto token : tokens) {
		// Print the lexed output
		ceres::pretty_print_token(token);
	}
}