/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collecter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:27:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/01 15:11:03 by ijoubair         ###   ########.fr       */
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
		line = get_next_line(fd);
	}
	create_map_arr(map);
}