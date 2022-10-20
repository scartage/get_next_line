/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:24:35 by scartage          #+#    #+#             */
/*   Updated: 2022/03/01 13:17:43 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* funciones/herramientas */

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

/*funciones dentro del get para "procesar" lo que guardamos/mostramos */

char	*get_next_line(int fd);
char	*goto_read(int fd, char	*save);
char	*make_line(char			*save);
char	*save_next_line(char	*save);
#endif
