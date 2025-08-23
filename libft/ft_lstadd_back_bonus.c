/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 08:48:30 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/21 07:19:37 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (lst && new)
	{
		if (lst[0])
		{
			last_node = ft_lstlast(lst[0]);
			last_node->next = new;
		}
		else
			lst[0] = new;
	}
}
