void removeDuplicates(struct Node* head)
{
    struct Node* current = head;
	struct Node* next_next; 
   /* do nothing if the list is empty */
    if (current == NULL) 
       return; 
  /* Traverse the list till last node */
    while (current->next != NULL) 
    {
       /* Compare current node with next node */
       if (current->data == current->next->data) 
       {
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else 
       {
          current = current->next; 
       }
    }
}
