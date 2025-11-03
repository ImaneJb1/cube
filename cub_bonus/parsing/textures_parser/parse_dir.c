/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:22:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/03 15:25:24 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

void	check_textures(void)
{
	if(text_func() == NULL)
	{
		printf("Unvalid textures\n");
		free_and_exit(1);
	}
	if((*text_func())->no == NULL || (*text_func())->so == NULL 
	|| (*text_func())->ea == NULL || (*text_func())->we == NULL)
	{
		printf("Unvalid textures\n");
		free_and_exit(1);
	}
}

void	is_path_valid(char *path, char *conf)
{
	if(access(path, F_OK) < 0)
	{
		printf("the path %s is inaccessible\n", path);
		free_and_exit(1);
	}
}

void	parse_dir(char *line, config *arr)
{
	int i;
	char **splited;

	i = 0;
	while(i < 5)
	{
		if(ft_strncmp(line, arr[i].direction, 3) == 0)
		{
			if(arr[i].flag == 1) // duplicated
			{
				printf("textures are duplicated\n");
				free_and_exit(1);
			}
			arr[i].flag = 1;
			line =  ft_substr(line, 3, ft_strlen(line) - 3);
			splited = ft_split(line, ' ');
			is_path_valid(splited[0], arr[i].direction);
			(*arr[i].texture) = splited[0];
		}
		i++;
	}
}
