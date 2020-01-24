CC = g++

#link the curses directory 
CFLAGS = -lncurses

OUTPUT = ctris

W_DIR = windows

all: $(W_DIR)/window.cpp $(W_DIR)/border_window.cpp $(W_DIR)/game_window.cpp main.cpp
	$(CC) -o $(OUTPUT) main.cpp $(W_DIR)/window.cpp $(W_DIR)/game_window.cpp $(W_DIR)/border_window.cpp $(CFLAGS)