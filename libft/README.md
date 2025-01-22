# Libft

## Project Overview
This project is about coding a C library called Libft.

## Project Requirements
- Language: C

- Compliance: Code must follow project Norm standards, avoid memory leaks, and prevent crashes.

- Files: `Makefile`, `libft.h`, and source files (`*.c`).

## Core Functions
1. Libc Reimplementations: Replicate functions like `ft_strlen`, `ft_memcpy`, and more without external libraries.

2. Additional Utilities: Custom implementations of functions like `ft_split`, `ft_itoa`.

3. Bonus: A linked list suite using `t_list`.
```c
/**
 * @content:	The data contained in the node.
 * @next:		The address to the next node, or
 *				NULL if the next node is the last one.
*/
typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;
```

## Compilation
- Ensure Makefile supports `all`, `clean`,  `fclean`, `re`, and `bonus` targets

- to compile run:
    ```bash
    make
    # To bonus part to library use:
    make bonus
    ```

## More Details
- For more details see the project's [subject](en.subject.pdf).
