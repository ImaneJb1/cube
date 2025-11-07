/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:20:08 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/07 16:17:29 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	init_player(t_data *data)
{
	data->p.move_speed = 2;
	data->p.move_dir = 0;
	data->p.rot_dir = 0;
	data->p.right_x = 0;
	data->p.left_y = 0;
	data->p.rot_speed = 2 * (M_PI / 180);
	if (data->p.direction == 'N')
		data->p.view_angle = 270 * (M_PI / 180);
	if (data->p.direction == 'E')
		data->p.view_angle = 0;
	if (data->p.direction == 'S')
		data->p.view_angle = 90 * (M_PI / 180);
	if (data->p.direction == 'W')
		data->p.view_angle = 180 * (M_PI / 180);
}

int	get_width(char *map[])
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			i++;
		}
		if (i > l)
			l = i;
		j++;
	}
	return (l);
}

int	get_heigth(char *map[])
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void	init_ray(t_data *data)
{
	data->ray.distance = INT_MAX;
	data->ray.is_down = 0;
	data->ray.is_up = 0;
	data->ray.is_right = 0;
	data->ray.is_left = 0;
	data->ray.ver_walhit_x = 0;
	data->ray.ver_walhit_y = 0;
	data->ray.hor_walhit_x = 0;
	data->ray.hor_walhit_y = 0;
	data->ray.walhit_x = 0;
	data->ray.walhit_y = 0;
	data->ray.hit_vertical = 0;
	data->ray.hit_horiz = 0;
	data->ray.content = 0;
}

void	data_init(t_data *data)
{
	static char	**map;
	int			size;

	map = *the_map();
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(1);
	data->map = map;
	get_door(data);
	data->vertical_hit = 0;
	data->width = get_width(data->map);
	data->heigth = get_heigth(data->map);
	init_player(data);
	init_ray(data);
	init_first_person(data);
	data->shooting = 0;
	size = 5;
	if (!data->door_x && !data->door_y)
		size = 4;
	data->arr = init_text_arr(data->mlx_ptr, &data->arr, size);
}
