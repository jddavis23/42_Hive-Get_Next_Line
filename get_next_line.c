/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:44:33 by jdavis            #+#    #+#             */
/*   Updated: 2021/12/17 10:25:19 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_line(char *c, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '\n')
		{
			*line = ft_strnew(i);
			if (!*line)
			{
				ft_strdel(&c);
				return (-1);
			}
			ft_strncpy(*line, c, i);
			temp = ft_strdup(c);
			ft_bzero(c, ft_strlen(c));
			ft_strcat(c, &temp[i + 1]);
			ft_strdel(&temp);
			return (1);
		}
		++i;
	}
	return (0);
}

static int	is_end(int ret, char *c, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	if (ret == 0 && ft_strlen(c) > 0)
	{
		i = ft_strlen(c);
		temp = ft_strnew(ft_strlen(c));
		if (!temp)
		{
			ft_strdel(&c);
			return (-1);
		}
		ft_strncpy(temp, c, i);
		*line = temp;
		ft_strclr(c);
		ft_memdel((void **)c);
		return (1);
	}
	return (0);
}

static int	checks_plus(const int fd, char **line, char **c)
{
	if (fd < 0 || fd >= 4500 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (!c[fd])
	{
		c[fd] = ft_strnew(100000);
		if (!c[fd])
			return (-1);
	}	
	return (1);
}

static int	initial_check(int ret, char *buff, char *c, char **line)
{
	if (ret < 0)
	{
		ft_memdel((void **)c);
		return (-1);
	}
	if (ret)
	{
		buff[ret] = '\0';
		ft_strcat(c, buff);
		if (is_line(c, line) == -1)
			return (-1);
		else if (*line)
			return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*c[4500];
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (checks_plus(fd, line, c) == -1)
		return (-1);
	ret = 1;
	*line = NULL;
	if (is_line(c[fd], line) == -1)
		return (-1);
	else if (*line)
		return (1);
	while (ret != 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (initial_check(ret, buff, c[fd], line) == -1)
			return (-1);
		else if (*line)
			return (1);
	}
	return (is_end(ret, c[fd], line));
}
