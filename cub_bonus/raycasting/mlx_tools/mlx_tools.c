/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:42:29 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/06 17:14:57 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

int	mouse_move(int x, int y, t_data *data)
{
	int	delta_x;

	(void)x;
	(void)y;
	delta_x = x - (WIDTH / 2);
	data->p.view_angle += delta_x * 0.002;
	mlx_mouse_move(data->mlx_ptr, data->mlx_win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

void	hook_init(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
	mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, shooting, data);
	mlx_hook(data->mlx_win, DestroyNotify, 0, press_x, data);
	mlx_hook(data->mlx_win, MotionNotify, PointerMotionMask, mouse_move, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, release_key, data);
	mlx_mouse_hide(data->mlx_ptr, data->mlx_win);
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
