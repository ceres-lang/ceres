#pragma once

#include <cstddef>
#include <string>

#include "node.h"

namespace ceres {
	enum class TypeTag {
		TYPE_INT,
		TYPE_CHAR,
		TYPE_STRING,
		TYPE_BOOLEAN
	};

	/**
	 * AST node to represent a primitive value
	 */
	struct ValueNode: ASTNode {
	public:
		// Tagged union to store the type value
		TypeTag tag;
		union {
			int int_val;
			char char_val;
			bool bool_val;
			std::string str_val;
		} value;

		virtual void accept(NodeVisitor& v);

		template <typename T>
		void create_from_primitive(T t);
	};
}