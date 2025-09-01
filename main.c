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

int is_wall(t_data *data, char *map[], double x, double y)
{
	int grid_x;
	int grid_y;

	if(data->ray.is_up && ((int) y) % SQUARESIZE == 0)//set on lhafa dyal square wich is wall   mataaaaaalan : y = 64 and tilesize = 32 -> grid_y = 2 -> map[2] ou ana bagha map[1]
		y -= 1;
	if(data->ray.is_left && ((int) x) % SQUARESIZE == 0)
		x -= 1;
	grid_x = floor(x / SQUARESIZE);
	grid_y = floor(y / SQUARESIZE);
	if(grid_x < 0 || grid_y < 0 || grid_x >= data->width || grid_y >= data->heigth || map[grid_y][grid_x] == '1')
		return(1);
	return(0);
}

double normlizing(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	while(angle <= 0)
	{
		angle += (2 * M_PI);
	}
	// while(angle > (2 * M_PI))
	// {
	// 	angle -= (2 * M_PI);
	// }
	return(angle); 
}

void update_player(t_data *data)
{
	int move_step;
	double next_x;
	double next_y;

	move_step = data->p.move_dir * data->p.move_speed;
	data->p.view_angle += data->p.rot_dir * data->p.rot_speed;
	data->p.view_angle = normlizing(data->p.view_angle);
	next_x = data->p.p_x + cos(data->p.view_angle) * data->p.move_dir * data->p.move_speed;
	next_y = data->p.p_y + sin(data->p.view_angle) * data->p.move_dir * data->p.move_speed;
	if(!is_wall(data, data->map, next_x, next_y)) //naxt_x *1.5 
	{
		data->p.p_y = next_y;
		data->p.p_x = next_x;
	}
}

void reset(t_data *data)
{
	data->p.move_dir = 0;
	data->p.rot_dir = 0;
}
void	which_key(int keysym, t_data *data)
{
	if(keysym == XK_Right)
		data->p.rot_dir = 1;
	if(keysym == XK_Left)
		data->p.rot_dir = -1;
	if(keysym == XK_Up)
		data->p.move_dir = 1;
	if(keysym == XK_Down)
		data->p.move_dir = -1;
}

int	press_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		press_x(data);
	else
		which_key(keysym,data);
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

int release_key(int keysem, t_data *data)
{
	if(keysem == XK_Up || keysem == XK_Down)
		data->p.move_dir = 0;
	if(keysem == XK_Right || keysem == XK_Left)
		data->p.rot_dir = 0;
	return(0);
}

int moves_loop(t_data *data)
{
	update_player(data);
	rendring_(data);
	return(0);
}

