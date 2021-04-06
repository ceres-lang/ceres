#pragma once

#include <cstddef>
#include <string>

#include "node.h"
#include "value.h"

#include "../token.h"

namespace ceres {
	/**
	 * AST node to represent an operator
	 */
	struct OperatorNode: ASTNode {
	public:
		ASTNode left;
		TokenKind op;
		ASTNode right;

		virtual void accept(NodeVisitor& visitor);
	};
};