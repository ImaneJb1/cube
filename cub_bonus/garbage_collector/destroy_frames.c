/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_frames.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:06:25 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/03 15:14:37 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	destroy_frames(t_frame *frames, t_data *data, int size)
{
	int	i;

	if(!data || !data->mlx_ptr)
		return;
	i = 0;
	while(i < size)
	{
		if(frames->img_ptr)
			mlx_destroy_image(data->mlx_ptr, frames->img_ptr);
		i++;
	}
}

void	destroy_weapon(t_data *data)
{
	destroy_frames(data->weapon.intro, data, 20);
	destroy_frames(data->weapon.walking, data, 20);
	destroy_frames(data->weapon.shooting, data, 5);
}

