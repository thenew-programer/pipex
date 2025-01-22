/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:34:21 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/16 11:44:58 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->path = NULL;
	cmd->ctx.fd[STDIN_FILENO] = STDIN_FILENO;
	cmd->ctx.fd[STDOUT_FILENO] = STDOUT_FILENO;
	cmd->ctx.fd_close = -1;
	cmd->next = NULL;
	return (cmd);
}

void	cmd_addback(t_cmd **head, t_cmd *cmd)
{
	t_cmd	*last;

	if (!*head)
		*head = cmd;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		if (last)
			last->next = cmd;
	}
}

void	free_cmdlst(t_cmd **head)
{
	t_cmd	*cur;
	t_cmd	*tmp;

	cur = *head;
	while (cur)
	{
		tmp = cur->next;
		free_cmd(cur);
		cur = tmp;
	}
	*head = NULL;
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->args)
			free_strs_split(cmd->args);
		if (cmd->path)
			free(cmd->path);
		free(cmd);
	}
}
