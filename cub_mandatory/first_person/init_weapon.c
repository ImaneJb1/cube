/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:54:21 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/11 13:58:25 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	init_weapon(t_data *data)
{
	data->weapon.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"cub_mandatory/textures/gun24.xpm", &data->weapon.width,
			&data->weapon.height);
	if (!data->weapon.img_ptr)
	{
		printf("Error\nGun texture failed\n");
		free_all();
		exit(1);
	}
	data->weapon.pxl_ptr = mlx_get_data_addr(data->weapon.img_ptr,
			&data->weapon.b_p_p, &data->weapon.line_len, &data->weapon.endian);
}

int	get_color(int x, int y, t_weapon *frame)
{
	if (!frame->pxl_ptr)
	{
		printf("ERROR: frame->pxl_ptr is NULL!\n");
		return (0);
	}
	if (x < 0 || x >= frame->width || y < 0 || y >= frame->height)
	{
		printf("Error in get color\n");
		free_and_exit(1);
	}
	return (*(int *)(frame->pxl_ptr + (y * frame->line_len) + (x * (frame->b_p_p
				/ 8))));
}

void	put_weapon(t_data *data, t_weapon *weapon)
{
	int (x), (y);
	int (img_x), (img_y);
	int (x_img_end), (color);
	x_img_end = WIDTH / 2 + weapon->width / 2;
	x = WIDTH / 2 - weapon->width / 2;
	img_x = 0;
	while (x < x_img_end)
	{
		img_y = 0;
		y = HEIGHT - weapon->height;
		while (y < HEIGHT)
		{
			if (img_x >= weapon->width || img_y >= weapon->height)
				break ;
			color = get_color(img_x, img_y, weapon);
			if ((unsigned int)color != 0xFF000000
				&& (unsigned int)color != 0x00000000)
				my_img_pixel_put(data, x, y, color);
			y++;
			img_y++;
		}
		x++;
		img_x++;
	}
}
