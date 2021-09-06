/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:54:50 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 11:01:05 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* 
** ====================
** includes
** ====================
*/

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* 
** ====================
** typedef
** ====================
*/

# define LLINT		long long int
# define A_STACK	0
# define B_STACK	1
# define A_TOP		body->stack_a->top
# define B_TOP		body->stack_b->top
# define PIVOT1		pivot->first
# define PIVOT2		pivot->second

typedef struct s_merge
{
	int	n1;
	int	n2;
	int	l;
	int	m;
	int	r;
	int	k;
	int	*left;
	int	*right;
}		t_merge;

typedef struct s_nbr
{
	LLINT			val;
	int				res;
}					t_nbr;

typedef struct s_arr
{
	LLINT			*arr;
	int				size;
}					t_arr;

typedef struct s_info
{
	int				size;
	char			stack_name;
	struct s_info	*next;
}					t_info;

typedef struct s_istack
{
	t_info			*top;
}					t_istack;

typedef struct s_pivot
{
	int				first;
	int				second;
	int				size1;
	int				size2;
}					t_pivot;

typedef struct s_node
{
	LLINT			value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bot;
	int				length;
}					t_stack;

typedef struct s_body
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	LLINT			median;
	int				cur_sort_cnt;
	int				size;
	int				ins_ct;
	int				flag;
}					t_body;

/* 
** ====================
** src/algorithm
** ====================
*/

int		insert_sort(LLINT *arr, int size);
int		merge_sort(LLINT *arr, int l, int r);

/* 
** ====================
** src/body
** ====================
*/

int		free_body(t_body *body);
int		fatal_body(t_body *body, const char *msg);
int		init_body(t_body *body);

/* 
** ====================
** src/errors
** ====================
*/

int		error(const char *msg);
void	*ptr_error(const char *msg);
void	fatal(const char *msg);

/* 
** ====================
** src/init
** ====================
*/

LLINT	*check(t_arr *numbers, int argc, char *argv[]);
int		find_strs_lenfth(char ***strs);
void	free_strs(char ***strs);

/* 
** ====================
** src/instructions
** ====================
*/

int		pa(t_body *body, int flag);
int		pb(t_body *body, int flag);
int		ra(t_body *body, int flag);
int		rb(t_body *body, int flag);
int		rr(t_body *body, int flag);
int		sa(t_body *body, int flag);
int		sb(t_body *body, int flag);
int		ss(t_body *body, int flag);
int		rra(t_body *body, int flag);
int		rrb(t_body *body, int flag);
int		rrr(t_body *body, int flag);

/* 
** ====================
** src/push_swap
** ====================
*/

int		push_swap(t_body *body);
int		sort_small(t_body *body, int len);
int		find_pivot(t_body *body, t_pivot *pivot, int stack_len, char stack_name);
int		find_median(t_body *body, int *pivot, int len, char stack_name);
int		a_to_b(t_body *body, int len);
int		b_to_a(t_body *body, int len);
void	sort_2(t_body *body);
void	sort_3(t_body *body);
void	sort_5(t_body *body);

/* 
** ====================
** src/checker_program
** ====================
*/

int		checker_program(t_body *body);
int		checker_program_helper(t_body *body, char *line);

/* 
** ====================
** src/stack
** ====================
*/

int		stack_init(t_stack *s);
int		is_empty(t_stack *s);
int		push_top(t_stack *s, t_node *node);
t_node	*pop_top(t_stack *s);
void	iter(t_stack *s);
int		free_stack(t_stack *s);
int		get_stack_length(t_stack *s);
t_node	*get_new_node(LLINT value);
int		is_stack_sorted(t_stack *s);

int		info_stack_init(t_istack *s);
int		info_is_empty(t_istack *s);
int		info_push_top(t_istack *s, t_info *info);
t_info	*info_pop_top(t_istack *s);
int		free_istack(t_istack *s);
t_info	*get_new_info(int size, char stack_name);


/* 
** ====================
** src/utils
** ====================
*/

int		js_strcmp(const char *s1, const char *s2);
int		js_strlen(const char *str);
t_nbr	js_strnbr(const char *str);
char	*js_strchr(char *str, char c);
char	*js_strjoin(const char *s1, const char *s2);
char	*js_strndup(char *str, int size);
char	**js_split(const char *str, char c);
int		check_duplicate(LLINT *arr, int size);
int		get_line(int fd, char **line);

#endif
