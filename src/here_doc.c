/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:46:03 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/21 11:53:38 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <unistd.h>

#define BUFFER_SIZE 512

char	*read_heredoc(char *limiter)
{
	char	*str;
	char	*tmp;
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;
	buf[0] = 0;
	while (1)
	{
		bytes_read = read(STDIN_FILENO, buf, BUFFER_SIZE);
		tmp = ft_strnstr(buf, limiter, BUFFER_SIZE);
		*tmp = 0;
		tmp = str;
		if (tmp)
			str = ft_strjoin(str, buf);
			

	}
	return (str);
}
