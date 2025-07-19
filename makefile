CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LDFLAGS = -lncurses

SRC = src/main.cpp src/tetris.cpp src/rotate_block.cpp
TARGET = bin/tetris-nc

all:$(TARGET)

$(TARGET):
	@mkdir -p bin/
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf bin

.PHONY: all clean
