/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:29:07 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/14 14:29:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void create_map_arr(char *string)
{
	char ***map;

	map = the_map();
	*map = ft_split(string, '\n');
	if(!the_map())
	{
		printf("map is NULL\n");
		exit(1);
	}
}

int is_inside_the_map(int x, int y, char **map)
{
	if(map[y + 1] == NULL)
		return(0);
	
	if((y == 0 && x == 0) || y == 0)
		return (0);
	if((map[y - 1][x] == 0 || map[y - 1][x] == ' '))
		return(0);
	if(map[y + 1][x] == 0 || map[y + 1][x] == ' ')
		return(0);
	if(x > 0 && (map[y][x - 1] == 0 || map[y][x - 1] == ' '))
		return(0);
	if(map[y][x + 1] == 0 || map[y][x + 1] == ' ')
		return(0);
	return(1);
}

int	is_valid_char(char c)
{
	if(c != '1' && c != '0' && c != 'N' && c != 'D' && c != ' ') 
		return(0);
	return(1);
}


int	is_map_valid(char **map)
{
	int (y), (x);
	
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x++])
		{
			if(!is_valid_char(map[y][x]))
				return(printf("Unvalid character in the map\n"), 0);
			if(map[y][x] == '0' || map[y][x] == 'N'|| map[y][x] == 'D')
			{
				if (!is_inside_the_map(x, y, map))
					return(printf("The map should be surrounded by walls\n"), 0);
			}
			x++;
		}
		y++;
	}
	return(1);
}

void	parse_map(void)
{
	char **map;

	map = *the_map();
	printf("map[0] = %s\n", map[0]);
	if(!is_map_valid(map))
	{	
		free_all();
		exit(1);
	}
}