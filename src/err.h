/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:46:07 by ybouryal          #+#    #+#             */
/*   Updated: 2025/01/16 11:54:47 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# define OPEN_INFILE_ERR		"unable to create infile"
# define OPEN_OUTFILE_ERR		"unable to create outfile"
# define MALLOC_ERR				"malloc failed"
# define USAGE_ERR				"Usage: ./pipex infile cmd1 cmd2 outfile"
# define FILE_READ_ACCESS_ERR	"access: Unable to access file in read mode: "
# define FILE_WRITE_ACCESS_ERR	"access: Unable to access file in write mode: "
# define CMD_NOT_FOUND			"command not found: "
# define EMPTY_CMD				"empty string provided"
# define PIPE_ERR				"unable to create a pipe"

#endif /* ERR_H */
