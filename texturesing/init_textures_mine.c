/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_mine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:21:30 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/11 20:57:56 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	load_all_textures(t_data *data)
{
	int height;
	int width;
	int i;
	t_img tmp_img;
	static char *paths[4] = {"textures/north.xpm",
						"textures/south.xpm",
						"textures/west.xpm",
						"textures/east.xpm"};
	
	i = 0;
	while(paths[i])
	{
		tmp_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path[i], &width, &height);
		if(!tmp_img)
		{
			printf(""Error loading texture: %s\n", path");
			exit(1);	
		}
		tmp_img.img_pxl_ptr = mlx_get_data_addr(tmp_img.img_ptr, &tmp_img.b_p_p, &tmp_img.line_len, &tmp_img.endian);
		q
		i++;
	}
}