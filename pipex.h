/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:47:56 by chly-huc          #+#    #+#             */
/*   Updated: 2021/08/13 22:18:01 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H
#include "lib/libft/libft.h"
#include "lib/get_next_line/get_next_line.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "errno.h"
#include <sys/types.h>
#include <sys/wait.h>

#define PATH_ERROR 444
#define ARG_ERROR 555
#define OPEN_ERROR 666
#define MALLOC_ERROR 777
#define ARGC 888
#define PIPE_ERROR 999

typedef struct	s_sh
{
	char *str1;
	char *str2;
	
	char *file;
	char **all_path;
	char **env;
	char *free_ptr;
	int fd_in;
	int fd_out;
	int pipe_fd[2];
	int fd_backup[2];
}				t_sh;

t_sh	*ft_malloc_sh(void);
char	*ft_search_path(t_sh *sh, char *str);
void exec_cmd(t_sh *sh, int x, char **env);
void error(t_sh *sh, int x, char *str);
void free_engine(t_sh *sh);

#endif