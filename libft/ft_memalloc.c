/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:58:09 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/04 14:42:34 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*fresh;

	i = 0;
	fresh = malloc(size);
	if (!fresh)
		return (0);
	ft_bzero(fresh, size);
	return ((void *)fresh);
}
