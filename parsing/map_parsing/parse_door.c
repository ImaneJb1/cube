/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:29:44 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/28 22:47:36 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

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
				data->map[y][x] = '1';
				printf("x1 = %d, ddy1 = %d\n", x, y);
				data->door_x = x * SQUARESIZE;
				data->door_y = y * SQUARESIZE;
				printf("x1 = %f, ddy2 = %f\n", data->door_x, data->door_y);
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

