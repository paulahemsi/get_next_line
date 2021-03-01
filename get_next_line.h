/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:16:44 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/28 23:43:11 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/param.h>
# include <sys/resource.h>

# define READ_LINE		1
# define ERROR			-1
# define NEW_LINE		1
# define NO_NEW_LINE	0

typedef	struct	s_get_next_line
{
	char		read[BUFFER_SIZE + 1];
	char		*temp;
	char		*break_line_ptr;
	int			read_return;
}				t_gnl;

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
void			*ft_memset(void *s, int c, size_t n);

#endif
