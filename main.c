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

int is_wall(t_data *data, char *map[], double x, double y, char c)
{
	int grid_x;
	int grid_y;

	if(c == 'h' && data->ray.is_up )//set on lhafa dyal square wich is wall   mataaaaaalan : y = 64 and tilesize = 32 -> grid_y = 2 -> map[2] ou ana bagha map[1]
		y -= 1;
	if(c == 'v' && data->ray.is_left )
		x -= 1;
	grid_x = floor(x / SQUARESIZE);
	grid_y = floor(y / SQUARESIZE);
	if(grid_x < 0 || grid_y < 0 || grid_x >= data->width || grid_y >= data->heigth)
		return(1);
	if(map[grid_y][grid_x] == '1')
		return(1);
	return(0);
}
	// cub->player.current_ray_angle = fmod(cub->player.current_ray_angle, 2 * PI);
	// if (cub->player.current_ray_angle < 0)
	// 	cub->player.current_ray_angle += 2 * PI;
		
double normlizing(double angle)
{
	// angle = fmod(angle, 2 * M_PI);
	while(angle < 0)
	{
		angle += (2 * M_PI);
	}
	while(angle > (2 * M_PI))
	{
		angle -= (2 * M_PI);
	}
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

	next_x = data->p.p_x + (cos(data->p.view_angle) * data->p.move_dir * data->p.move_speed) + data->p.step_x;
	next_y = data->p.p_y + (sin(data->p.view_angle) * data->p.move_dir * data->p.move_speed) + data->p.step_y;
	if(!is_wall(data, data->map, next_x, next_y, 'n')) //next_x *1.5 
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
void	which_key(int keysem, t_data *data)
{
	if(keysem == XK_Right)
		data->p.rot_dir = 1;
	if(keysem == XK_Left)
		data->p.rot_dir = -1;
	if(keysem == XK_Up || keysem == XK_w)
		data->p.move_dir = 1;
	if(keysem == XK_Down || keysem == XK_s)
		data->p.move_dir = -1;
	if(keysem == XK_d)
	{
		data->p.step_x = cos(data->p.view_angle + M_PI / 2) * data->p.move_speed;
		data->p.step_y = sin(data->p.view_angle + M_PI / 2) * data->p.move_speed;
	}
	if(keysem == XK_a)
	{
		data->p.step_x = cos(data->p.view_angle - M_PI / 2) * data->p.move_speed;
		data->p.step_y = sin(data->p.view_angle - M_PI / 2) * data->p.move_speed;
	}
}

int	press_key(int keysem, t_data *data)
{
	if (keysem == XK_Escape)
		press_x(data);
	else
		which_key(keysem,data);
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
	if(keysem == XK_Up || keysem == XK_Down || keysem == XK_s || keysem == XK_w)
		data->p.move_dir = 0;
	if(keysem == XK_Right || keysem == XK_Left)
		data->p.rot_dir = 0;
	if(keysem == XK_d || keysem == XK_a)
	{
		data->p.step_x = 0;
		data->p.step_y = 0;
	}
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
	if (x < 0 || y < 0 || x >= WIDTH|| y >= HEIGHT)
        return;
	offset = (img->line_len * y) + (x * (img->b_p_p / 8));
	*((unsigned int *)(img->img_pxl_ptr + offset)) = color;
}

void draw_circle(t_data *data, int color)
{
	int radius;
	double dx;
	double dy;
	radius = 4;
	
	double y;
	double x;
	y = data->p.p_y - radius;
	while (y <= data->p.p_y + radius)
	{
		x = data->p.p_x - radius;
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

void draw_square(t_data *data, double x, double y, int color)
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
				color = 0x808080;
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

double absolute_value(double value)
{
	if(value < 0)
		return(-value);
	return(value);
}

void init_line(t_line *line,t_data *data, double y1, double x1)
{
	line->move_x = 1;
	line->move_y = 1;
	line->x = data->p.p_x;
	line->y = data->p.p_y;
	line->dx = absolute_value(x1 - line->x);
	line->dy = absolute_value(y1 - line->y);
	if(x1 < data->p.p_x)
		line->move_x = -1;
	if(y1 < data->p.p_y)
		line->move_y = -1;
}

void draw_vertic(t_data *data, double x1, double y1)
{
	t_line line;
	double D;
	int i;

	i = 0;
	init_line(&line, data, y1, x1);
	D = 2*line.dx - line.dy;
	while(i <= line.dy)
	{
		img_pixel_put(data, &data->img,floor(line.x), floor(line.y), 0x00ff00);
		if(D >= 0)
		{  
			line.x += line.move_x;
			D = D - 2*line.dy;
		}
		line.y += line.move_y;
		D = D + 2*line.dx;
		i++;
	}
}

void draw_horiz(t_data *data, double x1, double y1)
{
	t_line line;
	double D;
	int i;

	i = 0;
	init_line(&line, data, y1, x1);
	D = 2*line.dy - line.dx;
	while(i <= line.dx)
	{
		img_pixel_put(data, &data->img,floor(line.x), floor(line.y), 0x00ff00);
		if(D >= 0)
		{
			line.y += line.move_y;
			D = D - 2*line.dx;
		}
		line.x += line.move_x;
		D = D + 2*line.dy;
		i++;
	}
}

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    float dx = x1 - x0;
    float dy = y1 - y0;
    int steps;
    float x_inc, y_inc;
    float x = x0;
    float y = y0;

    // choose the number of steps = the longest distance
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    x_inc = dx / steps;
    y_inc = dy / steps;

    for (int i = 0; i <= steps; i++)
    {
        img_pixel_put(data, &data->img, (int)x, (int)y, color);
        x += x_inc;
        y += y_inc;
    }
}


void bresenhams(t_data *data, double x, double y)
{
	double dx;
	double dy;

	dx = fabs(x - data->p.p_x);
	dy = fabs(y - data->p.p_y);
	img_pixel_put(data, &data->img,x, y, 0xFF69B4);
	// if(dx >= dy)
	// {
	// 	draw_horiz(data, x, y);
	// }
	// else
	// 	draw_vertic(data, x, y);
}

void cast_ray(t_data *data, double rayangle)
{
	// printf("wall hit x = %f y = %f\n", data->ray.walhit_x, data->ray.walhit_y);
	// draw_line(data,data->p.p_x, data->p.p_y, floor(data->ray.walhit_x), floor(data->ray.walhit_y), 0x000000);
	// bresenhams(data, data->ray.walhit_x, data->ray.walhit_y);
	
	img_pixel_put(data, &data->img, data->ray.walhit_x, data->ray.walhit_y, 0x00ff00);
}

double calculate_distance(t_data *data, double x_d , double y_d)
{
	double dx;
	double dy;

	dx = x_d - data->p.p_x;
	dy = y_d - data->p.p_y;
	return(sqrt(dx * dx + dy * dy));

}

void ray_direction(t_data *data, double rayangle)
{
	data->ray.rayangle = rayangle;
	if(rayangle >= 0 && rayangle <= M_PI)
		data->ray.is_down = 1;
	data->ray.is_up = !data->ray.is_down;
	if(rayangle <= 0.5 * M_PI || rayangle >= M_PI * 1.5)
		data->ray.is_right = 1;
	data->ray.is_left = !data->ray.is_right;
}

void calcul_first_inter_H(t_intrsc *inter, t_data *data, double rayangle)
{
	if(data->ray.is_down)
		inter->first_int_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE + SQUARESIZE;
	else if(data->ray.is_up)
		inter->first_int_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE;
	inter->first_int_x = data->p.p_x + ((inter->first_int_y - data->p.p_y) / tan(rayangle));
	inter->next_x = inter->first_int_x;
	inter->next_y = inter->first_int_y;
}

void calcul_step_H(t_data *data, double *xa, double *ya, double rayangle)
{
	if(data->ray.is_down)
		*ya = SQUARESIZE;
	else if(data->ray.is_up)
		*ya = -SQUARESIZE;
	*xa = *ya / tan(rayangle);
	if(data->ray.is_left && *xa > 0)
		*xa *= -1;
	if(data->ray.is_right && *xa < 0)
		*xa *= -1;
}

void calcul_inter_H(t_data *data, double xa, double ya, t_intrsc *inter)
{
	while(inter->next_x < data->width * SQUARESIZE && inter->next_x >= 0 && inter->next_y < data->heigth * SQUARESIZE && inter->next_y >= 0)
	{
		if (is_wall(data, data->map, inter->next_x, inter->next_y, 'h'))
		{
			data->ray.hit_horiz = 1;
			data->ray.hor_walhit_x = inter->next_x;
			data->ray.hor_walhit_y = inter->next_y;
			data->ray.content = data->map[(int) inter->next_y / SQUARESIZE][(int) inter->next_x / SQUARESIZE];
			break;
		}
		else
		{
			inter->next_x += xa;
			inter->next_y += ya;
		}
	}
}

double find_hor_inter(t_data *data, double rayangle)
{
	t_intrsc inter;
	double ya;
	double xa;

	calcul_first_inter_H(&inter, data, rayangle);
	calcul_step_H(data, &xa, &ya, rayangle);
	calcul_inter_H(data, xa, ya, &inter);
	if(data->ray.hit_horiz)
		return(calculate_distance(data, data->ray.hor_walhit_x, data->ray.hor_walhit_y));
	else 
		return(INT_MAX);
}

void calcul_first_inter_V(t_intrsc *inter, t_data *data, double rayangle)
{
	if(data->ray.is_right)
		inter->first_int_x = floor(data->p.p_x / SQUARESIZE) * SQUARESIZE + SQUARESIZE;
	else if(data->ray.is_left)
		inter->first_int_x = floor(data->p.p_x / SQUARESIZE) * SQUARESIZE ;
	inter->first_int_y = data->p.p_y + ((inter->first_int_x - data->p.p_x) * tan(rayangle));
	inter->next_x = inter->first_int_x;
	inter->next_y = inter->first_int_y;
}

void calcul_step_V(t_data *data, double *xa, double *ya, double rayangle)
{
	if(data->ray.is_right)
		*xa = SQUARESIZE;
	else if(data->ray.is_left)
		*xa = -SQUARESIZE;
	*ya = SQUARESIZE * tan(rayangle);
	if(data->ray.is_up && *ya > 0)
		*ya *= -1;
	if(data->ray.is_down && *ya < 0)
		*ya *= -1;
}

void calcul_inter_V(t_data *data, double xa, double ya, t_intrsc *inter)
{
	while(inter->next_x <= data->width * SQUARESIZE && inter->next_x >= 0 && inter->next_y <= data->heigth * SQUARESIZE && inter->next_y >= 0)
	{
		if (is_wall(data, data->map, inter->next_x, inter->next_y, 'v'))
		{
			data->ray.hit_vertical = 1;
			data->ray.ver_walhit_x = inter->next_x;
			data->ray.ver_walhit_y = inter->next_y;
			data->ray.content = data->map[(int) inter->next_y / SQUARESIZE][(int) inter->next_x / SQUARESIZE];
			break;
		}
		else
		{
			inter->next_x += xa;
			inter->next_y += ya;
		}
	}
}

double find_ver_inter(t_data *data, double rayangle)
{
	t_intrsc inter;
	double ya;
	double xa;

	calcul_first_inter_V(&inter, data, rayangle);
	calcul_step_V(data, &xa, &ya, rayangle);
	calcul_inter_V(data, xa, ya, &inter);
	if(data->ray.hit_vertical)
		return(calculate_distance(data, data->ray.ver_walhit_x, data->ray.ver_walhit_y));
	else 
		return(INT_MAX);
}

void draw_3d_map(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			img_pixel_put(data, &data->img, x, y, 0xff0000);
			x++;
		}
		y++;
	}
}

