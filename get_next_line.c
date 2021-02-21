/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:17:28 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/02/21 01:28:27 by phemsi-a         ###   ########.fr       */
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

	//* ler uma linha do fd, (que fica salva no read_str)
		//? finalizar read_str com '\0'
		// * se \n ou EOF estiver dentro da read_str, copiar parte anterior ao \n para line_str e parte posterior para excess. break
		//* se não, copiar read_str para line_str e seguir o loop
	//* copiar 

int	get_next_line(int fd, char **line)
{
	char		read_str[BUFFER_SIZE];
	char		temp[BUFFER_SIZE];
	static char	*line_str;
	static char	excedente[BUFFER_SIZE];
	int			read_return;
	int			i;
	int			j;

	i = 0;
	line_str = *line;
	//? antes de tudo algo que inicialize as strings para não ficar com sujeira de memória e evitar erros?
	//! se o exedente tiver \n, precisa já fazer *line ser o exedente, ver se tem exedente do exedente o.O e retornar. çocorro
	while (((read_return = read(fd, read_str, BUFFER_SIZE)) != READ_EOF) &&
			!(ft_strchr(read_str, '\n')))
	{
		read_str[read_return] = '\0';
		if (excedente[i])
		{
			line_str = ft_strjoin(line_str, excedente);
			printf("LINE + EXCEDENTE:%s\n", line_str);
		}
		printf("LINHA QUE FOI LIDA COM O READ:%s\n", read_str);
		line_str = ft_strjoin(line_str, read_str);
	}
	while ((read_str[i] != '\n') && (read_str[i] != EOF))
	{
		temp[i] = read_str[i];
		i++;
	}
	temp[i] = '\0';
	line_str = ft_strjoin(line_str, temp);
	j = 0;
	i++;
	while (i < BUFFER_SIZE)
	{
		excedente[j] = read_str[i]; 	
		i++;
		j++;
	}
	excedente[j] = '\0';
	printf("EXCEDENTE: %s\n", excedente);
	printf("LINHA SALVA QUANDO A QUEBRA DE LINHA FOI ENCONTRADA: %s\n", line_str);
	*line = line_str;
	return (read_return);
}
































	// char		*line_str;
	// char		*str_read;
	// char		*end_line_ptr;
	// int			read_return;

	// line_str = *line;
	// if (!(line_str) || !(str_read = (char*)calloc((BUFFER_SIZE + 1), sizeof(char))))
	// 	return (-1);
	// read_return = read(fd, str_read, BUFFER_SIZE);
	// while ((end_line_ptr = ft_strchr(str_read, '\n')) == NULL)
	// {	printf("str_read: %s\n", str_read);
	// 	if ((read_return == -1) || (read_return == 0))
	// 	{
	// 		free(str_read);
	// 		free(line_str);
	// 		return (read_return);
	// 	}
	// 	line_str = ft_strjoin(line_str, str_read);
	// 	printf("line_str: %s\n", line_str);
	// 	read_return = read(fd, str_read, BUFFER_SIZE);
	// }
	// str_read[BUFFER_SIZE] = '\0';
	// *end_line_ptr = '\0';
	// line_str = ft_strjoin(line_str, str_read);
	// *line = line_str;
	// return (1);
