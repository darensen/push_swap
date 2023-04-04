/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:18:45 by arnaud            #+#    #+#             */
/*   Updated: 2023/04/04 17:01:46 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"



typedef struct s_pile
{
	int				content;
	int				index;
	
	struct 			s_pile *next;
	
}		t_pile;

int main(int ac, char **av);

// OPERATIONS
void rotate_a(t_pile **pile);
void rotate_b(t_pile **pile);
void swap_a(t_pile **pile);
void swap_b(t_pile **pile);
void push_a(t_pile **pile_a, t_pile **pile_b);
void push_b(t_pile **pile_a, t_pile **pile_b);
void free_list(t_pile **pile);
void ss(t_pile **pile_a, t_pile **pile_b);
void rotate(t_pile **pile);
void reverse_rotate_a(t_pile **pile);
void reverse_rotate_b(t_pile **pile);
void rrr(t_pile **pile_a, t_pile **pile_b);

// UTILS
void push_number(t_pile **first, int new_data);
int tab_len(int *tab);
int	ft_mediane(int *tab);
int last_content(t_pile **pile);
t_pile *add_index_a(t_pile **pile_a);
t_pile *add_index_b(t_pile **pile_b);
void add_index(t_pile **pile_a, t_pile **pile_b);
int *sorted_tab(int *tab);
t_pile *find_adress(t_pile **pile_a, int mid);
int is_sorted(t_pile **pile_a, int nb);
void print_all(t_pile **pile_a, t_pile **pile_b);
int is_double(int *tab);
int is_number(char **tab);
int is_max_size(int *tab);
void sort(t_pile **pile_a, t_pile **pile_b);
int	lstsize(t_pile *pile);
int *fill_tab(char **av, int ac);
int find_smallest(t_pile **pile);
int find_biggest(t_pile **pile);
int    lst_cont(t_pile **pile);
int search(t_pile **pile, int val);


// ALGO
void    tri_4(t_pile **pile_a, t_pile **pile_b, int *tab);
void algo(t_pile **pile_a, t_pile **pile_b, int *tab);
void tri_5(t_pile **pile_a, t_pile **pile_b, int *tab);
void tri_3(t_pile **pile_a);

#endif