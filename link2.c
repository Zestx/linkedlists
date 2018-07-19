//LINKED LISTS PRACTICE
#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct node
{
	int n;
	struct node *next;
}Node;
//Here I use a struct to contain eventual informations about the list(nbr of nodes,..);
typedef struct list
{
	Node *first;
	int node_count;
}List;

//Prototypes
List *init_ll(void);
void add_head_ll(List *list, int nvalue);
void add_node_ll(List *list, Node *b_elem, int nvalue);
void remove_head_ll(List *list);
void remove_node_ll(List *list, Node *to_rm);
void display_ll(List *list);
void remove_ll(List *list);
int countnodes_ll(List *list);

//MAIN.. (ll functions tests)
int main(void)
{
	printf("\n");
	//init the list.
	List *linked = init_ll();
	//fill the list.
	add_head_ll(linked, 7);
	add_head_ll(linked, 5);
	add_head_ll(linked, 10);
	add_head_ll(linked, 12);
	add_head_ll(linked, 78);
	//display inital list
	printf("INITIAL list: \n");
	display_ll(linked);

	//add an element (24) inside the list (after '12').
	Node *buff = linked->first;
	while(buff)
	{
		if(buff->n == 12)
		{
			add_node_ll(linked, buff, 24);
		}

		buff = buff->next;
	}
	//display the list
	printf("ADDED 24 after 12: \n");
	display_ll(linked);
	
	//remove the node that contain '10' in the list.
	buff = linked->first;
	while(buff)
	{
		if(buff->n == 10)
		{	
			remove_node_ll(linked, buff);	
		}
		
		buff = buff->next;
	}
	//display the list
	printf("REMOVED 10: \n");
	display_ll(linked);

	//count the nodes in the list.
	int nnodes = countnodes_ll(linked);
	//display the result
	printf("NUMBER of elements in the list: %d\n", nnodes);
	//or..
	printf("NUMBER of elements in the list: %d\n", linked->node_count);
	
	//Empty the list.
	remove_ll(linked);
	//display the (hopefuly) empty list.
	printf("EMPTIED THE LIST: \n");
	display_ll(linked);

	
	printf("\n");
		
	return 0;
}

//Initialize a linked list.
List *init_ll(void)
{
	List *nlist = malloc(sizeof(List));

	if(!nlist)
	{
		exit(EXIT_FAILURE);//wrapper?
	}
	
	nlist->first = NULL;
	nlist->node_count = 0;
	return nlist;
}

//Add a node(n_elem) to the head of a linked list.
void add_head_ll(List *list, int nvalue)
{
	Node *new_node = malloc(sizeof(Node));
	
	if(!new_node)
	{
		exit(EXIT_FAILURE);
	}//check for 'list' at initialization is 'safe' enough?

	new_node->n    = nvalue;
	new_node->next = list->first;
	list->first  = new_node;
	list->node_count++;
	
}

//Add a node 'inside' a linked list (after a specified node);
void add_node_ll(List *list, Node *b_node, int nvalue)//b_ stands for "before"
{
	Node *new_node = malloc(sizeof(Node));

	if(!new_node)
	{
		exit(EXIT_FAILURE);
	}
	
	new_node->n = nvalue;
	new_node->next = b_node->next;
	b_node->next = new_node;
	list->node_count++;

}

//Remove the node at the head of a linked list.
void remove_head_ll(List *list)
{
	if(!list)//not necessary?
	{
		exit(EXIT_FAILURE);
	}

	if(list->first)
	{
		Node *node_rm = list->first;//node_rm stands for 'node to remove'
		list->first = list->first->next;
		free(node_rm);
	}
	list->node_count--;

}

//Remove a node inside the list.
void remove_node_ll(List *list, Node *node)
{

	if(!node)
	{
		exit(EXIT_FAILURE);
	}

		if(node == list->first)
		{
			Node *node_rm = list->first;
			list->first = list->first->next;
		       	free(node_rm);	
		}
		
		else
		{
			Node *b_rm = list->first;
			Node *node_rm = list->first->next;
			int endloop = 0;

			do
			{	
				if(node == node_rm)
				{
					b_rm->next = node_rm->next;
					free(node_rm);
					endloop = 1;
				}
				
				b_rm = node_rm;
				node_rm = node_rm->next;
			}while(endloop != 1);
		
		}
		list->node_count--;
}

//Delete (free) the whole list.
void remove_ll(List *list)
{

	if(!list)//unnecessary?
	{
		exit(EXIT_FAILURE);
	}

	Node *buff = malloc(sizeof(Node));
	while(list->first)
	{
		buff = list->first;
		list->first = list->first->next;
		free(buff);
	}
	list->node_count = 0;
	list->first = NULL;
}

//Display a whole linked list.
void display_ll(List *list)
{
	Node *curr_node = list->first;
	if(!list)//unnecesary?
	{
		exit(EXIT_FAILURE);
	}

	while(curr_node)
	{
		printf("%d -> ", curr_node->n);
		curr_node = curr_node->next;
	}
	
	printf("END.\n");
}

//Count the number of elements in a linked list.
int countnodes_ll(List *list)
{
	if(!list)
	{
		exit(EXIT_FAILURE);
	}

	Node *curr_node = list->first;
	int count = 0;
	while(curr_node)
	{
		if(curr_node)
		{
			count++;
		}
		curr_node = curr_node->next;
	}

	return count;
}




