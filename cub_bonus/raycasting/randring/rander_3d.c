/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:19:36 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/01 15:19:59 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

void draw_ceiling(t_data *data, double top_wall)
{
	int y;
	
	y = 0;
	while(y < top_wall)
	{
		my_img_pixel_put(data, &data->img, data->ray.id, y, 0x0000ff);
		y++;
	}
}

void draw_floor(t_data *data, double bottom_wall)
{
	int y;
	
	y = HEIGHT;
	while(y > bottom_wall)
	{
		my_img_pixel_put(data, &data->img, data->ray.id, y, 0x00ff00);
		y--;
	}
}

void draw_wall(t_data *data, double top_wall, double bottom_wall)
{
	int y;
	
	y = top_wall;
	while(y < bottom_wall)
	{
		my_img_pixel_put(data, &data->img, data->ray.id, y, 0xffffff);
		y++;
	}
}

