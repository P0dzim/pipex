/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 08:32:10 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/21 07:19:33 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (lst[0] == (t_list *)0)
			lst[0] = new;
		else
		{
			temp = lst[0];
			lst[0] = new;
			lst[0]->next = temp;
		}
	}
}
