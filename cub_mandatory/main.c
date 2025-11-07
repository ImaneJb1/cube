/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:40:07 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/07 15:44:56 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	parse_map();
	data_init(data);
	rendring_(data);
	hook_init(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_all();
	get_next_line(-1);
	return (0);
}
