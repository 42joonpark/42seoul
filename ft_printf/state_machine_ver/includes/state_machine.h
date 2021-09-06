/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:00:31 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 15:09:00 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_MACHINE_H
# define STATE_MACHINE_H

enum	tokens
{
    TK_PERCENTAGE = 0,
    TK_ONE_NINE,
    TK_NULL,
    TK_DOT,
    TK_ASTERISK,
    TK_HYPEN,
    TK_ZERO,
    TK_SPECIFIER,
    TK_ELSE
};

int 	get_token(char input);
int 	get_state(int state, int input);

#endif
