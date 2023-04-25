#include "push_swap.h"

void swap_a(t_pile **pile)
{
	t_pile *tmp = *pile;
	int i;
	
	printf("sa\n");
	i = tmp->content;
	if ((*pile)->next != NULL && pile != NULL)
	{
		(*pile)->content = (*pile)->next->content;
		(*pile)->next->content = i;
	}
}

 void swap_b(t_pile **pile)
 {
	printf("sb\n");
	t_pile *tmp = *pile;
	int i;

	i = tmp->content;
	if ((*pile)->next != NULL && pile != NULL)
	{
		(*pile)->content = (*pile)->next->content;
		(*pile)->next->content = i;
	}
	
 }

void ss(t_pile **pile_a, t_pile **pile_b)
{
	//printf("ss\n");
	swap_a(pile_a);
	swap_b(pile_b);
}