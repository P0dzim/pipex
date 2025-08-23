/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:12:40 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/18 11:14:28 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_str(char *sub_str, size_t size, size_t start, char const *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	size;

	size = ft_strlen(s);
	sub_str = (char *)0;
	if (size < (size_t)start || (size_t)start > size)
	{
		sub_str = (char *)ft_calloc(1, 1);
		if (sub_str != (char *)0)
			return (sub_str);
		return ((char *)0);
	}
	if (len >= size)
	{
		sub_str = (char *) ft_calloc(((size + 1) - (size_t)start), 1);
		fill_str(sub_str, (size - (size_t)start), start, s);
	}
	else
	{
		sub_str = (char *) ft_calloc((len + 1), 1);
		fill_str(sub_str, len, (size_t)start, s);
	}
	return (sub_str);
}

static void	fill_str(char *sub_str, size_t size, size_t start, char const *s)
{
	size_t	i;

	i = 0;
	if (sub_str)
	{
		while ((i < size) && s[i + start])
		{
			sub_str[i] = s[i + start];
			i++;
		}
	}
}
