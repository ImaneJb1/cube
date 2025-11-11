/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:15:58 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/11 14:06:16 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_texture	*init_text_arr(void *mlx_ptr, t_texture **arr, int size)
{
	int	i;

	i = 0;
	*arr = gc_malloc(sizeof(t_texture) * size);
	fill_image_arr(mlx_ptr, arr);
	return (*arr);
}

void	fill_image_arr(void *mlx_ptr, t_texture **arr)
{
	int		i;
	char	*path[4];

	path[0] = (*text_func())->no;
	path[1] = (*text_func())->so;
	path[2] = (*text_func())->we;
	path[3] = (*text_func())->ea;
	i = 0;
	while (i < 4)
	{
		(*arr)[i].type = i;
		(*arr)[i].path = path[i];
		if (access(path[i], O_RDONLY) < 0)
		{
			printf("Error\n%s is inaccessible\n", path[i]);
			break ;
		}
		(*arr)[i].img_ptr = mlx_xpm_file_to_image(mlx_ptr, path[i],
				&(*arr)[i].width, &(*arr)[i].height);
		(*arr)[i].img_pxl_ptr = mlx_get_data_addr((*arr)[i].img_ptr,
				&(*arr)[i].b_p_p, &(*arr)[i].line_len, &(*arr)[i].endian);
		i++;
	}
}

int	get_textures_type(t_data *data)
{
	if (data->vertical_hit)
	{
		if (data->p.p_x > data->ray.walhit_x)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (data->p.p_y > data->ray.walhit_y)
			return (NORTH);
		else
			return (SOUTH);
	}
}
