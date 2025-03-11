CC = clang++
CFLAGS = -Wall -Wextra -std=c++17
TARGET = simplemath

build: $(TARGET)

$(TARGET):
  $(CC) $(CFLAGS) simplemath.cpp -o $@

clean:
  rm -f $(TARGET)

.PHONY: clean