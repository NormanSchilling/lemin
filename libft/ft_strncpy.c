/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:09:44 by nschilli          #+#    #+#             */
/*   Updated: 2013/11/23 14:12:51 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*s;

	s = s1;
	while (n--)
	{
		if (*s2)
			*(s1++) = *(s2++);
		else
			*(s1++) = '\0';
	}
	return (s);
}