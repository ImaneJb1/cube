/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:17:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/06 15:56:36 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s3;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = gc_malloc(len * sizeof(char) + 1);
	if (!s3)
		return (free((char *)s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		s3[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
