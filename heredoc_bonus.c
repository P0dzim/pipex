/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:53:30 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/19 20:00:04 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_str(char *str, int	*heredoc_msg);

int	here_doc(t_env *env)
{
	int		pipe_fd[2];
	char	*str;
	int		fd;
	int		heredoc_msg;

	if (pipe(pipe_fd) == -1)
		return (-1);
	heredoc_msg = 1;
	while (1)
	{
		if (heredoc_msg)
			ft_putstr_fd("heredoc> ", 1);
		heredoc_msg = 0;
		str = get_next_line(0);
		if (str && !ft_strncmp(str, env->argv[1], ft_strlen(env->argv[1]))
			&& ft_strlen(env->argv[1]) + 1 == ft_strlen(str))
			break ;
		ft_putstr_fd(str, pipe_fd[1]);
		free_str(str, &heredoc_msg);
	}
	free_str(str, &heredoc_msg);
	fd = dup(pipe_fd[0]);
	close_pipes(pipe_fd);
	return (fd);
}

static void	free_str(char *str, int	*heredoc_msg)
{
	if (str)
	{
		free(str);
		*heredoc_msg = 1;
	}
}
