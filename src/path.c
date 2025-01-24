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

#include "libft.h"
#include "pipex.h"

int	find_path(t_cmd *cmd, char *env)
{
	int		i;
	char	**strs;
	char	*tmp;
	char	*tmp1;

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
		if (find_path(tmp, data->env) == FALSE)
			die(CMD_NOT_FOUND, data, 0, TRUE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	set_path(t_pipe *data, char **env)
{
	int		i;

	i = 0;
	if (!env)
		return (data->env = ft_strdup("."), FALSE);
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			break ;
		i++;
	}
	if (env[i])
	{
		data->env = ft_strdup(env[i] + 5);
		return (TRUE);
	}
	data->env = ft_strdup(".");
	return (FALSE);
}
