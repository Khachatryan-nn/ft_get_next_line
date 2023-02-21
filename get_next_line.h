/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:32:03 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/21 15:14:09 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100

#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int     ft_strlen(const char *s);
char    *ft_strdup(const char *s1);

#endif
#endif