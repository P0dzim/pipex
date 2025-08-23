/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:50:28 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/17 08:10:15 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			*last_c;
	unsigned char	uc;

	last_c = (char *)0;
	uc = (unsigned int) c;
	while (*s)
	{
		if (uc == *s)
			last_c = (char *)s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (last_c);
}
