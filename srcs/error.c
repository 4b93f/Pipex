/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 21:32:32 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/14 22:59:55 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_engine(t_sh *sh)
{
	if (sh->all_path)
		free_tab(sh->all_path);
	free(sh);
	exit(0);
}

void	error(t_sh *sh, int x, char *str)
{
	dup2(sh->fd_backup[0], 0);
	dup2(sh->fd_backup[1], 1);
	if (x == ENV_ERROR)
		printf("Error with env\n");
	if (x == -1)
		printf("pipex: %s: command not found\n", str);
	if (x == ARGC)
		printf("Too much or less arguments\n");
	if (x == ARG_ERROR)
		printf("Error with argument\n");
	if (x == OPEN_ERROR)
		printf("pipex: %s: No suck file or directory\n", str);
	if (x == MALLOC_ERROR)
		printf("Malloc Error\n");
	if (x == PIPE_ERROR)
		printf("Error with pipe\n");
	if (x == PATH_ERROR)
		printf("Error with PATH\n");
	if (x == -1 || x == ARGC || x == ARG_ERROR
		|| x == OPEN_ERROR || x == PIPE_ERROR
		|| x == PATH_ERROR || x == ENV_ERROR)
		free_engine(sh);
	exit(0);
}
