/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:20:05 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/12 10:42:27 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	l = (t_list *)(malloc(sizeof(t_list)));
	if (!l)
		return (NULL);
	if (content)
	{
		l->content = malloc(content_size);
		if (!l->content)
			return (NULL);
		l->content_size = content_size;
		ft_memcpy(l->content, content, content_size);
	}
	else
	{
		l->content = NULL;
		l->content_size = 0;
	}
	l->next = NULL;
	return (l);
}
