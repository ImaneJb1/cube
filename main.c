/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/08/01 15:get_heigth(data->map):37 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/12 12:09:19 by nel-khad         ###   ########.fr       */
=======
/*   Created: 2025/08/01 15:12:37 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/12 14:20:30 by ijoubair         ###   ########.fr       */
>>>>>>> imane
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
	if (keysym == XK_Left && !is_wall(data->map, (data->player_x - 10) / SQUARESIZE, (data->player_y) / SQUARESIZE))
		data->player_x -= 10;
	if (keysym == XK_Right && !is_wall(data->map, (data->player_x + 10) / SQUARESIZE, (data->player_y) / SQUARESIZE))
		data->player_x += 10;
	if (keysym == XK_Up && !is_wall(data->map, (data->player_x) / SQUARESIZE, (data->player_y - 10) / SQUARESIZE))
		data->player_y -= 10;
	if (keysym == XK_Down && !is_wall(data->map, (data->player_x) / SQUARESIZE, (data->player_y + 10) / SQUARESIZE))
		data->player_y += 10; 
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
	
	int y = data->player_y - radius;
	while (y <= data->player_y + radius)
	{
		int x = data->player_x - radius;
		while (x <= data->player_x + radius)
		{
			dx = x - data->player_x;
			dy = y - data->player_y;
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

	printf("salam %s\n",data->map[0]);
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if(data->map[i][j] == '1')
				color = 0x000000;
			else
				color = 0xffffff;
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

// void ray_casting(data)
// {

// }

void randring_(t_data *data)
{
	rander_map(data);
	put_player(data);
	// ray_casting(data);
}

void init_player(t_data *data, char *map[])
{
	int i;
	int j;
	int color;
	
	i = 0;
	j = 0;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			
			if(data->map[i][j] == 'P')
			{
				data->player_x = (j * SQUARESIZE + SQUARESIZE / 2);
				data->player_y = (i * SQUARESIZE + SQUARESIZE / 2);
				// data->map[i][j] = '0';//distroy img
				return;
			}
			j++;
		}
		i++;
	}
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

int get_width(char *map[])
{
	int i;
	i = 0;
	
	while(map[0][i])
	{
		i++;
	}
	return(i);
}

void data_init(t_data *data)
{
	static char *map[] = {
    "111111111111111111",
    "100000000010000001",
    "100011110001111001",
    "10000000P000000001",
    "101111011111011101",
    "100000010000010001",
    "111101111011110111",
    "100100000000000001",
    "101111111111110101",
    "100000000000000001",
    "111111111111111111",
    NULL
	};

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	exit(1);
	data->map = map;
	data->mlx_win = mlx_new_window(data->mlx_ptr, get_width(data->map) * SQUARESIZE, get_heigth(data->map) * SQUARESIZE, "noussa");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, get_width(data->map) * SQUARESIZE, get_heigth(data->map) * SQUARESIZE);
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
		&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	init_player(data, map);
	randring_(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
}



int main(int argc, char **argv)
{
<<<<<<< HEAD
	t_data data;
	
	data_init(&data);
	
	hook_init(&data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

=======
	textures *txt;

	if(!check_argv(argc, argv))
		return 0;
	if(!fill_textures_map(argv[1]))
	{
		free_all();
		return 0;
	}// it creates the map array
	check_textures(); // this exits the program in case of faillure 
	parse_map(); // this exits the program in case of faillure
	free_all();
	get_next_line(-1);
	//debuging
	// txt = (*text_func());
	// if(txt == NULL)
	// {
	// 	printf("NULL\n");
	// 	return 0;
	// }
	// printf("no = %s\n", txt->no);
	// printf("so = %s\n", txt->so);
	// printf("ea = %s\n", txt->ea);
	// printf("we = %s\n", txt->we);
	// printf("f = %s\n", txt->f);
	// printf("c = %s\n", txt->c);
>>>>>>> imane
	return 0;
}
