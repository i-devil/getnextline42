/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:32:48 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/10 22:19:39 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*copy_src;
	unsigned char		*copy_dst;
	unsigned char		cara;

	if (!dst && !src)
		return (NULL);
	cara = (unsigned char)c;
	copy_src = (const unsigned char *)src;
	copy_dst = (unsigned char *)dst;
	while (n--)
		if ((*copy_dst++ = *copy_src++) == cara)
			return (copy_dst);
	return (NULL);
}
