/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:29:44 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/31 21:56:56 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

void	get_door(t_data *data)
{
	int (x), (y), (flag);

	flag = 0;
	y = 0;
	while(data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if(data->map[y][x] == 'D')
			{
				flag = 1;
				data->door_x = x * SQUARESIZE;
				data->door_y = y * SQUARESIZE;
			}
			x++;
		}
		y++;
	}
	if(flag == 0)
	{
		data->door_x = -1;
		data->door_y = -1;
	}
}

