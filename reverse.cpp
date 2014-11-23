#include <fstream>
#include <iostream>

using namespace std;

typedef struct node_t
{
	int value;
	struct node_t *next;
};

void
add(node_t **head, int value)
{
	node_t *to_add = (node_t *) malloc(sizeof(node_t));
	node_t *tmp = *head;

	to_add->value = value;
	to_add->next = NULL;

	if (NULL == tmp) {
		*head = to_add;
		return;
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = to_add;
}

int
reverse(node_t **head, node_t *current, node_t *previous)
{
	if (NULL == current) {
		return 1;
	}

	if (reverse(head, current->next, current))
		*head = current;

	current->next = previous;

	return 0;
}

void
print(node_t *head)
{
	while (head) {
		cout << "Value is: " << head->value << endl;
		head = head->next;
	}
}

int
main(void)
{
	node_t *head = NULL;	

	add(&head, 1);
	add(&head, 2);
	add(&head, 3);
	add(&head, 4);
	add(&head, 5);

	reverse(&head, head, NULL);

	print(head);

	return 0;
}
