/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:58:10 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/14 20:15:51 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include <stdio.h>



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

int			fill_line(t_list **lst, char *str, int *pos)
{
	char	*ret = str;
	int		i;
	char	*tmp;

	tmp = (char *)(*lst)->content + *pos;
	while (*tmp != '\n' || *tmp != EOF)
	{
		*str++ = *tmp++;
		if (++(*pos) == (*lst)->content_size)
		{
			*lst = (*lst)->next;
			tmp = (char *)(*lst)->content;
			*pos = 0;
		}
	}
	*str = 0;
	if (*tmp == EOF)
		return (0);
	if (++(*pos) == (*lst)->content_size)
	{
		*lst = (*lst)->next;
		*pos = 0;
	}
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*lst = NULL;
	static int		pos = 0;
	int			ret;
	char		buff[BUFF_SIZE];
	char		*str;

	if (!lst)
		while (ret = read(fd, buff, BUFF_SIZE))
			ft_lstpushback(&lst, ft_lstnew((void *)buff, ret));
	str = (char *)(malloc(sizeof(char) * count_line(lst, pos) + 1));
	if (!str)
		return (-1);
	*line = str;
	return (fill_line(&lst, str, &pos));
}

int		main()
{
	int	fd;
	char	*str;

	fd = open("42", 'r');
	
	while(get_next_line(fd, &str))
		printf("%s\n", str);
}




