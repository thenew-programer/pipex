/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:56:11 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/16 11:59:35 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs_split(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_pipe_data(t_pipe *data)
{
	if (!data)
		return ;
	if (data->cmd)
		free_cmdlst(&data->cmd);
	if (data->infile)
		free(data->infile);
	if (data->outfile)
		free(data->outfile);
	if (data->infile_fd > 2)
		close_file(&data->infile_fd, -1);
	if (data->outfile_fd > 2)
		close_file(&data->outfile_fd, -1);
	if (data->pipefd[R_END] > 2)
		close_file(&data->pipefd[R_END], -1);
	if (data->pipefd[W_END] > 2)
		close_file(&data->pipefd[W_END], -1);
	free(data);
}
