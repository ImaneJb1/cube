/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collecter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:27:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/09 18:35:16 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	collect_the_map(char *line, int fd)
{
	char *map;
	char *tmp;

	map = NULL;
	tmp = NULL;
	while(line)
	{
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		line = get_next_line(fd);
	}
	create_map_arr(map);
}