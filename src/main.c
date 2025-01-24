/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:48:03 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/18 21:32:24 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipe	*data;
	int		ret;

	if (ac < 5)
		die(USAGE_ERR, NULL, 1, TRUE);
	data = init_pipe();
	if (!data)
		die(MALLOC_ERR, data, 1, TRUE);
	set_path(data, env);
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		parser(ac - 2, &(av[2]), data);
		data->infile_fd = STDIN_FILENO;
		data->outfile_fd = open_file(data->outfile, data, O_APPEND);
		heredoc(data);
	}
	else
	{
		parser(ac - 1, &(av[1]), data);
		data->infile_fd = open_file(data->infile, data, O_RDONLY);
		data->outfile_fd = open_file(data->outfile, data, O_WRONLY);
	}
	path(data);
	ret = exec(data, env);
	free_pipe_data(data);
	return (ret);
}
