/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:45:07 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/07 17:35:20 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

config	*init_fc_arr(textures *text)
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
	arr[1].direction = "C ";
	arr[1].texture = &text->c;
	return(arr);
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
				printf("Invalid map, F or C is duplicated\n");
				return;
			}
			arr[i].flag = 1;
			line =  ft_substr(line, 2, ft_strlen(line) - 2);
			splited = ft_split(line, ' ');
			(*arr[i].texture) = splited[0];
		}
		i++;
	}
}
