/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:08:44 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/28 23:58:39 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		gnl_check_line(char **stock, char **line)
{
	char	*tmp;
	char	*str;

	tmp = *stock;
	str = ft_strchr(*stock, '\n');
	if (!str)
		return (0);
	*str = '\0';
	*line = ft_strdup(*stock);
	*stock = ft_strdup(str + 1);
	free(tmp);
	return (1);
}

static	char	*gnl_strjoin(char *s1, char *s2, int s)
{
	char		*str;
	int			x;
	int			y;

	x = s1 != NULL ? ft_strlen(s1) : 0;
	y = s2 != NULL ? ft_strlen(s2) : 0;
	str = (char *)ft_memalloc(sizeof(char) * (x + y + 1));
	x = 0;
	while (s1 && s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	if (s1 && (s == 1 || s == 3))
		free(s1);
	y = 0;
	while (s2 && s2[y])
	{
		str[x + y] = s2[y];
		y++;
	}
	if (s2 && (s == 2 || s == 3))
		free(s2);
	return (str);
}

static	int		gnl_last_line(char **stock, char **line)
{
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*s[99];
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || fd > 99 || line == NULL)
		return (-1);
	if (s[fd] && gnl_check_line(&(s[fd]), line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		s[fd] = (s[fd] ? gnl_strjoin(s[fd], buf, 1) : ft_strdup(buf));
		if (gnl_check_line(&(s[fd]), line))
			return (1);
	}
	if (s[fd] && ret >= 0)
		return (gnl_last_line(&(s[fd]), line));
	return (ret > 0 ? 1 : ret);
}
