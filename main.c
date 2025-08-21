/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:get_heigth(data->map):37 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/12 12:09:19 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int is_wall(char *map[], int j, int i)
{
	if(i < 0 || j < 0 || !map[i] || !map[i][j] || map[i][j] == '1')
		return(1);
	return(0);
}
void	wich_key(int keysym, t_data *data)
{
	printf("1 -- %f\n",data->player.vew_angle);
	if (keysym == XK_Left)
		data->player.vew_angle += -(data->player.rot_speed);
	if (keysym == XK_Right)
		data->player.vew_angle += (data->player.rot_speed);
	if (keysym == XK_Up && !is_wall(data->map, (data->player.player_x) / SQUARESIZE, (data->player.player_y - 2) / SQUARESIZE))
		data->player.player_y -= 1;
	if (keysym == XK_Down && !is_wall(data->map, (data->player.player_x) / SQUARESIZE, (data->player.player_y + 2) / SQUARESIZE))
		data->player.player_y += 1;
	printf("2 -- %f\n",data->player.vew_angle);
	printf("3 -- %f\n",data->player.rot_speed);
}

int	press_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		press_x(data);
	}
	else
	{
		wich_key(keysym,data);
	}
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr,  get_width(data->map) * SQUARESIZE, get_heigth(data->map) * SQUARESIZE);
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	randring_(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	return (0);
}

int press_x(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return(0);
}

void	hook_init(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
	// mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, press_mouse, data);
	mlx_hook(data->mlx_win, DestroyNotify, 0, press_x, data);
}

void img_pixel_put(t_data *data, t_img *img, int x, int y, int color)
{
	int offset;
	if (x < 0 || y < 0 || x >= get_width(data->map) * SQUARESIZE || y >= get_heigth(data->map) * SQUARESIZE)
        return;
	offset = (img->line_len * y) + (x * (img->b_p_p / 8));
	*((unsigned int *)(img->img_pxl_ptr + offset)) = color;
}

void draw_circle(t_data *data, int color)
{
	int radius;
	int dx;
	int dy;
	radius = 4;
	
	int y = data->player.player_y - radius;
	while (y <= data->player.player_y + radius)
	{
		int x = data->player.player_x - radius;
		while (x <= data->player.player_x + radius)
		{
			dx = x - data->player.player_x;
			dy = y - data->player.player_y;
			if (dx*dx + dy*dy <= radius*radius)//chack if the point inside
				img_pixel_put(data, &data->img, x, y, color);
			x++; 
		}
		y++;
	}

}

void draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	j = 0;
	i = 0;
	
	while(i < SQUARESIZE - 1)
	{
		j = 0;
		while(j < SQUARESIZE - 1)
		{
			img_pixel_put(data, &data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void rander_map(t_data *data)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	color = -1;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if(data->map[i][j] == '1')
				color = 0x1A1033;
			else if(data->map[i][j] == '0')
				color = 0xffffff;
			if(color > 0)
				draw_square(data, j * SQUARESIZE, i * SQUARESIZE, color);
			j++;
		}
		i++;
	}
}

void put_player(t_data *data)
{
	draw_circle(data, 0xFF69B4);
}

int absolute_value(int value)
{
	if(value < 0)
		return(-value);
	return(value);
}

void draw_vertic(t_data *data, int x1, int y1)
{
	int dx;
	int dy;
	int move_x;
	int move_y;
	int D;
	int i;
	int x;
	int y;

	i = 0;
	move_x = 1;
	move_y = 1;
	x = data->player.player_x;
	y = data->player.player_y;
	dx = absolute_value(x1 - x);
	dy = absolute_value(y1 - y);
	if(x1 < data->player.player_x)
		move_x = -1;
	if(y1 < data->player.player_y)
		move_y = -1;
	D = 2*dx - dy;
	while(x != x1 || y != y1)
	{
		img_pixel_put(data, &data->img,x, y, 0xFF69B4);
		if(D >= 0)
		{
			x += move_x;
			D = D - 2*dy;
		}
		y += move_y;
		D = D + 2*dx;
	}
}
void draw_horiz(t_data *data, int x1, int y1)
{
	int dx;
	int dy;
	int move_x;
	int move_y;
	int D;
	int i;
	int x;
	int y;

	i = 0;
	move_x = 1;
	move_y = 1;
	x = data->player.player_x;
	y = data->player.player_y;
	dx = absolute_value(x1 - x);
	dy = absolute_value(y1 - y);
	if(x1 < data->player.player_x)
		move_x = -1;
	if(y1 < data->player.player_y)
		move_y = -1;
	D = 2*dy - dx;
	while(i <= dx)
	{
		img_pixel_put(data, &data->img,x, y, 0xFF69B4);
		if(D >= 0)
		{
			y += move_y;
			D = D - 2*dx;
		}
		x += move_x;
		D = D + 2*dy;
		i++;
	}
}

void bresenhams(t_data *data, int x, int y)
{
	int dx;
	int dy;

	dx = absolute_value(x - data->player.player_x);
	dy = absolute_value(y - data->player.player_y);
	if(dx >= dy)
	{
		draw_horiz(data, x, y);
	}
	else
		draw_vertic(data, x, y);
}

void ray_casting(t_data *data)
{
	int x;
	int y;

	x = data->player.player_x;
	y = data->player.player_y;
	bresenhams(data, x + cos(data->player.vew_angle) * 100, y + sin(data->player.vew_angle) * 100);
}

void randring_(t_data *data)
{
	rander_map(data);
	put_player(data);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
}

int get_width(char *map[])
{
	int i;
	int j;
	int l;
	i = 0;
	j = 0;
	l = 0;

	while(map[j])
	{
		i = 0;
		while(map[j][i])
		{
			i++;
		}
		if(i > l)
			l = i;
		j++;
	}
	return(l);
}

int get_heigth(char *map[])
{
	int i;
	i = 0;
	
	while(map[i])
	{
		i++;
	}
	return(i);
}
void init_player(t_data *data)
{
	data->player.move_speed = 4;
	data->player.rot_speed = 3 * (M_PI / 180);//3 degres every rotation
	if(data->player.direction == 'N')
		data->player.vew_angle = 270 * (M_PI / 180);
	if(data->player.direction == 'E')
		data->player.vew_angle = 0;
	if(data->player.direction == 'S')
		data->player.vew_angle = 90 * (M_PI / 180);
	if(data->player.direction == 'W')
		data->player.vew_angle = 180 * (M_PI / 180);
}

void data_init(t_data *data)
{
	static char **map;
	map = *the_map();

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(1);
	data->map = map;
	data->mlx_win = mlx_new_window(data->mlx_ptr, get_width(data->map) * SQUARESIZE, get_heigth(data->map) * SQUARESIZE, "cub3d");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, get_width(data->map) * SQUARESIZE, get_heigth(data->map) * SQUARESIZE);
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
		&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	init_player(data);

}



int main(int argc, char **argv)
{
	t_data *data;

	data = data_func();
	// textures *txt;

	printf("wassssaaaaaaaaaaaaalaaaaaaaaaam\n");
	if(!check_argv(argc, argv))
		return 0;
	if(!fill_textures_map(argv[1]))
	{
		free_all();
		return 0;
	}// it creates the map array
	check_textures(); // this exits the program in case of faillure 
	parse_map(); // this exits the program in case of faillure
	data_init(data);
	randring_(data);
	hook_init(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	
	free_all();
	get_next_line(-1);
	return 0;
}
