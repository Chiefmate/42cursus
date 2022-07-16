/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:33:01 by hyunhole          #+#    #+#             */
/*   Updated: 2022/07/13 13:33:01 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char *envp[])
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	if (!envp[i])
		ft_error(127, "PATH error");
	path = envp[i] + 5;
	return (ft_split(path, ':'));
}

char	*get_cmd_argv(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	*target_path;
	char	*temp;

	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	target_path = ft_strjoin("/", cmd);
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], target_path);
		fd = access(temp, X_OK);
		if (fd != -1)
		{
			free(target_path);
			return (temp);
		}
		close(fd);
		free(temp);
		i++;
	}
	free(target_path);
	return (NULL);
}

int	parse_input(t_input *in, char *av[], char *envp[])
{
	int	ret;

	ret = 1;
	in->infd = open(av[1], O_RDONLY);
	if (in->infd == -1)
		ft_error(1, "infile error");
	in->outfd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (in->outfd == -1)
		ft_error(1, "outfile error");
	in->path = get_path(envp);
	in->cmd_arg[0] = ft_split(av[2], ' ');
	in->cmd_arg[1] = ft_split(av[3], ' ');
	in->cmd[0] = get_cmd_argv(in->path, in->cmd_arg[0][0]);
	in->cmd[1] = get_cmd_argv(in->path, in->cmd_arg[1][0]);
	if (!in->cmd[0] || !in->cmd[1])
	{
		ret = 127;
		perror("command not found");
	}
	return (ret);
}

void	fd_part(int fd_close, int std_in, int std_out)
{
	close(fd_close);
	if (dup2(std_in, STDIN_FILENO) == -1)
		ft_error(1, "dup2 error");
	if (dup2(std_out, STDOUT_FILENO) == -1)
		ft_error(1, "dup2 error");
	close(std_in);
	close(std_out);
	return ;
}

int	main(int ac, char *av[], char *envp[])
{
	t_input	in;
	int		ret;

	if (ac != 5)
		ft_error(1, "not valid input");
	ret = parse_input(&in, av, envp);
	if (pipe(in.pipe_fd) < 0)
		ft_error(1, "pipe error");
	in.pid = fork();
	if (in.pid == -1)
		ft_error(1, "fork error");
	else if (in.pid == 0)
	{
		fd_part(in.pipe_fd[0], in.infd, in.pipe_fd[1]);
		if (execve(in.cmd[0], in.cmd_arg[0], envp) == -1)
			ft_error(ret, "execve error");
	}
	else
	{
		fd_part(in.pipe_fd[1], in.pipe_fd[0], in.outfd);
		if (execve(in.cmd[1], in.cmd_arg[1], envp) == -1)
			ft_error(ret, "execve error");
	}
	return (0);
}