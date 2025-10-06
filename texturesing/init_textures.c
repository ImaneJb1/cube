/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:13:30 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/06 17:54:46 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void load_texture_from_path(t_data *data, int index, char *path)
{
    int width;
    int height;
    t_img tmp_img;

    tmp_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
    if (!tmp_img.img_ptr)
    {
        printf("Error loading texture: %s\n", path);
        exit(1);
    }

    tmp_img.img_pxl_ptr = mlx_get_data_addr(tmp_img.img_ptr, &tmp_img.b_p_p, &tmp_img.line_len, &tmp_img.endian);

    data->textures[index] = allocate_textures(width, height);
    fill_textures(data->textures[index], &tmp_img, width, height);

    data->textures_w[index] = width;
    data->textures_h[index] = height;

    mlx_destroy_image(data->mlx_ptr, tmp_img.img_ptr); // نحررو tmp image
}

void load_all_textures(t_data *data)
{
	char *paths[6];
    int i = 0;

	paths[0] = "../textures/floor.xpm";
	paths[1] = "../textures/ceiling.xpm";
	paths[2] = "../textures/north.xpm";
	paths[3] = "../textures/south.xpm";
	paths[4] = "../textures/east.xpm";
	paths[5] = "../textures/west.xpm";
	

    while (i < 4)
    {
        load_texture_from_path(data, i, paths[i]);
        i++;
    }
}

