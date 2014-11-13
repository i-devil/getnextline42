/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:08:31 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/11 09:16:37 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char		*ft_strnew(size_t size)
{
	char	*str;
	int		i;
	int		j;

	i = (int)size;
	j = 0;
	str = (char *)(malloc(sizeof(char) * (i + 1)));
	if (!str)
		return (NULL);
	while (j <= i)
		str[j++] = '\0';
	return (str);
}
