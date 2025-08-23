/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 08:58:33 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/21 07:19:17 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_current;
	t_list	*lst_next;

	if (lst && del)
	{
		if (lst[0])
		{
			lst_current = lst[0];
			lst_next = lst_current->next;
			while (lst_current->next != (t_list *)0)
			{
				lst_current->next = (t_list *)0;
				ft_lstdelone(lst_current, del);
				lst_current = lst_next;
				if (lst_current && lst_current->next)
					lst_next = lst_current->next;
			}
			if (lst_current)
			{
				del(lst_current->content);
				free(lst_current);
			}
			lst[0] = (t_list *)0;
		}
	}
}
