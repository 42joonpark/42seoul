/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:29:11 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/21 13:54:07 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/stat.h>

int	check_file_type(const char *filepath)
{
	struct stat	buf;

	stat(filepath, &buf);
	if (S_ISREG(buf.st_mode))
		return (REGULAR);
	else if (S_ISDIR(buf.st_mode))
		return (DIRECTORY);
	else
		return (WRONG_MODE);
}
