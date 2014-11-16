/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:46:17 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/16 14:42:48 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*copy_src;
	unsigned char		*copy_dst;

	if (!dst || !src)
		return (NULL);
	copy_src = (const unsigned char *)src;
	copy_dst = (unsigned char *)dst;
	while (n--)
		*copy_dst++ = *copy_src++;
	return (dst);
}
