/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:29:07 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/13 23:48:04 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	create_map_arr(char *string)
{
	char	***map;
	int		i;

	map = the_map();
	*map = ft_split(string, '\n');
	if (!*the_map())
	{
		printf("Error\nThe map is NULL\n");
		free_and_exit(1);
	}
	i = 0;
	while ((*map)[i])
	{
		if ((*map)[i][0] == '\n')
		{
			printf("Error\nInvalid map\n");
			free_and_exit(1);
		}
		i++;
	}
}

int	is_inside_the_map(int x, int y, char **map)
{
	if (map[y + 1] == NULL)
		return (0);
	if (y == 0 || x == 0 || y == get_heigth(map) || x == (int)ft_strlen(map[y]))
		return (0);
	if ((map[y - 1][x] == 0 || map[y - 1][x] == ' '))
		return (0);
	if (map[y + 1][x] == 0 || map[y + 1][x] == ' ')
		return (0);
	if (x > 0 && (map[y][x - 1] == 0 || map[y][x - 1] == ' '))
		return (0);
	if (map[y][x + 1] == 0 || map[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	is_valid_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != ' ' && c != '\n' && c != 'E'
		&& c != 'W' && c != 'S')
		return (0);
	return (1);
}

int	is_map_valid(char **map)
{
	int (y), (x);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] && !is_valid_char(map[y][x]))
				return (printf("Error\nInvalid character in the 
					map %c\n", map[y][x]), 0);
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'D'
				|| map[y][x] == 'E' || map[y][x] == 'W' || map[y][x] == 'S')
			{
				if (!is_inside_the_map(x, y, map))
					return (printf("Error\nInvalid map\n"), 0);
				parse_player(map[y][x], x, y);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	parse_map(void)
{
	char	**map;

	map = *the_map();
	if (!map)
	{
		printf("Error\nNo map detected\n");
		free_and_exit(1);
	}
	if (!is_map_valid(map))
	{
		free_all();
		exit(1);
	}
	if (data_func()->p.direction == 0)
	{
		printf("Error\nNo player in the map\n");
		free_and_exit(1);
	}
}
