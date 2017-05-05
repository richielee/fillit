/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:17:08 by rili              #+#    #+#             */
/*   Updated: 2017/04/25 14:17:11 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*crawler;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		crawler = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = crawler;
	}
	*alst = NULL;
}
