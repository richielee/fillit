/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:17:30 by rili              #+#    #+#             */
/*   Updated: 2017/04/25 16:38:30 by rili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*dump;

	if (!f || !lst)
		return (NULL);
	fresh = ft_lstnew(f(lst)->content, f(lst)->content_size);
	dump = fresh;
	lst = lst->next;
	while (lst)
	{
		fresh->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!fresh->next)
			return (NULL);
		lst = lst->next;
		fresh = fresh->next;
	}
	return (dump);
}
