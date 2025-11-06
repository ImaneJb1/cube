/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_shooting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:10:07 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/05 16:13:30 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

int	shooting(int button, int x, int y, void *param)
{
	int		i;
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	i = 0;
	if (button == 1)
		data->shooting = 1;
	return (0);
}

void	draw_shooting(t_data *data)
{
	static int	i;

	if (i < 5)
	{
		put_frame(data, &data->weapon.shooting[i]);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr,
			0, 0);
		usleep(20400);
		i++;
	}
	else
	{
		put_frame(data, &data->weapon.walking[1]);
		data->shooting = 0;
		i = 0;
	}
}
