/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:43:26 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/15 07:38:20 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	position;
	char	*str;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	position = 0;
	str = (char *) ft_calloc((size_s1 + size_s2 + 1), 1);
	if (str != (char *)0)
	{
		while (*s1)
		{
			str[position] = *s1;
			position++;
			s1++;
		}
		while (*s2)
		{
			str[position] = *s2;
			position++;
			s2++;
		}
	}
	return (str);
}
