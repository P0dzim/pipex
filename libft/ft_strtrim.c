/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 07:43:13 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/18 07:15:55 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trim_end;
	size_t	trim_begins;
	size_t	trimmed_str_size;
	char	*trimmed_str;

	trim_begins = 0;
	if (!s1 || !set)
		return ((char *)0);
	trim_end = ft_strlen(s1);
	if (trim_end == 0)
		return ((char *)ft_calloc(1, 1));
	while (is_in_set(s1[trim_begins], set))
		trim_begins++;
	while (trim_end > 0 && is_in_set(s1[trim_end - 1], set))
		trim_end--;
	if (trim_begins <= trim_end)
		trimmed_str_size = trim_end - trim_begins + 1;
	else
		trimmed_str_size = 1;
	trimmed_str = (char *) ft_calloc(trimmed_str_size, 1);
	if (trimmed_str)
		(void)ft_strlcpy(trimmed_str, &s1[trim_begins], trimmed_str_size);
	return (trimmed_str);
}

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
