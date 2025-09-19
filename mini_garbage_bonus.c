/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_garbage_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:04:31 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/19 16:12:57 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	clear_lst(t_args_lst *lst);

void	lst_control(char **args)
{
	static t_args_lst	*lst;
	t_args_lst			*temp;

	if (!lst && args)
	{
		lst = malloc(sizeof(t_args_lst));
		if (!lst)
			return ;
		lst->args = args;
		lst->next = NULL;
	}
	else if (args != NULL)
	{
		temp = lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = malloc(sizeof(t_args_lst));
		temp->next->args = args;
		temp->next->next = NULL;
	}
	else
		clear_lst(lst);
}

static void	clear_lst(t_args_lst *lst)
{
	t_args_lst	*temp;

	while (lst)
	{
		temp = lst;
		ft_free_table(&lst->args);
		lst = lst->next;
		free(temp);
	}
}
