# Ceres v0.0.1
Ceres is designed to be a modern and minimalistic C like language. For now, it will be interpreted but later on
I do want to write a compiler (either using LLVM or transpiling to C code).

## Building
```
meson setup builddir
meson compile -C builddir && ./builddir/ceres
```

## Example
```
println("hello world\n");
```

## Goals
- [x] Lexer
- [ ] Parser
- [ ] AST
- [ ] Interpretor
- [ ] Codegen?
