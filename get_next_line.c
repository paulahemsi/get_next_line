/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:17:28 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/18 20:19:04 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Write a function which returns a line read from a file descriptor, without the newline.
** 
*/
/*
** Calling your function get_next_line in a loop will then allow you to read the text
** available on a file descriptor one line at a time until the EOF.
** Make sure that your function behaves well when it reads from a file and when it reads from the standard input.
** 
*/
/*
** Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used
** as the buffer size for the read calls in your get_next_line. This value will be
** modified by your evaluators and by moulinette.
** Compilation will be done this way : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32
** get_next_line.c get_next_line_utils.c
** Your read must use the BUFFER_SIZE defined during compilation to read from
** a file or from stdin
*/
int	get_next_line(int fd, char **line)
{
	char	*line_str;
	char	*str_read;
	char	*end_line_ptr;
	int		read_return;

	line_str = *line;
	if (!(line_str) || !(str_read = (char*)calloc((BUFFER_SIZE + 1), sizeof(char))))
		return (-1);
	read_return = read(fd, str_read, BUFFER_SIZE);
	// printf("read_return: %d\n", read_return);
	while ((end_line_ptr = ft_strchr(str_read, '\n')) == NULL)
	{
		if ((read_return == -1) || (read_return == 0))
		{
			free(str_read);
			free(line_str);
			return (read_return);
		}
		str_read[BUFFER_SIZE] = '\0';
		line_str = ft_strjoin(line_str, str_read);
		// printf("line_str: %s\n", line_str);
		read_return = read(fd, str_read, BUFFER_SIZE);
		// printf("read_return: %d\n", read_return);
	}
	*end_line_ptr = '\0';
	line_str = ft_strjoin(line_str, str_read);
	// printf("line finale: %s\n", line_str);
	*line = line_str;
	return (1);
}
