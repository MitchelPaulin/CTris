CC = g++

#link the curses directory 
CFLAGS = -lncurses

OUTPUT = ctris

all: window.cpp border_window.cpp game_window.cpp main.cpp
	$(CC) -o $(OUTPUT) main.cpp window.cpp game_window.cpp border_window.cpp $(CFLAGS)