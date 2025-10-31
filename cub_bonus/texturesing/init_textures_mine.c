/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_mine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:21:30 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/30 16:07:39 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "header.h"

// int	**allocate_textures(int width, int height)
// {
// 	int **textures;
// 	int i;

// 	textures = malloc(sizeof(int *) * height);
// 	if(!textures)
// 		return(NULL);
// 	i = 0;
// 	while(i < height)
// 	{
// 		textures[i] = malloc(sizeof(int) * width);
// 		if(!textures[i])
// 			return(NULL);
// 		i++;
// 	}
// 	return(textures);
// }

// void	fill_textures(int **textures, t_img *img, int width, int height);
// {
// 	int y;
// 	int x;
// 	char *pixel;
// 	int color;

// 	y = 0;
// 	while(textures[y])
// 	{
// 		x = 0;
// 		while(textures[y][x])
// 		{												//offset
// 			pixel = img->img_pxl_ptr + (y * img->line_len + x * (img->b_p_p
						// / 8));
// 			color = *(int)pixel;
// 			textures[y][x] = color;
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	load_all_textures(t_data *data)
// {
// 	int height;
// 	int width;
// 	int i;
// 	t_img tmp_img;
// 	static char *paths[4] = {"textures/north.xpm",
// 						"textures/south.xpm",
// 						"textures/west.xpm",
// 						"textures/east.xpm"};

// 	i = 0;
// 	while(paths[i])
// 	{
// 		tmp_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path[i], &width,
				// &height);
// 		if(!tmp_img)
// 		{
// 			printf(""Error loading texture: %s\n", path");
// 			exit(1);
// 		}
// 		tmp_img.img_pxl_ptr = mlx_get_data_addr(tmp_img.img_ptr, &tmp_img.b_p_p,
				// &tmp_img.line_len, &tmp_img.endian);
// 		data->textures[i] = allocate_textures(width, height);
// 		if(!data->textures[i])
// 		{
// 			printf("Memory allocation failed for texture: %s\n", path[i]);
// 			exit(1);
// 		}
// 		fill_textures(data->textures[i], tmp_img.img_pxl_ptr, width, height);
// 		i++;
// 	}
// }
