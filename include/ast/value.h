#pragma once

#include <cstddef>
#include <string>
#include <variant>

#include "node.h"

namespace ceres {
	enum class Type {
		INT,
		BOOL,
		CHAR,
		STRING,
	};

	struct IdentifierNode: ASTNode {
	public:
		std::string name;

		IdentifierNode(std::string name) : name(name) {}
	};

	/**
	 * AST node to represent a primitive value
	 */
	struct ValueNode: ASTNode {
	private:
		Type type;
	public:
		std::variant<int, char, bool, std::string> value;

		// Getters
		int& int_val() { return std::get<0>(value); }
		char& char_val() { return std::get<1>(value); }
		bool& bool_val() { return std::get<2>(value); }
		std::string& str_val() { return std::get<3>(value); }

		virtual void accept(NodeVisitor& v);

		template <typename T>
		inline void create_from_primitive(T t) {
			// Template magic to initialize a ValueNode with a primitive type

			if (std::is_same<T, int>::value) {
				this->type = Type::INT;
				this->value = std::move(t);
			}
			else if (std::is_same<T, char>::value) {
				this->type = Type::CHAR;
				this->value = std::move(t);
			}
			else if (std::is_same<T, bool>::value) {
				this->type = Type::BOOL;
				this->value = std::move(t);
			}
			else if (std::is_same<T, std::string>::value) {
				this->type = Type::STRING;
				this->value = std::move(t);
			}
		}
	};
}