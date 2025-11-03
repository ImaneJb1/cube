#include "../../header.h"

static void calcul_first_inter_V(t_intrsc *inter, t_data *data, double rayangle)
{
	if(data->ray.is_right)
		inter->first_int_x = floor(data->p.p_x / SQUARESIZE) * SQUARESIZE + SQUARESIZE;
	else if(data->ray.is_left)
		inter->first_int_x = floor(data->p.p_x / SQUARESIZE) * SQUARESIZE ;
	inter->first_int_y = data->p.p_y + ((inter->first_int_x - data->p.p_x) * tan(rayangle));
	inter->next_x = inter->first_int_x;
	inter->next_y = inter->first_int_y;
}

static void calcul_step_V(t_data *data, double *xa, double *ya, double rayangle)
{
	if(data->ray.is_right)
		*xa = SQUARESIZE;
	else if(data->ray.is_left)
		*xa = -SQUARESIZE;
	*ya =  (int)SQUARESIZE * tan(rayangle);
	if(data->ray.is_up && *ya > 0)
		*ya *= -1;
	if(data->ray.is_down && *ya < 0)
		*ya *= -1;
}

static void calcul_inter_V(t_data *data, double xa, double ya, t_intrsc *inter)
{
	while(inter->next_x <= data->width * SQUARESIZE && inter->next_x >= 0 && inter->next_y <= data->heigth * SQUARESIZE && inter->next_y >= 0)
	{
		if (is_wall(data, inter->next_x, inter->next_y, 'v'))
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