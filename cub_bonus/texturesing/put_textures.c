/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:47:38 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/06 17:20:29 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

t_dim	calculate_wall_dimensions(t_data *data)
{
	t_dim	wall;
	double	distance_proj_plane;

	distance_proj_plane = (WIDTH / 2) / tan(FOV / 2);
	wall.wall_height = ((SQUARESIZE) / data->ray.distance)
		* distance_proj_plane;
	wall.top_wall = (HEIGHT / 2) - (wall.wall_height / 2);
	data->ray.top_wall = wall.top_wall;
	if (wall.top_wall < 0)
		wall.top_wall = 0;
	wall.bottom_wall = (HEIGHT / 2) + (wall.wall_height / 2);
	if (wall.bottom_wall >= HEIGHT)
		wall.bottom_wall = HEIGHT - 1;
	if (wall.bottom_wall < wall.top_wall)
		wall.bottom_wall = wall.top_wall;
	return (wall);
}

void	render_3d(t_data *data)
{
	t_dim	wall;

	int (type), (y);
	wall = calculate_wall_dimensions(data);
	type = get_textures_type(data);
	set_tex_x(data, type);
	set_step(wall.wall_height, &data->arr[type]);
	y = 0;
	while (y < HEIGHT)
	{
		if (y < wall.top_wall)
			my_img_pixel_put(data, data->ray.id, y, data->ceiling_color);
		else if (y >= wall.top_wall && y <= wall.bottom_wall)
		{
			draw_textured_wall(data, &data->arr[type], data->ray.top_wall,
				wall.bottom_wall);
			y = wall.bottom_wall + 1;
		}
		else if (y > wall.bottom_wall)
			my_img_pixel_put(data, data->ray.id, y, data->floor_color);
		y++;
	}
}

void	my_img_pixel_put(t_data *data, int x, int y, int color)
{
	int		offset;
	t_img	*img;

	img = &data->img;
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	offset = (img->line_len * y) + (x * (img->b_p_p / 8));
	*((unsigned int *)(img->img_pxl_ptr + offset)) = color;
}

void	draw_textured_wall(t_data *data, t_texture *texture, double top_wall,
		double bottom_wall)
{
	int	y;
	int	tex_y;
	int	color;

	set_tex_pos(top_wall, texture);
	if (top_wall < 0)
		top_wall = 0;
	y = (int)top_wall;
	while (y <= (int)bottom_wall)
	{
		tex_y = (int)texture->tex_pos;
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		color = *(int *)(texture->img_pxl_ptr + tex_y * texture->line_len
				+ data->tex_x * (texture->b_p_p / 8));
		my_img_pixel_put(data, data->ray.id, y, color);
		texture->tex_pos += texture->step;
		y++;
	}
}
