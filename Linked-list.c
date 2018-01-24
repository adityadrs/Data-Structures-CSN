
/************************************************************************************************************************************
=====================================================================================================================================

    -----------------------------------------------------------
    |    Name                :      Aditya Dhan Raj Singh     |
    -----------------------------------------------------------


This program generates a linked list that stores n values.
Eacch entered value is appened to the end of the list. Other than append(), push() and insert_after() functions can be used.
to change the way data is added to the list change the function in the loop that is running in the 
		int main()
		{
		    .
		    .
		    int Y;
		    for (int i = 0; i < a; ++i)
		    {
		      printf("Please the value: ");
		      scanf("%d", &Y);
	=====>	  append(&CSN102, Y); 
		here in place of append(), push() and insert_after() can be used.
		    .
		    .
		    .
		    }
		}

NOTE: The syntax of using the insert_after() function is:
        insert_afte(head->next, value)

=====================================================================================================================================
************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// A linked list node

struct Node
{
  int data;
  struct Node *next;
};

//The push function adds a new node in the front of the linked list 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
//The insert_after function adds a new node in after a perticular node in the linked list
void insert_after(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
 
//the append function adds a new node at the end of the liked list
//(add to the end)
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;  /* used in step 5*/
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
 
//function to reverse the linked list
static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}


//this is the print function that prints the data stored in the linked list
void print_list(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}


void delete_node(struct Node **head_ref, int key)
{
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp); 
}

//This depends on the delete_node() function
//I have seperated it from the main() for neatness
void delete_node_function(struct Node *node)
{
    printf("\nEnter the element to delete: " );
    int del;
    scanf("%d", &del);
    printf("You have entered: %d\n", del);
    printf("Are you sure? \ny/n: ");
    char condition_1;
    scanf(" %c", &condition_1);
    if (condition_1 == 'y')
      {
          printf("You have chosen Yes\nUpdated list is:\n");
          delete_node(&node, del);
          print_list(node);
      }
    else if (condition_1 == 'n')
      {
          printf("NO");
          printf("You have chosen No\n");
          print_list(node);
      }
    else
      {
        printf("Invalid Input\n");
      }
    

}

int main()
{
    
    struct Node* CSN102 = NULL;
    int a;
    printf("Please the number of elements in the list: ");
    scanf("%d", &a);

    printf("You entered: %d\n", a);

    int Y;
    for (int i = 0; i < a; ++i)
    {
      printf("Please the value: ");
      scanf("%d", &Y);
      append(&CSN102, Y);
    }

    printf("\nThe current list is: \n");
    print_list(CSN102);
    printf("\nThe reversed list is: \n");
    reverse(&CSN102);
    print_list(CSN102);
    delete_node_function(CSN102);


    return 0;
}

