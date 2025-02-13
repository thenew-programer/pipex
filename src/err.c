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

char	*remove_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = 0;
		i++;
	}
	return (str);
}

void	die(char *err, char *sup, t_pipe *data, int status)
{
	if (err)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		if (errno == 0)
			ft_putstr_fd(err, STDERR_FILENO);
		else
			ft_putstr_fd(remove_endl(strerror(errno)), STDERR_FILENO);
	}
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(sup, STDERR_FILENO);
	if (data)
	{
		free_pipe_data(data);
		exit(status);
	}
}