void draw_ceiling(t_data *data, double top_wall)
{
	int y;
	
	y = 0;
	while(y < top_wall)
	{
		img_pixel_put(data, &data->img, data->ray.id, y, 0x0000ff);
		y++;
	}
}
void draw_floor(t_data *data, double bottom_wall)
{
	int y;
	
	y = HEIGHT;
	while(y > bottom_wall)
	{
		img_pixel_put(data, &data->img, data->ray.id, y, 0x00ff00);
		y--;
	}
}

void draw_wall(t_data *data, double top_wall, double bottom_wall)
{
	int y;
	
	y = top_wall;
	while(y < bottom_wall)
	{
		img_pixel_put(data, &data->img, data->ray.id, y, 0xffffff);
		y++;
	}
}



void render_3d(t_data *data)
{
	double distance_proj_plane;
	double wall_height;
	double top_wall;
	double bottom_wall;
	int y;

	y = 0;
	distance_proj_plane = (WIDTH / 2) / tan(FOV / 2);
	// printf("distance project plane = %f   %d\n", data->ray.distance, data->ray.id);
	// printf("ray id   = %d\n", data->ray.id);
	wall_height = ((SQUARESIZE ) / data->ray.distance) * distance_proj_plane;
	// printf("wall height = %f \n", wall_height);
	top_wall = (HEIGHT / 2) - (wall_height / 2);
	data->ray.top_wall = abs(top_wall);
	if(top_wall < 0)
		top_wall = 0;
	bottom_wall = (HEIGHT / 2) + (wall_height / 2);
	if(bottom_wall > HEIGHT)
		bottom_wall = HEIGHT;
	while(y < HEIGHT)
	{
		if(y < top_wall)
			img_pixel_put(data, &data->img, data->ray.id, y, 0x0000ff);
		else if(y >= top_wall && y <= bottom_wall)
			 //render_walls
		else if(y > bottom_wall)
		img_pixel_put(data, &data->img, data->ray.id, y, 0x000000);
		y++;
	}q
}
		// img_pixel_put(data, &data->img, data->ray.id, y, 0xff00fff); //
		
