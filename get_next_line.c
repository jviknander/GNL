/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:14:38 by jde-melo          #+#    #+#             */
/*   Updated: 2021/11/24 14:15:11 by jde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*m;
	int		i;

	m = malloc(ft_strlen(s1) + 1);
	if (!m)
		return (NULL);
	i = -1;
	while (s1[++i])
		m[i] = s1[i];
	m[i] = '\0';
	return (m);
}
char	*ft_strjoin(char const *s1, char const *s2)
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
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			size;
	size_t			i;

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
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	line = NULL;	
	if (fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	storage = malloc(sizeof(char *) * (BUFFER_SIZE + 1)); 
	if (!storage)	
		return (NULL);
	//buf = ft_strchr(storage, '\n');
	if(!line)
	line =ft_strdup("oooo");
	r = 1;
	while (!ft_strchr(line, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (NULL); 
		buf[r] = '\0';
		printf("linha1: %s\n", buf);	
		line  = ft_strjoin(line, buf); 
		//line = ft_strdup(buf);
	}
	printf("linha1: %s\n", line);	
	return (line);	
}

















