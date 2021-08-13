/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_sh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:55:15 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/13 22:10:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

t_sh	ft_create_sh(void)
{
	t_sh sh;

	sh.all_path = NULL;
	sh.fd_in = 0;
	sh.fd_out = 1;
	sh.fd_backup[0] = dup(0);
	sh.fd_backup[1] = dup(1);
	return (sh);
}

t_sh	*ft_malloc_sh(void)
{
	t_sh *malloc_sh;

	if (!(malloc_sh = malloc(sizeof(t_sh))))
		return (NULL);
	*malloc_sh = ft_create_sh();
	return (malloc_sh);
}

void	ft_free_sh(t_sh *sh)
{
	if (!sh)
		return ;
	free(sh);
}