/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:58:04 by jandreu           #+#    #+#             */
/*   Updated: 2014/11/11 13:30:09 by jandreu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	void *ptr;

	ptr = ft_strncpy(dst, src, n);
	return (ptr);
}
