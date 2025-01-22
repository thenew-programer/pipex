/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:39:50 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/16 12:00:15 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	die(char *err, t_pipe *data, int status)
{
	if (err)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		if (errno == 0 && err && *err)
			ft_putendl_fd(err, STDERR_FILENO);
		else
			perror("");
	}
	if (data)
		free_pipe_data(data);
	exit(status);
}
