/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:01:52 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/13 16:05:03 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*putnum(char *s, long int n, int *i)
{
	if (n > 9)
	{
		putnum(s, n / 10, i);
		(*i)++;
	}
	s[*i] = n % 10 + '0';
	return (s);
}

char		*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	num;

	i = 0;
	num = n;
	if (num < 0)
	{
		if ((res = (char *)malloc(sizeof(char) * ft_digitnum(num) + 2)) == 0)
			return (0);
		res[i] = '-';
		num *= -1;
		i++;
	}
	else if ((res = (char *)malloc(sizeof(char) * ft_digitnum(num) + 1)) == 0)
		return (0);
	res = putnum(res, num, &i);
	res[i + 1] = '\0';
	return (res);
}
