/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_frames.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:06:25 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/03 15:09:15 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	destroy_frames(t_frame *frames, t_data *data, int size)
{
	int	i;
	
	i = 0;
	while(i < size)
	{
		if(frames->img_ptr)
			mlx_destroy_
	}
}