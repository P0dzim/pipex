/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_aux_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:52:31 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/11 11:05:01 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	b_aux_bonus(va_list args, t_sentinel *sentinel, char *str)
{
	t_flags	flags;

	str++;
	b_aux_init_flags(&flags);
	if (*str == '#')
		flags.hashtag = *str++;
	if ((*str == ' ' || *(str + 1) == ' ' ) && *(str - 1) != '#')
		flags.space = *str++;
	if (*(str) == '0' || *(str - 1) == '0')
		flags.zero = *str++;
	flags.width = b_atoi(&flags, str);
	while (ft_isdigit(*str) || *str == '-' || *str == '+')
		str++;
	if (*str == '.')
	{
		flags.dot = *str++;
		flags.precision = ft_atoi(str);
		flags.dot_zero = *str;
		while (ft_isdigit(*str))
			str++;
	}
	flags.spec = *str;
	b_aux_make_str(args, sentinel, flags);
}

int	b_aux_nextchr(const char *str)
{
	const char	*str_start;

	str_start = str;
	str++;
	if (b_aux_isspec(*str))
		return (2);
	if (*str == ' ' || *str == '#')
		str++;
	while (ft_isdigit(*str) || *str == '-' || *str == '+')
		str++;
	if (*str == '.')
		str++;
	while (ft_isdigit(*str) || *str == '-')
		str++;
	return ((str - str_start + 1));
}

int	b_aux_isspec(char c)
{
	char	*specs;
	int		i;

	i = 0;
	specs = "sciduxXp%";
	while (specs[i])
	{
		if (specs[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	b_aux_init_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 1;
	flags->precision = 0;
	flags->spec = 0;
	flags->width = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->space = 0;
	flags->hashtag = 0;
	flags->dot_zero = 0;
}

void	b_aux_make_str(va_list args, t_sentinel *sentinel, t_flags flags)
{
	if (flags.spec == 'c')
		b2_aux_char(sentinel, flags, args);
	else if (flags.spec == 's')
		b2_aux_str(sentinel, flags, args);
	else if (flags.spec == 'x' || flags.spec == 'X')
		b_hex_node(sentinel, flags, args);
	else if (flags.spec == 'i' || flags.spec == 'd')
		b_iud_integer(sentinel, flags, args);
	else if (flags.spec == 'u')
		b_iud_uinteger(sentinel, flags, args);
	else if (flags.spec == 'p')
		b_pointer(sentinel, flags, args);
	else if (flags.spec == '%')
		new_node(ft_strdup("%"), sentinel, '%');
	else
		b_pointer_nothing(flags, sentinel);
}
