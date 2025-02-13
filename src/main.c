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

	if (ac != 5)
		return (die(USAGE_ERR, "", NULL, TRUE), 0);
	data = init_pipe();
	if (!data)
		die(MALLOC_ERR, "", data, TRUE);
	set_path(data, env);
	parser(ac - 1, av + 1, data);
	data->infile_fd = open_file(data, data->infile, O_RDONLY);
	data->outfile_fd = open_file(data, data->outfile, O_WRONLY);
	path(data);
	ret = exec(data, env);
	free_pipe_data(data);
	return (ret);
}
