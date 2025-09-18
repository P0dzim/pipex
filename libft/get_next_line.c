/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 07:16:21 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 14:13:48 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_buffer(int fd, char *buffer);
static char	*get_line(char *buffer);
static void	clean_buffer(char **buffer, char *line);

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return ((char *)0);
	if (!buffer[fd])
		buffer[fd] = (char *) ft_calloc(1, 1);
	if (!buffer[fd])
		return ((char *)0);
	buffer[fd] = fill_buffer(fd, buffer[fd]);
	line = get_line(buffer[fd]);
	clean_buffer(&buffer[fd], line);
	return (line);
}

static char	*fill_buffer(int fd, char *buffer)
{
	char	*next_buffer;
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	next_buffer = (char *) ft_calloc((BUFFER_SIZE + 1), 1);
	if (!next_buffer)
		return ((char *)0);
	while (!ft_strchr((const char *)buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, next_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(next_buffer);
			return ((char *)0);
		}
		next_buffer[bytes_read] = '\0';
		temp = ft_strjoin(buffer, next_buffer);
		free(buffer);
		buffer = temp;
	}
	free(next_buffer);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*ptr_buffer;
	char	*line;

	ptr_buffer = buffer;
	if (!buffer || !*buffer)
		return ((char *)0);
	while (*ptr_buffer != '\n' && *ptr_buffer)
		ptr_buffer++;
	line = (char *) ft_calloc((size_t)(ptr_buffer - buffer + 2), 1);
	if (!line)
		return ((char *)0);
	if (*ptr_buffer == '\n')
		(void) ft_strlcpy(line, buffer, (ptr_buffer - buffer + 2));
	else
		(void) ft_strlcpy(line, buffer, (ptr_buffer - buffer + 1));
	return (line);
}

static void	clean_buffer(char **buffer, char *line)
{
	char	*new_buffer;
	size_t	size_buffer;
	size_t	size_line;

	if (!*buffer || !**buffer || !line)
	{
		if (*buffer)
			free(*buffer);
		*buffer = (char *)0;
		return ;
	}
	size_buffer = ft_strlen(*buffer);
	size_line = ft_strlen(line);
	if (size_buffer == size_line)
	{
		free(*buffer);
		*buffer = (char *)0;
		return ;
	}
	new_buffer = (char *) ft_calloc((size_buffer - size_line + 1), 1);
	if (new_buffer)
		(void) ft_strlcpy(new_buffer, &buffer[0][size_line],
			(size_buffer - size_line + 1));
	free(*buffer);
	*buffer = new_buffer;
}
