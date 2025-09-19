/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:26:00 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/18 07:56:19 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	beggin_process(char **argv, char **envp, int *pipe_fd);
static pid_t	end_process(char **argv, char **envp, int *pipe_fd);

int	fork_process(char **argv, char **envp, int *pipe_fd)
{
	pid_t	first_process;
	pid_t	final_process;
	int		i;

	i = 0;
	first_process = beggin_process(argv, envp, pipe_fd);
	final_process = end_process(argv, envp, pipe_fd);
	close_pipes(pipe_fd);
	if (first_process > 0)
		waitpid(first_process, NULL, 0);
	if (final_process < 0)
	{
		if (final_process == -1)
			i = FILE_ERROR;
		if (final_process == -2)
			i = COMMAND_NF;
	}
	else
		waitpid(final_process, &i, 0);
	lst_control(NULL);
	return (((i & 0xff00) >> 8));
}

static pid_t	beggin_process(char **argv, char **envp, int *pipe_fd)
{
	char	**args;
	int		fd_file;
	pid_t	fork_id;

	fd_file = check_input(argv[1]);
	if (fd_file == -1)
		return (-1);
	make_args(&args, argv[2], envp);
	if (!args)
		return (-2);
	fork_id = fork();
	if (fork_id == -1)
		perror("");
	else if (fork_id == 0)
	{
		close(pipe_fd[0]);
		exec_program(args, envp, fd_file, pipe_fd[1]);
	}
	close(fd_file);
	return (fork_id);
}

static pid_t	end_process(char **argv, char **envp, int *pipe_fd)
{
	char	**args;
	int		fd_file;
	pid_t	fork_id;

	fd_file = check_output(argv[4]);
	if (fd_file == -1)
		return (-1);
	make_args(&args, argv[3], envp);
	if (!args)
		return (-2);
	fork_id = fork();
	if (fork_id == -1)
		perror("");
	else if (fork_id == 0)
	{
		close(pipe_fd[1]);
		exec_program(args, envp, pipe_fd[0], fd_file);
	}
	close(fd_file);
	return (fork_id);
}
