/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:11:57 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/05 18:46:31 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_argv(int argc, char **argv)
{
	char	*ext;

	if(argc != 2)
		return(0);
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

// kan3amer les textures f struct textures

int check_textures(char *file_name)
{
	char *line;
	int fd;
	textures *text;
	config *arr;

	fd = open(file_name, O_RDONLY);
	if(fd < 0)
	{
		perror("");
		return(0);
	}
	arr = init_dir_arr(text);
	text = init_textures();
	line = get_next_line(fd);
	while(line)
	{
		line = ft_strtrim(line, " \n\t"); // remove spaces from jnab
		parse_dir(line, text);
		parse_floor_ceiling(line, text);
		line = get_next_line(fd);
	}
	return (1);
}
