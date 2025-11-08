/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:29:44 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/08 13:40:18 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

void	set_door(t_data *data)
{
	data->door_x = 0;
	data->door_y = 0;
}

void	get_door(t_data *data)
{
	char	**map;

	int (x), (y), (flag);
	flag = 0;
	y = 0;
	map = *the_map();
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'D')
			{
				flag = 1;
				data->door_x = x * SQUARESIZE;
				data->door_y = y * SQUARESIZE;
			}
			x++;
		}
		y++;
	}
	if (flag == 0)
		set_door(data);
}
