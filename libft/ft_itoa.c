/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:39:15 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/19 07:59:06 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		reverse(char *str);
static size_t	memsize(long num);

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	size_t	i[2];

	num = (long) n;
	i[0] = 0;
	i[1] = memsize(num);
	str = (char *) ft_calloc ((i[1] + 1), 1);
	if (str)
	{
		if (num < 0)
		{
			num = num * -1;
			str[0] = '-';
			i[0] = i[0] + 1;
		}
		while (i[1] > i[0])
		{
			str[i[0]] = (num % 10) + '0';
			num = num / 10;
			i[0] = i[0] + 1;
		}
		reverse(str);
	}
	return (str);
}

static size_t	memsize(long num)
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

static void	reverse(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[0] == '-')
		i++;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
