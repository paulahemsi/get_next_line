/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:16:44 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/24 19:29:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define READ_LINE	1
# define READ_EOF	0
# define READ_ERROR	-1
# define INIT		1
# define START		0

typedef	struct	s_get_next_line
{
	char		*read;
	char		*temp;
	char		*break_line_ptr;
	int			read_return;
}				t_gnl;

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
void			ft_strclr(char *s);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
