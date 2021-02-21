/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:16:44 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/21 01:46:24 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define READ_ERROR	-1
# define READ_EOF	0

typedef	struct				s_get_next_line
{
	char					read[BUFFER_SIZE + 1];
	char					temp[BUFFER_SIZE + 1];
	char					excess[BUFFER_SIZE + 1];
	char					*line_aux;
}							t_string;

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_strclr(char *s);

#endif
