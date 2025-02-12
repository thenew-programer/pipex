/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:27:44 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/26 11:07:43 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_pipe *data, t_cmd *cmd, char **env);

int	exec(t_pipe *data, char **env)
{
	t_cmd	*cmd;
	int		status;
	int		i;

	duptwo(data, data->infile_fd, STDIN_FILENO);
	duptwo(data, data->outfile_fd, STDOUT_FILENO);
	close_file(&data->infile_fd, STDIN_FILENO);
	close_file(&data->outfile_fd, STDOUT_FILENO);
	if (pipe(data->pipefd) == -1)
		die("", "", data, 1);
	cmd = data->cmd;
	cmd->ctx.fd[STDOUT_FILENO] = data->pipefd[STDOUT_FILENO];
	cmd->ctx.fd_close = data->pipefd[STDIN_FILENO];
	exec_cmd(data, cmd, env);
	close_file(&data->pipefd[STDOUT_FILENO], STDOUT_FILENO);
	cmd = cmd->next;
	cmd->ctx.fd[STDIN_FILENO] = data->pipefd[STDIN_FILENO];
	cmd->ctx.fd_close = data->pipefd[STDOUT_FILENO];
	exec_cmd(data, cmd, env);
	i = 0;
	while (i++ < 2)
		wait(&status);
	close(data->pipefd[STDIN_FILENO]);
	close(data->pipefd[STDOUT_FILENO]);
	return (WEXITSTATUS(status));
}

static void	exec_cmd(t_pipe *data, t_cmd *cmd, char **env)
{
	int	pid;

	if (!cmd->path)
		return ;
	pid = fork();
	if (pid == -1)
		die("", "", data, 1);
	if (pid == 0)
	{
		close_file(&cmd->ctx.fd_close, -1);
		duptwo(data, cmd->ctx.fd[STDIN_FILENO], STDIN_FILENO);
		duptwo(data, cmd->ctx.fd[STDOUT_FILENO], STDOUT_FILENO);
		if (execve(cmd->path, cmd->args, env) == -1)
			die("", "", data, TRUE);
	}
}
