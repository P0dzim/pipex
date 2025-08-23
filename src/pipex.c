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

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

static char	*file1_and_cmd1(char **argv);
static char	*file2_and_cmdend(int argc, char **argv);
static void	bash_args_init(char **bash_args, char *str);

int	main(int argc, char **argv)
{
	char	*bash_args[4];
	char 	*temp;
	int		pipeid[2];

	if (argc < 5)
		return (1);
	pipe(pipeid);
	bash_args_init(bash_args, file1_and_cmd1(argv));
	return (0);
}

static	char *file1_and_cmd1(char **argv)
{
	char *tab[5];

	tab[0] = "< ";
	tab[1] = argv[1];
	tab[2] = " ";
	tab[3] = argv[2];
	tab[4] = NULL;
	return(ft_reverse_split(tab, 0));
}

static	char *file2_and_cmdend(int argc, char **argv)
{
	char *tab[4];

	tab[0] = argv[argc - 2];
	tab[1] = " > ";
	tab[2] = argv[argc - 1];
	tab[3] = NULL;
	return(ft_reverse_split(tab, 0));
}

static void	bash_args_init(char **bash_args, char *str)
{
	bash_args[0] = "/bin/bash";
	bash_args[1] = "-c";
	bash_args[2] = str;
	bash_args[3] = NULL;
}
