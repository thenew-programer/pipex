/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IO.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:39:17 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/16 10:50:12 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_in_file(char *filename)
{
	int	fd;
	int	ret;

	ret = access(filename, R_OK);
	if (ret == -1)
	{
		die("", filename, NULL, FALSE);
		return (STDIN_FILENO);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 3)
	{
		die("", filename, NULL, FALSE);
		return (STDIN_FILENO);
	}
	return (fd);
}

static int	open_out_file(char *filename, t_pipe *data)
{
	int	fd;
	int	ret;
	int	flags;
	int	permissions;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	ret = access(filename, W_OK);
	if (ret == -1 && errno == EACCES)
		die("", filename, NULL, TRUE);
	permissions = S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH;
	fd = open(filename, flags, permissions);
	if (fd < 3)
		die("", filename, data, TRUE);
	return (fd);
}

int	open_file(t_pipe *data, char *filename, int flags)
{
	int	fd;

	fd = -1;
	if (flags == O_RDONLY)
		fd = open_in_file(filename);
	else if (flags == O_WRONLY)
		fd = open_out_file(filename, data);
	return (fd);
}

int	close_file(int *fd, int dflt)
{
	if (*fd < 3)
		return (TRUE);
	close(*fd);
	*fd = dflt;
	return (TRUE);
}
