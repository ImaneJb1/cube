/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:25:43 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/24 17:49:08 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	init_weapon(t_data *data)
{
	data->weapon.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponpng.xpm", &data->weapon.width, &data->weapon.height);
	data->weapon.pxl_ptr = mlx_get_data_addr(data->weapon.img_ptr, &data->weapon.b_p_p, &data->weapon.line_len, &data->weapon.endian);
}

void	put_weapon(t_data *data)
{
	int (x), (y);
	int (img_x), (img_y);
	int x_img_end, color;

	x_img_end = WIDTH / 2 + data->weapon.width / 2;
	x = WIDTH / 2 -	data->weapon.width / 2;
	img_x = 0;
	while(x < x_img_end)
	{
		// printf("x= %d, x_img_end= %d\n",x, x_img_end);
		img_y = 0;
		y = HEIGHT - data->weapon.height;
		while(y != HEIGHT)
		{
			color = *(int *)(data->weapon.pxl_ptr + (img_y * data->weapon.line_len) + (img_x * (data->weapon.b_p_p / 8)));
			if(color != 0x06ff00)
				my_img_pixel_put(data, &data->img, x, y, color);						
			y++;
			img_y++;
		}
		x++;
		img_x++;
	}
}
