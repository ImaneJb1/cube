/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collecter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:27:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/08 13:50:08 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	collect_the_map(char *line, int fd)
{
	char	*map;

	map = NULL;
	line = ft_strtrim(line, " \t");
	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
		line = ft_strtrim(line, " \t");
		if (!line)
			break ;
		if (line[0] != '1')
		{
			printf("ERROR: the map is Invalid in line [%s]\n", line);
			free_and_exit(1);
		}
	}
	create_map_arr (map);
}
