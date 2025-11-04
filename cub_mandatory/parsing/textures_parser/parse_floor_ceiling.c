/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:45:07 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/04 14:55:59 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"


config	*init_fc_arr(textures *text, t_data *data)
{
	config *arr;
	int i;

	arr = malloc(sizeof(config) * 2);
	if(!arr)
	{
		perror("");
		return(NULL);
	}
	i = 0;
	while(i < 2)
	{
		arr[i].flag = 0;
		i++;
	}
	arr[0].direction = "F ";
	arr[0].texture = &text->f;
	arr[0].color = &data->floor_color;
	arr[1].direction = "C ";
	arr[1].color = &data->ceiling_color;
	arr[1].texture = &text->c;
	return(arr);
}

int	strlen_2d(char **str)
{
	int i;

	i = 0;
	if(!str)
		return 0;
	while(str[i])
		i++;
	return(i);
}

void	is_valid_format(char *format)
{
	char **splited;
	int i;
	int num;
	
	i = 0;
	// printf("format = %s\n", format);
	splited = ft_split(format, ',');
	if(strlen_2d(splited) != 3 )
	{
		printf("Error: Invalid color format in F/C element (expected R,G,B)\n");	
		free_and_exit(1);
	}
	while(splited[i])
	{
		num = ft_atoi(splited[i]);
		if(!(num >= 0 && num <= 255))
		{
			printf("Error: Invalid color value in F/C element (must be in range 0-255)\n");
			free_and_exit(1);
		}
		i++;
	}
}

char	*join_2d_arr(char **splited)
{
	int i;
	char *joined;

	joined = NULL;
	i = 0;
	while(splited[i])
	{
		joined = ft_strjoin(joined, splited[i]);
		i++;
	}
	return(joined);
}

void	parse_floor_ceiling(char *line, config *arr, t_data *data)
{
	int i;
	char **splited;

	i = 0;
	if(arr == NULL)
		return;
	while(i < 2)
	{
		if(ft_strncmp(line, arr[i].direction, 2) == 0)
		{
			if(arr[i].flag == 1) // duplicated
			{
				printf("Error: Invalid map, F or C is duplicated\n");
				free_and_exit(1);
			}
			arr[i].flag = 1;
			line =  ft_substr(line, 2, ft_strlen(line) - 2);
			splited = ft_split(line, ' ');//hona
			line = join_2d_arr(splited);
			is_valid_format(line);
			(*arr[i].texture) = line;
			(*arr[i].color) = get_hex_color(line);
		}
		i++;
	}
}
