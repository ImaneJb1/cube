/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:18:02 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/17 14:22:13 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	parse_player(char char_map, int x, int y)
{
	static int flag;
	static char *s;
	int i;

	i = 0;
	s = "NSWE";
	while(s[i])
	{
		if(char_map == s[i])
		{
			if(flag == 0)
			{
				data_func()->p_position = s[i];
				data_func()->player_x = x * SQUARESIZE - SQUARESIZE / 2;
				data_func()->player_y = y * SQUARESIZE - SQUARESIZE / 2;
				flag = 1;
			}
			else
			{
				printf("unvalid map\n");
				free_and_exit(1);

			}
		}
		i++;
	}
}
