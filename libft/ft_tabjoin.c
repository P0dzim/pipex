/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:32:27 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/06 12:32:29 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **t1, char **t2)
{
	int		len[2];
	int		i;
	char	**ntab;

	i = 0;
	len[0] = ft_tablen(t1);
	len[1] = ft_tablen(t2);
	ntab = ft_calloc((size_t)(len[0] + len[1] + 1), sizeof(char *));
	if (!ntab)
		return (NULL);
	while (*t1)
	{
		ntab[i] = *t1;
		t1++;
		i++;
	}
	while (*t2)
	{
		ntab[i] = *t2;
		t2++;
		i++;
	}
	return (ntab);
}
