/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:51:00 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/11 13:58:47 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	destroy_weapon(t_data *data)
{
	if (!data)
	{
		printf("Error\ndestroy weapon: data is null\n");
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

	if (!map || !map[0])
	{
		return ;
	}
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

void	destroy_all(void)
{
	t_data	*data;

	data = data_func();
	destroy_weapon(data);
	destroy_textures(data);
	if (data->mlx_ptr && data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->mlx_ptr && data->mlx_win)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
