
```markdown
*This project has been created as part of the 42 curriculum by aabu-jwe.*

# Libft

## Description
Libft is the introductory project of the 42 cursus curriculum. The objective is to re-implement essential functions from the standard C library (`libc`), along with custom memory and string utilities, as well as singly linked-list data structures. Because standard library routines are largely prohibited throughout the 42 core program, the resulting static library (`libft.a`) serves as the foundational utility suite for future projects such as `ft_printf`, `get_next_line`, `push_swap`, and `minishell`.

### Detailed Library Description
The project compiles into a static archive (`libft.a`) containing 43 functions organized into three sections:

1. **Part 1 - Libc Functions:**
   - **Memory Operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
   - **String Inspection & Copying:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
   - **Type Checking & ASCII:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
   - **Dynamic Memory & Conversions:** `ft_atoi`, `ft_calloc`, `ft_strdup`

2. **Part 2 - Additional Functions:**
   - **String Manipulation:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
   - **File Descriptor Writes:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

3. **Bonus Part - Linked List Manipulations:**
   - Singly linked list utilities built around the `t_list` structure:
     - Node creation & deletion: `ft_lstnew`, `ft_lstdelone`, `ft_lstclear`
     - Insertion & inspection: `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`
     - Iteration & transformation: `ft_lstiter`, `ft_lstmap`

---

## Instructions

### Compilation
The project includes a standard `Makefile` that compiles the library using `cc` with the flags `-Wall -Wextra -Werror`:

- Compile mandatory functions into `libft.a`:
  ```bash
  make

```

* Compile both mandatory and bonus linked-list functions:
```bash
make bonus

```


* Clean intermediate object files (`.o`):
```bash
make clean

```


* Remove all object files and the compiled archive (`libft.a`):
```bash
make fclean

```


* Perform a complete clean rebuild:
```bash
make re

```



### Usage

Include `libft.h` in your source files and link the archive when compiling your project:

1. Include the header:
```c
#include "libft.h"

```


2. Compile and link:
```bash
cc -Wall -Wextra -Werror main.c libft.a -o my_program

```



---

## Resources

* **References & Documentation:**
* Standard UNIX manual pages: `man 3 malloc`, `man 3 string`, `man 3 stddef`.
* POSIX IEEE Std 1003.1 reference specifications for memory and pointer semantics.
* GNU C Library (glibc) source reference for standard boundary edge cases.


* **AI Usage:**
* AI was utilized as a thought partner to verify edge-case memory safety (such as overlap prevention in `ft_memmove`, bounds handling in `ft_strlcat`, and memory cleanup handling on allocation failures in `ft_lstmap`).
* AI assisted in designing comprehensive assertion test suites to validate heap allocations, file descriptor redirections, and Valgrind leak safety.



```

---

### Command to Create It Directly

Run this command in the root folder of your project to create or overwrite `README.md` immediately[cite: 2]:

```bash
cat << 'EOF' > README.md
*This project has been created as part of the 42 curriculum by aabu-jwe.*

# Libft

## Description
Libft is the introductory project of the 42 cursus curriculum. The objective is to re-implement essential functions from the standard C library (`libc`), along with custom memory and string utilities, as well as singly linked-list data structures. Because standard library routines are largely prohibited throughout the 42 core program, the resulting static library (`libft.a`) serves as the foundational utility suite for future projects such as `ft_printf`, `get_next_line`, `push_swap`, and `minishell`.

### Detailed Library Description
The project compiles into a static archive (`libft.a`) containing 43 functions organized into three sections:

1. **Part 1 - Libc Functions:**
   - **Memory Operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
   - **String Inspection & Copying:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
   - **Type Checking & ASCII:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
   - **Dynamic Memory & Conversions:** `ft_atoi`, `ft_calloc`, `ft_strdup`

2. **Part 2 - Additional Functions:**
   - **String Manipulation:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
   - **File Descriptor Writes:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

3. **Bonus Part - Linked List Manipulations:**
   - Singly linked list utilities built around the `t_list` structure:
     - Node creation & deletion: `ft_lstnew`, `ft_lstdelone`, `ft_lstclear`
     - Insertion & inspection: `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`
     - Iteration & transformation: `ft_lstiter`, `ft_lstmap`

---

## Instructions

### Compilation
The project includes a standard `Makefile` that compiles the library using `cc` with the flags `-Wall -Wextra -Werror`:

- Compile mandatory functions into `libft.a`:
  ```bash
  make

```

* Compile both mandatory and bonus linked-list functions:
```bash
make bonus

```


* Clean intermediate object files (`.o`):
```bash
make clean

```


* Remove all object files and the compiled archive (`libft.a`):
```bash
make fclean

```


* Perform a complete clean rebuild:
```bash
make re

```



### Usage

Include `libft.h` in your source files and link the archive when compiling your project:

1. Include the header:
```c
#include "libft.h"

```


2. Compile and link:
```bash
cc -Wall -Wextra -Werror main.c libft.a -o my_program

```



---

## Resources

* **References & Documentation:**
* Standard UNIX manual pages: `man 3 malloc`, `man 3 string`, `man 3 stddef`.
* POSIX IEEE Std 1003.1 reference specifications for memory and pointer semantics.
* GNU C Library (glibc) source reference for standard boundary edge cases.


* **AI Usage:**
* AI was utilized as a thought partner to verify edge-case memory safety (such as overlap prevention in `ft_memmove`, bounds handling in `ft_strlcat`, and memory cleanup handling on allocation failures in `ft_lstmap`).
* AI assisted in designing comprehensive assertion test suites to validate heap allocations, file descriptor redirections, and Valgrind leak safety.
EOF



```

```
