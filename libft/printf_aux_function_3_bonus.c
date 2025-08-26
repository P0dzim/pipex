/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_function_3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:13:15 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:38:08 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	make_hex_str(char *str, char *hex, t_ull nbr)
{
	int	i;

	i = 0;
	if (nbr < 16)
	{
		str[0] = hex[nbr % 16];
		return ;
	}
	while (nbr > 0)
	{
		str[i] = hex[nbr % 16];
		i++;
		nbr = nbr / 16;
	}
	reverse_str(str);
}
