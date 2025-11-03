/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collecter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:27:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/03 16:00:41 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

void	collect_the_map(char *line, int fd)
{
	char *map;
	char *tmp;

	map = NULL;
	tmp = NULL;
	while(line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	get_next_line(-1);
	create_map_arr(map);
}