void	hook_init(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
	// mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, press_mouse, data);
	mlx_hook(data->mlx_win, DestroyNotify, 0, press_x, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, release_key, data);
	mlx_loop_hook(data->mlx_ptr, moves_loop, data);
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
	
	int y = data->p.p_y - radius;
	while (y <= data->p.p_y + radius)
	{
		int x = data->p.p_x - radius;
		while (x <= data->p.p_x + radius)
		{
			dx = x - data->p.p_x;
			dy = y - data->p.p_y;
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

	while(i < SQUARESIZE)
	{
		j = 0;
		while(j < SQUARESIZE)
		{
			// if(j == SQUARESIZE - 1 || i == SQUARESIZE -1 || i == 0 || j == 0)
			// 	img_pixel_put(data, &data->img, x + j, y + i, 0x000000);
			// else
				img_pixel_put(data, &data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void render_map(t_data *data)
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
	x = data->p.p_x;
	y = data->p.p_y;
	dx = absolute_value(x1 - x);
	dy = absolute_value(y1 - y);
	if(x1 < data->p.p_x)
		move_x = -1;
	if(y1 < data->p.p_y)
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
	x = data->p.p_x;
	y = data->p.p_y;
	dx = absolute_value(x1 - x);
	dy = absolute_value(y1 - y);
	if(x1 < data->p.p_x)
		move_x = -1;
	if(y1 < data->p.p_y)
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

void bresenhams(t_data *data, double x, double y)
{
	double dx;
	double dy;

	dx = fabs(x - data->p.p_x);
	dy = fabs(y - data->p.p_y);
	if(dx >= dy)
	{
		draw_horiz(data, x, y);
	}
	else
		draw_vertic(data, x, y);
}

void cast_ray(t_data *data, double rayangle)
{
	printf(" playerangle %f, rayangle %f\n",data->p.view_angle, rayangle);
	// if(data->ray.hit_vertical)
	// 	bresenhams(data, floor(data->ray.ver_walhit_x), floor(data->ray.ver_walhit_y));
	// else
	// 	bresenhams(data, floor(data->ray.hor_walhit_x), floor(data->ray.hor_walhit_y));
	// bresenhams(data, data->p.p_x + cos(rayangle) * 50, data->p.p_y + sin(rayangle) * 50);
	bresenhams(data, floor(data->ray.walhit_x), floor(data->ray.walhit_y));
}

// void find_vertic_inters(t_data *data, double angle)
// {
// 	double first_inters_x;
// 	double first_inters_y;
// 	double ya;
// 	double xa;

// 	angle = tan(angle);
// 	if(data->ray.is_up)
// 		first_inters_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE - 1;
// 	else if(data->ray.is_down)
// 		first_inters_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE + SQUARESIZE;
// 	else
// 		return;
// 	if(fabs(angle) <= 1e-6)
// 		return;
// 	first_inters_x = ((first_inters_y - data->p.p_y) / angle + data->p.p_x);
// 	data->ray.ver_walhit_x = first_inters_x;
// 	data->ray.ver_walhit_y = first_inters_y;
// 	// finding Ya and Xa
// 	if(data->ray.is_up)
// 		ya = -SQUARESIZE;
// 	if(data->ray.is_down)
// 		ya = SQUARESIZE;
// 	xa = ya / angle;
// 	while(data->ray.ver_walhit_x <= data->width * SQUARESIZE && data->ray.ver_walhit_x >= 0 && data->ray.ver_walhit_y <= data->heigth * SQUARESIZE && data->ray.ver_walhit_y >= 0)
// 	{
// 		if(is_wall(data, data->map, data->ray.ver_walhit_x, data->ray.ver_walhit_y))
// 		{
// 			data->ray.hit_vertical = 1;
// 			break;
// 		}
// 		else
// 		{
// 			data->ray.ver_walhit_x += xa;
// 			data->ray.ver_walhit_y += ya;
// 			// printf("xa = %f ya = %f\n", xa,ya);
// 		}
// 	}
// }

// int find_inters(double first_x, double first_y, double tan_angle)
// {
// 	double xa;
// 	double ya;
// 	t_data *data;

// 	data = data_func();
// 	printf("left = %d   right = %d \n", data->ray.is_left,data->ray.is_right);
// 	if(data->ray.is_left)
// 		xa = -SQUARESIZE;
// 	else if(data->ray.is_right)
// 		xa = SQUARESIZE;
// 	else 
// 		return(1);
// 	if (fabs(cos(data->ray.rayangle)) < 1e-6)
//     	return(1);	
// 	ya = xa * tan_angle;
// 	while(data->ray.hor_walhit_x <= data->width * SQUARESIZE && data->ray.hor_walhit_x >= 0 && data->ray.hor_walhit_y <= data->heigth * SQUARESIZE && data->ray.hor_walhit_y >= 0)
// 	{
// 		if(is_wall(data, data->map, data->ray.hor_walhit_x, data->ray.hor_walhit_y))
// 		{
// 			data->ray.hit_horiz = 1;
// 			break;
// 		}
// 		else
// 		{
// 			data->ray.hor_walhit_x += xa;
// 			data->ray.hor_walhit_y += ya;
// 			// printf("xa = %f ya = %f\n", xa,ya);
// 		}
// 	}
// 	return(0);
// }



// int find_hor_inter(t_data *data, double rayangle)
// {
// 	int first_int_x;
// 	int first_int_y;
// 	int ya;
// 	int xa;
// 	int next_x;
// 	int next_y;


// 	if(fabs(cos(rayangle)) == 0)
// 		return 0;
// 	if(data->ray.is_down)
// 		first_int_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE + SQUARESIZE;
// 	else if(data->ray.is_up)
// 		first_int_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE - 1;
// 	first_int_x = (first_int_y - data->p.p_y) * tan(rayangle) + data->p.p_x;
// 	next_x = first_int_x;
// 	next_y = first_int_y;
// 	if(data->ray.is_down)
// 		ya = SQUARESIZE;
// 	else if(data->ray.is_up)
// 		ya = -SQUARESIZE;
// 	xa = ya / tan(rayangle);
// 	while(next_x <= data->width * SQUARESIZE && next_x >= 0 && next_y <= data->heigth * SQUARESIZE && next_y >= 0)
// 	{
// 		if (is_wall(data, data->map, next_x, next_y))
// 		{
// 			data->ray.hit_horiz = 1;
// 			data->ray.hor_walhit_x = next_x;
// 			data->ray.hor_walhit_y = next_y;
// 			break;
// 		}
// 		else
// 			next_x += xa;
// 			next_y += ya;
// 	}
// 	return(0);
// }

double calculate_distance(t_data *data, int x_d , int y_d)
{
	double dx;
	double dy;

	dx = x_d - data->p.p_x;
	dy = y_d - data->p.p_y;
	return(sqrt(dx * dx + dy * dy));
}

// void get_distance(t_data *data)
// {
// 	int hor_distance;
// 	int ver_distance;

// 	if(data->ray.hit_horiz)
// 		hor_distance = calculate_distance(data, data->ray.hor_walhit_x, data->ray.hor_walhit_y);
// 	else if(data->ray.hit_vertical)
// 		ver_distance = calculate_distance(data, data->ray.ver_walhit_x, data->ray.ver_walhit_y);
// 	data->ray.distance = ver_distance;
// 	if(ver_distance > hor_distance)
// 		data->ray.distance = hor_distance;
// }

// void cast_allrays(t_data *data)
// {
// 	double rayangle;
// 	int i;


// 	i = 0;
// 	rayangle = normlizing(data->p.view_angle - (FOV / 2));
// 	while(i < NUM_RAYS)
// 	{
// 		data->ray.rayangle = rayangle;
// 		if(rayangle >= 0 && rayangle <= M_PI)
// 			data->ray.is_down = 1;
// 		data->ray.is_up = !data->ray.is_down;
// 		if(rayangle < 0.5 * M_PI || rayangle > M_PI * 1.5)
// 			data->ray.is_right = 1;
// 		data->ray.is_left = !data->ray.is_right;
// 		printf("up %d down %d\n", data->ray.is_up, data->ray.distance);
// 		find_vertic_inters(data, rayangle);
// 		// find_hor_inter(data, rayangle);
// 		cast_ray(data, rayangle);
// 		get_distance(data);
// 		init_ray(data);
// 		rayangle += (FOV / NUM_RAYS);
// 		rayangle = normlizing(rayangle);
// 		i++;
// 	}
// }

void ray_direction(t_data *data, double rayangle)
{
	data->ray.rayangle = rayangle;
	if(rayangle > 0 && rayangle < M_PI)
		data->ray.is_down = 1;
	data->ray.is_up = !data->ray.is_down;
	if(rayangle < 0.5 * M_PI || rayangle > M_PI * 1.5)
		data->ray.is_right = 1;
	data->ray.is_left = !data->ray.is_right;
}

double find_hor_inter(t_data *data, double rayangle)
{
	double first_int_x;
	double first_int_y;
	double ya;
	double xa;
	double next_x;
	double next_y;

	// if (fabs(cos(rayangle)) < 1e-6)
	// 	return INT_MAX;
	if(data->ray.is_down)
		first_int_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE + SQUARESIZE;
	else if(data->ray.is_up)
		first_int_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE;
	first_int_x = data->p.p_x + (first_int_y - data->p.p_y) / tan(rayangle);
	next_x = first_int_x;
	next_y = first_int_y;
	data->ray.hor_walhit_x = first_int_x;
	data->ray.hor_walhit_y = first_int_y;
	if(data->ray.is_down)
		ya = SQUARESIZE;
	else if(data->ray.is_up)
		ya = -SQUARESIZE;
	xa = SQUARESIZE / tan(rayangle);
	if(data->ray.is_left && xa > 0)
		xa *= -1;
	if(data->ray.is_right && xa < 0)
		xa *= -1;
	while(next_x <= data->width * SQUARESIZE && next_x >= 0 && next_y <= data->heigth * SQUARESIZE && next_y >= 0)
	{
		if (is_wall(data, data->map, next_x, next_y))
		{
			data->ray.hit_horiz = 1;
			data->ray.hor_walhit_x = next_x;
			data->ray.hor_walhit_y = next_y;
			break;
		}
		else
		{
			next_x += xa;
			next_y += ya;
		}
	}
	return(calculate_distance(data, data->ray.hor_walhit_x, data->ray.hor_walhit_y));
}

double find_ver_inter(t_data *data, double rayangle)
{
	double first_int_x;
	double first_int_y;
	double ya;
	double xa;
	double next_x;
	double next_y;

	// if (fabs(sin(rayangle)) < 1e-6)
	// 	return INT_MAX;
	if(data->ray.is_right)
		first_int_x = floor(data->p.p_x / SQUARESIZE) * SQUARESIZE + SQUARESIZE;
	else if(data->ray.is_left)
		first_int_x = floor(data->p.p_x / SQUARESIZE) * SQUARESIZE;
	first_int_y = data->p.p_y + (first_int_x - data->p.p_x) * tan(rayangle);
	next_x = first_int_x;
	next_y = first_int_y;
	if(data->ray.is_right)
		xa = SQUARESIZE;
	else if(data->ray.is_left)
		xa = -SQUARESIZE;
	ya = SQUARESIZE * tan(rayangle);
	if(data->ray.is_up && ya > 0)
		ya *= -1;
	if(data->ray.is_down && ya < 0)
		ya *= -1;
	while(next_x <= data->width * SQUARESIZE && next_x >= 0 && next_y <= data->heigth * SQUARESIZE && next_y >= 0)
	{
		if (is_wall(data, data->map, next_x, next_y))
		{
			data->ray.hit_vertical = 1;
			data->ray.ver_walhit_x = next_x;
			data->ray.ver_walhit_y = next_y;
			printf("ver wall x  = %f, y = %f", data->ray.ver_walhit_x, data->ray.ver_walhit_y);
			break;
		}
		else
		{
			next_x += xa;
			next_y += ya;
		}
	}
	return(calculate_distance(data, data->ray.ver_walhit_x, data->ray.ver_walhit_y));
}


void cast_allrays(t_data *data)
{
	double rayangle;
	int hor_distance;
	int ver_distance;
	int i;

	i = 0;
	rayangle = normlizing(data->p.view_angle - (FOV / 2));
	hor_distance = INT_MAX;
	ver_distance = INT_MAX;
	while(i < NUM_RAYS)
	{
		ray_direction(data, rayangle);
		printf("is down %d is up %d is left %d is right %d\n", data->ray.is_down,data->ray.is_up, data->ray.is_left, data->ray.is_right);
		hor_distance = find_hor_inter(data, rayangle);
		ver_distance = find_ver_inter(data, rayangle);
		if(hor_distance > ver_distance)
		{
			data->ray.walhit_x = data->ray.ver_walhit_x;
			data->ray.walhit_y = data->ray.ver_walhit_y;
		}
		else if(hor_distance < ver_distance)
		{
			data->ray.walhit_x = data->ray.hor_walhit_x;
			data->ray.walhit_y = data->ray.hor_walhit_y;
		}
		else{
			data->ray.walhit_x = data->p.p_x;
			data->ray.walhit_y = data->p.p_y;
		}
		printf("wallhit x = %f, wallhit y = %f", data->ray.walhit_x, data->ray.walhit_y);
		cast_ray(data, rayangle);
		init_ray(data);
		rayangle = normlizing(rayangle + (FOV / NUM_RAYS));
		i++;
	}
}

void rendring_(t_data *data)
{
	render_map(data);
	put_player(data);
	cast_allrays(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	mlx_do_sync(data->mlx_ptr);
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
	data->p.move_speed = 4;
	data->p.move_dir = 0;
	data->p.rot_dir = 0;
	data->p.rot_speed = 3 * (M_PI / 180);//3 degres every rotation
	if(data->p.direction == 'N')
		data->p.view_angle = 270 * (M_PI / 180);
	if(data->p.direction == 'E')
		data->p.view_angle = 0;
	if(data->p.direction == 'S')
		data->p.view_angle = 90 * (M_PI / 180);
	if(data->p.direction == 'W')
		data->p.view_angle = 180 * (M_PI / 180);
}

void init_ray(t_data *data)
{
	data->ray.distance = 0;
	data->ray.is_down = 0;
	data->ray.is_up = 0;
	data->ray.is_right = 0;
	data->ray.is_left = 0;
	data->ray.ver_walhit_x = 0;
	data->ray.ver_walhit_y = 0;
	data->ray.hor_walhit_x = 0;
	data->ray.hor_walhit_y = 0;
	data->ray.walhit_x = data->p.p_x;
	data->ray.walhit_y = data->p.p_y;
	data->ray.hit_vertical = 0;
	data->ray.hit_horiz = 0;
	data->ray.wall_content = 0;

}

void data_init(t_data *data)
{
	static char **map;
	map = *the_map();

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(1);
	data->map = map;
	data->width = get_width(data->map);
	data->heigth = get_heigth(data->map);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->width * SQUARESIZE, data->heigth * SQUARESIZE, "cub3d");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->width * SQUARESIZE, data->heigth * SQUARESIZE);
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
		&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	init_player(data);
	init_ray(data);
	rendring_(data);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = data_func();
	// textures *txt;

	// printf("wassssaaaaaaaaaaaaalaaaaaaaaaam\n");
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
	hook_init(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	
	free_all();
	get_next_line(-1);
	return 0;
}
