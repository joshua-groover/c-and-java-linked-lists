#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

struct LList* createLList() {
  /* Create an empty linked list. */
  /* DO NOT MODIFY THIS CODE */
  struct LList* list = malloc(sizeof(struct LList));
  list->head = NULL;
  return list;
}

void printList(struct LList *list)
{
  /* Print a list from head to tail. */
  /* DO NOT MODIFY THIS CODE */
  struct LNode *entry;
  if(list == NULL) {
    printf("List has not been initialized!\n");
    return;
  }
  entry = list->head;
  printf("List Contents:\n");
  while(entry != NULL)
  {
    printf("  %s is at %f, %f\n", entry->name, entry->latitude, entry->longitude);
    entry = entry->next;
  }
}


int addNode(struct LList *list, char* name, double lat, double lon) {
  /*  Add a new entry to the linked list. 
      Return the index number of the new entry 
  */
 //set things up/allocate space for the new node
 int pos = 0;
 struct LNode* newNode = malloc(sizeof(struct LNode));

 //add all the data into the node
 newNode->name = name;
 newNode->latitude = lat;
 newNode->longitude = lon;
 newNode->next = NULL;

 if (list->head == NULL){
   //if the list is empty add in this element as the first node
   list->head = newNode;
 }
 else{
   struct LNode* iterator = list->head;
   pos++;
   //go through the list until the end
   while (iterator->next != NULL){
     iterator = iterator->next;
     pos++;
   }
   //add the element
   iterator->next = newNode;
 }
  return pos;
}

int remNode(struct LList *list, char* name)
{
  /*  Removes the element named "name" from the list, if it exists.
      Returns the index of the element removed.
  */
  //if list is empty there is nothing to remove
  if (list->head == NULL){
    return -1;
  }

  //set things up
  int pos = 0;
  struct LNode* prev;
  struct LNode* tester;
  prev = list->head;
  tester = prev->next;

  //if the names of the first element and input name are the same, remove the list element
  if (strcmp(prev->name, name) == 0){
    list->head = tester;
    free(prev);
    return pos;
  }
  
  //iterate through the list and look for the name, if found remove it and return the pos
  pos++;
  while (tester != NULL){
    if (strcmp(tester->name, name) == 0){
      prev->next = tester->next;
      free(tester);
      return pos;
    }
    prev = prev->next;
    tester = prev->next;
    pos++;
  }

  //if not found return -1
  return -1;
}

void sortList(struct LList *list, int len){
  if (len == 2){
    //if list length is two, check/change the elements so they are in order
    if (list->head->longitude > list->head->next->longitude){
      struct LNode* first = list->head;
      struct LNode* second = first->next;
      first->next = NULL;
      second->next = first;
      list->head = second;
    } 
  }
  else if (len >= 3){
    //create pointers to go through the list
    struct LNode* first = list->head;
    struct LNode* comp1 = first->next;
    struct LNode* comp2 = comp1->next;

    //do a basic sort on the list
    for (int i=1; i<len; i++){
      first = list->head;
      comp1 = first->next;
      comp2 = comp1->next;
      for (int j=0; j<(len-1); j++){
        if (j == 0){
          //see if the first two elements are in order/correct them if not
          if (first->longitude > comp1->longitude){
            first->next = comp2;
            comp1->next = first;
            list->head = comp1;

            first = list->head;
            comp1 = first->next;
            comp2 = comp1->next;
          }
        }
        else{
          //check the rest of the elements, swap them to the correct order
          if (comp1->longitude > comp2->longitude){
            first->next = comp2;
            comp1->next = comp2->next;
            comp2->next = comp1;
          }
          first = first->next;
          comp1 = first->next;
          comp2 = comp1->next;
        }
      }
    }
  }
}

int findElement(struct LList *list, char* name, double lat, double lon){
  //set things up
  struct LNode* iterator = list->head;
  int pos = 0;

  //go through the list and look for the matching node
  while (iterator != NULL){
    if (strcmp(iterator->name, name) == 0 & iterator->latitude == lat & iterator->longitude == lon){
      return pos;
    }
    iterator = iterator->next;
    pos++;
  }
  //if couldnt find it, return -1
  return -1;
}

int addSortedNode(struct LList *list, char* name, double lat, double lon)
{
  /*  Add a point to the list, sorted by longitude in ascending order. 
      Returns the position of the new point.
  */
  //add the node into the list
  addNode(list, name, lat, lon);

  //set things up and get the len of the list
  int len = 0;
  struct LNode* iterator;
  iterator = list->head;
  while(iterator != NULL){
    len++;
    iterator = iterator->next;
  }

  //sort the list
  sortList(list, len);

  //find the original element in the list and return the pos
  int pos = findElement(list, name, lat, lon);
  return pos;
}

int clearList(struct LList *list) 
{
  /* Delete list and free all of the memory associate with its LNodes. */
  //if list is empty, return -1
  if (list->head == NULL){
    return -1;
  }

  //free the first element and set everything up
  int count = 1;
  struct LNode* tester;
  struct LNode* line;
  tester = list->head;
  line = tester->next;
  free(tester);

  //go through all the elements and free them
  while(line != NULL){
    tester = line;
    line = line->next;
    free(tester);
    count++;
  }

  //set the head equal to null
  list->head = NULL;
  return count;
}
