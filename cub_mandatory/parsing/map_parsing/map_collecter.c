/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collecter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:27:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/11 13:55:50 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	collect_the_map(char *line, int fd)
{
	char	*map;
	char	*tmp;

	map = NULL;
	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
		tmp = ft_strtrim(line, " \t");
		if (!tmp)
			break ;
		if (tmp[0] != '1')
		{
			printf("Error\nthe map is Invalid in line [%s]\n", line);
			free_and_exit(1);
		}
	}
	create_map_arr (map);
}
