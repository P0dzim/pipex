/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hex_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:02:34 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 20:39:51 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	b_hex_node(t_sentinel *sentinel, t_flags flags, va_list args)
{
	char	*hex_dig;
	char	*str;
	t_ull	nbr;

	nbr = (t_ull) va_arg(args, unsigned int);
	if (flags.spec == 'X')
		hex_dig = "0123456789ABCDEF";
	else
		hex_dig = "0123456789abcdef";
	str = (char *) ft_calloc(HEX_LEN, 1);
	make_hex_str(str, hex_dig, nbr);
	if (!nbr && !flags.precision && flags.dot)
		str[0] = '\0';
	if (flags.zero && flags.dot)
		flags.space = 1;
	if (flags.zero && flags.dot)
		flags.zero = 0;
	if (flags.precision)
		str = b_iud_make_zero_str(str, flags.precision);
	if (flags.hashtag && nbr)
		str = address_prefix(flags.spec, str);
	if (flags.width)
		b_iud_make_width_str(flags, str, sentinel);
	else
		new_node(str, sentinel, flags.spec);
}

char	*address_prefix(char spec, char *str)
{
	char	*temp;

	if (spec == 'X')
		temp = "0X";
	else
		temp = "0x";
	temp = b_iud_free_and_join(ft_strdup(temp), str);
	return (temp);
}
