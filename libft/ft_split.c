/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:10:35 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/21 07:18:34 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_array(char **array, char *str, char c, int total_splits);
static size_t	count_splits(char *s, char c);
static size_t	next_split(const char *s, char c);
static void		free_array(char ***array, int j);

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	trim[2];
	char	*trimmed_str;
	int		total_splits;

	trim[0] = c;
	trim[1] = '\0';
	trimmed_str = ft_strtrim(s, trim);
	total_splits = count_splits(trimmed_str, c);
	array = (char **) ft_calloc((total_splits + 1), sizeof(char *));
	if (array)
	{
		array[total_splits] = (char *)0;
		fill_array(array, trimmed_str, c, total_splits);
		free(trimmed_str);
	}
	return (array);
}

static size_t	count_splits(char *s, char c)
{
	size_t	total;

	total = 0;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			total++;
			while (*s == c)
				s++;
		}
		if (*s)
			s++;
	}
	return (++total);
}

static size_t	next_split(const char *s, char c)
{
	size_t	position;

	position = 0;
	while (s[position] != c && s[position])
		position++;
	return (position);
}

static void	fill_array(char **array, char *str, char c, int total_splits)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < total_splits && *str)
	{
		array[j] = (char *) ft_calloc((next_split(str, c) + 1), 1);
		if (!array[j])
		{
			free_array(&array, j);
			break ;
		}
		while (*str != c && *str)
		{
			array[j][i] = *str;
			str++;
			i++;
		}
		while (*str && *str == c)
			str++;
		i = 0;
		j++;
	}
}

static void	free_array(char ***array, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(array[0][i]);
		i++;
	}
	free(array[0]);
	array[0] = (char **)0;
}
