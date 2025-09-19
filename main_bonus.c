/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 07:53:22 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/19 19:23:45 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	**fill_pipe_fd(int argc);
static void	alloc_error(int **pipe_fd, int i);
static void	pipe_error(int **pipe_fd, int i, int allocs);

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		**pipe_fd;
	t_env	env;

	if (argc < 5)
		return (1);
	env.heredoc = 0;
	if (!ft_strcmp(argv[1], "here_doc") && argc == 5)
		return (1);
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		argv++;
		argc--;
		env.heredoc = 1;
	}
	env.argc = argc;
	env.argv = argv;
	env.pipec = argc - 4;
	env.envp = envp;
	env.pipe_fd = fill_pipe_fd(argc);
	i = fork_process(env);
	return (i);
}

static int	**fill_pipe_fd(int argc)
{
	int	**pipe_fd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	pipe_fd = ft_calloc((size_t)(argc - 4), sizeof(int *));
	if (pipe_fd == NULL)
		exit(1);
	while (i < argc - 4)
	{
		pipe_fd[i] = ft_calloc(2, sizeof(int));
		if (!pipe_fd[i])
			alloc_error(pipe_fd, i);
		i++;
	}
	while (j < argc - 4)
	{
		if (pipe(pipe_fd[j]) == -1)
			pipe_error(pipe_fd, j, i);
		j++;
	}
	return (pipe_fd);
}

static void	alloc_error(int **pipe_fd, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(pipe_fd[j]);
		j++;
	}
	free(pipe_fd);
	exit(errno);
}

static void	pipe_error(int **pipe_fd, int i, int allocs)
{
	int	j;

	j = 0;
	while (j < i)
	{
		close_pipes(pipe_fd[j]);
		j++;
	}
	alloc_error(pipe_fd, allocs);
}
