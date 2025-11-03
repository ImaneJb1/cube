/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:16:43 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/02 23:54:54 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if(fd < 0)
	{
		perror("");
		return(-1);
	}  
	return(fd);
}
