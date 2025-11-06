/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collecter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:27:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/06 16:02:02 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	collect_the_map(char *line, int fd)
{
	char	*map;

	map = NULL;
	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	create_map_arr(map);
}
