/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:58:10 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/13 20:47:45 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include <stdio.h>


int			get_next_line(int const fd, char **line)
{
}

void		print(void *s, int size)
{
	write(1, s, size);
}

void		ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (!new)
		return;
	if (lst)
		lst = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}


int		main()
{
	int			fd;
	int			ret;
	char		buff[BUFF_SIZE];
	t_list		*lst;

	int i = 8;

	fd = open("42", 'r');

	while (ret = read(fd, buff, BUFF_SIZE))
		ft_lstpushback(&lst, ft_lstnew(buff, ret));

	while (lst)
	{
		printf("\n%d\n", lst->content_size);
		print(lst->content, lst->content_size);
		lst = lst->next;
	}
	
}
