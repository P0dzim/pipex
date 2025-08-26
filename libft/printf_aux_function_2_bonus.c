/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_function_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:13:56 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:38:10 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	aux_dec(va_list args, t_sentinel *sentinel, char *spec)
{
	int	nbr;

	nbr = va_arg(args, int);
	new_node(ft_itoa(nbr), sentinel, *(spec + 1));
}

void	aux_int(va_list args, t_sentinel *sentinel, char *spec)
{
	int	nbr;

	nbr = va_arg(args, int);
	new_node(ft_itoa(nbr), sentinel, *(spec + 1));
}

void	aux_unsingned_dec(va_list args, t_sentinel *sentinel, char *spec)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	new_node(ft_uitoa(nbr), sentinel, *(spec + 1));
}

void	aux_hex(va_list args, t_sentinel *sentinel, char *spec)
{
	t_ull	nbr;
	char	*str;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	nbr = va_arg(args, unsigned int);
	str = (char *) ft_calloc((HEX_LEN + 1), sizeof(char));
	if (!nbr || !str)
	{
		if (str)
			free(str);
		new_node(ft_strdup("0"), sentinel, *(spec + 1));
		return ;
	}
	make_hex_str(str, hex_digits, nbr);
	new_node(str, sentinel, *(spec + 1));
}

void	aux_hex_cap(va_list args, t_sentinel *sentinel, char *spec)
{
	t_ull	nbr;
	char	*str;
	char	*hex_digits;

	hex_digits = "0123456789ABCDEF";
	nbr = va_arg(args, unsigned int);
	str = (char *) ft_calloc((HEX_LEN + 1), sizeof(char));
	if (!nbr || !str)
	{
		if (str)
			free(str);
		new_node(ft_strdup("0"), sentinel, *(spec + 1));
		return ;
	}
	make_hex_str(str, hex_digits, nbr);
	new_node(str, sentinel, *(spec + 1));
}
