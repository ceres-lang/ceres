#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>

#include "../include/token.h"
#include "../include/lexer.h"
#include "../include/parser.h"

std::string read_file_contents(const std::string& path) {
	std::ifstream file(path);

	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

int main() {
	std::printf("Ceres v0.0.1\n");

	auto lexer = new ceres::Lexer();
	auto parser = new ceres::Parser();

	//auto tokens = lexer->scan(R"(def hello_world123 : bool == = true;)");
	auto tokens = lexer->scan(read_file_contents("docs/examples/hello.crs"));

	for (auto& token : tokens) {
		// Print the lexed output
		ceres::pretty_print_token(token);
	}
}