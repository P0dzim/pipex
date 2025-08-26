/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_function_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:13:07 by vitosant          #+#    #+#             */
/*   Updated: 2025/08/08 11:38:06 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	aux_char(va_list args, t_sentinel *sentinel, char *spec)
{
	int		c;
	char	str[2];

	c = va_arg(args, int);
	str[0] = (unsigned char)c;
	str[1] = '\0';
	new_node(ft_strdup(str), sentinel, *(spec + 1));
}

void	aux_str(va_list args, t_sentinel *sentinel, char *spec)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		new_node(ft_strdup("(null)"), sentinel, *(spec + 1));
		return ;
	}
	new_node(ft_strdup(str), sentinel, *(spec + 1));
}

void	aux_point(va_list args, t_sentinel *sentinel, char *spec)
{
	unsigned long long	mem_addr;
	int					index;
	char				*hex_digits;
	char				*str;

	hex_digits = "0123456789abcdef";
	index = 0;
	mem_addr = (unsigned long long) va_arg(args, void *);
	str = (char *) ft_calloc((ADDR_LEN + 1), sizeof(char));
	if (!mem_addr || !str)
	{
		free(str);
		new_node(ft_strdup("(nil)"), sentinel, *(spec + 1));
		return ;
	}
	while (mem_addr > 0)
	{
		str[index] = hex_digits[mem_addr % 16];
		index++;
		mem_addr = mem_addr / 16;
	}
	str[index++] = 'x';
	str[index] = '0';
	reverse_str(str);
	new_node(str, sentinel, *(spec + 1));
}

void	aux_percent(va_list args, t_sentinel *sentinel, char *spec)
{
	(void) args;
	new_node(ft_strdup("%"), sentinel, *(spec + 1));
}

void	reverse_str(char *str)
{
	size_t	len;
	size_t	index;
	char	temp;

	len = ft_strlen((const char *)str) - 1;
	index = 0;
	while (index < len)
	{
		temp = str[index];
		str[index] = str[len];
		str[len] = temp;
		index++;
		len--;
	}
}
