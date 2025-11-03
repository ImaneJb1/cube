/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:11:57 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/03 00:48:18 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	check_argv(int argc, char **argv)
{
	char	*ext;

	if (argc != 2)
		return (0);
	ext = ft_strchr(argv[1], '.');
	if (!ext || ft_strlen(argv[1]) <= 4)
	{
		ft_putstr_fd("Error: No extension detected. Please use a .cub file.\n",
			2);
		return (0);
	}
	if (ft_strcmp(ext, ".cub") == 0)
		return (1);
	ft_putstr_fd("Error: Invalid file type. Expected a .cub file.\n", 2);
	return (0);
}

int	map_reached(char first_char)
{
	if (first_char == '0' || first_char == '1')
		return (1);
	return (0);
}

void	init_arrays(textures **text, config **arr_dir, config **arr_fc,
		t_data *data)
{
	*arr_dir = init_dir_arr(*text);
	*arr_fc = init_fc_arr(*text, data);
}

int	parse_map_file(char *file_name, t_data *data)
{
	int			fd;
	textures	**text;

	fd = open_file(file_name);
	if(fd < 0)
		return (0);
	text = text_func();
	*text = init_textures();
	if(!fill_textures_map(file_name, data, fd, text))
		return(0);
	return(1);
}
// kan3amer les textures f struct textures
int	fill_textures_map(char *file_name, t_data *data, int fd, textures	**text)
{
	char		*line;
	// int			fd;
	// textures	**text;

	config(*arr_dir), (*arr_fc);
	// fd = open_file(file_name);
	// if(fd < 0)
	// 	return (0);
	// text = text_func();
	// *text = init_textures();
	init_arrays(text, &arr_dir, &arr_fc, data);
	line = get_next_line(fd);
	if (!line)
		return (printf("The file is empty\n"), 0);
	while (line)
	{
		if (map_reached(*line))
			collect_the_map(line, fd);
		else
		{
			line = ft_strtrim(line, " \n\t");
			parse_dir(line, arr_dir);
			parse_floor_ceiling(line, arr_fc, data);
			free(line);
		}
		line = get_next_line(fd);
	}
	return (free(line),1);
}

void	check_textures(void)
{
	if (text_func() == NULL)
	{
		printf("Unvalid textures\n");
		free_and_exit(1);
	}
	if ((*text_func())->no == NULL || (*text_func())->so == NULL
		|| (*text_func())->ea == NULL || (*text_func())->we == NULL)
	{
		printf("Unvalid textures\n");
		free_and_exit(1);
	}
}
