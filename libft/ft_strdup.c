/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 08:08:24 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/21 07:09:05 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*newstr;
	size_t	index;
	size_t	index_dup;

	index = 0;
	index_dup = 0;
	newstr = (char *)0;
	while (src[index])
		index++;
	newstr = (char *) ft_calloc((index + 1), 1);
	while (index_dup < index && newstr != (char *)0)
	{
		newstr[index_dup] = src[index_dup];
		index_dup++;
	}
	return (newstr);
}
