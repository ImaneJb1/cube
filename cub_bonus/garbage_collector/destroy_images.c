/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:51:00 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/05 14:14:19 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"


void	destroy_textures(t_data *data)
{
	int	i;
	int size;
	if (!data || !data->arr)
	{
		// printf("destroy weapon: data is null\n");
		return ;
	}
	i = 0;
	size = 5;
	if(!data->door_x && !data->door_y)
		size = 4;
	while (i < size)
	{
		if (data->arr[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->arr[i].img_ptr);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;
	if((*the_map()) == NULL)
		return;
	if(!map || !map[0])
	{
		// printf("nuuuuuull\n");
		return;
	}
	i = 0;
		// printf("%s %d\n", map[0],i);

	while (map[i])
	{
		// printf("%s %d\n", map[i],i);
		free(map[i]);
		map[i] = NULL;
		i++;
	}
}

void	destroy_all(void)
{
	t_data	*data;

	data = data_func();
	destroy_weapon(data);
	destroy_textures(data);
	// free_map(data->map);
	if(data->mlx_ptr && data->img.img_ptr)
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if(data->mlx_ptr && data->mlx_win)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
