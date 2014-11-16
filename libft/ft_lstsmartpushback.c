/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsmartpushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 10:38:32 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/16 11:08:12 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstsmartpushback(t_list **start, t_list *new)
{
	static t_list	*memstart = NULL;
	static t_list	*memend = NULL;

	if (memstart && *start == memstart)
	{
		memend->next = new;
		memend = new;
	}
	else
	{
		ft_lstpushback(start, new);
		memstart = *start;
		memend = new;
	}
}
