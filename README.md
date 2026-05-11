*This project has been created as part of the 42 curriculum by qianshuyin.*

## Description

**push_swap** is a sorting algorithm project where the goal is to sort a stack of integers using the fewest possible operations.

The program receives a list of integers as arguments, which are loaded onto stack **A**. Using only a restricted set of stack operations and a second auxiliary stack **B**, it must output the sequence of operations that sorts the integers in ascending order on stack A.

The algorithm implemented is a **greedy cost-based sort** (commonly called "Turkish sort"):
1. All elements except the top 3 are pushed from A to B.
2. Stack A is sorted with a brute-force 3-element sort.
3. For each node in B, the cheapest insertion point in A is found by minimizing the total rotation cost of both stacks combined.
4. Nodes are pushed back to A one by one in optimal order.
5. Finally, A is rotated until the smallest element is on top.

The 11 allowed operations are: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` binary. `make clean` removes object files; `make fclean` removes everything including the binary; `make re` does a full rebuild.

### Execution

```bash
./push_swap <integer> [<integer> ...]
```

Pass a list of unique integers as arguments. The program prints the sorted sequence of operations to stdout.

**Examples:**

```bash
# Sort 5 numbers
./push_swap 3 1 4 1 5
# Error — duplicates

./push_swap 5 3 1 4 2
# outputs a sequence of operations, e.g.:
# pb
# pb
# ra
# ...

# Check move count
./push_swap 5 3 1 4 2 | wc -l

# Validate correctness using a checker (if available)
ARG="5 3 1 4 2"; ./push_swap $ARG | ./checker $ARG
```

**Error handling:** the program prints `Error` to stderr and exits if arguments are not valid integers, contain duplicates, or are out of 32-bit integer range.

## Resources

- [push_swap subject (42 intra)](https://cdn.intra.42.fr/pdf/pdf/104798/en.us_push_swap.pdf) — official project specification
- [Sorting algorithms overview — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm) — background on sorting concepts
- [The "Turkish sort" explained — Medium](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — walkthrough of the greedy cost-based approach used in this project
- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — tool for visually debugging operation sequences

### AI usage

Claude (claude-sonnet-4-6 via Claude Code) was used to write this README file. It was not used for algorithm design, implementation, or debugging of the C source code.
