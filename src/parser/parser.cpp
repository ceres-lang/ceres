#include "../include/parser.h"
#include "../include/ast/value.h"

namespace ceres {

	IdentifierNode Parser::parse_identifier() {
		std::string name = peek().data;
		IdentifierNode i_node(name);

		advance();
		return i_node;
	}

	ValueNode Parser::parse_number() {
		int value = std::stoi(peek().data);
		ValueNode v_node;

		v_node.create_from_primitive<int>(value);
		advance();

		return v_node;
	}

	ValueNode Parser::parse_string() {
		std::string value = peek().data;
		ValueNode v_node;

		v_node.create_from_primitive<std::string>(value);
		advance();

		return v_node;
	}
}