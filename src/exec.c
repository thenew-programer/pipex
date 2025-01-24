/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:27:44 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/18 22:28:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	exec_cmd(t_pipe *data, t_cmd *cmd, char **env);

int	exec(t_pipe *data, char **env)
{
	t_cmd	*cmd;
	int		status;
	int		i;

	cmd = data->cmd;
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
		die("", data, 1, TRUE);
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
		die("", data, 1, TRUE);
	close_file(&data->infile_fd, -1);
	close_file(&data->outfile_fd, -1);
	i = 0;
	while (cmd)
	{
		if (pipe(data->pipefd) == -1)
			die("", data, 1, TRUE);
		cmd->ctx.fd[STDOUT_FILENO] = data->pipefd[STDOUT_FILENO];
		exec_cmd(data, cmd, env);
		close_file(&data->pipefd[STDOUT_FILENO], -1);
		if (dup2(data->pipefd[STDIN_FILENO], STDIN_FILENO) == -1)
			die("", data, 1, TRUE);
		close_file(&data->pipefd[STDIN_FILENO], -1);
		cmd = cmd->next;
		i++;
	}
	while (i-- > 0)
		wait(&status);
	return (WEXITSTATUS(status));
}

static int	exec_cmd(t_pipe *data, t_cmd *cmd, char **env)
{
	pid_t	pid;

	if (!cmd)
		return (FALSE);
	pid = fork();
	if (pid == -1)
		die("", data, 1, TRUE);
	if (pid == 0)
	{
		close_file(&data->pipefd[STDIN_FILENO], -1);
		if (!cmd->next)
			close_file(&cmd->ctx.fd[STDOUT_FILENO], STDOUT_FILENO);
		if (dup2(cmd->ctx.fd[STDOUT_FILENO], STDOUT_FILENO) == -1)
			die("", NULL, 1, TRUE);
		close_file(&data->pipefd[STDOUT_FILENO], -1);
		execve(cmd->path, cmd->args, env);
	}
	return (TRUE);
}
