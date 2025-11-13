/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:30:27 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/13 23:25:12 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	is_rgb_valid(char *line)
{
	char	*tmp;
	int		i;

	int (comma), (error);
	tmp = ft_strtrim(line, " ");
	i = 0;
	comma = 0;
	error = 0;
	while (tmp[i])
	{
		if (tmp[i] == ',')
			comma++;
		if ((i < (int)ft_strlen(tmp) - 1) && (ft_isdigit(tmp[i]) && tmp[i
					+ 1] == ' '))
			error = 1;
		i++;
	}
	if (comma != 2 || error == 1)
	{
		printf("Error\nInvalid color format in F/C "
			"element (expected R,G,B)\n");
		free_and_exit(1);
	}
}

int	check_arr_flags(t_config *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i].flag == 1)
			return (1);
		i++;
	}
	return (0);
}
