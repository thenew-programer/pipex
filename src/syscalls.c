/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscalls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:01:27 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/26 11:04:06 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	duptwo(t_pipe *data, int oldfd, int newfd)
{
	int	ret;

	ret = dup2(oldfd, newfd);
	if (-1 == ret)
		die("", "", data, TRUE);
	return (ret);
}

int	access_file(t_pipe *data, char *filename, int mode)
{
	int	ret;

	ret = access(filename, mode);
	if (ret == -1)
		die("", filename, data, TRUE);
	return (ret);
}

int	create_pipe(t_pipe *data, int *fd)
{
	int	ret;

	ret = pipe(fd);
	if (ret == -1)
		die("", "", data, TRUE);
	return (ret);
}
