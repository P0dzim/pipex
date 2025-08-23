/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:21:24 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/19 15:46:24 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	position;

	dst_size = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	position = 0;
	if (size > 0)
	{
		while (dst[dst_size])
			dst_size++;
		if (size <= dst_size)
			return (src_size + size);
		while ((dst_size < (size - 1)) && src[position])
			dst[dst_size++] = src[position++];
		dst[dst_size] = '\0';
		if (dst_size < size)
			return (dst_size + src_size - position);
	}
	else
		return (src_size);
	return (dst_size);
}
