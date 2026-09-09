*This project has been created as part of the 42 curriculum by <hlatt>.*

# Description

Libft is a custom C library developed as part of the 42 curriculum. The goal of this project is to recreate a collection of commonly used functions from the C standard library and to implement additional utility functions that can be reused throughout future 42 projects.

The project focuses on developing a strong understanding of C programming fundamentals, including memory management, pointers, strings, linked lists, and function pointers.

The library is compiled into a static library called `libft.a`, which can be included and linked with other C projects.

# Instructions

## Compilation

The library can be compiled using the provided Makefile:

```bash
make
```

This creates the static library:

```text
libft.a
```

## Makefile Commands

```bash
make
```

Compiles the library.

```bash
make clean
```

Removes the object files.

```bash
make fclean
```

Removes the object files and `libft.a`.

```bash
make re
```

Removes the existing compiled files and recompiles the library.

## Using Libft

Include the library header in your C source file:

```c
#include "libft.h"
```

Then compile and link the library with your project:

```bash
cc your_file.c -I. -L. -lft
```

# Resources

## References

* C standard library documentation: https://en.cppreference.com/w/c
* POSIX documentation: https://pubs.opengroup.org/onlinepubs/9699919799/
* GNU C Library documentation: https://www.gnu.org/software/libc/manual/
* The Libft subject and documentation provided by the 42 curriculum.

## AI Usage

AI was used as a learning and debugging aid during this project.

It was used for:

* explaining C programming concepts such as pointers, pointer-to-pointer usage, memory allocation, and linked-list manipulation;
* understanding the purpose and expected behavior of the required Libft functions;
* reasoning about edge cases and memory management;
* analyzing compiler, linker, and tester errors;
* debugging implementation logic, including memory leaks and allocation-failure handling;
* helping identify and understand problems without replacing the student's own implementation and understanding.

The project was implemented and tested by the student. AI was primarily used to explain concepts, assist with reasoning, and help debug problems encountered during development.

# Library Description

Libft contains a collection of functions for character handling, string manipulation, memory management, number conversion, file-descriptor output, and singly linked-list manipulation.

## Character Functions

* `ft_isalpha`
* `ft_isdigit`
* `ft_isalnum`
* `ft_isascii`
* `ft_isprint`
* `ft_toupper`
* `ft_tolower`

## String Functions

* `ft_strlen`
* `ft_strlcpy`
* `ft_strlcat`
* `ft_strchr`
* `ft_strrchr`
* `ft_strncmp`
* `ft_strnstr`
* `ft_strdup`

## Memory Functions

* `ft_memset`
* `ft_bzero`
* `ft_memcpy`
* `ft_memmove`
* `ft_memchr`
* `ft_memcmp`
* `ft_calloc`

## Conversion Functions

* `ft_atoi`
* `ft_itoa`

## File Descriptor Functions

* `ft_putchar_fd`
* `ft_putstr_fd`
* `ft_putendl_fd`
* `ft_putnbr_fd`

## String Utility Functions

* `ft_substr`
* `ft_strjoin`
* `ft_strtrim`
* `ft_split`
* `ft_strmapi`
* `ft_striteri`

## Linked List Functions

The library also contains functions for manipulating singly linked lists using the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

The linked-list functions are:

* `ft_lstnew` — creates a new node.
* `ft_lstadd_front` — adds a node to the beginning of a list.
* `ft_lstsize` — counts the number of nodes in a list.
* `ft_lstlast` — returns the last node of a list.
* `ft_lstadd_back` — adds a node to the end of a list.
* `ft_lstdelone` — deletes one node and its content.
* `ft_lstclear` — deletes and frees every node in a list.
* `ft_lstiter` — applies a function to every node's content.
* `ft_lstmap` — creates a new list by applying a function to every node's content.

The linked-list functions make extensive use of pointers and function pointers and require careful memory management to avoid leaks and invalid memory access.
