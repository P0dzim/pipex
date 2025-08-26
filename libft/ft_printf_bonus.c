/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:12:47 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:37:43 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	fill_functions(t_func *functions);
static int	make_formated_str(const char *str, t_sentinel *sentinel);
static int	str_len_n_free(char *str, int i);
size_t		put_node_str(char *str, t_sentinel *sentinel, size_t i, int *i_s);

int	ft_printf(const char *str, ...)
{
	int			new_str_len;
	t_func		functions[ASCII_SIZE];
	va_list		args;
	t_sentinel	*sentinel;

	if (!str)
		return (-1);
	va_start(args, str);
	sentinel = init_sentinel();
	fill_functions(functions);
	fill_sentinel (str, functions, args, sentinel);
	new_str_len = make_formated_str(str, sentinel);
	clean_nodes(sentinel);
	free(sentinel);
	va_end(args);
	return (new_str_len);
}

static void	fill_functions(t_func *functions)
{
	int	i;

	i = 0;
	while (i < ASCII_SIZE)
	{
		functions[i] = aux_nothing;
		i++;
	}
	functions['c'] = aux_char;
	functions['s'] = aux_str;
	functions['p'] = aux_point;
	functions['d'] = aux_dec;
	functions['i'] = aux_int;
	functions['u'] = aux_unsingned_dec;
	functions['x'] = aux_hex;
	functions['X'] = aux_hex_cap;
	functions['%'] = aux_percent;
}

static int	make_formated_str(const char *str, t_sentinel *sentinel)
{
	char	*f_str;
	size_t	new_str_len;
	int		i;
	int		i_sen;

	i_sen = 0;
	i = 0;
	new_str_len = ft_strlen(str);
	new_str_len = new_str_len + sentinel->size;
	f_str = (char *) ft_calloc((new_str_len + 1), sizeof(char));
	while (*str)
	{
		if (*str == '%')
		{
			i += put_node_str(f_str, sentinel, (size_t)i, &i_sen);
			if (*str && *(str + 1))
				str = str + b_aux_nextchr(str);
		}
		if (*str == '\0')
			break ;
		if ((*str && *str != '%') || (*str && *(str + 1) == 0))
			f_str[i++] = *str++;
	}
	return (str_len_n_free(f_str, i));
}

size_t	put_node_str(char *str, t_sentinel *sentinel, size_t i, int *i_s)
{
	int		index_sentinel;
	t_node	*node;
	size_t	node_len;

	index_sentinel = 0;
	node = sentinel->nodes;
	while (index_sentinel++ < *i_s)
		node = node->next;
	*i_s = index_sentinel;
	if (!node->str)
		return (0);
	cpy_func(str, (const char *)node->str, i, node->flag);
	node_len = ft_strlen((const char *)node->str);
	if (!node_len && node->flag == 'c')
		node_len++;
	if (node->bonus)
	{
		cpy_func((str + node_len), (const char *)node->bonus->str, i,
			node->flag);
		node_len += ft_strlen(node->bonus->str);
		if (!ft_strlen(node->bonus->str) && node->bonus->flag == 'c')
			node_len++;
	}
	return (node_len);
}

static int	str_len_n_free(char *str, int i)
{
	write(1, str, i);
	free(str);
	return (i);
}
