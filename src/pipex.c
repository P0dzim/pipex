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
	if (argc < 5)
		return (1);
	fork_process(argc, argv);
	return (0);
}

char	*file1_and_cmd1(char **argv)
{
	char	*tab[5];

	tab[0] = "< ";
	tab[1] = argv[1];
	tab[2] = " ";
	tab[3] = argv[2];
	tab[4] = NULL;
	return(ft_reverse_split(tab, 0));
}

char	*file2_and_cmdend(int argc, char **argv)
{
	char	*tab[4];

	tab[0] = argv[argc - 2];
	tab[1] = " > ";
	tab[2] = argv[argc - 1];
	tab[3] = NULL;
	return(ft_reverse_split(tab, 0));
}

void	bash_args_init(char **bash_args, char *str)
{
	bash_args[0] = "/bin/bash";
	bash_args[1] = "-c";
	bash_args[2] = str;
	bash_args[3] = NULL;
}
