/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:16:44 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/18 20:07:20 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

/*
** read
*/
# include <unistd.h>
/*
** malloc, free, size_t
*/
# include <stdlib.h>
/*
** EOF
*/
# include <stdio.h>
/*
** INT_MAX
*/
# include <limits.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
