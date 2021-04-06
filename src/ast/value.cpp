#include <string>
#include <type_traits>

#include "../../include/ast/value.h"

namespace ceres {
	template <typename T>
	void ValueNode::create_from_primitive(T t) {
		// Template magic to initialize a ValueNode with a primitive type

		if (std::is_same<T, int>::value) {
			this->tag = TypeTag::TYPE_INT;
			this->value = static_cast<int>(t);
		}
		else if (std::is_same<T, char>::value) {
			this->tag = TypeTag::TYPE_CHAR;
			this->value = static_cast<char>(t);
		}
		else if (std::is_same<T, char>::value) {
			this->tag = TypeTag::TYPE_BOOLEAN;
			this->value = static_cast<bool>(t);
		}
		else if (std::is_same<T, char>::value) {
			this->tag = TypeTag::TYPE_STRING;
			this->value = static_cast<std::string>(t);
		}
	}

	void ValueNode::accept(NodeVisitor& v) {
		// TODO: add visitor stuff
	}
}