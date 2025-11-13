/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frames.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:25:43 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/13 23:44:57 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	init_frames(char *textures[], int size, t_frame *frame, t_data *data)
{
	int	i;

	i = 0;
	while (i < size)
	{
		frame[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, textures[i],
				&frame[i].width, &frame[i].height);
		if (!frame[i].img_ptr)
		{
			printf("Error\nLoading texture %s failed\n", textures[i]);
			free_all();
			exit(1);
		}
		frame[i].pxl_ptr = mlx_get_data_addr(frame[i].img_ptr, &frame[i].b_p_p,
				&frame[i].line_len, &frame[i].endian);
		i++;
	}
}

void	init_weapon_intro(t_data *data)
{
	static char	*textures[20] = {"cub_bonus/textures/intro_xpm/gun1.xpm",
		"cub_bonus/textures/intro_xpm/gun2.xpm",
		"cub_bonus/textures/intro_xpm/gun3.xpm",
		"cub_bonus/textures/intro_xpm/gun4.xpm",
		"cub_bonus/textures/intro_xpm/gun5.xpm",
		"cub_bonus/textures/intro_xpm/gun6.xpm",
		"cub_bonus/textures/intro_xpm/gun7.xpm",
		"cub_bonus/textures/intro_xpm/gun8.xpm",
		"cub_bonus/textures/intro_xpm/gun9.xpm",
		"cub_bonus/textures/intro_xpm/gun10.xpm",
		"cub_bonus/textures/intro_xpm/gun11.xpm",
		"cub_bonus/textures/intro_xpm/gun12.xpm",
		"cub_bonus/textures/intro_xpm/gun13.xpm",
		"cub_bonus/textures/intro_xpm/gun14.xpm",
		"cub_bonus/textures/intro_xpm/gun15.xpm",
		"cub_bonus/textures/intro_xpm/gun16.xpm",
		"cub_bonus/textures/intro_xpm/gun17.xpm",
		"cub_bonus/textures/intro_xpm/gun18.xpm",
		"cub_bonus/textures/intro_xpm/gun19.xpm",
		"cub_bonus/textures/intro_xpm/gun20.xpm"};

	init_frames(textures, 20, data->weapon.intro, data);
}

void	init_weapon_walking(t_data *data)
{
	static char	*textures[20] = {"cub_bonus/textures/walking_xpm/gun24.xpm",
		"cub_bonus/textures/walking_xpm/gun25.xpm",
		"cub_bonus/textures/walking_xpm/gun26.xpm",
		"cub_bonus/textures/walking_xpm/gun27.xpm",
		"cub_bonus/textures/walking_xpm/gun28.xpm",
		"cub_bonus/textures/walking_xpm/gun29.xpm",
		"cub_bonus/textures/walking_xpm/gun30.xpm",
		"cub_bonus/textures/walking_xpm/gun31.xpm",
		"cub_bonus/textures/walking_xpm/gun32.xpm",
		"cub_bonus/textures/walking_xpm/gun33.xpm",
		"cub_bonus/textures/walking_xpm/gun34.xpm",
		"cub_bonus/textures/walking_xpm/gun35.xpm",
		"cub_bonus/textures/walking_xpm/gun36.xpm",
		"cub_bonus/textures/walking_xpm/gun37.xpm",
		"cub_bonus/textures/walking_xpm/gun38.xpm",
		"cub_bonus/textures/walking_xpm/gun39.xpm",
		"cub_bonus/textures/walking_xpm/gun40.xpm",
		"cub_bonus/textures/walking_xpm/gun41.xpm",
		"cub_bonus/textures/walking_xpm/gun42.xpm",
		"cub_bonus/textures/walking_xpm/gun43.xpm"};

	init_frames(textures, 20, data->weapon.walking, data);
}

void	init_weapon_shooting(t_data *data)
{
	int			i;
	static char	*textures[5] = {
		"cub_bonus/textures/shooting_xpm/shooting1.xpm",
		"cub_bonus/textures/shooting_xpm/shooting2.xpm",
		"cub_bonus/textures/shooting_xpm/shooting3.xpm",
		"cub_bonus/textures/shooting_xpm/shooting4.xpm",
		"cub_bonus/textures/shooting_xpm/shooting5.xpm",
	};

	i = 0;
	while (i < 5)
	{
		data->weapon.shooting[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				textures[i], &data->weapon.shooting[i].width,
				&data->weapon.shooting[i].height);
		if (data->weapon.shooting[i].img_ptr == NULL)
			printf("Error\nShooting frame %d img_ptr failed\n", i);
		data->weapon.shooting[i].pxl_ptr = mlx_get_data_addr(
				data->weapon.shooting[i].img_ptr,
				&data->weapon.shooting[i].b_p_p,
				&data->weapon.shooting[i].line_len,
				&data->weapon.shooting[i].endian);
		i++;
	}
}
