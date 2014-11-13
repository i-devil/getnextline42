/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:52:38 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/12 09:51:57 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*copy;

	copy = (char *)s;
	i = ft_strlen(copy);
	while (i >= 0)
	{
		if (copy[i] == (char)c)
			return (copy + i);
		i--;
	}
	return (NULL);
}
