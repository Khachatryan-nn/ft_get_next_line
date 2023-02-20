/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:57:43 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/20 19:45:28 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		lenght;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	lenght = read(fd, buffer, BUFFER_SIZE);

}