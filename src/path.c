/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:23:09 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/18 21:31:14 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"
#include "libft.h"
#include "pipex.h"
#include <unistd.h>

int	find_path(t_pipe *data, t_cmd *cmd, char *env)
{
	int		i;
	char	**strs;
	char	*tmp;
	char	*tmp1;

	if (access(cmd->args[0], X_OK) == 0)
		return (cmd->path = ft_strdup(cmd->args[0]), TRUE);
	strs = ft_split(env, ':');
	i = 0;
	while (strs[i] && env)
	{
		tmp1 = ft_strjoin(strs[i++], "/");
		tmp = ft_strjoin(tmp1, cmd->args[0]);
		free(tmp1);
		if (access(tmp, X_OK) == 0)
			break ;
		errno = 0;
		free(tmp);
		tmp = NULL;
	}
	cmd->path = tmp;
	free_strs_split(strs);
	if (!tmp)
		return (FALSE);
	(void)data;
		// die(ft_strjoin(CMD_NOT_FOUND, cmd->args[0]), data, 127, TRUE);
	return (TRUE);
}

int	path(t_pipe *data)
{
	t_cmd	*tmp;
	int		ret;

	if (!data->cmd)
		return (FALSE);
	tmp = data->cmd;
	while (tmp)
	{
		if (access(tmp->args[0], X_OK) == 0)
		{
			tmp->path = ft_strdup(tmp->args[0]);
			tmp = tmp->next;
			continue ;
		}
		ret = find_path(data, tmp, data->env);
		if (ret == FALSE && tmp == data->cmd && data->infile_fd == STDIN_FILENO)
		{
			if (tmp->path)
				return (free(tmp->path), tmp->path = NULL, FALSE);
			return (FALSE);
		}
		else if (ret == FALSE)
			die(ft_strjoin(CMD_NOT_FOUND, tmp->args[0]), data, FALSE, FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	set_path(t_pipe *data, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	data->env = ft_strdup(".:");
	if (!env)
		return (FALSE);
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			break ;
		i++;
	}
	if (env[i])
	{
		tmp = data->env;
		data->env = ft_strjoin(data->env, env[i] + 5);
		free(tmp);
		return (TRUE);
	}
	return (FALSE);
}
