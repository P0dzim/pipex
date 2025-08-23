/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:23:45 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/21 07:08:33 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;

	index = 0;
	if (!s || !f)
		return ((char *)0);
	str = ft_strdup(s);
	if (!str)
		return ((char *)0);
	while (s[index])
	{
		str[index] = f(index, str[index]);
		index++;
	}
	return (str);
}
