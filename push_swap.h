/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:18:45 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/29 19:55:41 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
typedef struct s_pile
{
	int				content;
	int				index;
	
	struct 			s_pile *next;
	
}		t_pile;


int main(int ac, char **av);
void push_number(t_pile **first, int new_data);
int	ft_atoi(const char *str);

void swap_a(t_pile **pile);
void swap_b(t_pile **pile);
void push_a(t_pile **pile_a, t_pile **pile_b);
void push_b(t_pile **pile_a, t_pile **pile_b);
void free_list(t_pile **pile);
void ss(t_pile **pile_a, t_pile **pile_b);
void rotate_a(t_pile **pile);
void rotate_b(t_pile **pile);
void reverse_rotate_a(t_pile **pile);
void reverse_rotate_b(t_pile **pile);
void rrr(t_pile **pile_a, t_pile **pile_b);

int is_double(int *tab);
int is_number(char **tab);
int is_max_size(int *tab);

int tri(t_pile **pile_a, t_pile **pile_b, int *tab);
int last_lst(int nb, t_pile **pile_a, t_pile **pile_b);
void print_all(t_pile **pile_a, t_pile **pile_b);
int	lstsize(t_pile *lst);
int *fill_tab(char **av, int ac);
void tri2(t_pile **pile_a, t_pile **pile_b, int chunk, int *tab);
void tri_3(t_pile **pile_a);
int	lstsize(t_pile *lst);
t_pile  *addr(t_pile **pile, int mid);
int  inf(t_pile **pile, int mid);
int	*ft_sort_int_tab(int *tab, int size);
void add_index(t_pile **pile_a, t_pile **pile_b);
void	tri_5(t_pile **pile_a, t_pile **pile_b, int *tab);
int	lst_cont(t_pile **pile);
void    tri_g(t_pile **pile_a, t_pile **pile_b, int *tab, int size);
void suivant(t_pile **pile_a, t_pile **pile_b, int *tab, int size);




#endif