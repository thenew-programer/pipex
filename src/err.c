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

#include "libft.h"
#include "pipex.h"
#include <unistd.h>

void	die(char *err, char *sup, t_pipe *data, int status)
{
	if (err)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(sup, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		if (errno == 0)
			ft_putendl_fd(err, STDERR_FILENO);
		else
			perror("");
	}
	if (data)
	{
		free_pipe_data(data);
		exit(status);
	}
}
