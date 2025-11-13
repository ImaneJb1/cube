/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:23:44 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/13 23:46:52 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	is_door(t_data *data, char *map[], double x, double y)
{
	int	grid_x;
	int	grid_y;

	(void)data;
	grid_x = floor(x / SQUARESIZE);
	grid_y = floor(y / SQUARESIZE);
	if (map[grid_y][grid_x] == 'D')
		map[grid_y][grid_x] = '0';
}

int	is_player_wall(t_data *data, char *map[], double x, double y)
{
	int (grid_x), (grid_y);
	double (dx), (dy), (marge);
	(void)data;
	marge = 6.0;
	dx = -marge;
	while (dx <= marge)
	{
		dy = -marge;
		while (dy <= marge)
		{
			grid_x = floor((x + dx) / SQUARESIZE);
			grid_y = floor((y + dy) / SQUARESIZE);
			if (grid_x < 0 || grid_y < 0 || map[grid_y] == NULL
				|| grid_x >= (int)ft_strlen(map[grid_y]))
				return (1);
			if (map[grid_y][grid_x] == '1')
				return (1);
			dy += marge;
		}
		dx += marge;
	}
	return (0);
}

static void	update_player(t_data *data)
{
	int		move_step;
	double	next_x;
	double	next_y;

	move_step = data->p.move_dir * data->p.move_speed;
	data->p.view_angle += data->p.rot_dir * data->p.rot_speed;
	data->p.view_angle = normlizing(data->p.view_angle);
	next_x = data->p.p_x + (cos(data->p.view_angle) * data->p.move_dir
			+ data->p.right_x) * data->p.move_speed;
	next_y = data->p.p_y + (sin(data->p.view_angle) * data->p.move_dir
			+ data->p.left_y) * data->p.move_speed;
	if (!is_player_wall(data, data->map, next_x, next_y))
	{
		data->p.p_y = next_y;
		data->p.p_x = next_x;
	}
	else if (!is_player_wall(data, data->map, data->p.p_x, next_y))
		data->p.p_y = next_y;
	else if (!is_player_wall(data, data->map, next_x, data->p.p_y))
		data->p.p_x = next_x;
}

int	moves_loop(t_data *data)
{
	update_player(data);
	rendring_(data);
	return (0);
}

double	normlizing(double angle)
{
	while (angle < 0)
	{
		angle += (2 * M_PI);
	}
	while (angle > (2 * M_PI))
	{
		angle -= (2 * M_PI);
	}
	return (angle);
}
