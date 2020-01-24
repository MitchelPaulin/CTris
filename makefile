CC = g++

#link the curses directory 
CFLAGS = -lncurses

OUTPUT = ctris

W_DIR = src/windows
COMPILE_WINDOWS = $(W_DIR)/window.cpp $(W_DIR)/game_window.cpp $(W_DIR)/border_window.cpp

B_DIR = src/blocks

all: $(COMPILE_WINDOWS) src/main.cpp
	$(CC) -o $(OUTPUT) src/main.cpp $(COMPILE_WINDOWS) $(CFLAGS)