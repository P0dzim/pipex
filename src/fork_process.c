/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:14:37 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/27 12:23:17 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	beggin_process(char **argv, int *pipe_id);
static int	end_process(char **argv, int *pipe_id);
static char	**construct_args(char *argv, int *pipe_id);

void	fork_process(int argc, char **argv, int *pipe_id)
{
	int		process_ret;
	int		i;

	process_ret = beggin_process(argv, pipe_id);
	i = end_process(argv, pipe_id);
	printf("%i", process_ret);
	printf("\n%i\n", i);
}

static int	beggin_process(char **argv, int *pipe_id)
{
	int		input_file;
	char	**bin;
	int		i;
	pid_t	fork_id;

	input_file = check_file_exists(argv[0], pipe_id);
	bin = construct_args(argv[1], pipe_id);
	fork_id = fork();
	if (fork_id == 0)
	{
		close(pipe_id[0]);
		exec_program(input_file, pipe_id[1], bin);
		perror(strerror(errno));
		exit(1);
	}
	ft_free_table(&bin);
	close(input_file);
	waitpid(fork_id, &i, 0);
	return (i);
}

static int	end_process(char **argv, int *pipe_id)
{
	int		file_desc[2];
	char	**bin;
	int		return_pid;
	pid_t	fork_pid;

	file_desc[0] = open(argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file_desc[0] == -1)
		exit(1);
	file_desc[1] = dup(pipe_id[0]);
	bin = construct_args(argv[2], pipe_id);
	fork_pid = fork();
	close_pipe(pipe_id);
	if (fork_pid == 0)
	{
		exec_program(file_desc[1], file_desc[0], bin);
		exit(1);
	}
	ft_free_table(&bin);
	waitpid(fork_pid, &return_pid, 0);
	close(file_desc[0]);
	return (return_pid);
}

static char	**construct_args(char *argv, int *pipe_id)
{
	char	**args;
	char	*temp;

	args = ft_split(argv, ' ');
	temp = check_command_exist(args[0], pipe_id);
	free(args[0]);
	args[0] = temp;
	return (args);
}
