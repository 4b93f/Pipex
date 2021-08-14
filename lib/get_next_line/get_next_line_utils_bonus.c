/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:24:12 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/23 16:54:23 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_error(int fd, char *str)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];

	i = 0;
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}
