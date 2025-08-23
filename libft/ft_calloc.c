/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:53:55 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/19 08:14:30 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	big_size_t;
	void	*mem_adress;

	ft_memset(&big_size_t, 255, sizeof(size_t));
	if (nmemb <= 0 || size <= 0)
		return (malloc(1));
	if (big_size_t / nmemb >= size)
	{
		mem_adress = malloc(nmemb * size);
		if (mem_adress)
		{
			ft_bzero(mem_adress, (nmemb * size));
			return (mem_adress);
		}
	}
	return ((void *)0);
}
