/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:18:02 by ijoubair          #+#    #+#             */
/*   Updated: 2025/08/17 13:36:18 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	parse_player(char char_map)
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
				flag = 1;
			}
		}
		i++;
	}
}
