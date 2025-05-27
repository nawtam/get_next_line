/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:39:39 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/27 22:37:41 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*tmp = NULL;
	int				bytes;
	char			buf[BUFFER_SIZE + 1];
	int 			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = tmp;
	tmp = NULL;
	bytes = 1;
	while (bytes > 0)
	{
		i = -1;
		bytes = read(fd, buf, BUFFER_SIZE);
		while (++i <= bytes && bytes > 0)
		{
			line = ft_strjoin(line, buf[i]);
			if (buf[i] == '\n')
			{
				tmp = (ft_statictmp(buf, i, bytes));
				return (line);
			}
		}
	}
	free (line);
	return (NULL);
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// int main()
// {
// 	int	fd = open("text.txt", O_RDONLY);
// 	char *line;

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	// while (1)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	if (!line)
// 	// 		break ;
// 	// 	printf("%s", line);
// 	// 	free (line);
// 	// }
// 	close(fd);
// 	return (0);
// }