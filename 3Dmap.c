// #include "header.h"

// typedef struct s_projection {
//     double distance_proj_plane;
//     double wall_height;
//     double top_wall;
//     double bottom_wall;
// } t_projection;

// t_projection compute_projection(t_data *data)
// {
//     t_projection proj;

//     proj.distance_proj_plane = (WIDTH / 2.0) / tan(FOV / 2.0);
//     if (data->ray.distance <= 0.0001)
//         data->ray.distance = 0.0001;

//     proj.wall_height = (SQUARESIZE * proj.distance_proj_plane) / data->ray.distance;

//     proj.top_wall = (HEIGHT / 2.0) - (proj.wall_height / 2.0);
//     if (proj.top_wall < 0) proj.top_wall = 0;

//     proj.bottom_wall = (HEIGHT / 2.0) + (proj.wall_height / 2.0);
//     if (proj.bottom_wall > HEIGHT) proj.bottom_wall = HEIGHT;

//     return proj;
// }

// typedef struct s_texture_info {
//     int **texture;
//     int tex_w;
//     int tex_h;
// } t_texture_info;

// t_texture_info choose_texture(t_data *data)
// {
//     int tex_id = data->ray.wall_dir; // 0=NORTH,1=SOUTH,2=WEST,3=EAST
//     t_texture_info info;

//     info.texture = data->textures[tex_id];
//     info.tex_w = data->textures_w[tex_id];
//     info.tex_h = data->textures_h[tex_id];

//     return info;
// }

// int compute_tex_x(t_data *data, t_texture_info info)
// {
//     double wall_x;

//     if (data->ray.hit_vertical)
//         wall_x = fmod(data->ray.walhit_y, (double)SQUARESIZE);
//     else
//         wall_x = fmod(data->ray.walhit_x, (double)SQUARESIZE);

//     if (wall_x < 0) wall_x += SQUARESIZE;

//     int tex_x = (int)((wall_x / (double)SQUARESIZE) * (double)info.tex_w);

//     if (data->ray.hit_vertical && data->ray.is_left)
//         tex_x = info.tex_w - tex_x - 1;
//     if (data->ray.hit_horiz && data->ray.is_up)
//         tex_x = info.tex_w - tex_x - 1;

//     return tex_x;
// }

// void draw_vertical_stripe(t_data *data, int x, t_projection proj, t_texture_info tex_info, int tex_x)
// {
//     int y = 0;

//     while (y < HEIGHT)
//     {
//         if (y < (int)proj.top_wall)
//             img_pixel_put(data, &data->img, x, y, data->ceiling_color);
//         else if (y <= (int)proj.bottom_wall)
//         {
//             int dist_from_top = y - (int)proj.top_wall;
//             int wall_strip_height = (int)(proj.bottom_wall - proj.top_wall);
//             if (wall_strip_height == 0) wall_strip_height = 1;

//             int tex_y = (int)(((double)dist_from_top / wall_strip_height) * tex_info.tex_h);
//             int color = get_texture_color(tex_info.texture, tex_info.tex_w, tex_info.tex_h, tex_x, tex_y);
//             img_pixel_put(data, &data->img, x, y, color);
//         }
//         else
//             img_pixel_put(data, &data->img, x, y, data->floor_color);

//         y++;
//     }
// }

// void render_3d(t_data *data)
// {
//     t_projection proj = compute_projection(data);
//     t_texture_info tex_info = choose_texture(data);
//     int tex_x = compute_tex_x(data, tex_info);
//     draw_vertical_stripe(data, data->ray.id, proj, tex_info, tex_x);
// }
