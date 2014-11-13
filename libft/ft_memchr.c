/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:16:00 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/10 17:30:36 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	void		*tmp;

	i = 0;
	tmp = (void *)s;
	while (i < n)
	{
		if (((unsigned char *)tmp)[i] == (unsigned char)c)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
