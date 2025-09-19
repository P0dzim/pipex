/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 07:54:39 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/19 18:45:17 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

# define FILE_ERROR 256
# define COMMAND_NF 32512

typedef struct s_args_lst
{
	char				**args;
	struct s_args_lst	*next;
}						t_args_lst;

typedef struct s_env
{
	int		argc;
	int		pipec;
	int		heredoc;
	int		**pipe_fd;
	char	**argv;
	char	**envp;
}			t_env;

void	close_pipes(int	*pipe_id);
int		fork_process(t_env env);
int		file_error(char *file, int *pipe_fd);
int		check_input(char *file);
int		check_output(t_env *env);
void	make_args(char ***args, char *command, char **envp);
void	exec_program(char **args, char **env, int std_in, int std_out);
void	lst_control(char **args);
int		here_doc(t_env *env);

#endif