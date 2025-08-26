/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_node_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:40:02 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:37:51 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	b_node_free(t_node *node)
{
	free(node->str);
	free(node);
}

void	b_node_add_bonus(t_sentinel *sentinel, char *str, char op)
{
	t_node	*bonus_node;

	bonus_node = (t_node *)ft_calloc(1, sizeof(t_node));
	bonus_node->next = NULL;
	bonus_node->bonus = NULL;
	bonus_node->flag = op;
	bonus_node->str = str;
	if (!sentinel->nodes)
		sentinel->nodes = bonus_node;
	else
		b_node_last(sentinel)->bonus = bonus_node;
	sentinel->size = sentinel->size + ft_strlen(str);
}

t_node	*b_node_last(t_sentinel *sentinel)
{
	t_node	*node;

	node = sentinel->nodes;
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	make_gen_node(int c, char *str, t_sentinel *sentinel, char op)
{
	char	str_chr[2];

	str_chr[0] = (unsigned char)c;
	str_chr[1] = 0;
	if (op == 'c')
	{
		b_node_add_bonus(sentinel, ft_strdup(str_chr), op);
		return ;
	}
	new_node(str, sentinel, op);
}
