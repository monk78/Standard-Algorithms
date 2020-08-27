#include <stdio.h>
#include<string.h>
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d",n)
#define ps(n) printf("%s",n);
#define ss(n) scanf("%s",n);
struct node {
   int data;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
void Insert() {
   int val;
   ps("Insert the element in queue :\n ");
   sl(val);
   if (rear == NULL) {
      rear = (struct node *)malloc(sizeof(struct node));
      rear->next = NULL;
      rear->data = val;
      front = rear;
   } else {
      temp=(struct node *)malloc(sizeof(struct node));
      //rear->next = temp;
      temp->data = val;
      temp->next = NULL;
      rear->next = temp;
      rear=temp;
   }
}
void Delete() {
   temp = front;
   if (front == NULL) {
      ps("Underflow\n");
      return;
   }
   else
   if (temp->next != NULL) {
      temp = temp->next;
      ps("Element deleted from queue is : \n");
      pl(front->data);
      free(front);
      front = temp;
   }
   else {
      ps("Element deleted from queue is :\n ");
      pl(front->data);
      ps("\n");
      free(front);
      front = NULL;
      rear = NULL;
   }
   ps("\n");
}

void Display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      ps("Queue is empty\n");
      return;
   }
   ps("Queue elements are: \n");
   while (temp != NULL) {
      pl(temp->data);
      temp = temp->next;
   }
    ps("\n");
}
int main() {
   int ch;
   ps("1 Insert element to queue\n");
   ps("2) Delete element from queue\n");
   ps("3) Display all the elements of queue\n");
   ps("4) Exit \n");
do {
   ps("Enter your choice : \n");
   sl(ch);
   switch (ch) {
      case 1: Insert();
         break;
      case 2: Delete();
         break;
      case 3: Display();
         break;
      case 4: ps("Exit");
         break;
      default: ps("Invalid choice\n");
   }
} while(ch!=4);
   return 0;
}
