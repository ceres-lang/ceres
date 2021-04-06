## Syntax specification for Ceres v0.0.1

Ceres currently supports integers (integral numbers), string literals (either delimited via " or \`),
and boolean data types - `true`, and `false`.

Comments starting with `// line` are ignored by the lexer

```
%precedence + 10
%precedence - 10
%precedence * 20
%precedence / 20

Expr := Integer 
     | Identifier
     | Expr "+" Expr
     | Expr "-" Expr
     | Expr "*" Expr
     | Expr "/" Expr

Identifier := [A-Za-z_]+
String := StringDelim [StringDelim^]+ StringDelim
StringDelim = "\""
            | "`" 

Integer := [0-9]+

%comment "//[^\n]"
```