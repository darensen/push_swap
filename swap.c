#include "push_swap.h"

void swap_a(t_pile **pile)
{
	t_pile *temp = *pile;
	int i = temp->content;
	t_pile *third_to_last;
	t_pile *last;
	t_pile *second_to_last;

	if (!pile)
		return ;
	if (temp->next->next == NULL)
	{
		temp->content = temp->next->content;
		temp->next->content = i;
		return ;
	}
	while (temp->next->next->next != NULL) // on parcours jusqu'a l'avant avant dernier
		temp = temp->next;
	third_to_last = temp;
	last = temp->next->next;
	second_to_last = temp->next;
	third_to_last->next = last;
	second_to_last->next = NULL;
	last->next = second_to_last;
}

 void swap_b(t_pile **pile)
 {
	t_pile *temp = *pile;
	int i = temp->content;
	t_pile *third_to_last;
	t_pile *last;
	t_pile *second_to_last;

	if (!pile)
		return ;
	if (temp->next->next == NULL)
	{
		temp->content = temp->next->content;
		temp->next->content = i;
		return ;
	}
	while (temp->next->next->next != NULL) // on parcours jusqu'a l'avant avant dernier
		temp = temp->next;
	third_to_last = temp;
	last = temp->next->next;
	second_to_last = temp->next;
	third_to_last->next = last;
	second_to_last->next = NULL;
	last->next = second_to_last;
 }

void ss(t_pile **pile_a, t_pile **pile_b)
{
	swap_a(pile_a);
	swap_b(pile_b);
}