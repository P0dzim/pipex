/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pointer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:18:26 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/11 11:11:58 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	b_pointer(t_sentinel *sentinel, t_flags flags, va_list args)
{
	char	*hex_dig;
	char	*str;
	t_ull	nbr;

	nbr = va_arg(args, t_ull);
	hex_dig = "0123456789abcdef";
	str = (char *) ft_calloc((ADDR_LEN + 1), 1);
	if (nbr)
		make_hex_str(str, hex_dig, nbr);
	else
		(void) ft_strlcpy(str, "(nil)", (ADDR_LEN + 1));
	if (nbr && flags.precision)
		str = b_iud_make_zero_str(str, flags.precision);
	if (nbr)
		str = address_prefix('x', str);
	if (flags.width)
		b_iud_make_width_str(flags, str, sentinel);
	else
		new_node(str, sentinel, flags.spec);
}

void	b_point_minusstr(char *str, char *width)
{
	size_t	i;

	i = 0;
	if (ssize_t_atoi(str) >= 0 || !width || *width == '\0'
		|| *width != '0')
		return ;
	while (str[i])
	{
		if (str[i] == '-')
			str[i] = '0';
		i++;
	}
	width[0] = '-';
}

void	b_pointer_nothing(t_flags flags, t_sentinel *sentinel)
{
	char	str[3];

	str[0] = '%';
	str[1] = flags.spec;
	str[2] = '\0';
	new_node(ft_strdup(str), sentinel, flags.spec);
}
