/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:57:43 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/21 15:14:10 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;
	int			lenght;
	int			i;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	lenght = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i] != '\0' || buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	line = ft_substr(buffer, 0, i);
	line[i] = '\0';
	return (line);
}

#include <stdio.h>
int	main(void)
{
	int	fd1 = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd1));
}