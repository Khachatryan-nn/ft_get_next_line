/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:57:43 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/23 21:06:21 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*find_next_line(int fd, char *backup, char *buffer)
{
	int		len;

	len = 0;
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
			return (0);
		else if (len == 0)
			break;
		buffer[len] = '\0';
		backup = ft_strjoin(backup, buffer);
		if (ft_strchr(backup, '\n'))
			break;
	}
	return (backup);
}

char	*exclude_excess_part(char *backup, int i)
{
	char	*temp;
	int		len;

	len = ft_strlen(backup);
	temp = ft_substr(backup, i, len);
	free(backup);
	backup = 0;
	backup = ft_substr(temp, 0, BUFFER_SIZE);
	free(temp);
	temp = 0;
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
    if (!backup)
    	backup = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	backup = find_next_line(fd, backup, buffer);
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		i++;
	}
	line = ft_substr(backup, 0, i + 1);
	backup = exclude_excess_part(backup, i + 1);
	free(buffer);
	buffer = 0;
	return (line);
}

int	main(void)
{
	int	fd1 = open("text.txt", O_RDONLY);
	printf("result of function:[[[[[%s]]]]]\n", get_next_line(1000));
	printf("result of function:[[[[[%s]]]]]\n", get_next_line(fd1));
	printf("result of function:[[[[[%s]]]]]\n", get_next_line(fd1));
	printf("result of function:[[[[[%s]]]]]\n", get_next_line(fd1));
}

#if 0

Latin is such a beautiful language
But I prefer to learn French
Because I'm in love with France
And with Paris also!

#endif