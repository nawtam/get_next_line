/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:39:39 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/27 14:23:48 by ntamacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_statictmp(char *buf, int i, int bytes)
{
	char	*tmp;
	int		j;

	j = 0;
	i++;
	tmp = malloc(bytes - i + 1);
	if (!tmp)
		return (NULL);
	while (i <= (bytes - 1))
	{
		tmp[j] = buf[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*tmp = NULL;
	int				bytes;
	char			buf[BUFFER_SIZE + 1];
	int 			i;

	line = tmp;
	while (1)
	{
		i = 0;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		while (i <= (bytes - 1) && bytes > 0)
		{
			line = ft_strjoin(line, buf[i]);
			if (buf[i] == '\n')
			{
				tmp = (ft_statictmp(buf, i, bytes));
				return (line);
			}
			i++;
		}
	}
	free (line);
	return (NULL);
}


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int	fd = open("text.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (!line)
	// 		break ;
	// 	printf("%s", line);
	// 	free (line);
	// }
	close(fd);
	return (0);
}