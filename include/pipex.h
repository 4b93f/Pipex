/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:47:56 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/14 22:54:31 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "errno.h"
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../lib/libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include "../lib/get_next_line/get_next_line.h"

# define ARGC 888
# define ENV_ERROR 333
# define ARG_ERROR 555
# define PATH_ERROR 444
# define OPEN_ERROR 666
# define PIPE_ERROR 999
# define MALLOC_ERROR 777

typedef struct s_sh
{
	char	*str1;
	char	*str2;
	char	*file;
	char	**env;
	int		fd_in;
	int		fd_out;
	char	*free_ptr;
	char	**all_path;
	int		pipe_fd[2];
	int		fd_backup[2];
}				t_sh;

t_sh	*ft_malloc_sh(char **argv);
void	free_engine(t_sh *sh);
void	error(t_sh *sh, int x, char *str);
char	*ft_search_path(t_sh *sh, char *str);
void	exec_cmd(t_sh *sh, int x, char **env);

#endif