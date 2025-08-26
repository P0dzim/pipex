/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_open_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:27:03 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/26 11:07:48 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file_exists(char *file, int *pipe_id)
{
	int	fd;

	if (access(file, F_OK) == -1)
	{
		dup2(1, 2);
		close(pipe_id[0]);
		close(pipe_id[1]);
		ft_printf("%s: No such file or directory\n", file);
		exit(1);
	}
	fd = open(file, O_RDONLY);
	return (fd);
}

char	*check_command_exist(char *bin, int *pipe_id)
{
	char	*str;

	str = ft_strjoin("/bin/", bin);
	if (access(str, F_OK) == -1)
	{
		dup2(1, 2);
		close(pipe_id[0]);
		close(pipe_id[1]);
		ft_printf("%s: command not found\n", bin);
		free(str);
		exit(1);
	}
	return (str);
}