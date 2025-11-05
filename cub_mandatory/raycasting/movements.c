#include "../header.h"

void is_door(t_data *data, char *map[], double x, double y)
{
	int grid_x;
	int grid_y;
	(void)data;
	
	grid_x = floor(x  / SQUARESIZE);
	grid_y = floor(y / SQUARESIZE);
	if(map[grid_y][grid_x] == 'D')
		map[grid_y][grid_x] = 'P';
}

int is_player_wall(t_data *data, char *map[], double x, double y)
{
	int grid_x;
	int grid_y;
	double dx;
	double dy;
	double marge;

	marge = 1;
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

static void update_player(t_data *data)
{
	int move_step;
	double next_x;
	double next_y;

	move_step = data->p.move_dir * data->p.move_speed;
	data->p.view_angle += data->p.rot_dir * data->p.rot_speed;
	data->p.view_angle = normlizing(data->p.view_angle);
	next_x = data->p.p_x + (cos(data->p.view_angle) * data->p.move_dir + data->p.right_x) * data->p.move_speed ;
	next_y = data->p.p_y + (sin(data->p.view_angle) * data->p.move_dir + data->p.left_y) * data->p.move_speed;
	if(!is_player_wall(data, data->map, next_x, next_y)) //next_x *1.5 
	{
		data->p.p_y = next_y;
		data->p.p_x = next_x;
	}
}

int moves_loop(t_data *data)
{
	update_player(data);
	// draw_first_person_walking(data, data->weapon.walking, 20);
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


