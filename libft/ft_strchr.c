/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:45:10 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/09 14:51:09 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	copy = (char *)s;
	len = ft_strlen(copy);
	while (i <= len)
	{
		if (copy[i] == (char)c)
			return (copy + i);
		i++;
	}
	return (NULL);
}
