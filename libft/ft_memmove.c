/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:51:40 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/08 17:15:30 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*copy;
	size_t	i;

	i = 0;
	copy = malloc(len);
	if (copy)
	{
		copy = ft_memcpy(copy, src, len);
		while (i < len)
		{
			((char *)dst)[i] = ((char *)copy)[i];
			i++;
		}
	}
	return (dst);
}
