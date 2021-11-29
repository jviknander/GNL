/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:14:38 by jde-melo          #+#    #+#             */
/*   Updated: 2021/11/28 21:26:57 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char *ft_substr(char *s, int start, int len)
{
	char			*sub;
	int			size;
	int			i;

	sub = NULL;
	if (s)
	{
		if (ft_strlen(s) <= len)
			size = ft_strlen(s);
		else
			size = len;
		if (start >= ft_strlen(s))
			size = 0;
		sub = malloc(size + 1);
		if (!sub)
			return (NULL);
		i = 0;
		while (i < size)
			sub[i++] = s[start++];
		sub[i] = '\0';
	}
	return (sub);
}

char	*ft_strdup(char *str)
{
	char *m;
	int	size;
	int i;

	
	size = ft_strlen(str);
	m = malloc(sizeof(char) * size + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (str[i])
	{
		m[i] = str[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}


int ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] ==  (char )c)
			return (i);
		i++;
	}
	return (-1);
}


char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			r;
	int 		until_n;		

	
	line = NULL;
	if (fd > 1024 || BUFFER_SIZE < 0)
		return (NULL) ;
	r = read (fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		if (storage == NULL)
			 storage = ft_strdup(""); // caso nao tenha nada, manda nada para a alocacao do storage
		buf[r] = '\0';
		storage = ft_strjoin(storage, buf);
		if (ft_strchr(buf, '\n') != -1)
				break;
		r = read(fd, buf, BUFFER_SIZE);
	}
	until_n = ft_strchr(storage, '\n');
	line = ft_substr(storage, 0, until_n);
	storage = ft_substr(storage, until_n + 1, ft_strlen(storage) - until_n);
	return (line);
}
