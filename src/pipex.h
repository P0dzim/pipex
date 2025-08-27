/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:44:59 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/27 11:32:34 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	fork_process(int argc, char **argv, int *pipe_id);

int		check_file_exists(char *file, int *pipe_id);
char	*check_command_exist(char *bin, int *pipe_id);

void	close_pipe(int *pipe_fd);

void	exec_program(int std_in, int std_out, char **param);

void	write_error(int return_pid);

#endif