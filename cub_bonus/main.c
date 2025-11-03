/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:get_heigth(data->map):37 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/12 12:09:19 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"


int main(int argc, char **argv)
{
	t_data *data;
	
	data = data_func();
	
	if(!check_argv(argc, argv))
	return 0;
	if(!parse_map_file(argv[1], data))
	{
		return 0;
	}// it creates the map array
	check_textures(); // this exits the program in case of faillure 
	parse_map();
	data_init(data);
	init_first_person(data);
	rendring_(data);
	hook_init(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_all();
	get_next_line(-1);
	return 0;
}
// i should parse when there is no playeer