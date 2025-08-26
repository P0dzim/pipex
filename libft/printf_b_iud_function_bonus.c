/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_iud_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:16:38 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/11 09:45:35 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	b_iud_integer(t_sentinel *sentinel, t_flags flags, va_list args)
{
	char	*str;
	int		nbr;

	nbr = va_arg(args, int);
	str = ft_itoa(nbr);
	if (!nbr && !flags.precision && flags.dot)
		str[0] = '\0';
	if (flags.space && nbr < 0)
		flags.space = 0;
	if (flags.zero && flags.dot)
		flags.space = 1;
	if (flags.zero && flags.dot)
		flags.zero = 0;
	if (flags.plus && ft_atoi(str) >= 0)
		str = b_iud_free_and_join("+", str);
	if (flags.precision)
		str = b_iud_make_zero_str(str, flags.precision);
	if (flags.space && !flags.precision)
		str = b_iud_free_and_join(ft_strdup(" "), str);
	if (flags.width)
		b_iud_make_width_str(flags, str, sentinel);
	else
		new_node(str, sentinel, flags.spec);
}

void	b_iud_uinteger(t_sentinel *sentinel, t_flags flags, va_list args)
{
	char			*str;
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	str = ft_uitoa(nbr);
	if (!nbr && !flags.precision && flags.dot)
		str[0] = '\0';
	if (flags.plus)
		str = b_iud_free_and_join("+", str);
	if (flags.zero && flags.dot)
		flags.space = 1;
	if (flags.zero && flags.dot)
		flags.zero = 0;
	if (flags.precision)
		str = b_iud_make_zero_str(str, flags.precision);
	if (flags.space && !flags.precision)
		str = b_iud_free_and_join(ft_strdup(" "), str);
	if (flags.width)
		b_iud_make_width_str(flags, str, sentinel);
	else
		new_node(str, sentinel, flags.spec);
}

char	*b_iud_make_zero_str(char *str, int precision)
{
	char	*temp;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = (ssize_t) precision - (ssize_t)ft_strlen(str);
	if (ssize_t_atoi(str) < 0)
		j++;
	if (j <= 0)
		return (str);
	temp = (char *) ft_calloc((size_t)(j + 1), 1);
	while (i < j)
		temp[i++] = '0';
	b_point_minusstr(str, temp);
	return (b_iud_free_and_join(temp, str));
}

char	*b_iud_free_and_join(char *start, char *end)
{
	char	*temp;

	temp = ft_strjoin(start, end);
	free(end);
	if (*start != '+' && *start != '\0')
		free(start);
	return (temp);
}

void	b_iud_make_width_str(t_flags flags, char *str, t_sentinel *sentinel)
{
	long	width;
	char	*temp;

	width = flags.width;
	if (width < 0)
		width *= -1;
	if ((size_t) width <= ft_strlen(str))
	{
		new_node(str, sentinel, flags.spec);
		return ;
	}
	temp = (char *) ft_calloc((size_t) width + 1 - ft_strlen(str), 1);
	if (flags.zero)
		ft_memset(temp, '0', (size_t) width - ft_strlen(str));
	else
		ft_memset(temp, ' ', (size_t) width - ft_strlen(str));
	b_point_minusstr(str, temp);
	if (flags.width < 0)
	{
		new_node(str, sentinel, flags.spec);
		b_node_add_bonus(sentinel, temp, ' ');
		return ;
	}
	make_gen_node(flags.spec, temp, sentinel, ' ');
	b_node_add_bonus(sentinel, str, flags.spec);
}
