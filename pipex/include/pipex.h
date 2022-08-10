/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:33:38 by hyunhole          #+#    #+#             */
/*   Updated: 2022/07/13 13:33:38 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_input {
	int		infd;
	int		outfd;
	char	**path;
	char	*cmd0;
	char	**cmd_arg0;
	char	*cmd1;
	char	**cmd_arg1;
	int		pipe_fd[2];
	pid_t	pid;
}				t_input;

char	**get_path(char *envp[]);
char	*get_cmd_argv(char **path, char *cmd);
int		parse_input(t_input *in, char *av[], char *envp[]);
void	handle_fd(int fd_close, int std_in, int std_out);

void	ft_error(int code, char *msg);
void	ft_error_free_in(t_input *in, int code, char *msg);

#endif