#include <string>

#include "../../include/ast/value.h"
#include "../../include/ast/variable.h"

namespace ceres {

	VariableDeclarationNode::VariableDeclarationNode(bool constant, std::string name, ValueNode val) {
		this->is_constant = constant;
		this->name = name;
		this->val = val;
	}

	void VariableDeclarationNode::accept(NodeVisitor& visitor) {
		// TODO: add visitor stuff
	}

	void VariableAssignmentNode::accept(NodeVisitor& visitor) {
		// TODO: add visitor stuff
	}
}