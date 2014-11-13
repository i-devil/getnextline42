/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:23:00 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/11 14:09:50 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;

	copy_s1 = (unsigned char *)s1;
	copy_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*copy_s1 != *copy_s2)
			return (*copy_s1 - *copy_s2);
		copy_s1++;
		copy_s2++;
	}
	return (0);
}
