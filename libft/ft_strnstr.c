/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:05:08 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/09 18:04:37 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s2);
	while (i < n)
	{
		if (ft_memcmp(s1, s2, j) == 0 && j <= n - i)
			return ((char *)s1);
		if (s1[i] == '\0')
			return (NULL);
		s1++;
		i++;
	}
	return (NULL);
}
