/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:17:28 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/26 14:56:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_errors(int fd, char **line, t_gnl *string)
{
	ft_memset(string, 0, sizeof(*string));
	if ((fd < 0) || (fd > RLIMIT_NOFILE) || (BUFFER_SIZE < 1) || !(line))
		return (1);
	return (0);
}

static void	add_to_line(t_gnl *string, char **line)
{
	string->read[string->read_return] = '\0';
	string->temp = ft_strjoin(*line, string->read);
	free(*line);
	*line = string->temp;
}

static int	new_line_found(t_gnl *string, char **line, char **excess)
{
	string->read[string->read_return] = '\0';
	*string->break_line_ptr = '\0';
	string->temp = ft_strjoin(*line, string->read);
	free(*line);
	*line = string->temp;
	string->temp = ft_strdup(string->break_line_ptr + 1);
	free(*excess);
	*excess = string->temp;
	return (READ_LINE);
}

static int	excess_with_new_line(char **line, t_gnl *string, char **excess)
{
	*string->break_line_ptr = '\0';
	string->temp = ft_strjoin(*line, *excess);
	free(*line);
	*line = string->temp;
	string->temp = ft_strdup(string->break_line_ptr + 1);
	free(*excess);
	*excess = string->temp;
	return (READ_LINE);
}

int			get_next_line(int fd, char **line)
{
	static char		*excess[OPEN_MAX];
	t_gnl			string;

	if (check_errors(fd, line, &string))
		return (-1);
	*line = ft_strdup("");
	if (excess[fd] != NULL)
	{
		if ((string.break_line_ptr = ft_strchr(excess[fd], '\n')))
			return (excess_with_new_line(line, &string, &excess[fd]));
		string.temp = ft_strjoin(*line, excess[fd]);
		free(*line);
		free(excess[fd]);
		excess[fd] = NULL;
		*line = string.temp;
	}
	while (((string.read_return = read(fd, string.read, BUFFER_SIZE)) > 0)
			&& !(string.break_line_ptr = ft_strchr(string.read, '\n')))
		add_to_line(&string, line);
	if (string.read_return < 1)
	{
		free(excess[fd]);
		return (string.read_return);
	}
	return (new_line_found(&string, line, &excess[fd]));
}
