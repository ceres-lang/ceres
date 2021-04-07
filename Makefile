TARGET := ceres

CC = clang++
CFLAGS = -Iinclude -Wall -Wextra -O2 -std=c++2a

CPPFILES	:= $(shell find ./src -type f -name '*.cpp')
OBJ			:= $(CPPFILES:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	rm -rf $(TARGET) $(OBJ)
