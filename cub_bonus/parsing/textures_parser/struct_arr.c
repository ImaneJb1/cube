/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:52:27 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/04 22:06:00 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

config	*init_dir_arr(textures *text)
{
	config *arr;
	int i;

	arr = gc_calloc(5, sizeof(config) * 5);
	if(!arr)
	{
		perror("");
		return(NULL);
	}
	i = 0;
	while(i < 5)
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
	arr[4].direction = "DO ";
	arr[4].texture = &text->door;
	return(arr);
}

config *init_c_f_arr(textures *text)
{
	config *arr;

	arr = gc_malloc(sizeof(config) * 2);
	if(!arr)
	{
		perror("");
		return(NULL);
	}
	arr[0].direction = "F ";
	arr[0].texture = &text->f;
	arr[1].direction = "C ";
	arr[1].texture = &text->c;
	return(arr);
}
