/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamacha <ntamacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:39:33 by ntamacha          #+#    #+#             */
/*   Updated: 2025/05/27 22:31:39 by ntamacha         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (s1 && s1[i])
		i++;
	new = malloc(i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	free(s1);
	return (new);
}
