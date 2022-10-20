/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:26:19 by scartage          #+#    #+#             */
/*   Updated: 2022/03/01 14:55:33 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_line(char	*save)
{
	int		i;
	char	*str;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*save_next_line(char	*save)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	c = 0;
	while (save[i] != '\0')
		str[c++] = save[i++];
	str[c] = '\0';
	free(save);
	return (str);
}

char	*goto_read(int fd, char	*save)
{
	int		checker;
	char	*buff_aux;

	buff_aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff_aux == NULL)
		return (NULL);
	checker = 1;
	while (ft_strchr(save, '\n') == NULL && checker != 0)
	{
		checker = read(fd, buff_aux, BUFFER_SIZE);
		if (checker == -1)
		{
			free(save);
			free(buff_aux);
			return (NULL);
		}
		buff_aux[checker] = '\0';
		save = ft_strjoin(save, buff_aux);
	}
	free(buff_aux);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = goto_read(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	line = make_line(save[fd]);
	save[fd] = save_next_line(save[fd]);
	return (line);
}
