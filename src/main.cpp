#include <iostream>
#include <cstdio>

#include "../include/token.h"
#include "../include/lexer.h"
#include "../include/parser.h"

int main() {
	std::printf("Ceres v0.0.1\n");

	auto lexer = new ceres::Lexer();
	auto parser = new ceres::Parser();

	parser->tokens.push_back(ceres::Token(ceres::TokenKind::IDENTIFIER, "hello_world123"));
	auto vnode = parser->parse_identifier();

	std::cout << "IDENT VAL " << vnode.name << std::endl;

	//std::vector<ceres::Token> tokens = lexer->scan(R"(hello="hello \"world\"\\n")");

	auto tokens = lexer->scan(R"(def hello_world123 : bool = true;)");

	for (auto& token : tokens) {
		// Print the lexed output
		//ceres::pretty_print_token(token);
	}
}