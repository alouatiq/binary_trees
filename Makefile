# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
HEADERS = binary_trees.h

# Source Files

SRC_0 = 0-binary_tree_node.c
OBJ_0 = $(SRC_0:.c=.o)

SRC_9 = 0-binary_tree_node.c 9-binary_tree_height.c binary_tree_print.c \
        2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_9 = $(SRC_9:.c=.o)

SRC_10 = 0-binary_tree_node.c 10-binary_tree_depth.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_10 = $(SRC_10:.c=.o)

SRC_12 = 0-binary_tree_node.c 12-binary_tree_leaves.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_12 = $(SRC_12:.c=.o)

SRC_13 = 0-binary_tree_node.c 13-binary_tree_nodes.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_13 = $(SRC_13:.c=.o)

SRC_14 = 0-binary_tree_node.c 14-binary_tree_balance.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_14 = $(SRC_14:.c=.o)

SRC_15 = 0-binary_tree_node.c 15-binary_tree_is_full.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_15 = $(SRC_15:.c=.o)

SRC_16 = 0-binary_tree_node.c 16-binary_tree_is_perfect.c binary_tree_print.c \
         2-binary_tree_insert_right.c 3-binary_tree_delete.c
OBJ_16 = $(SRC_16:.c=.o)

SRC_17 = 0-binary_tree_node.c 17-binary_tree_sibling.c binary_tree_print.c \
         3-binary_tree_delete.c
OBJ_17 = $(SRC_17:.c=.o)

SRC_18 = 0-binary_tree_node.c 18-binary_tree_uncle.c binary_tree_print.c \
         3-binary_tree_delete.c
OBJ_18 = $(SRC_18:.c=.o)

# Source and Object Files for Advanced Tasks from 18 to 22
SRC_100 = 0-binary_tree_node.c binary_tree_print.c \
           3-binary_tree_delete.c 100-binary_trees_ancestor.c
OBJ_100 = $(SRC_100:.c=.o)


SRC_101 = 0-binary_tree_node.c binary_tree_print.c 3-binary_tree_delete.c \
           101-binary_tree_levelorder.c
OBJ_101 = $(SRC_101:.c=.o)

SRC_102 = 0-binary_tree_node.c binary_tree_print.c 3-binary_tree_delete.c \
           102-binary_tree_is_complete.c
OBJ_102 = $(SRC_102:.c=.o)

SRC_103 = 0-binary_tree_node.c binary_tree_print.c 103-binary_tree_rotate_left.c
OBJ_103 = $(SRC_103:.c=.o)

# Source Files for Advanced tasks from 23 to 40
SRC_23 = 0-binary_tree_node.c 104-binary_tree_rotate_right.c binary_tree_print.c
SRC_24 = 0-binary_tree_node.c 110-binary_tree_is_bst.c binary_tree_print.c
SRC_25 = 0-binary_tree_node.c 111-bst_insert.c binary_tree_print.c
SRC_26 = 0-binary_tree_node.c 111-bst_insert.c 112-array_to_bst.c binary_tree_print.c
SRC_27 = 0-binary_tree_node.c 111-bst_insert.c 113-bst_search.c binary_tree_print.c
SRC_28 = 0-binary_tree_node.c 111-bst_insert.c 114-bst_remove.c binary_tree_print.c
SRC_30 = 0-binary_tree_node.c 120-binary_tree_is_avl.c binary_tree_print.c
SRC_31 = 0-binary_tree_node.c 121-avl_insert.c binary_tree_print.c
SRC_32 = 0-binary_tree_node.c 121-avl_insert.c 122-array_to_avl.c binary_tree_print.c
SRC_33 = 0-binary_tree_node.c 121-avl_insert.c 123-avl_remove.c binary_tree_print.c
SRC_34 = 0-binary_tree_node.c 124-sorted_array_to_avl.c binary_tree_print.c
SRC_36 = 0-binary_tree_node.c 130-binary_tree_is_heap.c binary_tree_print.c
SRC_37 = 0-binary_tree_node.c 131-heap_insert.c binary_tree_print.c
SRC_38 = 0-binary_tree_node.c 131-heap_insert.c 132-array_to_heap.c binary_tree_print.c
SRC_39 = 0-binary_tree_node.c 131-heap_insert.c 133-heap_extract.c binary_tree_print.c
SRC_40 = 0-binary_tree_node.c 131-heap_insert.c 133-heap_extract.c 134-heap_to_sorted_array.c binary_tree_print.c

