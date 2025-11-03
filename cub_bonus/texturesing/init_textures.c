/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:50:26 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/03 22:05:09 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

t_texture	*init_text_arr(void *mlx_ptr, t_texture **arr, int size)
{
	int	i;

	i = 0;
	*arr = malloc(sizeof(t_texture) * size);
	fill_image_arr(mlx_ptr, arr, size);
	return (*arr);
}

void	fill_image_arr(void *mlx_ptr, t_texture **arr, int size)
{
	int		i;
	char	*path[size];

	path[0] = (*text_func())->no;
	path[1] = (*text_func())->so;
	path[2] = (*text_func())->we;
	path[3] = (*text_func())->ea;
	if(size == 5)
		path[4] = (*text_func())->door;
	i = 0;
	printf("size = %d\n", size);
	while (i < size)
	{
		(*arr)[i].type = i;
		(*arr)[i].path = path[i];
		if (access(path[i], O_RDONLY) < 0)
		{
			printf("ERROR %d is inaccessible\n", i);
			break ;
		}
		(*arr)[i].img_ptr = mlx_xpm_file_to_image(mlx_ptr, path[i],
				&(*arr)[i].width, &(*arr)[i].height);
		(*arr)[i].img_pxl_ptr = mlx_get_data_addr((*arr)[i].img_ptr,
				&(*arr)[i].b_p_p, &(*arr)[i].line_len, &(*arr)[i].endian);
		i++;
	}
}

int	render_door(t_data *data, double x, double y, char c)
{
	int	grid_x;
	int	grid_y;

	grid_x = floor(x / SQUARESIZE);
	grid_y = floor(y / SQUARESIZE);
	if (c == 'h')
	{
		if (data->map[grid_y][grid_x] == 'D' || data->map[grid_y
			- 1][grid_x] == 'D')
			return (1);
	}
	else if (c == 'v')
	{
		if (data->map[grid_y][grid_x] == 'D' || data->map[grid_y][grid_x
			- 1] == 'D')
			return (1);
	}
	// if(data->map[grid_y][grid_x] == 'P')
	//     return(1);
	return (0);
}

int	get_textures_type(t_data *data)
{
	if (data->vertical_hit)
	{
		if (render_door(data, data->ray.walhit_x, data->ray.ver_walhit_y, 'v'))
			return (DOOR);
		if (data->p.p_x > data->ray.walhit_x)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (render_door(data, data->ray.walhit_x, data->ray.hor_walhit_y, 'h'))
			return (DOOR);
		if (data->p.p_y > data->ray.walhit_y)
			return (NORTH);
		else
			return (SOUTH);
	}
}



