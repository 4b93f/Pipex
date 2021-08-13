/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:11:25 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/13 22:19:29 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exec(t_sh *sh, char **argp, char *file, int x)
{
	if (x == 0)
	{
		dup2(sh->fd_in, 0);
		dup2(sh->pipe_fd[1], 1);
		close(sh->pipe_fd[1]);
		close(sh->pipe_fd[0]);
		error(sh, execve(file, argp, sh->env), argp[0]);
		exit(0);
	}
	else
	{
		dup2(sh->fd_out, 1);
		dup2(sh->pipe_fd[0], 0);
		error(sh, execve(file, argp, sh->env), argp[0]);
		close(sh->pipe_fd[0]);
		exit(0);
	}
}

void exec_cmd(t_sh *sh, int x, char **env)
{
	char *file;
	char **envp;
	char **argp;
	pid_t pid;

	if (x == 0)
	{
		file = ft_strjoin(ft_search_path(sh, sh->str1), sh->str1);
		argp = ft_split(sh->str1, ' ');
	}
	else
	{
		file = ft_strjoin(ft_search_path(sh, sh->str2), sh->str2);
		argp = ft_split(sh->str2, ' ');
	}
	pid = fork();
	if (pid == 0 && x == 0)
		exec(sh, argp, file, x);
	if (pid == 0 && x == 1)
		exec(sh, argp, file, x);
	free_tab(argp);
	free(file);
}
