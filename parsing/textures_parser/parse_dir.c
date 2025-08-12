/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:22:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/12 16:01:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	is_path_valid(char *path, char *conf)
{
	if(access(path, F_OK) < 0)
	{
		printf("the path of %sis inaccessible\n", conf);
		free_and_exit(1);
	}
}

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
			is_path_valid(line, arr[i].direction);
			line =  ft_substr(line, 3, ft_strlen(line) - 3);
			splited = ft_split(line, ' ');
			(*arr[i].texture) = splited[0];
			return (1);
		}
		i++;
	}
	return (1);
}
