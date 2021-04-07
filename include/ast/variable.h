#pragma once

#include <cstddef>
#include <string>

#include "node.h"
#include "value.h"

namespace ceres {
	/**
	 * AST node to represent a variable declaration 
	 */
	struct VariableDeclarationNode: ASTNode {
	public:
		// If this is set, we throw an error if the user attempts to modify the variable
		// TODO: implement later
		bool is_constant;
		std::string name;
		ValueNode val;

		VariableDeclarationNode(bool constant, std::string name, ValueNode val);
		virtual void accept(NodeVisitor& visitor);
	};

	struct VariableAssignmentNode: ASTNode {
	public:
		std::string name;
		ValueNode value;

		virtual void accept(NodeVisitor& visitor);	
	};
};