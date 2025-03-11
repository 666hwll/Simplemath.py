CC = clang++
CFLAGS = -Wall -Wextra -std=c++17
TARGET = simplemath

build: 
  $(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET)

clean:
  rm -f $(TARGET)

.PHONY: clean