/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:51:53 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/19 19:56:37 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_input(char *file)
{
	int	fd;

	if (access(file, F_OK) == -1)
	{
		perror(file);
		return (-1);
	}
	else if (access(file, R_OK) == -1)
	{
		perror(file);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("open");
	return (fd);
}

int	check_output(t_env *env)
{
	int		fd;
	char	*file;

	if (env->heredoc)
		file = env->argv[env->argc - 1];
	else
		file = env->argv[env->argc - 1];
	if (access(file, F_OK) == 0 && access(file, W_OK) == -1)
	{
		perror(file);
		return (-1);
	}
	if (env->heredoc)
		fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0664);
	else
		fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd == -1)
		perror("open");
	return (fd);
}
