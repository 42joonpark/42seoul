/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:00:14 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 18:32:33 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state_machine.h"

int		get_token(char input)
{
  if (input == '%')
    return (TK_PERCENTAGE);
  else if (input >= '1' && input <= '9')
    return (TK_ONE_NINE);
  else if (input == '\0')
    return (TK_NULL);
  else if (input == '.')
    return (TK_DOT);
  else if (input == '*')
    return (TK_ASTERISK);
  else if (input == '-')
    return (TK_HYPEN);
  else if (input == '0')
    return (TK_ZERO);
  else if (input == 'c' || input == 'd' || input == 's' ||
	  input == 'x' || input == 'X' || input == 'u' ||
	  input == 'i' || input == 'p')
    return (TK_SPECIFIER);
  else
    return (TK_ELSE);
  return (-1);
}

int		get_state(int state, int input)
{
	int	arr[81] = {	2, 1, 10, 1, 1, 1, 1, 1, 1,
	  				2, 1, 10, 1, 1, 1, 1, 1, 1,
					8, 3, -1, 5, 4, 2, 2, 8, -1,
	               	8, 3, -1, 5, -1, -1, 3, 8, -1,
	               	8, -1, -1, 5, -1, -1, -1, 8, -1,
	               	8, 6, -1, -1, 7, -1, 6, 8, -1,
	               	8, 6, -1, -1, -1, -1, 6, 8, -1,
	               	8, -1, -1, -1, -1, -1, -1, 8, -1
				};
  
  return (arr[(state * 9) + input]);
}
