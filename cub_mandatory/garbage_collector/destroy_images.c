/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:51:00 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/03 00:47:58 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	destroy_weapon(t_data *data)
{
	if (!data)
	{
		printf("destroy weapon: data is null\n");
		return ;
	}
	if (data->mlx_ptr && data->weapon.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->weapon.img_ptr);
}

void	destroy_textures(t_data *data)
{
	int	i;

	if (!data || !data->arr)
	{
		// printf("destroy weapon: data is null\n");
		return ;
	}
	i = 0;
	while (i < 4)
	{
		if (data->arr[i].img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->arr[i].img_ptr);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;
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
		i++;
	}
}

void	destroy_all(void)
{
	t_data	*data;

	data = data_func();
	free_map(data->map);
	destroy_weapon(data);
	destroy_textures(data);
	if(data && data->mlx_ptr && data->img.img_ptr && data->mlx_win)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
