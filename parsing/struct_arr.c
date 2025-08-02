/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:52:27 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/02 11:51:18 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

config	*init_dir_arr(dir_textures *text)
{
	config *arr;

	arr = malloc(sizeof(config) * 4);
	int i;
	i = 0;
	while(i < 4)
	{
		arr[i].flag = 0;
		i++;
	}
	arr[0].direction = "NO ";
	arr[0].texture = &text->no;
	arr[1].direction = "SO ";
	arr[1].texture = &text->so;
	arr[2].direction = "WE ";
	arr[2].texture = &text->we;
	arr[3].direction = "EA ";
	arr[3].texture = &text->ea;
	return(arr);
}
