/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:22:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/07 17:34:36 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// config	*init_dir_arr(textures *text)
// {
// 	config *arr;
// 	int i;

// 	arr = malloc(sizeof(config) * 4);
// 	if(!arr)
// 	{
// 		perror("");
// 		return(NULL);
// 	}
// 	i = 0;
// 	while(i < 4)
// 	{
// 		arr[i].flag = 0;
// 		i++;
// 	}
// 	arr[0].direction = "NO ";
// 	arr[0].texture = &text->no;
// 	arr[1].direction = "SO ";
// 	arr[1].texture = &text->so;
// 	arr[2].direction = "WE ";
// 	arr[2].texture = &text->we;
// 	arr[3].direction = "EA ";
// 	arr[3].texture = &text->ea;
// 	return(arr);
// }

int	parse_dir(char *line, config *arr)
{
	int i;
	char **splited;

	i = 0;
	if(arr == NULL)
		return (0);
	while(i < 4)
	{
		if(ft_strncmp(line, arr[i].direction, 3) == 0)
		{
			if(arr[i].flag == 1) // duplicated
			{
				printf("finawa ghaadii\n");
				return (0);
			}
			arr[i].flag = 1;
			line =  ft_substr(line, 3, ft_strlen(line) - 3);
			splited = ft_split(line, ' ');
			(*arr[i].texture) = splited[0];
			return (1);
		}
		i++;
	}
	return (1);
}
