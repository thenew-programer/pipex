/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:38:35 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/26 11:24:18 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

/* Get_Next_Line Buffer size*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

/* Part 1: Libc functions */

/**
 * Desc:	Checks if the char 'c' is an alphabet or digit.
 *
 * @c:		The char to check.
 *
 * return:	Non-zero value if 'c' is alnum
 * 			Zero otherwise.
 */
int		ft_isalnum(int c);

/**
 * Desc:	checks if the char 'c' is an alphabet.
 *
 * @c:		The char to check.
 *
 * return:	Non-zero value if 'c' is alpha.
 * 			Zero otherwise.
 */
int		ft_isalpha(int c);

/**
 * Desc:	checks if the char 'c' is a digit.
 *
 * @c:		The char to check.
 *
 * return:	Non-zero value if 'c' is alpha.
 * 			Zero otherwise.
 */
int		ft_isdigit(int c);

/**
 * Desc:	checks if the char 'c' is an ascii char.
 *
 * @c:		The char to check.
 *
 * return:	Non-zero value if 'c' is ascii.
 * 			Zero otherwise.
 */
int		ft_isascii(int c);

/**
 * Desc:	checks if the char 'c' is a printable
 * 			ascii char.
 *
 * @c:		The char to check.
 *
 * return:	Non-zero value if 'c' is a printable ascii.
 * 			Zero otherwise.
 */
int		ft_isprint(int c);

/**
 * Desc:	converts the character 'c' to uppercase.
 *
 * @c:		The char to modify.
 *
 * return:	The converted char if possible.
 * 			The original char if not possible.
 */
int		ft_toupper(int c);

/**
 * Desc:	converts the character 'c' to lowercase.
 *
 * @c:		The char to modify.
 *
 * return:	The converted char if possible.
 * 			The original char if not possible.
 */
int		ft_tolower(int c);

/**
 * Desc:	compares two string 's1' and 's2'.
 *
 * @s1:		The string to be compared.
 * @s2:		The string to be compared with.
 *
 * return:	0 if the strings 's1' and s2' are equal.
 * 			negative value if 's1' is less than 's2'.
 * 			positive value if 's1' is greater than 's2'.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *str);
void	*ft_memset(void *dest, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/* Part 2: */

/*
 * Desc:	allocates and returns a substring from the string 's'
 *
 * @s:		pointer to string from which to create the substring.
 * @start:	The start index of the substring in the string 's'.
 * @len:	The maximum length of the substring.
 *
 * Return:	The substring.
 *			NULL if the allocation fails.
 * */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
 * Desc:	Allocate and returns a new string which is the result of the
 * 			of 's1' and 's2'.
 *
 * @s1:		pointer to the prefix string.
 * @s2:		pointer to the suffix string.
 *
 * return:	The new string
 * 			NULL if allocation fails
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
 * Desc:	allocates and returns a copy of 's1' with the chars specified
 * 			in 'set' removed from the beginning and the end of the string
 *
 * @s1:		The string to be trimmed.
 * @s2:		The reference set of chars to trim.
 *
 * return:	The trimmed string
 * 			NULL if the allocation fails
*/
char	*ft_strtrim(char const *s1, char const *set);

/*
 * Desc:	Allocates and returns an array of strings obtained
 * 			by splitting 's' using the char 'c' as a delimiter.
 * 			the array must end with a NULL pointer.
 *
 * @s:		The string to be split.
 * @c:		The delimiter character.
 *
 * return:	The array of new strings.
 * 			NULL if the allocation fails
*/
char	**ft_split(char const *s, char c);

/*
 * Desc:	Allocates and returns string representing the integer
 * 			received as an argument. Negative numbes included.
 *
 * @n:		The integer to convert
 *
 * return:	The string representing the integer.
 * 			NULL if the allocation fails.
*/
char	*ft_itoa(int n);

/**
 * Desc:	Applies the function f to each character of the
 * 			string 's' and save the output to a new string
 * 			created using malloc.
 *
 * @s:		The string on which to iterate.
 * @f:		The function to apply to each char.
 *
 * return:	The string created from the application of 'f'
 * 			NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
 * Desc:	Applies the function 'f' on each character of the string
 * 			passed as argument. Each char is passed by address to 'f'
 * 			to be modified if necessary.
 *
 * @s:		The string on which to iterate
 * @f:		The function to apply to each char.
 *
 * return:	None
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * Desc:	Outputs the char 'c' to the given file descriptor.
 *
 * @c:		The character to output.
 * @fd:		The file descriptor on which to write.
 *
 * return:	None.
*/
void	ft_putchar_fd(char c, int fd);

/**
* Desc:		Outputs the string 's' to the given file
* 			descriptor.
*
* @s:		The string to output.
* @fd:		the file descriptor on which to write.
*
* return:	None.
*/
void	ft_putstr_fd(char *s, int fd);

/**
* Desc:		Outputs the string 's' to the given file
* 			descriptor, followed by a newline.
*
* @s:		The string to output.
* @fd:		the file descriptor on which to write.
*
* return:	None.
*/
void	ft_putendl_fd(char *s, int fd);

/**
 * Desc:	Outputs the integer 'n' to the given
 * 			file descriptor.
 *
 * @n:		The integer to output.
 * @fd:		The file descriptor on which to write.
 *
 * return:	None.
*/
void	ft_putnbr_fd(int n, int fd);

/* Bonus */

/**
 * @content:	The data contained in the node.
 * @next:		The address to the next node, or
 *				NULL if the next node is the last one.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * Desc:		Allocates and returns a new node.
 *
 * @content:	The content to create the node with.
 *
 * return:		The new node.
*/
t_list	*ft_lstnew(void *content);

/**
 * Desc:	Adds the node 'new' at the beginning of the list.
 *
 * @lst:	The beginning of the list.
 *
 * return:	None
*/
void	ft_lstadd_front(t_list **lst, t_list *new_node);

/**
 * Desc:	Counts the number of nodes in a list.
 *
 * @lst:	The beginning of the list.
 *
 * @return:	the length of the list.
*/
int		ft_lstsize(t_list *lst);

/**
 * Desc:	Returns the last node of the list.
 *
 * @lst:	the beginning of the list.
 *
 * return:	Last node of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/**
 * Desc:	Adds the node 'new' at the end of the list.
 *
 * @lst:	The address of a pointer to the first link of a list.
 * @new:	The address of a pointer to the node to be added to
 *			the list.
 *
 * return:	None
*/
void	ft_lstadd_back(t_list **lst, t_list *new_node);

/**
 * Desc:	Takes as a parameter a node and frees the memory
 *			of the node's content using the funtion 'del' given
 *			as a param and free the node.
 *
 * @lst:	The node to free.
 * @del:	The address of the function used to del the content
 *
 * return:	None.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * Desc:	Iterates the list 'lst' and applies the function
 *			'f' on the content of each node.
 *
 * @lst:	the address of a pointer to a node.
 * @f:		The address of the function used to iterate on the lst.
 *
 * return:	None.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Desc:	Iterates the list 'lst' and applies the function 'f'
 *			on the content of each node. Creates a new list
 *			resulting of the successive applications of the
 *			function 'f'. The 'del' function is used to delete
 *			the content of a node if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * Desc:	function that returns a line read from a
 *			file descriptor
 *
 * @fd:		File descriptor to read from.
 *
 * return:	line from file, Or null if
 * 			an error occur.
*/
char	*get_next_line(int fd);
#endif
