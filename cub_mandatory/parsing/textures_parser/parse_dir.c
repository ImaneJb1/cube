/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:22:42 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/13 23:35:57 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	check_textures(void)
{
	if (text_func() == NULL)
	{
		printf("Error\nMissing textures\n");
		free_and_exit(1);
	}
	if ((*text_func())->no == NULL || (*text_func())->so == NULL
		|| (*text_func())->ea == NULL || (*text_func())->we == NULL)
	{
		printf("Error\nMissing textures\n");
		free_and_exit(1);
	}
	if (!(*text_func())->c || !(*text_func())->f)
	{
		printf("Error\nMissing RGB color\n");
		free_and_exit(1);
	}
}

void	is_path_valid(char *path, char *conf)
{
	(void)conf;
	if (ft_strchr(path, '.') && ft_strcmp(ft_strchr(path, '.'), ".xpm") != 0)
	{
		printf("Error\nPlease use [%s] \'.xpm\' textures files\n", path);
		free_and_exit(1);
	}
	else if (ft_strchr(path, '.') == NULL)
	{
		printf("Error\nPlease use \'.xpm\' textures files\n");
		free_and_exit(1);
	}
	else if (access(path, F_OK) < 0)
	{
		printf("Error\nThe path %s is inaccessible\n", path);
		free_and_exit(1);
	}
}

int	parse_dir(char *line, t_config *arr)
{
	int		i;
	char	**splited;

	i = 0;
	while (i < 5)
	{
		if (ft_strncmp(line, arr[i].direction, 3) == 0)
		{
			if (arr[i].flag == 1)
			{
				printf("Error\nTextures are duplicated\n");
				free_and_exit(1);
			}
			arr[i].flag = 1;
			line = ft_substr(line, 3, ft_strlen(line) - 3);
			splited = ft_split(line, ' ');
			is_path_valid(splited[0], arr[i].direction);
			(*arr[i].texture) = splited[0];
			return (1);
		}
		i++;
	}
	return (0);
}
