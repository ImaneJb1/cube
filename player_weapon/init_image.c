/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:25:43 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/27 15:16:04 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	init_walking(char *textures[], int size,t_frame (*frame)[22], t_data *data)
{
	int i = 0;
	while(i < size)
	{
		(*frame)[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, textures[i], &(*frame)[i].width, &(*frame)[i].height);
		(*frame)[i].pxl_ptr = mlx_get_data_addr((*frame)[i].img_ptr, &(*frame)[i].b_p_p, &(*frame)[i].line_len, &(*frame)[i].endian);
		i++;
	}
}

void	init_intro(char *textures[], int size,t_frame (*frame)[20], t_data *data)
{
	int i = 0;
	while(i < size)
	{
		(*frame)[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, textures[i], &(*frame)[i].width, &(*frame)[i].height);
		(*frame)[i].pxl_ptr = mlx_get_data_addr((*frame)[i].img_ptr, &(*frame)[i].b_p_p, &(*frame)[i].line_len, &(*frame)[i].endian);
		i++;
	}
}

void	init_weapon_intro(t_data *data)
{
	static char *intro_textures[20] = {
	"textures/intro_xpm/gun1.xpm",
	"textures/intro_xpm/gun2.xpm",
	"textures/intro_xpm/gun3.xpm",
	"textures/intro_xpm/gun4.xpm",
	"textures/intro_xpm/gun5.xpm",
	"textures/intro_xpm/gun6.xpm",
	"textures/intro_xpm/gun7.xpm",
	"textures/intro_xpm/gun8.xpm",
	"textures/intro_xpm/gun9.xpm",
	"textures/intro_xpm/gun10.xpm",
	"textures/intro_xpm/gun11.xpm",
	"textures/intro_xpm/gun12.xpm",
	"textures/intro_xpm/gun13.xpm",
	"textures/intro_xpm/gun14.xpm",
	"textures/intro_xpm/gun15.xpm",
	"textures/intro_xpm/gun16.xpm",
	"textures/intro_xpm/gun17.xpm",
	"textures/intro_xpm/gun18.xpm",
	"textures/intro_xpm/gun19.xpm",
	"textures/intro_xpm/gun20.xpm"
    };
	init_intro(intro_textures, 20, &data->weapon.intro, data);
}

void init_weapon_walking(t_data *data)
{
    static char *walking_textures[20] = {
        "textures/walking_xpm/gun24.xpm",
        "textures/walking_xpm/gun25.xpm",
        "textures/walking_xpm/gun26.xpm",
        "textures/walking_xpm/gun27.xpm",
        "textures/walking_xpm/gun28.xpm",
        "textures/walking_xpm/gun29.xpm",
        "textures/walking_xpm/gun30.xpm",
        "textures/walking_xpm/gun31.xpm",
        "textures/walking_xpm/gun32.xpm",
        "textures/walking_xpm/gun33.xpm",
        "textures/walking_xpm/gun34.xpm",
        "textures/walking_xpm/gun35.xpm",
        "textures/walking_xpm/gun36.xpm",
        "textures/walking_xpm/gun37.xpm",
        "textures/walking_xpm/gun38.xpm",
        "textures/walking_xpm/gun39.xpm",
        "textures/walking_xpm/gun40.xpm",
        "textures/walking_xpm/gun41.xpm",
        "textures/walking_xpm/gun42.xpm",
        "textures/walking_xpm/gun43.xpm"
    };
	init_walking(walking_textures, 20, &data->weapon.walking, data);
}

void init_weapon_shooting(t_data *data)
{
    static char *textures[11] = {
        "textures/shooting_xpm/shooting1.xpm",
        "textures/shooting_xpm/shooting2.xpm",
        "textures/shooting_xpm/shooting3.xpm",
        "textures/shooting_xpm/shooting4.xpm",
        "textures/shooting_xpm/shooting5.xpm",
        "textures/shooting_xpm/shooting6.xpm",
        "textures/shooting_xpm/shooting7.xpm",
        "textures/shooting_xpm/shooting8.xpm",
        "textures/shooting_xpm/shooting9.xpm",
        "textures/shooting_xpm/shooting10.xpm",
        "textures/shooting_xpm/shooting11.xpm"
    };
    int i = 0;
	
    while (i < 11)
    {
        data->weapon.shooting[i].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,textures[i],&data->weapon.shooting[i].width,&data->weapon.shooting[i].height);
		data->weapon.shooting[i].pxl_ptr = mlx_get_data_addr(data->weapon.shooting[i].img_ptr,
			&data->weapon.shooting[i].b_p_p,&data->weapon.shooting[i].line_len,&data->weapon.shooting[i].endian);
        i++;
    }
}


