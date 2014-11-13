/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:30:14 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/08 19:51:46 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;
	int		len;

	i = 0;
	len = ft_strlen((char *)s1);
	dst = (char *)(malloc(len));
	if (dst)
	{
		while (((char *)s1)[i] != '\0')
		{
			dst[i] = ((char *)s1)[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
		return (NULL);
	return (dst);
}
