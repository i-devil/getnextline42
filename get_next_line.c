/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:58:10 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/14 18:28:12 by ide-vill         ###   ########.fr       */
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

void		ft_lstpushback(t_list **start, t_list *new)
{
	t_list	*lst;

	lst = *start;
	if (!(*start))
		*start = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

int			count_line(t_list *lst, int local)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)lst->content + local;
	while (*tmp != '\n')
	{
		i++;
		tmp++;
		local++;
		if (local == lst->content_size)
		{
			lst = lst->next;
			tmp = (char *)(lst->content);
			local = 0;
		} 
	}
	return (i);
}

void		fill_line(t_list **lst, char *str, int *pos)
{
	char	*ret = str;
	int		i;
	char	*tmp;

	tmp = (char *)(*lst)->content + *pos;
	while (*tmp != '\n')
	{
		*str++ = *tmp++;
		if (++(*pos) == (*lst)->content_size)
		{
			*lst = (*lst)->next;
			tmp = (char *)(*lst)->content;
			*pos = 0;
		}
	}
	if (++(*pos) == (*lst)->content_size)
	{
		*lst = (*lst)->next;
		*pos = 0;
	}
	*str = '\0';
	printf("ret = %s\n", ret);
}

int		main()
{
	int			fd;
	int			ret;
	char		buff[BUFF_SIZE];
	t_list		*lst;
	static int	pos;
	char		*str;
	int			size;
	t_list		*locallst;

	pos = 0;
	fd = open("42", 'r');
	lst = NULL;
	while (ret = read(fd, buff, BUFF_SIZE))
		ft_lstpushback(&lst, ft_lstnew((void *)buff, ret));
	locallst = lst;
	while (locallst)
	{
		size = count_line(locallst, pos);
		printf("size = %d\n", size);
		str = (char *)(malloc(sizeof(char) * size + 1));
		if (!str)
			return;
		fill_line(&locallst, str, &pos);
	
	}
}





