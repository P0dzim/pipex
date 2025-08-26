/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:13:26 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:37:38 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	u_memsize(long num);

char	*ft_uitoa(unsigned int n)
{
	long	num;
	char	*str;
	size_t	i[2];

	num = (long) n;
	i[0] = 0;
	i[1] = u_memsize(num);
	str = (char *) ft_calloc ((i[1] + 1), 1);
	if (!str)
		return ((char *)0);
	while (i[1] > i[0])
	{
		str[i[0]] = (num % 10) + '0';
		num = num / 10;
		i[0] = i[0] + 1;
	}
	reverse_str(str);
	return (str);
}

static size_t	u_memsize(long num)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = num * -1;
		i++;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}
