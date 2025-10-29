#include "../../header.h"

int is_wall(t_data *data, char *map[], double x, double y, char c)
{
	int grid_x;
	int grid_y;

	if(c == 'h' && data->ray.is_up )//set on lhafa dyal square wich is wall   mataaaaaalan : y = 64 and tilesize = 32 -> grid_y = 2 -> map[2] ou ana bagha map[1]
		y -= 1;
	if(c == 'v' && data->ray.is_left )
		x -= 1;
	grid_x = floor(x  / SQUARESIZE);
	grid_y = floor(y / SQUARESIZE);
	if(grid_x < 0 || grid_y < 0 || grid_x >= data->width || grid_y >= data->heigth)
		return(1);
	if(map[grid_y][grid_x] == '1')
		return(1);
	return(0);
}
int is_player_wall(t_data *data, char *map[], double x, double y)
{
	int grid_x;
	int grid_y;
	double dx;
	double dy;
	double marge;

	marge = 6;
	dx = -marge;
	while(dx <= marge)
	{
		dy = -marge;
		while(dy <= marge)
		{
			grid_x = floor((x + dx)  / SQUARESIZE);
			grid_y = floor((y + dy) / SQUARESIZE);
			if(grid_x < 0 || grid_y < 0 || grid_x >= data->width || grid_y >= data->heigth)
				return(1);
			if(map[grid_y][grid_x] == '1')
				return(1);
			dy += marge;
		}
		dx += marge;
	}
	return(0);
}

static void calcul_first_inter_H(t_intrsc *inter, t_data *data, double rayangle)
{
	if(data->ray.is_down)
		inter->first_int_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE + SQUARESIZE;
	else if(data->ray.is_up)
		inter->first_int_y = floor(data->p.p_y / SQUARESIZE) * SQUARESIZE;
	inter->first_int_x = data->p.p_x + ((inter->first_int_y - data->p.p_y) / tan(rayangle));
	inter->next_x = inter->first_int_x;
	inter->next_y = inter->first_int_y;
}

static void calcul_step_H(t_data *data, double *xa, double *ya, double rayangle)
{
	if(data->ray.is_down)
		*ya = SQUARESIZE;
	else if(data->ray.is_up)
		*ya = -SQUARESIZE;
	*xa = (int)*ya / tan(rayangle);
	if(data->ray.is_left && *xa > 0)
		*xa *= -1;
	if(data->ray.is_right && *xa < 0)
		*xa *= -1;
}

static void calcul_inter_H(t_data *data, double xa, double ya, t_intrsc *inter)
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