/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:58:10 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/27 18:27:02 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				count_line(t_list *lst, unsigned int local)
{
	char					*tmp;
	unsigned int			i;

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
			if (!lst)
				break ;
			tmp = (char *)(lst->content);
			local = 0;
		}
	}
	return (i);
}

int				fill_line(t_list **lst, char *str, unsigned int *pos)
{
	char					*tmp;

	tmp = (char *)(*lst)->content + *pos;
	while (*tmp != '\n')
	{
		*str++ = *tmp++;
		if (++(*pos) == (*lst)->content_size)
		{
			*lst = (*lst)->next;
			if (*tmp != '\n' && !(*lst))
				return (0);
			if (!(*lst))
				return (1);
			tmp = (char *)(*lst)->content;
			*pos = 0;
		}
	}
	*str = 0;
	if (++(*pos) == (*lst)->content_size)
	{
		*lst = (*lst)->next;
		*pos = 0;
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_list			*lst = NULL;
	static unsigned int		pos = 0;
	int						ret;
	char					buff[BUFF_SIZE];
	static unsigned int		end = 0;

	if (fcntl(fd, F_GETFL) == -1 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!lst && end == 0)
	{
		end = 1;
		while ((ret = read(fd, buff, BUFF_SIZE)))
		{
			if (ret == -1)
				return (-1);
			ft_lstsmartpushback(&lst, ft_lstnew((void *)buff, ret));
		}
	}
	if (!lst && end == 1)
	{
		ft_lstsimpledel(&lst);
		return (0);
	}
	*line = (char *)(malloc(sizeof(char) * count_line(lst, pos) + 1));
	return (fill_line(&lst, *line, &pos));
}
