/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:14:37 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/26 11:45:09 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	child_process(char **argv, int i, int *pipe_id);
static char	**construct_args(char *argv, int *pipe_id);

void	fork_process(int argc, char **argv, char **envp, int *pipe_id)
{
	int		process_ret;
	int		i;

	process_ret = child_process(argv, 2, pipe_id);
	printf("%i", process_ret);
}

static int	child_process(char **argv, int i, int *pipe_id)
{
	int		fd_file;
	char	**bin;
	int		j;
	pid_t	fork_id;

	if (i == 1)
		printf("bonus here\n");
	fd_file = check_file_exists(argv[0], pipe_id);
	bin = construct_args(argv[1], pipe_id);
	fork_id = fork();
	if (fork_id == 0)
	{
		close(pipe_id[0]);
		dup2(pipe_id[1], STDOUT_FILENO);
		dup2(fd_file, STDIN_FILENO);
		execve(bin[0], bin, NULL);
		write(2, "evecve error", 12);
	}
	waitpid(fork_id, &j, 0);
	return (j);
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