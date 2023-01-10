/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:40:04 by aikram            #+#    #+#             */
/*   Updated: 2023/01/10 08:40:14 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	errs(int e)
{
	err1(e);
	exit(1);
}

void	err1(int e)
{
	if (!e)
		perror("error\nargument count\n");
	else if (e == 1)
		perror("error\noccured while opening file\n");
	else if (e == 2)
		perror("Fork: ");
	else if (e == 3)
		perror("error\noccured while opening pipe\n");
	else if (e == 4)
		perror("access: ");
	else if (e == 5)
		perror("execve: ");
}
