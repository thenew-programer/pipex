/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:50:37 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/16 11:55:25 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"
#include "pipex.h"

t_cmd	*parse_cmd(char *command, t_pipe *data)
{
	char	**strs;
	t_cmd	*cmd;
	int		len;

	cmd = cmd_new();
	if (!cmd)
		die(MALLOC_ERR, data, 1);
	strs = ft_split(command, ' ');
	len = ft_split_len(strs);
	if (len <= 0)
		return (free_strs_split(strs), free_cmd(cmd), NULL);
	cmd->args = strs;
	return (cmd);
}

void	parser(int ac, char **av, t_pipe *data)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	int		i;

	cmd = NULL;
	data->infile = ft_strdup(av[0]);
	data->outfile = ft_strdup(av[ac - 1]);
	i = 1;
	while (i < ac - 1)
	{
		tmp = parse_cmd(av[i], data);
		if (!tmp)
		{
			free_cmdlst(&cmd);
			die(EMPTY_CMD, data, 1);
		}
		cmd_addback(&cmd, tmp);
		i++;
	}
	data->cmd = cmd;
}
