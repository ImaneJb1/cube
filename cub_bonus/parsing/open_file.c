/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:16:43 by ijoubair          #+#    #+#             */
/*   Updated: 2025/10/31 21:50:04 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"


int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if(fd < 0)
	{
		perror("");
		free_and_exit(1);
		return(0);
	}  
	return(fd);
}
