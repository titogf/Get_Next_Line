/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:52:54 by gfernand          #+#    #+#             */
/*   Updated: 2022/03/10 18:02:51 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*s[MAX_FD_COUNT];
	char		*str;
	char		*line;
	int			i;
	char		*aux;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_FD_COUNT)
		return (NULL);
	str = ft_stuff();
	if (!s[fd])
		s[fd] = ft_stuff();
	i = ft_enter(s[fd]);
	if (i == -1 || s[fd][i] != '\n')
	{
		aux = str;
		str = ft_read(str, fd);
		if (str == NULL)
			return (ft_free(aux, s[fd]));
	}
	line = ft_export_line(str, s[fd]);
	aux = s[fd];
	s[fd] = ft_leftover(str, s[fd]);
	free(aux);
	return (line);
}

char	*ft_read(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*aux;
	int		length;

	length = BUFFER_SIZE;
	while (ft_enter(str) == -1 && length == BUFFER_SIZE)
	{
		length = read(fd, buff, BUFFER_SIZE);
		if (length < 0)
			return (NULL);
		buff[length] = '\0';
		if (length <= 0)
			break ;
		aux = ft_strjoin(str, buff, 0);
		free(str);
		str = aux;
	}
	return (str);
}

void	*ft_free(char *aux, char *s)
{
	free(aux);
	free(s);
	return (NULL);
}

char	*ft_export_line(char *str, char *s)
{
	char	*buff;
	char	*string;
	int		i;

	string = ft_strjoin(s, str, 0);
	i = 0;
	if (string == NULL)
		return (NULL);
	while (string[i] != '\n' && string[i])
		i++;
	if (string[i] == '\n')
		i++;
	buff = ft_substr(string, 0, i);
	if (!ft_strlen(buff))
	{
		free(buff);
		return (NULL);
	}
	free(string);
	return (buff);
}

char	*ft_leftover(char *str, char *s)
{
	char	*aux;
	int		i;

	aux = ft_strjoin(s, str, 0);
	free(str);
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (aux[i] && aux[i] != '\n')
		i++;
	if (aux[i] == '\n')
		i++;
	if (ft_strlen(aux) == 0)
	{
		free(aux);
		return (NULL);
	}
	s = ft_substr(aux, i, ft_strlen(aux) - i);
	free(aux);
	return (s);
}
