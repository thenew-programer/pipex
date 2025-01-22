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

static int	open_in_file(char *filename, t_pipe *data)
{
	int	fd;

	if (access(filename, R_OK) == -1)
		die(FILE_READ_ACCESS_ERR, data, 1);
	fd = open(filename, O_RDONLY);
	if (fd < 3)
		die(OPEN_INFILE_ERR, data, 1);
	return (fd);
}

static int	open_out_file(char *filename, t_pipe *data)
{
	int	fd;
	int	ret;
	int	flags;
	int	permissions;

	flags = O_WRONLY;
	ret = access(filename, W_OK);
	if (ret == -1 && ENOENT == 2)
		flags |= O_CREAT;
	else if (ret == 0)
		flags |= O_TRUNC;
	else
		die(FILE_WRITE_ACCESS_ERR, data, 1);
	permissions = S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH;
	fd = open(filename, flags, permissions);
	if (fd < 3)
		die(OPEN_OUTFILE_ERR, data, 1);
	return (fd);
}

int	open_file(char *filename, t_pipe *data, int flags)
{
	int	fd;

	fd = -1;
	if (flags == O_RDONLY)
		fd = open_in_file(filename, data);
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
