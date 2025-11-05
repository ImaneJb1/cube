/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:17:05 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/05 22:17:36 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	hook_init(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
	mlx_hook(data->mlx_win, DestroyNotify, 0, press_x, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, release_key, data);
	mlx_loop_hook(data->mlx_ptr, moves_loop, data);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	offset = (img->line_len * y) + (x * (img->b_p_p / 8));
	*((unsigned int *)(img->img_pxl_ptr + offset)) = color;
}
