/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:41:29 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/04 10:29:05 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	draw_circle(t_data *data)
{
	int	radius;
	int	px;
	int	py;
	int	dy;
	int	dx;

	radius = 2;
	px = data->p.p_x * MINISCAL;
	py = data->p.p_y * MINISCAL;
	dy = -radius;
	while (dy <= radius)
	{
		dx = -radius;
		while (dx <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius)
				img_pixel_put(data, &data->img, px + dx, py + dy, 0xFF0000);
			dx++;
		}
		dy++;
	}
}

void	draw_square(t_data *data, double x, double y, int color)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < SQUARESIZE * MINISCAL)
	{
		j = 0;
		while (j < SQUARESIZE * MINISCAL)
		{
			if (j == SQUARESIZE * MINISCAL - 1 || i == SQUARESIZE * MINISCAL - 1
				|| i == 0 || j == 0)
				img_pixel_put(data, &data->img, x + j, y + i, 0x000000);
			else
				img_pixel_put(data, &data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	put_player(t_data *data)
{
	draw_circle(data);
}

int	inside_circle(int radius, double x, double y, t_data *data)
{
	double	dx;
	double	dy;

	dx = x - data->p.p_x;
	dy = y - data->p.p_y;
	if (dx * dx + dy * dy <= radius * radius) // check if the point inside
		return (1);
	return (0);
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
				color = 0x808080;
			else if(data->map[i][j] == 'D')
				color = 0x4f0e1a;
			else if (data->map[i][j] == '0' || ft_strchr("SNWE",
					data->map[i][j]))
				color = -1;
			if (color >= 0)
				draw_square(data, j * SQUARESIZE * MINISCAL, i * SQUARESIZE
					* MINISCAL, color);
			color = -1;
			j++;
		}
		i++;
	}
}

void rendring_(t_data *data)
{
	cast_allrays(data);
	if(data->shooting)
		draw_shooting(data);
	else if((data->p.move_dir == 1 || data->p.move_dir == -1 || data->moving == 1))
		draw_first_person_walking(data, data->weapon.walking, 20);
	else
		draw_first_person_intro(data, data->weapon.intro, 20);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	mlx_do_sync(data->mlx_ptr);
}