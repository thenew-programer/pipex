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
#include <stdlib.h>
#include <unistd.h>

static int	exec_cmd(t_pipe *data, t_cmd *cmd, char **env, int *status);

int	exec(t_pipe *data, char **env)
{
	t_cmd	*cmd;
	int		status;
	int		i;

	cmd = data->cmd;
	data->outfile_fd = open_file(data->outfile, data, O_WRONLY);
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
		die("", data, 1);
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
		die("", data, 1);
	close_file(&data->infile_fd, -1);
	close_file(&data->outfile_fd, -1);
	i = 0;
	while (cmd)
	{
		if (pipe(data->pipefd) == -1)
			die("", data, 1);
		cmd->ctx.fd[STDOUT_FILENO] = data->pipefd[STDOUT_FILENO];
		exec_cmd(data, cmd, env, &status);
		close_file(&data->pipefd[STDOUT_FILENO], -1);
		if (dup2(data->pipefd[STDIN_FILENO], STDIN_FILENO) == -1)
			die("", data, 1);
		close_file(&data->pipefd[STDIN_FILENO], -1);
		cmd = cmd->next;
		i++;
	}
	while (i-- > 0)
		wait(&status);
	return (WEXITSTATUS(status));
}

static int	exec_cmd(t_pipe *data, t_cmd *cmd, char **env, int *status)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		die("", data, *status);
	if (pid == 0 && cmd)
	{
		close_file(&data->pipefd[STDIN_FILENO], -1);
		if (!cmd->next)
			close_file(&cmd->ctx.fd[STDOUT_FILENO], STDOUT_FILENO);
		if (dup2(cmd->ctx.fd[STDOUT_FILENO], STDOUT_FILENO) == -1)
			die("", NULL, *status);
		close_file(&data->pipefd[STDOUT_FILENO], -1);
		execve(cmd->path, cmd->args, env);
	}
	// else
	// {
	// 	waitpid(pid, status, 0);
	// 	if (WIFEXITED(*status) && WEXITSTATUS(*status) != 0)
	// 		die(NULL, data, WEXITSTATUS(*status));
	// 	*status = WEXITSTATUS(*status);
	// }
	return (*status);
}
