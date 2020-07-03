/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:38:33 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:38:34 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	list = *alst;
	del(list->content, list->content_size);
	list->content = 0;
	if (list->next == 0)
	{
		free(*alst);
		*alst = 0;
	}
	else
	{
		ft_lstdel(&list->next, del);
		free(*alst);
		*alst = 0;
	}
}
