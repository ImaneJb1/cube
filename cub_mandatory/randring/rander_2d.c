/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:14:04 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/05 22:14:30 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	draw_circle(t_data *data, int color)
{
	int		radius;
	double	dx;
	double	dy;
	double	y;
	double	x;

	radius = 5;
	y = data->p.p_y - radius;
	while (y <= data->p.p_y + radius)
	{
		x = data->p.p_x - radius;
		while (x <= data->p.p_x + radius)
		{
			dx = x - data->p.p_x;
			dy = y - data->p.p_y;
			if (dx * dx + dy * dy <= radius * radius)
				my_img_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_square(t_data *data, double x, double y, int color)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < SQUARESIZE)
	{
		j = 0;
		while (j < SQUARESIZE)
		{
			if (j == SQUARESIZE - 1 || i == SQUARESIZE - 1 || i == 0 || j == 0)
				my_img_pixel_put(data, x + j, y + i, 0x000000);
			else
				my_img_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	put_player(t_data *data)
{
	draw_circle(data, 0xFF69B4);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = -1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				color = 0xffffff;
			else if (data->map[i][j] == '0' || ft_strchr("SNWE",
					data->map[i][j]))
				color = 0x87CEEB;
			if (color > 0)
				draw_square(data, j * SQUARESIZE, i * SQUARESIZE, color);
			color = -1;
			j++;
		}
		i++;
	}
}

void	rendring_(t_data *data)
{
	cast_allrays(data);
	put_weapon(data, &data->weapon);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	mlx_do_sync(data->mlx_ptr);
}
