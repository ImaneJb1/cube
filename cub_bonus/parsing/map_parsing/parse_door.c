/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:29:44 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/06 16:08:15 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

void	get_door(t_data *data)
{
	int (x), (y), (flag);
	flag = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'D')
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
	{
		data->door_x = 0;
		data->door_y = 0;
	}
}
