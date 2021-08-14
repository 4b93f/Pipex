/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:11:25 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/14 22:58:40 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec(t_sh *sh, char **argp, char *file, int x)
{
	if (x == 0)
	{
		dup2(sh->fd_in, 0);
		dup2(sh->pipe_fd[1], 1);
		close(sh->pipe_fd[1]);
		close(sh->pipe_fd[0]);
		error(sh, execve(file, argp, sh->env), argp[0]);
	}
	else
	{
		dup2(sh->fd_out, 1);
		dup2(sh->pipe_fd[0], 0);
		close(sh->pipe_fd[0]);
		error(sh, execve(file, argp, sh->env), argp[0]);
	}
}

char	*bultin(char *str)
{
	int		i;
	int		j;
	char	*dup;

	j = -1;
	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	dup = malloc(sizeof(char *) * i + 1);
	if (!dup)
		return (NULL);
	while (++j < i)
		dup[j] = str[j];
	dup[j] = '\0';
	return (dup);
}

void	exec_cmd(t_sh *sh, int x, char **env)
{
	char	*file;
	char	*built_in;
	char	**argp;
	pid_t	pid;

	if (x == 0)
	{
		built_in = bultin(sh->str1);
		file = ft_strjoin(ft_search_path(sh, built_in), built_in);
		argp = ft_split(sh->str1, ' ');
	}
	else
	{
		built_in = bultin(sh->str2);
		file = ft_strjoin(ft_search_path(sh, built_in), built_in);
		argp = ft_split(sh->str2, ' ');
	}
	pid = fork();
	if (pid == 0 && x == 0)
		exec(sh, argp, file, x);
	if (pid == 0 && x == 1)
		exec(sh, argp, file, x);
	free(built_in);
	free(file);
	free_tab(argp);
}
