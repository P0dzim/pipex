/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:29:22 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/19 16:12:32 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_program(char **args, char **env, int std_in, int std_out)
{
	if (dup2(std_in, STDIN_FILENO) == -1)
		perror("");
	if (dup2(std_out, STDOUT_FILENO) == -1)
		perror("");
	if (close(std_in) == -1)
		perror("");
	if (close(std_out) == -1)
		perror("");
	execve(args[0], args, env);
	perror("");
	exit(errno);
}
