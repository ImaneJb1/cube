/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weapon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:21:28 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/27 15:46:22 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	init_first_person(t_data *data)
{
	init_weapon_intro(data);
	init_weapon_walking(data);
	init_weapon_shooting(data);
}

void	put_frame(t_data *data, t_frame frame)
{
	int (x), (y);
	int (img_x), (img_y);
	int x_img_end, color;

	x_img_end = WIDTH / 2 + frame.width / 2;
	x = WIDTH / 2 -	frame.width / 2;
	img_x = 0;
	int i = 0;
	while(x < x_img_end)
	{
		printf("lpp %d\n", i);
		i++;
		img_y = 0;
		y = HEIGHT - frame.height;
		while(y != HEIGHT)
		{
			color = *(int *)(frame.pxl_ptr + (img_y * frame.line_len) + (img_x * (frame.b_p_p / 8)));
			if((color & 0x00FFFFFF) != 0x000000)
				my_img_pixel_put(data, &data->img, x, y, color);						
			y++;
			img_y++;
		}
		x++;
		img_x++;
	}
}

// void	draw_first_person(t_data *data, t_frame *frames, int size)
// {
// 	static int i = 0; 
// 	if(i > size || i < 0)
// 		i = 0;
// 	printf("i = %d\n",i);
// 	// mlx_clear_window(data->mlx_ptr, data->mlx_win);
// 	usleep(600);
// 	put_frame(data, frames[i]);
// 	i++;
// 	// draw_first_person(data, data->weapon.walking, 22);
// }

void draw_first_person(t_data *data, t_frame *frames, int size)
{
    static int frame_index = 0;
    static int counter = 0;
    int animation_speed = 5; 
// adjust to slow down animation

    // Clear before drawing new frame
    // mlx_clear_window(data->mlx_ptr, data->mlx_win);

    // Draw current frame
	printf("%d\n", frame_index);
    put_frame(data, frames[frame_index]);

    // Control speed of animation
    counter++;
    if (counter >= animation_speed)
    {
        frame_index = (frame_index + 1) % size;
        counter = 0;
    }
}

