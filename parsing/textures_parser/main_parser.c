/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:11:57 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/09 18:34:31 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

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

int map_reached(char first_char)
{
	if(first_char == '0' || first_char == '1')
		return (1);
	return(0);
}

void	init_arrays(textures **text, config **arr_dir, config **arr_fc)
{	
	*arr_dir = init_dir_arr(*text);
	*arr_fc = init_fc_arr(*text);	
}

//kan3amer les textures f struct textures
int fill_textures_map(char *file_name)
{
	char *line;
	int fd;
	textures **text;
	config(*arr_dir), (*arr_fc);
	
	fd = open(file_name, O_RDONLY);
	if(fd < 0)
	{
		perror("");
		return(0);
	}
	text = text_func();
	*text = init_textures();
	init_arrays(text, &arr_dir, &arr_fc);
	line = get_next_line(fd);
	while(line)
	{
		if(map_reached(*line))
			collect_the_map(line, fd);
		line = ft_strtrim(line, " \n\t"); // remove spaces from jnab
		parse_dir(line, arr_dir);
		parse_floor_ceiling(line, arr_fc);
		line = get_next_line(fd);
	}
	return (1);
}

void	check_textures(void)
{
	if(text_func() == NULL)
	{
		printf("Unvalid textures\n");
		//free
		exit(1);
	}
	if((*text_func())->no == NULL || (*text_func())->so == NULL 
	|| (*text_func())->ea == NULL || (*text_func())->we == NULL)
	{
		printf("Unvalid textures\n");
		//free
		exit(1);
	}
}
