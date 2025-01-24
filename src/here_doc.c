/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:46:03 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/21 11:53:38 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*read_heredoc(char *limiter)
{
	char	*str;
	char	*line;
	char	*tmp;

	str = ft_strdup("");
	ft_putstr_fd("heredoc> ", 1);
	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (free(str), NULL);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0)
			return (free(line), *ft_strrchr(str, '\n') = 0, str);
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(STDIN_FILENO);
	}
	return (str);
}

void	heredoc(t_pipe *data)
{
	t_cmd	*cmd;
	char	*str;

	data->heredoc = TRUE;
	str = read_heredoc(data->infile);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		die(MALLOC_ERR, data, 1, TRUE);
	cmd->args = (char **)malloc(sizeof(char *) * 3);
	if (!cmd->args)
		die(MALLOC_ERR, data, 1, TRUE);
	cmd->args[0] = ft_strdup("echo");
	cmd->args[1] = str;
	cmd->args[2] = NULL;
	cmd->next = data->cmd;
	data->cmd = cmd;
}
