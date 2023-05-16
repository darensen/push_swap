/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:18:45 by arnaud            #+#    #+#             */
/*   Updated: 2023/05/16 16:17:53 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

typedef struct s_pile
{
	int				content;
	int				index;	
	struct s_pile	*next;
}		t_pile;

typedef struct s_struct
{
	int				index_a;
	int				index_b;
	int				calcul;
	int				val;
	int				imaxa;
	int				imaxb;
	int				mouv;
}		t_struct;

int			main(int ac, char **av);

// OPERATIONS
void		rotate_a(t_pile **pile);
void		rotate_b(t_pile **pile);
void		swap_a(t_pile **pile);
void		swap_b(t_pile **pile);
void		push_a(t_pile **pile_a, t_pile **pile_b);
void		push_b(t_pile **pile_a, t_pile **pile_b);
void		free_list(t_pile **pile);
void		ss(t_pile **pile_a, t_pile **pile_b);
void		rotate(t_pile **pile);
void		reverse_rotate_a(t_pile **pile);
void		reverse_rotate_b(t_pile **pile);
void		rrr(t_pile **pile_a, t_pile **pile_b);
void		rr(t_pile **pile_a, t_pile **pile_b);

// UTILS
void		push_number(t_pile **first, int new_data);
int			tab_len(int *tab);
int			last_content(t_pile **pile);
t_pile		*add_index_a(t_pile **pile_a);
t_pile		*add_index_b(t_pile **pile_b);
void		add_index(t_pile **pile_a, t_pile **pile_b);
int			*sorted_tab(int *tab, int size);
int			is_sorted(t_pile **pile_a, int nb);
void		print_all(t_pile **pile_a, t_pile **pile_b);
int			is_double(int *tab, int size);
int			is_number(char **tab);
int			is_max_size(int *tab, int size);
void		sort(t_pile **pile_a, t_pile **pile_b);
int			lstsize(t_pile *pile);
int			*fill_tab(char **av, int ac, int ac0);
int			find_smallest(t_pile **pile);
int			find_biggest(t_pile **pile);
int			lst_cont(t_pile **pile);
int			search(t_pile **pile, int val);
t_pile		*pile_last(t_pile **lst);
void		pile_addfront(t_pile **lst, t_pile *new);
void		ft_swap(int *a, int *b);
char		**ft_split(char const *s, char c);
int			ft_isdigit2(char c);

// ALGO
void		tri_4(t_pile **pile_a, t_pile **pile_b, int *tab);
void		algo(t_pile **pile_a, t_pile **pile_b, int *tab, int size);
void		tri_5(t_pile **pile_a, t_pile **pile_b, int *tab);
void		tri_3(t_pile **pile_a);
void		exec_if(t_pile **pile_a, t_pile **pile_b);
int			nb_moves(int index_a, int index_b, t_pile **a, t_pile **b);
int			which_combo(int index_a, int index_b, t_pile **a, t_pile **b);
void		mouv_if_rrr(t_pile **pile_a, t_pile **pile_b, t_struct info);
void		mouv_if_rr(t_pile **pile_a, t_pile **pile_b, t_struct tab);
void		mouv_if_rrarb(t_pile **pile_a, t_pile **pile_b, t_struct tab);
void		mouv_if_rarrb(t_pile **pile_a, t_pile **pile_b, t_struct tab);
void		exec(t_pile **pile_a, t_pile**pile_b);
void		sorted_final(t_pile **pile_a);
int			is_sorted2(t_pile **pile_a);
int			ft_isdigit(char c);
int			ft_atoi(const char *nptr);
t_struct	optimal_bloc(t_pile **pile_a, t_pile **pile_b);
#endif
