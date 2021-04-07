## Syntax specification for Ceres v0.0.1
---

Ceres currently supports integers (integral numbers), string literals (either delimited via " or \`),
and boolean data types - `true`, and `false`.

Comments starting with `// line` are ignored by the lexer

## Planned Features
---

## Variables
---
```groovy
def name : str = "charlotte";
def meaning_of_everything : int = 42;
def is_ceres_awesome : bool = true;

// const means we *cannot* modify it after declaration
def const PI : float = 3.14159; // ...
```

## Conditionals
---
```groovy
if (age >= 16) {
    io::printf("can drive");
}
else if (some_other_condition) {
    // .. 
}
else {
    // will be ran if neither of the other conditions are met
}
```

## Loops
---
```rs
loop {
    // rust style infinite loop, must "break" out of it
    if (counter > 10) {
        break;
    }
}

for (def i : int in 0..10) {
    // traditional for loop
}

while (!stopped) {
    // traditional while loop, there is no do while equivalent due to 
    // confusion and do while is a bad practive imo.
}
```

## Functions
---
```kotlin
fun add_two(a : int, b : int): int {
    def result = a + b;
    return result;
}

fun bark(self: &Dog) {
    // special cases for passing a struct as the first parameter
    io::printf("bark");
}

// calling it 
add_two(5, 1); // => 6

// this is valid
bark(my_dog);

// this too is valid
my_dog::bark(); // NOTE: this is NOT oop, just syntax sugar for the above
```

## Formal Grammar
See the `grammar.bnf` file for more information about the formal grammar of Ceres.