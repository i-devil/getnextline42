/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:01:11 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/09 18:05:08 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (i >= j)
	{
		if (ft_memcmp(s1, s2, j) == 0)
		{
			return ((char *)s1);
		}
		s1++;
		i--;
	}
	return (NULL);
}
