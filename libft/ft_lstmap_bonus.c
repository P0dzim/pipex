/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 10:09:26 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/21 07:20:03 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return ((t_list *)0);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst)
	{
		lst = lst->next;
		while (lst)
		{
			new_node = ft_lstnew(f(lst->content));
			if (new_node == (t_list *)0)
			{
				ft_lstclear(&lst, del);
				break ;
			}
			ft_lstadd_back(&new_lst, new_node);
			lst = lst->next;
		}
	}
	return (new_lst);
}
