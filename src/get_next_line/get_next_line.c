/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:32:59 by glajara-          #+#    #+#             */
/*   Updated: 2023/09/28 21:04:37 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Frees the pointeris at *p1 and p2 (if any).
// *p1 points at NULL and returns NULL.
static void	*gnl_free(char **p1, char *p2)
{
	if (p2)
		free(p2);
	if (*p1)
	{
		free(*p1);
		*p1 = NULL;
	}
	return (NULL);
}

// Allocates (with malloc(3)) and returns a new string, which is the result of
// substracting the first line from storage, knowing its of length 'len'.
// At the end, the returned string is cleared from 'storage' (and original 
// storage is freed).
static char	*pop_line(char **storage, size_t len)
{
	char	*line;
	char	*newstorage;

	line = gnl_substr(*storage, 0, len);
	if (!line)
		return (NULL);
	newstorage = gnl_substr(*storage, len, SIZE_MAX);
	if (!newstorage)
	{
		free(line);
		return (NULL);
	}
	free(*storage);
	*storage = newstorage;
	if (gnl_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// Finds the first line feed (\n) in 'str', starting from index 'i'.
// If found, 'i' is the index of the first \n found in 'str' and returns 'i'.
// Otherwise, 'i' is the lenght of 'str' and returns -1. 
static int	find_lf(char *str, size_t *i)
{
	while (str && str[*i])
	{
		if (str[*i] == '\n')
			return (*i);
		(*i)++;
	}
	return (-1);
}

// Reads the file descriptor 'fd' into 'storage' until a LF (\n) is found,
// returning the new value of 'storage'.
// If LF is found 'lf' is its index inside 'storage'. 
// Otherwise, 'lf' is the index of the last character inside 'storage'.
static char	*feed_storage(char **storage, int fd, size_t *lf)
{
	char	*buf;
	int		read_bytes;

	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (gnl_free(storage, NULL));
	read_bytes = 1;
	while (find_lf(*storage, lf) == -1 && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buf[read_bytes] = '\0';
			if (!gnl_strjoin_free(storage, buf))
				return (gnl_free(storage, buf));
		}
		else if (read_bytes == -1)
			return (gnl_free(storage, buf));
	}
	free(buf);
	return (*storage);
}

// Reads from file descriptor 'fd' and returns the next line (ending with a LF.
// The function is supposed to be called multiple times inside a loop.
char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX] = {NULL};
	size_t		lf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lf = 0;
	if (!storage[fd] || find_lf(storage[fd], &lf) == -1)
		storage[fd] = feed_storage(&storage[fd], fd, &lf);
	if (!storage[fd])
		return (NULL);
	line = pop_line(&storage[fd], lf + 1);
	if (!line)
		return (gnl_free(&storage[fd], NULL));
	return (line);
}
