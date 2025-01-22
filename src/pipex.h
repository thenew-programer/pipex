/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:33:08 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/18 21:28:53 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "err.h"
# include "libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>

# define FALSE 0
# define TRUE 1
# define R_END 0
# define W_END 1

typedef struct s_ctx
{
	int	fd[2];
	int	fd_close;
}	t_ctx;

typedef struct s_cmd
{
	char			**args;
	char			*path;
	t_ctx			ctx;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipe
{
	char	*infile;
	int		infile_fd;
	char	*outfile;
	int		outfile_fd;
	int		pipefd[2];
	int		oldfd;
	t_cmd	*cmd;
	char	*env;
}	t_pipe;

/*---------------------------------err.c--------------------------------------*/
void	die(char *err, t_pipe *data, int status);

/*------------------------------dealloc.c-------------------------------------*/
void	free_strs_split(char **strs);
void	free_pipe_data(t_pipe *data);

/*-------------------------------utils.c--------------------------------------*/
int		ft_split_len(char **strs);
char	*ft_strs_cat(char **strs, int len);

/*--------------------------------init.c--------------------------------------*/
t_pipe	*init_pipe(void);

/*----------------------------------io.c--------------------------------------*/
int		open_file(char *filename, t_pipe *data, int flags);
int		close_file(int *fd, int dflt);
int		create_pipe(t_pipe *data);

/*---------------------------------cmd.c--------------------------------------*/
t_cmd	*cmd_new(void);
void	cmd_addback(t_cmd **head, t_cmd *cmd);
void	free_cmdlst(t_cmd **head);
void	free_cmd(t_cmd *cmd);

/*-------------------------------parser.c-------------------------------------*/
t_cmd	*parse_cmd(char *cmd, t_pipe *data);
void	parser(int ac, char **av, t_pipe *data);

/*--------------------------------path.c--------------------------------------*/
int		path(t_pipe *data);
int		set_path(t_pipe *data, char **env);

/*--------------------------------exec.c--------------------------------------*/
int		exec(t_pipe *data, char **env);

#endif /* PIPEX_H */
