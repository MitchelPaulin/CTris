CC = g++

#link the curses directory 
CFLAGS = -lncurses

OUTPUT = ctris

W_DIR = src/windows
COMPILE_WINDOWS = $(W_DIR)/window.cpp $(W_DIR)/game_window.cpp $(W_DIR)/border_window.cpp

B_DIR = src/blocks
COMPILE_BLOCKS = \
$(B_DIR)/square.cpp $(B_DIR)/block.cpp $(B_DIR)/t_piece.cpp $(B_DIR)/long_piece.cpp \
$(B_DIR)/square_piece.cpp $(B_DIR)/l_left_piece.cpp $(B_DIR)/l_right_piece.cpp $(B_DIR)/snake_right_piece.cpp

all: ${COMPILE_BLOCKS} $(COMPILE_WINDOWS) src/main.cpp
	$(CC) -o $(OUTPUT) ${COMPILE_BLOCKS} $(COMPILE_WINDOWS) src/main.cpp $(CFLAGS)