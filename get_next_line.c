/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:17:28 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/24 19:23:22 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_errors(int fd, char **line, t_gnl *string)
{
	if ((fd < 1) || !(line))
		return (1);
	if (!(string->read = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (1);
	return (0);
}

static void	add_to_line(t_gnl *string, char **line)
{
	if (*line == NULL)
		*line = ft_strdup(string->read);
	else
	{
		string->temp = ft_strjoin(*line, string->read);
		free(*line);
		*line = string->temp;
	}
}

static char	*new_line_found(t_gnl *string, char **line)
{
	*string->break_line_ptr = '\0';
	if (*line == NULL)
		*line = ft_strdup(string->read);
	else
	{
		string->temp = ft_strjoin(*line, string->read);
		free(*line);
		*line = string->temp;
	}
	return (ft_strdup(string->break_line_ptr + 1));
}

static char	*excess_with_new_line(char **line, t_gnl *string, char *excess)
{
	int	length;

	length = 0;
	while (excess[length] != '\n')
		length++;
	*line = ft_substr(excess, START, length);
	string->temp = ft_strdup(string->break_line_ptr + 1);
	return (ft_strdup(string->temp));
}

int			get_next_line(int fd, char **line)
{
	static char		*excess;
	t_gnl			string;

	*line = NULL;
	if (check_errors(fd, line, &string))
		return (-1);
	if (excess != NULL)
	{
		if ((string.break_line_ptr = ft_strchr(excess, '\n')))
		{
			excess = excess_with_new_line(line, &string, excess);
			return (READ_LINE);
		}
		*line = ft_strdup(excess);
	}
	while (((string.read_return = read(fd, string.read, BUFFER_SIZE)) > 0)
			&& !(string.break_line_ptr = ft_strchr(string.read, '\n')))
	{
		string.read[BUFFER_SIZE] = '\0';
		add_to_line(&string, line);
	}
	if (string.read_return < 1)
		return (string.read_return);
	excess = new_line_found(&string, line);
	return (READ_LINE);
}
