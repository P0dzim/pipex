/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:34:12 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/13 17:41:47 by vitosant         ###   ########.fr       */
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
# include "libft/libft.h"

# define FILE_ERROR 256
# define COMAND_NOT 32512

typedef struct s_args_lst
{
	char				**args;
	struct s_args_lst	*next;
}						t_args_lst;

void	close_pipes(int	*pipe_id);
int		fork_process(char **argv, char **envp, int *pipe_fd);
int		file_error(char *file, int *pipe_fd);
int		check_input(char *file);
int		check_output(char *file);
void	make_args(char ***args, char *command, char **envp);
void	exec_program(char **args, char **env, int std_in, int std_out);
void	lst_control(char **args);

#endif