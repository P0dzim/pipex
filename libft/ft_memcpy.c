/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:19:21 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/19 15:15:51 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			position;
	unsigned char	*s_dest;
	unsigned char	*s_src;

	position = 0;
	if (!dest && !src)
		return ((void *)0);
	s_dest = (unsigned char *) dest;
	s_src = (unsigned char *) src;
	while (n > position)
	{
		s_dest[position] = s_src[position];
		position++;
	}
	return (dest);
}
