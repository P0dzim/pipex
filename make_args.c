/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:09:10 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/19 20:34:33 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_bin(char *command, char **envp);
static char	**put_endbar(char **envp);

void	make_args(char ***args, char *command, char **envp)
{
	char	*temp;

	*args = ft_split(command, ' ');
	if (!*args)
		return ;
	if (*args[0])
		temp = search_bin(*args[0], envp);
	if (!*args || !*args[0] || !temp)
	{
		ft_free_table(args);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found\n", 2);
		return ;
	}
	free(args[0][0]);
	args[0][0] = temp;
	lst_control(*args);
}

static char	*search_bin(char *command, char **envp)
{
	char		*bin;
	static char	**paths;
	int			i;

	i = 1;
	if (!paths)
		paths = put_endbar(envp);
	if (ft_strchr(command, '/') && access(command, F_OK) == 0)
		return (ft_strdup(command));
	while (paths && paths[i])
	{
		bin = ft_strjoin(paths[i], command);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		i++;
	}
	return (NULL);
}

static char	**put_endbar(char **envp)
{
	int		i;
	int		j;
	char	*temp;
	char	**paths;

	i = 0;
	j = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	envp[i][4] = ':';
	paths = ft_split(envp[i], ':');
	if (!paths)
		return (NULL);
	while (paths[j])
	{
		temp = ft_strjoin(paths[j], "/");
		free(paths[j]);
		paths[j] = temp;
		j++;
	}
	envp[i][4] = '=';
	lst_control(paths);
	return (paths);
}
