/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:24:29 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/06 22:00:40 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = data_func();
	if (!check_argv(argc, argv))
		return (0);
	if (!parse_map_file(argv[1], data))
	{
		free_all();
		return (0);
	}
	check_textures();
	data_init(data);
	parse_map();
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	rendring_(data);
	hook_init(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
