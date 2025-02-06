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
#include <unistd.h>

static int	exec_cmd(t_pipe *data, t_cmd *cmd, char **env);

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
	i = -1;
	while (++i < 2)
		wait(&status);
	return (WEXITSTATUS(status));
}

static int	exec_cmd(t_pipe *data, t_cmd *cmd, char **env)
{
	int	pid;

	if (!cmd)
		return (FALSE);
	if (!cmd->path)
		return (127);
	pid = fork();
	if (pid == -1)
		die("", "", data, 1);
	if (pid == 0)
	{
		duptwo(data, cmd->ctx.fd[STDIN_FILENO], STDIN_FILENO);
		duptwo(data, cmd->ctx.fd[STDOUT_FILENO], STDOUT_FILENO);
		close_file(&cmd->ctx.fd_close, -1);
		if (execve(cmd->path, cmd->args, env) == -1)
			die("", "", data, 1);
	}
	return (TRUE);
}

// int	exec(t_pipe *data, char **env)
// {
// 	t_cmd	*cmd;
// 	int		status;
// 	int		i;
//
// 	cmd = data->cmd;
// 	duptwo(data, data->infile_fd, STDIN_FILENO);
// 	close_file(&data->infile_fd, -1);
// 	i = 0;
// 	while (cmd)
// 	{
// 		if (pipe(data->pipefd) == -1)
// 			die("", data, 1, TRUE);
// 		cmd->ctx.fd[STDOUT_FILENO] = data->pipefd[STDOUT_FILENO];
// 		find_path(data, cmd, data->env);
// 		exec_cmd(data, cmd, env);
// 		close_file(&data->pipefd[STDOUT_FILENO], -1);
// 		duptwo(data, data->pipefd[STDIN_FILENO], STDIN_FILENO);
// 		close_file(&data->pipefd[STDIN_FILENO], -1);
// 		cmd = cmd->next;
// 		i++;
// 	}
// 	while (i-- > 0)
// 		wait(&status);
// 	return (WEXITSTATUS(status));
// }
//
// static int	exec_cmd(t_pipe *data, t_cmd *cmd, char **env)
// {
// 	pid_t	pid;
// 	int		flag;
// 	int		fd;
//
// 	flag = O_WRONLY;
// 	pid = fork();
// 	if (pid == -1)
// 		die("", data, 1, TRUE);
// 	if (pid == 0)
// 	{
// 		close_file(&data->pipefd[STDIN_FILENO], -1);
// 		if (!cmd->next)
// 		{
// 			if (data->heredoc)
// 				flag = O_APPEND;
// 			fd = open_file(data->outfile, data, flag);
// 			close_file(&cmd->ctx.fd[STDOUT_FILENO], fd);
// 		}
// 		duptwo(data, cmd->ctx.fd[STDOUT_FILENO], STDOUT_FILENO);
// 		close_file(&data->pipefd[STDOUT_FILENO], -1);
// 		close_file(&fd, -1);
// 		execve(cmd->path, cmd->args, env);
// 	}
// 	return (TRUE);
// }
