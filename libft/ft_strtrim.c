/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:55:34 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/12 10:02:22 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_count_space_beg(const char *s)
{
	size_t			c;

	c = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		c++;
		s++;
	}
	return (c);
}

static size_t		ft_count_space_end(const char *s)
{
	size_t			c;

	s += ft_strlen(s) - 1;
	c = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		c++;
		s--;
	}
	return (c);
}

char				*ft_strtrim(const char *s)
{
	char			*str;
	size_t			i;
	size_t			beg;
	size_t			end;

	if (!s)
		return (NULL);
	beg = ft_count_space_beg(s);
	end = ft_count_space_end(s);
	i = ft_strlen(s + beg) - end;
	if (beg == end && i == -beg)
		return (ft_strnew(1));
	str = ft_strsub(s, beg, i);
	return (str);
}
