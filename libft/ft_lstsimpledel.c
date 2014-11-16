/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simpledel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 16:26:48 by ide-vill          #+#    #+#             */
/*   Updated: 2014/11/16 16:45:58 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstsimpledel(t_list **alst)
{
	if (*alst)
	{
		ft_lstsimpledel(&(*alst)->next);
		ft_lstsimpledelone(alst);
	}
}
