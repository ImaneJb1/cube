/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:11:57 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/02 15:07:55 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_argv(int argc, char *argv)
{
	char	*ext;

	if(argc != 2)
		return(0);
	ext = ft_strchr(argv, '.');
	if (!ext || ft_strlen(argv) <= 4)
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

int	check_map(char *map)
{
	char *line;
	int fd;
	fd = open(map, O_RDONLY) < 0;
	if(fd < 0)
	{
		perror("");
		return(0);
	}
	line = get_next_line(fd);
	while(line)
	{
		ft_strtrim(line, " \n\t"); // remove spaces from jnab
		parse_dir(line);
		line = get_next_line(fd);
	}
} 