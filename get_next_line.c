/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_this_shit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:08:57 by dmulish           #+#    #+#             */
/*   Updated: 2017/02/13 19:02:56 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		n_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*ft_erase(char *str)
{
	int	i;
	int	j;
	int	nlen;
	int	len;

	i = 0;
	j = 0;
	nlen = n_len(str);
	len = ft_strlen(str);
	if (!str)
		return (0);
	while (i < len - nlen - 1)
	{
		str[i] = str[nlen + i + 1];
		i++;
	}
	while (j++ < nlen + 1)
		str[len - j] = '\0';
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	char			*tmp;
	static t_line	*node;

	if (node == NULL)
	{
		if ((node = (t_line*)malloc(sizeof(t_line))) == NULL)
			return (-1);
		if ((node->ft = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
			return (-1);
		if ((node->buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
			return (-1);
		node->fd = fd;
		node->next = NULL;
	}
	while (node->buf[0] == '\n')
	{
		node->ft = NULL;
		node->buf = ft_erase(node->buf);
		return (1);
	}
	if (ft_strchr((const char*)node->buf, '\n') != 0)
	{
		tmp = NULL;
		tmp = ft_strsub((const char*)node->buf, 0, n_len(node->buf));
		*line = ft_strncpy(*line, (const char*)tmp, ft_strlen(tmp) + 1);
		node->buf = ft_erase(node->buf);
		return (1);
	}
	if (node->buf[0] != '\0')
	{
		tmp = NULL;
		tmp = ft_strdup((const char*)node->buf);
		*line = ft_strncpy(*line, (const char*)tmp, ft_strlen(tmp) + 1);
		node->ft = *line;
	}
	while ((i = read(node->fd, node->buf, BUFF_SIZE)) > 0)
	{
		while (node->buf[0] == '\n')
		{
			node->ft = NULL;
			node->buf = ft_erase(node->buf);
			return (1);
		}
		if (ft_strchr((const char*)node->buf, '\n') != 0)
		{
			tmp = NULL;
			tmp = ft_strsub((const char*)node->buf, 0, n_len(node->buf));
			*line = ft_strjoin((const char*)node->ft, (const char*)tmp);
			node->buf = ft_erase(node->buf);
			node->ft = NULL;
			return (1);
		}
		if (node->buf[0] != '\0')
		{
			tmp = NULL;
			tmp = ft_strdup((const char*)node->buf);
			*line = ft_strjoin((const char*)node->ft, (const char*)tmp);
			node->ft = *line;
		}
	}
	return (i);
}
