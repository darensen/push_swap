#include "push_swap.h"

void swap_a(t_pile **pile)
{

	if (!pile)
		return ;
	t_pile *temp = *pile;
	while (temp->next->next->next != NULL) // on parcours jusqu'a l'avant dernier
		temp = temp->next;

	t_pile *third_to_last = temp;
	t_pile *last = temp->next->next;
	t_pile *second_to_last = temp->next;
	
	third_to_last->next = last;
	second_to_last->next = NULL;
	last->next = second_to_last;

 }

 void swap_b(t_pile **pile)
 {
	
	if (!pile)
		return ;
	t_pile *temp = *pile;
	while (temp->next->next->next != NULL) // on parcours jusqu'a l'avant avant dernier
		temp = temp->next;

	t_pile *third_to_last = temp;
	t_pile *last = temp->next->next;
	t_pile *second_to_last = temp->next;
	
	third_to_last->next = last;
	second_to_last->next = NULL;
	last->next = second_to_last;
 }
