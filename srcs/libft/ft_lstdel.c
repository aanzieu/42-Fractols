/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:53:32 by aanzieu           #+#    #+#             */
/*   Updated: 2016/05/03 17:13:03 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p_next;

	while (*alst)
	{
		p_next = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = p_next;
	}
}
