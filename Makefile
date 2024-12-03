# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
HEADERS = binary_trees.h

# Source Files
SRC_0 = 0-binary_tree_node.c
SRC_9 = 0-binary_tree_node.c 9-binary_tree_height.c binary_tree_print.c \
        2-binary_tree_insert_right.c 3-binary_tree_delete.c
SRC_10 = 0-binary_tree_node.c 10-binary_tree_depth.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
SRC_12 = 0-binary_tree_node.c 12-binary_tree_leaves.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
SRC_13 = 0-binary_tree_node.c 13-binary_tree_nodes.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
SRC_14 = 0-binary_tree_node.c 14-binary_tree_balance.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_14 = $(SRC_14:.c=.o)
SRC_15 = 0-binary_tree_node.c 15-binary_tree_is_full.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_15 = $(SRC_15:.c=.o)
SRC_16 = 0-binary_tree_node.c 16-binary_tree_is_perfect.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_16 = $(SRC_16:.c=.o)

OBJ_0 = $(SRC_0:.c=.o)
OBJ_9 = $(SRC_9:.c=.o)
OBJ_10 = $(SRC_10:.c=.o)
OBJ_12 = $(SRC_12:.c=.o)
OBJ_13 = $(SRC_13:.c=.o)

# Executable Targets
TARGETS = 0-node 9-height 10-depth 12-leaves 13-nodes

.PHONY: all clean fclean re

# Default target: build all executables
all: $(TARGETS)

# Rule for 0-node
0-node: 0-main.o $(OBJ_0)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 9-height
9-height: 9-main.o $(OBJ_9)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 10-depth
10-depth: 10-main.o $(OBJ_10)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 12-leaves
12-leaves: 12-main.o $(OBJ_12)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 13-nodes
13-nodes: 13-main.o $(OBJ_13)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 14-balance
14-balance: 14-main.o $(OBJ_14)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 15-full
15-full: 15-main.o $(OBJ_15)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 16-perfect
16-perfect: 16-main.o $(OBJ_16)
	$(CC) $(CFLAGS) -o $@ $^

# Generic rule for object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ_0) $(OBJ_9) $(OBJ_10) $(OBJ_12) $(OBJ_13) *.o

# Clean all build artifacts
fclean: clean
	rm -f $(TARGETS)

# Rebuild everything
re: fclean all
