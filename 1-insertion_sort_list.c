#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	int flag = 0;
	listint_t *node = NULL, *next_node = NULL, *upTillNow = NULL;

	if (list == NULL || *list == NULL || get_size(list) < 2)
		return;
	node = *list;
	next_node = node->next;
	upTillNow = next_node;
	while (upTillNow != NULL)
	{
		if (next_node->n < node->n)
		{
			upTillNow = next_node->next;
			list = swap(node, next_node, list);
			node = next_node->prev;
			flag = 1;
			while (node != NULL)
			{
				next_node = node->next;
				if (next_node->n < node->n)
				{
					list = swap(node, next_node, list);
					node = next_node->prev;
				}
				else
					break;
			}
		}
		else
		{
			node = next_node;
			next_node = node->next;
			upTillNow = next_node;
			flag = 0;
		}
		if (flag == 1 && upTillNow != NULL)
		{
			node = upTillNow->prev, next_node = upTillNow;
		}
	}
}
/**
 * swap - swaps two nodes
 * @node: first node
 * @next_node: next node
 * @list: pointer to pointer to list
 * Return: pointer to pointer to updated list
 */
listint_t **swap(listint_t *node, listint_t *next_node, listint_t **list)
{
	listint_t *previous = NULL, *following = NULL;

	previous = node->prev;
	next_node->prev = previous;
	following = next_node->next;
	node->next = following;
	next_node->next = node;
	node->prev = next_node;
	if (following != NULL)
		following->prev = node;
	if (previous != NULL)
		previous->next = next_node;
	if (previous == NULL)
		*list = next_node;
	print_list(*list);
	return (list);
}
/**
 * get_size - gets size of list
 * @list: pointer to pointer to list
 * Return: size
 */
int get_size(listint_t **list)
{
	int size = 0;
	listint_t *node = NULL;

	node = *list;
	while (node != NULL)
	{
		size++;
		node = node->next;
	}
	return (size);
}
