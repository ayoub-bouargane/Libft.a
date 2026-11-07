*This project has been created as part of the 42 curriculum by aybouarg.*

# Libft

## Description

**Libft** is the first project of the 42 common core. The goal is to build, a personal C library (`libft.a`) that re-implements a set of standard C library functions, adds a few useful utility functions, and provides a basic linked-list. The library is reused in all the following 42 projects.

The project teaches:

- How the standard C library works internally (memory, strings, character handling).
- Dynamic memory management with `malloc` / `free`, and how to avoid leaks.
- Pointer manipulation, `size_t` and `unsigned char` pitfalls, and undefined behavior.
- Writing clean, modular code that follows the 42 Norm (`norminette`).
- Building a static library with `ar` and a proper `Makefile`.

## Instructions

### Requirements

- A C compiler (`cc`, `gcc`)
- `make`
- `ar`
- `git` (only to clone the repository)

### Installation

1. Go into the project folder:

```bash
cd libft
```

2. Build the library:

```bash
make
```

This creates the static library `libft.a` in the root of the project.

3. Use it in your own project:

- Copy `libft.a` and `libft.h` into your project (or keep the `libft` folder next to it).
- Include the header in your source files:

```c
#include "libft.h"
```

- Compile your program and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c libft.a
```

### Compilation

The library is compiled with the flags `-Wall -Wextra -Werror`.

```bash
make          # builds libft.a (Part 1 and Part 2 and Part 3)
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + make
```

### Norm check

```bash
norminette *.c *.h
```

## Library description

The library is split into three parts: libc re-implementations, additional functions, and the bonus linked-list functions.

### Part 1: Re-implementation of libc functions

#### Character functions

- `ft_isalpha`: returns non-zero if `c` is a letter (`A-Z` or `a-z`), otherwise 0.
- `ft_isdigit`: returns non-zero if `c` is a digit (`0-9`), otherwise 0.
- `ft_isalnum`: returns non-zero if `c` is a letter or a digit, otherwise 0.
- `ft_isascii`: returns non-zero if `c` is in the ASCII range (0 to 127), otherwise 0.
- `ft_isprint`: returns non-zero if `c` is a printable character (32 to 126), otherwise 0.
- `ft_toupper`: converts a lowercase letter to uppercase, and returns other characters unchanged.
- `ft_tolower`: converts an uppercase letter to lowercase, and returns other characters unchanged.

#### Memory functions

- `ft_memset`: fills the first `n` bytes of a memory area with the byte `c`, and returns the area.
- `ft_bzero`: sets the first `n` bytes of a memory area to zero.
- `ft_memcpy`: copies `n` bytes from `src` to `dest`. The areas must not overlap.
- `ft_memmove`: copies `n` bytes from `src` to `dest`, and works correctly even if the areas overlap, by choosing the copy direction.
- `ft_memchr`: searches for the first occurrence of the byte `c` in the first `n` bytes of a memory area, and returns a pointer to it or `NULL`.
- `ft_memcmp`: compares the first `n` bytes of two memory areas, and returns the difference between the first two bytes that differ, or 0 if they are equal.
- `ft_calloc`: allocates memory for `nmemb` elements of `size` bytes, sets it all to zero, and returns `NULL` if the multiplication overflows or if the allocation fails.

#### String functions

- `ft_strlen`: returns the length of a string, without the terminating `\0`.
- `ft_strlcpy`: copies a string into `dst` with a size limit, always null-terminates when `size` is not 0, and returns the length of `src`.
- `ft_strlcat`: appends `src` to the end of `dst` with a size limit, always null-terminates when there is room, and returns the length it tried to create.
- `ft_strchr`: returns a pointer to the first occurrence of the character `c` in a string (the terminating `\0` included), or `NULL`.
- `ft_strrchr`: returns a pointer to the last occurrence of the character `c` in a string (the terminating `\0` included), or `NULL`.
- `ft_strncmp`: compares at most `n` characters of two strings, and returns the difference between the first two characters that differ, or 0.
- `ft_strnstr`: looks for the string `little` inside `big`, searching at most `len` characters, and returns a pointer to the match or `NULL`. An empty `little` returns `big`.
- `ft_strdup`: returns a newly allocated copy of a string.

#### Conversion

- `ft_atoi`: converts the beginning of a string to an `int`. It skips leading whitespace, handles one optional `+` or `-` sign, and reads digits until the first non-digit.

### Part 2: Additional functions

- `ft_substr`: returns a new string extracted from `s`, starting at index `start`, of at most `len` characters. If `start` is beyond the end of `s`, it returns an empty string.
- `ft_strjoin`: returns a new string that is the concatenation of `s1` and `s2`.
- `ft_strtrim`: returns a new string made from `s1` without the characters of `set` at the beginning and at the end.
- `ft_split`: splits a string using the character `c` as a delimiter, and returns a `NULL`-terminated array of newly allocated strings. It frees everything if an allocation fails.
- `ft_itoa`: converts an integer to a newly allocated string, including negative numbers and `INT_MIN`.
- `ft_strmapi`: applies the function `f(index, char)` to each character of a string, and returns a new string made of the results.
- `ft_striteri`: applies the function `f(index, char *)` to each character of a string, directly on the string.
- `ft_putchar_fd`: writes a character to the given file descriptor.
- `ft_putstr_fd`: writes a string to the given file descriptor.
- `ft_putendl_fd`: writes a string followed by a newline to the given file descriptor.
- `ft_putnbr_fd`: writes an integer to the given file descriptor, including negative numbers and `INT_MIN`.

### Part 3: Linked lists

The library defines the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

- `ft_lstnew`: creates a new node with the given content, and `next` set to `NULL`.
- `ft_lstadd_front`: adds a node at the beginning of the list.
- `ft_lstsize`: counts the number of nodes in the list.
- `ft_lstlast`: returns the last node of the list.
- `ft_lstadd_back`: adds a node at the end of the list.
- `ft_lstdelone`: frees one node, after using `del` to free its content.
- `ft_lstclear`: deletes and frees a node and all the nodes after it, using `del` on each content, then sets the list pointer to `NULL`.
- `ft_lstiter`: applies a function to the content of each node.
- `ft_lstmap`: builds a new list by applying a function to the content of each node, and cleans up the new list with `del` if an allocation fails.

### Technical choices

- Byte-wise functions (`ft_memcpy`, `ft_memchr`, `ft_memcmp`, ...) cast pointers and values to `unsigned char`, so they behave like the original libc.
- `ft_memmove` handles overlapping memory by copying forward or backward depending on the addresses.
- `ft_calloc` checks for multiplication overflow before calling `malloc`.
- `ft_split` and `ft_lstmap` free everything already allocated if an allocation fails.
- Functions that mimic libc do not protect against `NULL`, like the originals. Part 2 and bonus functions check their arguments.

## Resources

### References

- `man 3 memset`, `man 3 memcpy`, `man 3 memmove`, `man 3 strlcpy`, `man 3 strlcat`, `man 3 strnstr`, `man 3 atoi`, `man 3 calloc` (Linux / BSD manual pages)
- [ISO/IEC 9899:1999 (C99) standard draft](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)
- [The 42 Norm (norminette)](https://github.com/42School/norminette)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [Valgrind documentation](https://valgrind.org/docs/manual/manual.html)

### Use of AI

AI was used as a helper, not to design the library. The logic of the functions was written by me. AI was used for:

- **Explanations:** understanding concepts such as `size_t` wrap-around, `NULL` handling choices compared to libc, and linker errors.
- **Tests:** suggestions of edge cases to compare my functions against the original libc ones.

Every suggestion was reviewed, tested and understood by me before being used.# Libft.a
