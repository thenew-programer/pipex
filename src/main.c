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

	ret = 0;
	if (ac < 4)
		die(USAGE_ERR, NULL, 1);
	data = init_pipe();
	set_path(data, env);
	if (!data)
		die(MALLOC_ERR, data, 1);
	parser(ac - 1, &(av[1]), data);
	data->infile_fd = open_file(data->infile, data, O_RDONLY);
	path(data);
	ret = exec(data, env);
	free_pipe_data(data);
	return (ret);
}
