/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_atoi_sign_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:16:39 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:38:03 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	atoi_sign(const char *nptr);

int	b_atoi(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flags->minus = -1;
		if (str[i] == '+')
			flags->plus = 1;
		i++;
	}
	return (atoi_sign(str));
}

int	atoi_sign(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
