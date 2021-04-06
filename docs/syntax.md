## Syntax specification for Ceres v0.0.1

Ceres currently supports integers (integral numbers), string literals (either delimited via " or \`),
and boolean data types - `true`, and `false`.

Comments starting with `// line` are ignored by the lexer

## Variables
Variables are defined using the syntax `def <name> :: <type> = <value>;`.
An example of this is `def count :: int = 3`. 

Ceres uses `=` operator to define both variable declaration and variable (re)assignment.

## Formal Grammar
See the `grammar.bnf` file for more information about the formal grammar of Ceres.