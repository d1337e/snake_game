CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LIBS = -lncurses

SRCDIR = src
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/Field.cpp $(SRCDIR)/Snake.cpp $(SRCDIR)/Game.cpp $(SRCDIR)/Food.cpp
TARGET = snake

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LIBS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

install-deps-ubuntu:
	sudo apt update
	sudo apt install build-essential libncurses5-dev libncursesw5-dev

install-deps-fedora:
	sudo dnf install gcc gcc-c++ ncurses-devel

install-deps-arch:
	sudo pacman -S gcc ncurses

.PHONY: clean run install-deps-ubuntu install-deps-fedora install-deps-arch