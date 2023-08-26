//4-WAP demonstrating bubble sort using linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node_025
{
	int data;
	struct Node_025 *next;
};

void insertAtTheBegin(struct Node_025 **start_ref, int data);
void bubbleSort(struct Node_025 *start);
void swap(struct Node_025 *a, struct Node_025 *b);
void printList(struct Node_025 *start);

int main()
{
	int arr[50],n,i;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	struct Node_025 *start = NULL;
    
    printf("Insert those elements");
	for (i = 0; i< n; i++)
	{
	    scanf("%d",&arr[i]);
		insertAtTheBegin(&start, arr[i]);
	}
	printf("\nLinked list before sorting ");
	printList(start);
	bubbleSort(start);
	printf("\nLinked list after sorting ");
	printList(start);

	getchar();
	return 0;
}

void insertAtTheBegin(struct Node_025 **start_ref, int data)
{
	struct Node_025 *ptr1 = (struct Node_025*)malloc(sizeof(struct Node_025));
	ptr1->data = data;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
}

void printList(struct Node_025 *start)
{
	struct Node_025 *temp = start;
	printf("\n");
	while (temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void bubbleSort(struct Node_025 *start)
{
	int swapped, i;
	struct Node_025 *ptr1;
	struct Node_025 *lptr = NULL;

	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	while (swapped);
}

void swap(struct Node_025 *a, struct Node_025 *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

