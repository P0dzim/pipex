/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:29:50 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/13 16:25:43 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	i;

	if (argc != 5)
		return (1);
	if (pipe(pipe_fd) == -1)
	{
		perror("");
		return (1);
	}
	i = fork_process(argv, envp, pipe_fd);
	return (i);
}
