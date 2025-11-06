/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:42:13 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/06 17:17:58 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

void	reset(t_data *data)
{
	data->p.move_dir = 0;
	data->p.rot_dir = 0;
	data->moving = 0;
}

static void	which_key(int keysem, t_data *data)
{
	if (keysem == XK_Right)
		data->p.rot_dir = 1;
	if (keysem == XK_Left)
		data->p.rot_dir = -1;
	if (keysem == XK_Up || keysem == XK_w)
		data->p.move_dir = 1;
	if (keysem == XK_Down || keysem == XK_s)
		data->p.move_dir = -1;
	if (keysem == XK_d)
	{
		data->moving = 1;
		data->p.right_x = cos(data->p.view_angle + M_PI / 2);
		data->p.left_y = sin(data->p.view_angle + M_PI / 2);
	}
	if (keysem == XK_a)
	{
		data->moving = 1;
		data->p.right_x = cos(data->p.view_angle - M_PI / 2);
		data->p.left_y = sin(data->p.view_angle - M_PI / 2);
	}
}

int	press_x(t_data *data)
{
	(void)data;
	free_and_exit(0);
	return (0);
}

int	press_key(int keysem, t_data *data)
{
	if (keysem == XK_Escape)
		press_x(data);
	else
		which_key(keysem, data);
	return (0);
}

int	release_key(int keysem, t_data *data)
{
	if (keysem == XK_Up || keysem == XK_Down || keysem == XK_s
		|| keysem == XK_w)
		data->p.move_dir = 0;
	if (keysem == XK_Right || keysem == XK_Left)
		data->p.rot_dir = 0;
	if (keysem == XK_d || keysem == XK_a)
	{
		data->moving = 0;
		data->p.right_x = 0;
		data->p.left_y = 0;
	}
	return (0);
}
