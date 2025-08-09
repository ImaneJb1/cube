/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:29:07 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/09 17:09:41 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void ceate_map_arr(char *string)
{
	char ***map;

	map = the_map();
	*map = ft_split(string, '\n');
	if(!the_map())
	{
		printf("map is NULL\n");
		return(NULL);
	}
}

int is_inside_the_map(int x, int y, char **map)
{
	if(map[y - 1][x] == 0)
		return(0);
	if(map[y + 1][x] == 0)
		return(0);
	if(map[y][x - 1] == 0)
		return(0);
	if(map[y][x + 1] == 0)
		return(0);
	return(1);
}

int	is_valid_char(char c)
{
	if(c != '1' && c != '0' && c != 'N' && c != 'D')
		return(0);
	return(1);
}

int	parse_map(void)
{
	if(!is_map_valid(*the_map()))
		return(0);
	return(1);
}

int	is_map_valid(char **map)
{
	int (y), (x);

	while(map[y])
	{
		while(map[y][x])
		{
			if(!is_valid_char(map[y][x]))
			{
				printf("Unvalid character in the map\n");
				return(0);
			}
			if(map[y][x] == '0' || map[y][x] == 'N'|| map[y][x] == 'D')
			{
				if (!is_inside_the_map(x, y, map))
				{
					printf("The map should be surrounded by walls\n");
					return 0;
				}
			}
			x++;
		}
		y++;
	}
	return(1);
}
