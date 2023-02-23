/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:32:03 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/23 19:25:10 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100

#endif

#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*exclude_excess_part(char *backup, int i);
char	*find_next_line(int fd, char *backup, char *buffer);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int     ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
char    *ft_strchr(const char *s, int c);

#endif