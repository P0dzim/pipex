/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_func_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:12:58 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:37:45 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	cpy_func(char *dst, const char *src, size_t index, char flag)
{
	if (!src)
		return ;
	if (ft_strlen(src) == 0 && flag == 'c')
	{
		dst[index] = '\0';
		return ;
	}
	while (*src)
	{
		dst[index] = *src;
		src++;
		index++;
	}
	return ;
}
