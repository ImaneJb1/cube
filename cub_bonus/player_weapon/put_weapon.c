/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weapon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:21:28 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/01 20:33:37 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"


void	init_first_person(t_data *data)
{
	init_weapon_intro(data);
	init_weapon_walking(data);
	init_weapon_shooting(data);
}

int get_color(int x, int y, t_frame *frame)
{
	if (!frame->pxl_ptr)
    {
        printf("ERROR: frame->pxl_ptr is NULL!\n");
        return 0; // or some default color
    }
    if (x < 0 || x >= frame->width || y < 0 || y >= frame->height)
    {
        printf("ERROR: x or y out of bounds! x=%d, y=%d, width= %d height= %d\n", x, y, frame->width, frame->height);
        exit(1);
    }
    return *(int *)(frame->pxl_ptr + (y * frame->line_len) + (x * (frame->b_p_p / 8)));
}

void	put_frame(t_data *data, t_frame *frame)
{
	int (x), (y);
	int (img_x), (img_y);
	int x_img_end, color;

	x_img_end = WIDTH / 2 + frame->width / 2;
	x = WIDTH / 2 -	frame->width / 2;
	img_x = 0;
	while(x < x_img_end)
	{
		img_y = 0;
		y = HEIGHT - frame->height;
		while(y < HEIGHT)
		{
			if (img_x >= frame->width || img_y >= frame->height)
    			break;
			color = get_color(img_x, img_y, frame);
			if (color != 0xFF000000 && color != 0x00000000)  // skip transparent (pure black)
					my_img_pixel_put(data, &data->img, x, y, color);
			y++;
			img_y++;
		}
		x++;
		img_x++;
	}
}

void	draw_first_person_intro(t_data *data, t_frame *frames, int size)
{
	static int i = 0; 
	if(i >= size || i < 0)
	{
		put_frame(data, &frames[19]);
		return;
	}
	usleep(2000);
	if (frames == NULL)
		return;
	put_frame(data, &frames[i]);
	i++;
}

void	draw_first_person_walking(t_data *data, t_frame *frames, int size)
{
	static int i = 0; 
	if(i >= size || i < 0)
		i = 0;
	usleep(10000);
	if (frames == NULL)
		return;
	put_frame(data, &frames[i]);
	i++;
}
