/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:18:02 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/31 21:57:03 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus.h"

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
				data_func()->p.direction = s[i];
				data_func()->p.p_x = x * SQUARESIZE + SQUARESIZE / 2;
				data_func()->p.p_y = y * SQUARESIZE + SQUARESIZE / 2;
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