void set_ray_val(double hor_distance, double ver_distance, t_data *data)
{
	if(hor_distance > ver_distance)
	{
		// printf("VER IS SMALLER = %f\n", ver_distance);
		data->vertical_hit = 0;
		data->ray.walhit_x = data->ray.ver_walhit_x;
		data->ray.walhit_y = data->ray.ver_walhit_y;
		data->ray.distance = ver_distance * cos(normlizing((data->p.view_angle) - data->ray.rayangle));
	}
	else if(hor_distance <= ver_distance)
	{
		// printf("HOR IS SMALLER = %f\n", hor_distance);
		data->vertical_hit = 1;
		data->ray.walhit_x = data->ray.hor_walhit_x;
		data->ray.walhit_y = data->ray.hor_walhit_y;
		data->ray.distance = hor_distance * cos(normlizing((data->p.view_angle )- data->ray.rayangle));
	}
}

void cast_allrays(t_data *data)
{
	double rayangle;
	double hor_distance;
	double ver_distance;
	int i;

	i = 0;
	rayangle = data->p.view_angle - (FOV / 2);
	while(i < NUM_RAYS)
	{
		rayangle = normlizing(rayangle);
		ray_direction(data, rayangle);
		// printf("%d rayangle = %f\n", i, rayangle);
		data->ray.id = i;
		hor_distance = find_hor_inter(data, rayangle);
		ver_distance = find_ver_inter(data, rayangle);
		set_ray_val(hor_distance, ver_distance, data);
		// cast_ray(data, rayangle);
		// printf("ray %d distance = %f  ver_dis %f\n", data->ray.id, data->ray.distance, ver_distance);
		render_3d(data); 
		init_ray(data);
		rayangle += (double)FOV / (double)NUM_RAYS;
		i++;
	}
}

void rendring_(t_data *data)
{
	// render_map(data);
	// put_player(data);
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
	data->p.move_speed = 2;
	data->p.move_dir = 0;
	data->p.rot_dir = 0;
	data->p.step_x = 0;
	data->p.step_y = 0;
	data->p.rot_speed = 1 * (M_PI / 180);
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
	data->ray.distance = INT_MAX;
	data->ray.is_down = 0;
	data->ray.is_up = 0;
	data->ray.is_right = 0;
	data->ray.is_left = 0;
	data->ray.ver_walhit_x = 0;
	data->ray.ver_walhit_y = 0;
	data->ray.hor_walhit_x = 0;
	data->ray.hor_walhit_y = 0;
	data->ray.walhit_x = 0;
	data->ray.walhit_y = 0;
	data->ray.hit_vertical = 0;
	data->ray.hit_horiz = 0;
	data->ray.content = 0;

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
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.img_pxl_ptr = mlx_get_data_addr(data->img.img_ptr,
		&data->img.b_p_p, &data->img.line_len, &data->img.endian);
	init_player(data);
	init_ray(data);
	rendring_(data);
	data->arr = init_text_arr(data->mlx_ptr, &data->arr, 4);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = data_func();

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