# Object Files for Advanced tasks from 23 to 40
OBJ_23 = $(SRC_23:.c=.o)
OBJ_24 = $(SRC_24:.c=.o)
OBJ_25 = $(SRC_25:.c=.o)
OBJ_26 = $(SRC_26:.c=.o)
OBJ_27 = $(SRC_27:.c=.o)
OBJ_28 = $(SRC_28:.c=.o)
OBJ_30 = $(SRC_30:.c=.o)
OBJ_31 = $(SRC_31:.c=.o)
OBJ_32 = $(SRC_32:.c=.o)
OBJ_33 = $(SRC_33:.c=.o)
OBJ_34 = $(SRC_34:.c=.o)
OBJ_36 = $(SRC_36:.c=.o)
OBJ_37 = $(SRC_37:.c=.o)
OBJ_38 = $(SRC_38:.c=.o)
OBJ_39 = $(SRC_39:.c=.o)
OBJ_40 = $(SRC_40:.c=.o)

# Executable Targets for Advanced tasks from 23 to 40
TARGETS = 104-rotate_right 110-is_bst 111-bst_insert 112-array_to_bst 113-bst_search \
          114-bst_remove 120-is_avl 121-avl_insert 122-array_to_avl 123-avl_remove \
          124-sorted_to_avl 130-is_heap 131-heap_insert 132-array_to_heap \
          133-heap_extract 134-heap_to_sorted

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

# Rule for 17-sibling
17-sibling: 17-main.o $(OBJ_17)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 18-uncle
18-uncle: 18-main.o $(OBJ_18)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 100-ancestor
100-ancestor: 100-main.o $(OBJ_100)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for 101-binary_tree_levelorder
101-levelorder: 101-main.o $(OBJ_101)
	$(CC) $(CFLAGS) -o $@ $^

102-complete: 102-main.o $(OBJ_102)
	$(CC) $(CFLAGS) -o $@ $^

103-rotate_left: 103-main.o $(OBJ_103)
	$(CC) $(CFLAGS) -o $@ $^

# Rules for each target
104-rotate_right: 104-main.o $(OBJ_23)
	$(CC) $(CFLAGS) -o $@ $^

110-is_bst: 110-main.o $(OBJ_24)
	$(CC) $(CFLAGS) -o $@ $^

111-bst_insert: 111-main.o $(OBJ_25)
	$(CC) $(CFLAGS) -o $@ $^

112-array_to_bst: 112-main.o $(OBJ_26)
	$(CC) $(CFLAGS) -o $@ $^

113-bst_search: 113-main.o $(OBJ_27)
	$(CC) $(CFLAGS) -o $@ $^

114-bst_remove: 114-main.o $(OBJ_28)
	$(CC) $(CFLAGS) -o $@ $^

120-is_avl: 120-main.o $(OBJ_30)
	$(CC) $(CFLAGS) -o $@ $^

121-avl_insert: 121-main.o $(OBJ_31)
	$(CC) $(CFLAGS) -o $@ $^

122-array_to_avl: 122-main.o $(OBJ_32)
	$(CC) $(CFLAGS) -o $@ $^

123-avl_remove: 123-main.o $(OBJ_33)
	$(CC) $(CFLAGS) -o $@ $^

124-sorted_to_avl: 124-main.o $(OBJ_34)
	$(CC) $(CFLAGS) -o $@ $^

130-is_heap: 130-main.o $(OBJ_36)
	$(CC) $(CFLAGS) -o $@ $^

131-heap_insert: 131-main.o $(OBJ_37)
	$(CC) $(CFLAGS) -o $@ $^

132-array_to_heap: 132-main.o $(OBJ_38)
	$(CC) $(CFLAGS) -o $@ $^

133-heap_extract: 133-main.o $(OBJ_39)
	$(CC) $(CFLAGS) -o $@ $^

134-heap_to_sorted: 134-main.o $(OBJ_40)
	$(CC) $(CFLAGS) -o $@ $^

# Generic rule for object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ_0) $(OBJ_9) $(OBJ_10) $(OBJ_12) $(OBJ_13) \
	      $(OBJ_23) $(OBJ_24) $(OBJ_25) $(OBJ_26) $(OBJ_27) $(OBJ_28) \
	      $(OBJ_30) $(OBJ_31) $(OBJ_32) $(OBJ_33) $(OBJ_34) $(OBJ_36) \
	      $(OBJ_37) $(OBJ_38) $(OBJ_39) $(OBJ_40) *.o

# Clean all build artifacts
fclean: clean
	rm -f $(TARGETS)

# Rebuild everything
re: fclean all
