/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:47:07 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/13 22:18:19 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_search_path(t_sh *sh, char *str)
{
	struct stat	buffer;
	char		*tmp;
	int			i;

	i = -1;
	while (sh->all_path && sh->all_path[++i])
	{
		tmp = ft_strjoin(sh->all_path[i], str);
		if (!tmp)
			return (NULL);
		if (!stat(tmp, &buffer))
		{
			free(tmp);
			return (sh->all_path[i]);
		}
		free(tmp);
	}
	return (NULL);
}

void	get_all_path(t_sh *sh, char **env)
{
	int			i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return ;
	sh->all_path = ft_split(env[i], ':');
	if (!sh->all_path)
		return ;
	i = -1;
	while (sh->all_path[++i])
	{
		sh->free_ptr = sh->all_path[i];
		sh->all_path[i] = ft_strjoin(sh->all_path[i], "/");
		free(sh->free_ptr);
	}
}

int pipe_engine(t_sh *sh)
{
	
	int pid;
	if (pipe(sh->pipe_fd) == -1)
		error(sh, PIPE_ERROR, NULL);
	if ((pid = fork()) == -1)
		strerror(errno);
	if (pid == 0)
	{
		return(1);
	}
	else
	{
		return(2);
	}
}

void setup(t_sh *sh, char **env, char **argv)
{
	int	fd;
	int pid;
	
	fd = 0;
	sh->env = env;
	get_all_path(sh, env);
	if (!sh->all_path)
		error(sh, PATH_ERROR, NULL);
	sh->str1 = argv[2];
	sh->str2 = argv[3];
	sh->fd_in = open(argv[1], O_RDONLY);
	if (sh->fd_in == -1)
		error(sh, OPEN_ERROR, argv[1]);
	sh->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error(sh, OPEN_ERROR, argv[4]);
	pid = pipe_engine(sh);
	if (pid == 1)
	{
		exec_cmd(sh, 0, env);
		close(sh->pipe_fd[1]);
		exec_cmd(sh, 1, env);
	}
	else
		wait(0);
}
int main(int argc, char **argv, char **env)
{
	t_sh *sh;

	sh = ft_malloc_sh();
	if (!sh)
		return (0);
	if (argc != 5)
		error(sh, ARGC, NULL);
	setup(sh, env, argv);
	free_engine(sh);
	return(1);
}