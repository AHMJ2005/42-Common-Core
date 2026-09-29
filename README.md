*This project has been created as part of the 42 curriculum by aabu-jwe.*

# Libft - Your Very First Own Library

## Description
**Libft** is the first project in the 42 curriculum. The goal of this project is to reimplement a subset of the standard C library (`libc`) functions, alongside additional utility functions for memory management, string manipulation, output formatting, and linked list handling.

Developing this custom library provides an in-depth understanding of low-level data representation, dynamic memory allocation on the heap (`malloc` / `free`), pointer arithmetic, and algorithmic edge cases. The resulting `libft.a` archive serves as a foundational library that will be expanded and reused throughout subsequent C programming assignments across the 42 curriculum.

---

## Detailed Overview of the Library

The library is compiled into a single static library file named `libft.a` and exposes prototypes via `libft.h`. The functions are divided into three primary categories:

### 1. Part 1 — Libc Functions
Standard library functions reimplemented with the exact same behaviors and prototypes (prefixed with `ft_`):

* **Character Classification & Conversion:**
  * `ft_isalpha` - Test for an alphabetic character.
  * `ft_isdigit` - Test for a digit (0 through 9).
  * `ft_isalnum` - Test for an alphanumeric character.
  * `ft_isascii` - Test for a 7-bit ASCII character.
  * `ft_isprint` - Test for any printable character including space.
  * `ft_toupper` - Convert lowercase letter to uppercase.
  * `ft_tolower` - Convert uppercase letter to lowercase.
* **String Examination & Search:**
  * `ft_strlen` - Calculate the length of a string.
  * `ft_strchr` - Locate character in string (first occurrence).
  * `ft_strrchr` - Locate character in string (last occurrence).
  * `ft_strncmp` - Compare two strings up to `n` characters.
  * `ft_strnstr` - Locate a substring within a string up to length `len`.
* **String Manipulation & Memory Operations:**
  * `ft_memset` - Fill memory with a constant byte.
  * `ft_bzero` - Zero a byte string.
  * `ft_memcpy` - Copy memory area.
  * `ft_memmove` - Copy memory area safely handling overlapping regions.
  * `ft_memchr` - Scan memory for a character.
  * `ft_memcmp` - Compare memory areas.
  * `ft_strlcpy` - Size-bounded string copy.
  * `ft_strlcat` - Size-bounded string concatenation.
* **Conversions & Heap Allocations:**
  * `ft_atoi` - Convert ASCII string to integer.
  * `ft_calloc` - Allocate memory initialized to zero.
  * `ft_strdup` - Duplicate a string using dynamic memory allocation.

### 2. Part 2 — Additional Utility Functions
Functions that either do not exist in the standard C library or exist in an alternative form:

* `ft_substr` - Allocates and returns a substring from a string `s`.
* `ft_strjoin` - Concatenates two strings into a newly allocated string.
* `ft_strtrim` - Trims leading and trailing characters matching `set` from `s1`.
* `ft_split` - Splits a string into an array of substrings using a delimiter character `c`.
* `ft_itoa` - Converts an integer into a null-terminated string representation.
* `ft_strmapi` - Applies a mapping function to each character of a string to create a new string.
* `ft_striteri` - Applies an in-place function to each character of a string by address.
* `ft_putchar_fd` - Outputs a character to the specified file descriptor.
* `ft_putstr_fd` - Outputs a string to the specified file descriptor.
* `ft_putendl_fd` - Outputs a string followed by a newline to the specified file descriptor.
* `ft_putnbr_fd` - Outputs an integer to the specified file descriptor.

### 3. Part 3 — Linked List Functions
Functions operating on the custom single-linked list structure `t_list`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

* `ft_lstnew` - Allocates and initializes a new list node.
* `ft_lstadd_front` - Inserts a node at the head of a list.
* `ft_lstsize` - Counts the number of nodes in a list.
* `ft_lstlast` - Retrieves the final node in a list.
* `ft_lstadd_back` - Appends a node to the end of a list.
* `ft_lstdelone` - Frees the memory of an individual node using a deletion function.
* `ft_lstclear` - Frees and clears an entire linked list from memory.
* `ft_lstiter` - Iterates over a list, applying a function to each node's content.
* `ft_lstmap` - Iterates over a list, applying a transformation function to create a new mapped list.

---

## Instructions

### Requirements
* Compiler: `cc` (Clang or GCC)
* Compilation Flags: `-Wall -Wextra -Werror`
* Archiver: `ar`
* Operating System: Linux (Debian, Ubuntu, Fedora) or macOS

### Compilation
To compile the library, navigate to the root directory where the `Makefile` is located and run:

```bash
make
```

This compiles all `.c` source files and archives them into the static library `libft.a`.

### Available Makefile Targets
* `make` or `make all`: Compiles all source files and produces `libft.a`.
* `make clean`: Removes all compiled object files (`*.o`).
* `make fclean`: Cleans all object files and removes `libft.a`.
* `make re`: Performs a complete rebuild (`fclean` followed by `all`).

### Linking and Usage
To use `libft` in your own C project:

1. Include the header file in your code:
   ```c
   #include "libft.h"
   ```
2. Compile your program specifying the path to `libft.a` and including the header search path:
   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

---

## Resources

### References & Documentation
* Linux Programmer's Manual / POSIX Reference (`man 3 malloc`, `man 3 string`, `man 3 stdlib`).
* [The C Programming Language (2nd Edition) - Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language).
* Norminette 42 Norm Documentation & Style Guidelines.

### AI Usage Disclosure
In accordance with the 42 AI Charter:
* **Tool Used:** Gemini.
* **Scope & Purpose:** Used exclusively as a documentation and formatting assistant to generate this `README.md` file layout in accordance with the 42 evaluation rubrics, and to structure testing checklists for edge cases (e.g., verifying integer overflow behaviors and zero-byte allocations in `calloc`).
* **Implementation Independence:** All C function implementations, algorithmic logic, pointer manipulations, and Makefile rules were written and reasoned through independently.
