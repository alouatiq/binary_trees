# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
HEADERS = binary_trees.h

# Project Files
SRC = 0-binary_tree_node.c 9-binary_tree_height.c
OBJ = $(SRC:.c=.o)

# Executable Targets
TARGETS = 0-node 9-height

.PHONY: all clean fclean re

# Default target: build all executables
all: $(TARGETS)

# Rule for 0-node
0-node: 0-main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 9-height
9-height: 9-main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Generic rule for object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ) *.o

# Clean all build artifacts
fclean: clean
	rm -f $(TARGETS)

# Rebuild everything
re: fclean all
