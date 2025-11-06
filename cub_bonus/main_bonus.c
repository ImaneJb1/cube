/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:24:29 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/06 17:24:31 by nel-khad         ###   ########.fr       */
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
