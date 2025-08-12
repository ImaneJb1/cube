/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:45:07 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/12 17:02:08 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

config	*init_fc_arr(textures *text)
{
	config *arr;
	int i;

	arr = gc_malloc(sizeof(config) * 2);
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
	arr[1].direction = "C ";
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
	{
		printf("%s length is %d\n", str[i],i);
		i++;
	}
	return(i);
}

void	is_valid_format(char *format)
{
	char **splited;
	int i;
	int num;
	
	i = 0;
	printf("format = %s\n", format);
	splited = ft_split(format, ',');
	if(strlen_2d(splited) < 3 )
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

void	parse_floor_ceiling(char *line, config *arr)
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
			printf("line = %s\n", line);
			splited = ft_split(line, ' ');//hona
			printf("splited[0] = %s\n", splited[0]);
			is_valid_format(splited[0]);
			(*arr[i].texture) = splited[0];
		}
		i++;
	}
}
//khsni nzid functin katjoini liya splited arr