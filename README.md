# Ceres v0.0.1
Ceres is designed to be a modern and minimalistic C like language. For now, it will be interpreted but later on
I do want to write a compiler (either using LLVM or transpiling to C code).

[View the (sort of) formal grammar](../main/docs/grammar.bnf)

## Building
```
meson setup builddir
meson compile -C builddir && ./builddir/ceres
```

## Example
```scala
def count : int = 3;
println("hello world\n");
```

## Goals
- [x] Lexer
- [ ] Parser
- [ ] AST
- [ ] Interpretor
- [ ] Codegen?
