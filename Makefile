# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
HEADERS = binary_trees.h

# Source Files
SRC_0 = 0-binary_tree_node.c
SRC_9 = 0-binary_tree_node.c 9-binary_tree_height.c binary_tree_print.c \
        2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_0 = $(SRC_0:.c=.o)
OBJ_9 = $(SRC_9:.c=.o)

# Executable Targets
TARGETS = 0-node 9-height

.PHONY: all clean fclean re

# Default target: build all executables
all: $(TARGETS)

# Rule for 0-node
0-node: 0-main.o $(OBJ_0)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 9-height
9-height: 9-main.o $(OBJ_9)
	$(CC) $(CFLAGS) -o $@ $^

# Generic rule for object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ_0) $(OBJ_9) *.o

# Clean all build artifacts
fclean: clean
	rm -f $(TARGETS)

# Rebuild everything
re: fclean all
