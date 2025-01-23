/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:22:37 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/18 21:28:33 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

t_pipe	*init_pipe(void)
{
	t_pipe	*data;

	data = (t_pipe *)malloc(sizeof(t_pipe));
	if (!data)
		return (NULL);
	data->outfile = NULL;
	data->cmd = NULL;
	data->env = NULL;
	data->infile = NULL;
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->pipefd[STDIN_FILENO] = -1;
	data->pipefd[STDOUT_FILENO] = -1;
	data->heredoc = FALSE;
	return (data);
}
