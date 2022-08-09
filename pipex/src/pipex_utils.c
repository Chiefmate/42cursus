/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:15:24 by hyunhole          #+#    #+#             */
/*   Updated: 2022/07/14 16:15:24 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int code, char *msg)
{
	perror(msg);
	exit(code);
}

void	ft_error_free_in(t_input *in, int code, char *msg)
{
	int	i;

	if (in->cmd0 != NULL)
		free(in->cmd0);
	if (in->cmd1 != NULL)
		free(in->cmd1);

	i = 0;
	while (in->cmd_arg0[i])
		free(in->cmd_arg0[i++]);
	if (in->cmd_arg0)
		free(in->cmd_arg0);

	i = 0;
	while (in->cmd_arg1[i])
		free(in->cmd_arg1[i++]);
	if (in->cmd_arg1)
		free(in->cmd_arg1);

	i = 0;
	while (in->path[i])
		free(in->path[i++]);
	if (in->path)
		free(in->path);

	perror(msg);
	exit(code);
}