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

#include "pipex.h"

int	find_path(t_cmd *cmd, char *env)
{
	int		i;
	char	**strs;
	char	*tmp;
	char	*tmp1;

	// if (access(cmd->args[0], X_OK) == 0)
	// 	return (cmd->path = ft_strdup(cmd->args[0]), TRUE);
	strs = ft_split(env, ':');
	i = 0;
	tmp = NULL;
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
	return (TRUE);
}

int	path(t_pipe *data)
{
	t_cmd	*tmp;
	int		ret;

	if (!data->cmd)
		return (0);
	tmp = data->cmd;
	while (tmp)
	{
		ret = find_path(tmp, data->env);
		if (ret == FALSE)
			die(CMD_NOT_FOUND, data, 1);
		tmp = tmp->next;
	}
	return (1);
}

int	set_path(t_pipe *data, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			break ;
		i++;
	}
	data->env = (env[i] + 5);
	if (env[i])
		return (TRUE);
	return (FALSE);
}
