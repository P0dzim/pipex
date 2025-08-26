/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:12:10 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:37:35 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_sentinel	*init_sentinel(void)
{
	t_sentinel	*sentinel;

	sentinel = (t_sentinel *) ft_calloc(1, sizeof(t_sentinel));
	if (!sentinel)
		return (NULL);
	sentinel->size = 0;
	sentinel->nodes = NULL;
	return (sentinel);
}

void	new_node(char *str, t_sentinel *sentinel, char flag)
{
	t_node	*node;
	t_node	*last_node;
	size_t	size_str;

	size_str = 0;
	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		return ;
	if (str)
		size_str = ft_strlen((const char *)str);
	node->str = str;
	node->bonus = NULL;
	node->next = NULL;
	node->flag = flag;
	sentinel->size = sentinel->size + size_str;
	last_node = sentinel->nodes;
	if (!sentinel->nodes)
	{
		sentinel->nodes = node;
		return ;
	}
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = node;
}

void	fill_sentinel(const char *str, t_func *func, va_list a, t_sentinel *s)
{
	while (*str)
	{
		if (*str == '%')
		{
			if (!b_aux_isspec(*(str + 1)))
				b_aux_bonus(a, s, (char *)str);
			else
				func[(int)*(str + 1)](a, s, (char *)str);
			if (*str && *(str + 1))
				str = str + b_aux_nextchr(str);
		}
		if ((*str && *str != '%') || (*str && *(str + 1) == 0))
			str++;
	}
}

void	clean_nodes(t_sentinel *lst)
{
	t_node	*lst_current;
	t_node	*lst_next;

	if (!lst || !lst->nodes)
		return ;
	lst_current = lst->nodes;
	lst_next = lst_current->next;
	while (lst_current && lst_current->next != (t_node *)0)
	{
		lst_current->next = (t_node *)0;
		if (lst_current->str)
			free(lst_current->str);
		if (lst_current->bonus)
			b_node_free(lst_current->bonus);
		free(lst_current);
		lst_current = lst_next;
		lst_next = lst_current->next;
	}
	if (lst_current)
	{
		if (lst_current->bonus)
			b_node_free(lst_current->bonus);
		free(lst_current->str);
		free(lst_current);
	}
}

void	aux_nothing(va_list args, t_sentinel *sentinel, char *spec)
{
	char	str[3];

	(void) args;
	str[0] = *spec;
	str[1] = *(spec + 1);
	str[2] = 0;
	new_node(ft_strdup(str), sentinel, '\0');
}
