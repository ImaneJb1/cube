/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:00:48 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/04 21:28:03 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_leftover(char *buffer)
// {
// 	char	*leftover;
// 	int		j;
// 	int		i;
// 	int		len;

// 	j = 0;
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (!buffer[i])
// 		return (NULL);
// 	len = ft_strlen(buffer) - i;
// 	leftover = gc_malloc(len * sizeof(char) + 1);
// 	if (!leftover)
// 	{
// 		return (NULL);
// 	}
// 	i++;
// 	while (j < len)
// 		leftover[j++] = buffer[i++];
// 	leftover[j] = 0;
// 	return (leftover);
// }

// //get line with '\n'
// char	*extract_line(char *buffer)
// {
// 	char	*line;
// 	size_t		i;

// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	line = gc_malloc(sizeof(char) * (i + 1 + (buffer[i] == '\n')));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i] == '\n')
// 		line[i++] = '\n';
// 	line[i] = 0;
// 	return (line);
// }

// //join the leftover with the new readed line
// // char	*join_free(char *buffer, char *buf)
// // {
// // 	char	*join;

// // 	join = ft_strjoin(buffer, buf);
// // 	if(!join)
// // 		return (NULL);
// // 	free(buffer);
// // 	return (join);
// // }

// // fill the buf
// char	*read_buff(int fd, char *buffer)
// {
// 	char	*buf;
// 	int		readed;

// 	buf = gc_malloc(BUFFER_SIZE * sizeof(char) + 1);
// 	if (!buf)
// 		return (NULL);
// 	// if (!buffer)
// 	// 	buffer = ft_calloc(1, 1);
// 	// if(!buffer)
// 	// 	return(free(buf), NULL);
// 	readed = 1;
// 	int i = 0;
// 	while (readed > 0)
// 	{
// 		readed = read(fd, buf, BUFFER_SIZE);
// 		if (readed == -1)
// 			return(NULL); 
// 		buf[readed] = 0;
// 		buffer = gft_strjoin(buffer, buf);
		
// 		if (ft_strchr(buf, '\n'))
// 			break ;
// 	}
// 	return (buffer);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE < 0)
// 		return (NULL);
// 	buffer = read_buff(fd, buffer);
// 	if (!buffer){
// 		printf("bufer\n");
// 		return (NULL);
// 	}
// 	if (*buffer == 0)
// 	{
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	line = extract_line(buffer);
// 	if(!line)
// 	{
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	buffer = get_leftover(buffer);
// 	return (line);
// }


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static int	read_buffer(int fd, char *buf, int *i, int *bytes)
{
	*bytes = read(fd, buf, BUFFER_SIZE);
	*i = 0;
	if (*bytes <= 0)
		return (0);
	return (1);
}

static char	*ft_trjoin(char *line, char c, int *j)
{
	line[*j] = c;
	(*j)++;
	line[*j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	i;
	static int	bytes;
	static int	eof;
	static char	line[BUFFER_SIZE];
	int			j;

	j = 0;
	if (eof)
		return (0);
	while (1)
	{
		if (i >= bytes && !read_buffer(fd, buf, &i, &bytes))
		{
			eof = 1;
			if (j == 0)
				return (0);
			return (line);
		}
		ft_trjoin(line, buf[i++], &j);
		if (line[j - 1] == '\n' || j >= BUFFER_SIZE - 1)
			return (line);
	}
}
