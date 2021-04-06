#pragma once

namespace ceres {
	class NodeVisitor {
		// TODO: implement
	};
	
	struct ASTNode {
		virtual void accept(NodeVisitor& v) = 0;
	};
}