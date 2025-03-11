CC = clang++
CFLAGS = -Wall -Wextra -std=c++17

build: 
  $(CC) $(CFLAGS) simplemath.cpp -o simplemath

clean:
  rm -f simplemath

.PHONY: clean