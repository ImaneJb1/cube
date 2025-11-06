/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:00:48 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/06 16:06:00 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"
#include "get_next_line.h"

char	*get_leftover(char *buffer)
{
	char	*leftover;
	int		j;
	int		i;
	int		len;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (NULL);
	len = ft_strlen(buffer) - i;
	leftover = gc_malloc(len * sizeof(char) + 1);
	if (!leftover)
	{
		return (NULL);
	}
	i++;
	while (j < len)
		leftover[j++] = buffer[i++];
	leftover[j] = 0;
	return (leftover);
}

char	*extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = gc_malloc(sizeof(char) * (i + 1 + (buffer[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*read_buff(int fd, char *buffer)
{
	char	*buf;
	int		readed;

	buf = gc_malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (NULL);
		buf[readed] = 0;
		buffer = gft_strjoin(buffer, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_buff(fd, buffer);
	if (!buffer)
	{
		return (NULL);
	}
	if (*buffer == 0)
	{
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	if (!line)
	{
		buffer = NULL;
		return (NULL);
	}
	buffer = get_leftover(buffer);
	return (line);
}
