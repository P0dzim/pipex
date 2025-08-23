/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:03:52 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/19 15:17:03 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s_dest;
	unsigned char	*s_src;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return ((void *)0);
	s_dest = (unsigned char *) dest;
	s_src = (unsigned char *) src;
	if (s_src > s_dest)
	{
		while (i < n)
		{
			s_dest[i] = s_src[i];
			i++;
		}
	}
	else
	{
		while (n--)
			s_dest[n] = s_src[n];
	}
	return (dest);
}
