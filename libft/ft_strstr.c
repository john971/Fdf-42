/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:52:01 by jandreu           #+#    #+#             */
/*   Updated: 2014/12/08 14:53:29 by jandreu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(char const *s1, char const *s2)
{
	int		i;
	size_t	j;
	char	*ptr;
	int		cmp;

	i = 0;
	j = 0;
	cmp = 1;
	ptr = (char *)s1;
	if (!*s2)
		return ((char*)s1);
	while (s1[i])
		if (s1[i] == s2[j])
		{
			i++, j++;
			if (j == ft_strlen(s2))
				return (ptr + (i - j));
		}
		else
		{
			i = cmp;
			cmp++;
			j = 0;
		}
	return (NULL);
}
