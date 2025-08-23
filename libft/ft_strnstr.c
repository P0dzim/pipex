/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 08:35:13 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/19 15:50:10 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_position;
	size_t	b_position;

	i = 0;
	l_position = 0;
	if (!big && !little)
		return ((char *)0);
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		b_position = i;
		while (b_position < len && big[b_position] == little[l_position])
		{
			l_position++;
			b_position++;
			if (little[l_position] == '\0')
				return ((char *)&big[i]);
		}
		l_position = 0;
		i++;
	}
	return ((char *)0);
}
