/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:24:29 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/08 13:28:35 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		size;

	data = data_func();
	if (!check_argv(argc, argv))
		return (0);
	if (!parse_map_file(argv[1], data))
		return (free_all(), 0);
	parse_map();
	get_door(data);
	size = 5;
	if (!data->door_x && !data->door_y)
		size = 4;
	check_textures();
	data_init(data);
	data->arr = init_text_arr(data->mlx_ptr, &data->arr, size);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	rendring_(data);
	hook_init(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
