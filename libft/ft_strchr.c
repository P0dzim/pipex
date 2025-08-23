/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:43:08 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/17 08:11:04 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned int) c;
	while (*s)
	{
		if (uc == *s)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return ((char *)0);
}
