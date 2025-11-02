/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:34:46 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/02 15:59:42 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	set_tex_x(t_data *data, int type)
{
	double	wall_x;

	if (data->vertical_hit == 0)
	{
		wall_x = fmod(data->ray.walhit_x, SQUARESIZE);
	}
	else
	{
		wall_x = fmod(data->ray.walhit_y, SQUARESIZE);
	}
	data->tex_x = (wall_x / SQUARESIZE) * data->arr[type].width;
}

void	set_step(double wall_height, t_texture *texture)
{
	texture->step = (double)texture->height / wall_height;
}

void	set_tex_pos(double top_wall, t_texture *texture)
{
	if (top_wall < 0)
		texture->tex_pos = (-top_wall) * texture->step;
	else
		texture->tex_pos = 0;
}
