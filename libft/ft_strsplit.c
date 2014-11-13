/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:44:58 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/11 14:44:02 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wcount(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c)
			{
				if (!s[i])
					return (j);
				i++;
			}
		}
		i++;
	}
	return (j);
}

static int	ft_lcount(const char *s, char c, int beg)
{
	int		i;

	i = 0;
	s += beg;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		wc;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	wc = ft_wcount(s, c);
	ret = (char **)(malloc(sizeof(char *) * (wc + 1)));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	ret[wc] = '\0';
	while (i < wc)
	{
		while (s[j] == c)
			j++;
		ret[i] = ft_strsub(s, j, ft_lcount(s, c, j));
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	return (ret);
}
