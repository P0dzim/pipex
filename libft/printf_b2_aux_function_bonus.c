/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2_aux_function_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:44:46 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/11 09:23:18 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static ssize_t	b2_aux_width_len(long width, int precision, size_t strlen);

void	b2_aux_char(t_sentinel *sentinel, t_flags flags, va_list args)
{
	char	*new_width;
	long	mod_width;
	char	str[2];

	mod_width = flags.width;
	new_width = NULL;
	if (mod_width < 0)
		mod_width *= -1;
	if (!flags.width || mod_width < 2)
		return (aux_char(args, sentinel, "%c"));
	b2_aux_width(&new_width, ' ', (ssize_t)(mod_width - 1));
	if (flags.width > 0)
	{
		str[0] = (char) va_arg(args, int);
		str[1] = '\0';
		make_gen_node(' ', new_width, sentinel, ' ');
		b_node_add_bonus(sentinel, ft_strdup(str), 'c');
		return ;
	}
	aux_char(args, sentinel, "%c");
	b_node_add_bonus(sentinel, new_width, ' ');
}

void	b2_aux_str(t_sentinel *sentinel, t_flags flags, va_list args)
{
	char	*in;
	char	*str;
	char	*width_str;
	long	mod_width;

	mod_width = flags.width;
	width_str = NULL;
	if (mod_width < 0)
		mod_width *= -1;
	in = va_arg(args, char *);
	str = ft_strdup(in);
	if (flags.dot)
	{
		if (ft_strlen(str) >= (size_t)flags.precision && flags.precision && in)
			str[flags.precision] = '\0';
		else if (!flags.precision || (flags.precision < 6 && !in))
			str[0] = '\0';
	}
	if (mod_width)
		b2_aux_width(&width_str, ' ',
			b2_aux_width_len(mod_width, flags.precision, ft_strlen(str)));
	b2_aux_lst(str, width_str, sentinel, flags.width);
}

void	b2_aux_width(char **width, char c, ssize_t size)
{
	if (size > 0)
		*width = (char *) ft_calloc((size_t)size + 1, sizeof(char));
	if (size > 0 && *width)
		ft_memset(*width, (int)c, size);
}

void	b2_aux_lst(char *str, char *flag_str, t_sentinel *sen, long i)
{
	if (i == 0 || !flag_str)
	{
		new_node(str, sen, 's');
		return ;
	}
	if (i < 0)
	{
		new_node(str, sen, 's');
		b_node_add_bonus(sen, flag_str, ' ');
		return ;
	}
	make_gen_node(0, flag_str, sen, 's');
	b_node_add_bonus(sen, str, ' ');
}

ssize_t	b2_aux_width_len(long width, int precision, size_t strlen)
{
	ssize_t	count;

	if ((size_t) precision >= strlen)
		return ((ssize_t) width - (ssize_t)strlen);
	count = (ssize_t) width - (ssize_t) precision - strlen;
	return (count);
}
