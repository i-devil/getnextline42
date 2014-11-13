/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:48:16 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/10 22:22:50 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*copy_str;
	int		len;
	int		i;

	if (s && f)
	{
		i = 0;
		len = ft_strlen(s);
		str = (char *)(malloc(len + 1));
		if (!str)
			return (NULL);
		copy_str = str;
		while (i < len)
		{
			*str = (*f)(i, *s);
			str++;
			s++;
			i++;
		}
		*str = 0;
		return (copy_str);
	}
	else
		return (NULL);
}
