/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:24:12 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/09 19:35:49 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void		*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)(malloc(size));
	if (str)
	{
		while (i < size)
			str[i++] = 0;
		return ((void *)str);
	}
	else
		return (NULL);
}
