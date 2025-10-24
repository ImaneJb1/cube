#include "../header.h"

static void update_player(t_data *data)
{
	int move_step;
	double next_x;
	double next_y;

	move_step = data->p.move_dir * data->p.move_speed;
	data->p.view_angle += data->p.rot_dir * data->p.rot_speed;
	data->p.view_angle = normlizing(data->p.view_angle);
	next_x = data->p.p_x + (cos(data->p.view_angle) * data->p.move_dir * data->p.move_speed) + data->p.step_x;
	next_y = data->p.p_y + (sin(data->p.view_angle) * data->p.move_dir * (data->p.move_speed)) + data->p.step_y;
	// int grid_x = floor(next_x / SQUARESIZE);
	// int grid_y = floor(next_y / SQUARESIZE);
	if(!is_wall(data, data->map, next_x, next_y, 'n')) //next_x *1.5 
	{
		data->p.p_y = next_y;
		data->p.p_x = next_x;
	}
	// else if(!is_wall(data, data->map, data->p.p_x, next_y, 'n'))
	// 	data->p.p_y = next_y;
	// else if(!is_wall(data, data->map, next_x, data->p.p_y, 'n'))
	// 	data->p.p_x = next_x;
}

int moves_loop(t_data *data)
{
	update_player(data);
	rendring_(data);
	return(0);
}

double normlizing(double angle)
{
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


