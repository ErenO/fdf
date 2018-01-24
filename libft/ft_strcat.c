/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:00:04 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 19:49:44 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *p1;
	char *p2;

	p1 = s1;
	p2 = (char *)s2;
	while (*p1)
		p1++;
	while (*p2)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return (s1);
}
