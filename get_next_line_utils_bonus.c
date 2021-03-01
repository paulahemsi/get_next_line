/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:30:11 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/28 23:30:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*c_in_s;

	if (c > 127)
		c %= 256;
	while (*s != '\0')
	{
		if (*s == c)
		{
			c_in_s = (char *)s;
			return (c_in_s);
		}
		s++;
	}
	if (*s == c)
	{
		c_in_s = (char *)s;
		return (c_in_s);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		end_s1;

	if (!s1 || !s2)
		return (NULL);
	string = (char *)malloc(((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	end_s1 = i;
	i = 0;
	while (s2[i] != '\0')
	{
		string[end_s1 + i] = s2[i];
		i++;
	}
	string[end_s1 + i] = '\0';
	return (string);
}

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strdup(const char *s)
{
	char	*string;
	size_t	length;
	size_t	i;

	length = ft_strlen(s);
	string = (char *)malloc(length + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		string[i] = s[i];
		i++;
	}
	string[length] = '\0';
	return (string);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	cc;
	char	*pointer_aux;

	i = 0;
	cc = (char)c;
	pointer_aux = (char *)s;
	while (i < n)
	{
		pointer_aux[i] = cc;
		i++;
	}
	return ((void *)s);
}
