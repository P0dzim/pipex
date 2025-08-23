/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:14:37 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/23 14:00:07 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_process(int argc, char **argv)
{
	int		i;
	int		pipe_id[2];
	int		all_right;
	char	*args[5];

	if (pipe(pipe_id) == -1)
	{
		perror(strerror(errno));
		return ;
	}
	all_right = fork();
	if (all_right == 0)
	{
		close(pipe_id[0]);
		dup2(pipe_id[1], STDOUT_FILENO);
		bash_args_init(args, file1_and_cmd1(argv));
		execve("/bin/bash", args, NULL);
	}
	else
	{
		close(pipe_id[1]);
		dup2(pipe_id[0], STDIN_FILENO);
		bash_args_init(args, file2_and_cmdend(argc, argv));
		execve("/bin/bash", args, NULL);
	}
}
