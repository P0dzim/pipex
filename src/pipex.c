/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: asa/08/22 10:35:56 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/22 14:22:47 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		pipe_id[2];
	int		i;
	pid_t	fork_id;

	if (argc != 5)
		return (1);
	if (pipe(pipe_id) == -1)
	{
		perror("pipe error");
		return (1);
	}
	argv++;
	fork_process(argc, argv, pipe_id);
	return (0);
}
