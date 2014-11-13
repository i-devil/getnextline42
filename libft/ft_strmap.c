/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:12:31 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/10 22:16:13 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*copy_str;
	int		len;

	if (s && f)
	{
		len = ft_strlen(s);
		str = (char *)(malloc(len + 1));
		copy_str = str;
		if (!str)
			return (NULL);
		while (*s)
		{
			*str = (*f)(*s);
			str++;
			s++;
		}
		*str = 0;
		return (copy_str);
	}
	else
		return (NULL);
}
