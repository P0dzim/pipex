/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:26:00 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/19 20:28:07 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static pid_t	beggin_process(t_env *env);
static pid_t	end_process(t_env *env);
static void		middle_process(t_env *env, pid_t *last_process);
static void		ft_free_pipe(t_env env);

int	fork_process(t_env env)
{
	pid_t	last_process;
	pid_t	final_process;
	int		i;

	i = 0;
	last_process = beggin_process(&env);
	middle_process(&env, &last_process);
	final_process = end_process(&env);
	if (last_process > 0)
		waitpid(last_process, NULL, 0);
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
	ft_free_pipe(env);
	return (((i & 0xff00) >> 8));
}

static pid_t	beggin_process(t_env *env)
{
	char	**args;
	int		fd_file;
	pid_t	fork_id;

	if (env->heredoc)
		fd_file = here_doc(env);
	else
		fd_file = check_input(env->argv[1]);
	if (fd_file == -1)
		return (-1);
	make_args(&args, env->argv[2], env->envp);
	if (!args)
		return (-2);
	fork_id = fork();
	if (fork_id == -1)
		perror("");
	else if (fork_id == 0)
	{
		close(env->pipe_fd[0][0]);
		exec_program(args, env->envp, fd_file, env->pipe_fd[0][1]);
	}
	close(fd_file);
	return (fork_id);
}

static pid_t	end_process(t_env *env)
{
	char	**args;
	int		file;
	pid_t	fork_id;

	file = check_output(env);
	if (file == -1)
		return (-1);
	if (env->heredoc)
		make_args(&args, env->argv[env->argc - 2], env->envp);
	else
		make_args(&args, env->argv[env->argc - 2], env->envp);
	if (!args)
		return (-2);
	fork_id = fork();
	if (fork_id == -1)
		perror("");
	else if (fork_id == 0)
	{
		close(env->pipe_fd[env->pipec - 1][1]);
		exec_program(args, env->envp, env->pipe_fd[env->pipec - 1][0], file);
	}
	close_pipes(env->pipe_fd[env->pipec - 1]);
	close(file);
	return (fork_id);
}

static void	middle_process(t_env *env, pid_t *last_process)
{
	int		index_fd;
	pid_t	fork_pid;
	char	**args;

	index_fd = 1;
	fork_pid = 0;
	while (index_fd < env->pipec)
	{
		make_args(&args, env->argv[2 + index_fd], env->envp);
		if (args)
			fork_pid = fork();
		if (args && fork_pid == 0)
		{
			close(env->pipe_fd[index_fd - 1][1]);
			exec_program(args, env->envp, env->pipe_fd[index_fd - 1][0],
				env->pipe_fd[index_fd][1]);
		}
		close_pipes(env->pipe_fd[index_fd - 1]);
		index_fd++;
		wait(NULL);
	}
	if (index_fd - 1)
		*last_process = fork_pid;
}

static void	ft_free_pipe(t_env env)
{
	int	i;

	i = 0;
	while (env.pipec > i)
	{
		free(env.pipe_fd[i]);
		i++;
	}
	free(env.pipe_fd);
	env.pipe_fd = NULL;
}
