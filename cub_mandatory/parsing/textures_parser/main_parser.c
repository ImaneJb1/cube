/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:11:57 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/13 23:50:17 by nel-khad         ###   ########.fr       */
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
		ft_putstr_fd("Error\nNo extension detected. Please use a .cub file.\n",
			2);
		return (0);
	}
	if (ft_strcmp(ext, ".cub") == 0)
		return (1);
	ft_putstr_fd("Error\nInvalid file type. Expected a .cub file.\n", 2);
	return (0);
}

int	map_reached( char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \t");
	if (tmp[0] == '0' || tmp[0] == '1')
		return (1);
	return (0);
}

void	init_arrays(t_textures **text, t_config **arr_dir, t_config **arr_fc,
		t_data *data)
{
	*arr_dir = init_dir_arr(*text);
	*arr_fc = init_fc_arr(*text, data);
}

int	parse_map_file(char *file_name, t_data *data)
{
	int			fd;
	t_textures	**text;

	fd = open_file(file_name);
	if (fd < 0)
		return (0);
	text = text_func();
	*text = init_textures();
	if (!fill_textures_map(file_name, data, fd, text))
		return (0);
	return (1);
}

int	fill_textures_map(char *file_name, t_data *data, int fd, t_textures **text)
{
	char		*line;
	t_config	*arr_dir;
	t_config	*arr_fc;

	(void)file_name;
	init_arrays(text, &arr_dir, &arr_fc, data);
	line = get_next_line(fd);
	if (!line)
		return (printf("Error\nThe file is empty\n"), 0);
	while (line)
	{
		if (map_reached(line))
			collect_the_map(line, fd);
		else
		{
			line = ft_strtrim(line, " \n\t");
			if (*line && (!parse_dir(line, arr_dir)
					&& !parse_floor_ceiling(line, arr_fc)))
				return (0);
		}
		line = get_next_line(fd);
	}
	return (1);
}
