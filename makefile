CC = g++

#link the curses directory 
CFLAGS = -lncurses

all: window.cpp border_window.cpp game_window.cpp main.cpp
	$(CC) -o output main.cpp window.cpp game_window.cpp border_window.cpp $(CFLAGS)