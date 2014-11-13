/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:05:54 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/08 20:55:33 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		dst_len;
	char		*copy_dst;
	char		*copy_src;

	copy_dst = dst;
	copy_src = (char *)src;
	len = size;
	while (*copy_dst && len--)
		copy_dst++;
	dst_len = copy_dst - dst;
	len = size - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(copy_src));
	while (*copy_src != '\0')
	{
		if (len != 1)
		{
			*copy_dst++ = *copy_src;
			len--;
		}
		copy_src++;
	}
	*copy_dst = '\0';
	return (dst_len + (copy_src - src));
}
