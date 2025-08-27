/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_open_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:27:03 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/27 11:15:45 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file_exists(char *file, int *pipe_id)
{
	int	fd;

	if (access(file, F_OK) == -1)
	{
		close_pipe(pipe_id);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close_pipe(pipe_id);
		perror(strerror(errno));
		exit(1);
	}
	return (fd);
}

char	*check_command_exist(char *bin, int *pipe_id)
{
	char	*str;

	str = ft_strjoin("/bin/", bin);
	if (access(str, F_OK) == -1)
	{
		close_pipe(pipe_id);
		ft_putstr_fd(bin, 2);
		ft_putstr_fd(": command not found\n", 2);
		free(str);
		exit(127);
	}
	return (str);
}
