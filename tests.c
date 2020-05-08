#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

/* You may NOT modify this file, except in the main() function. */

void sortTest()
{
        /* Test adding cities in sorted order. The numbers in parenthesis
                indicate the correct ordering to help you verify your function
                is correct.
        */
        /* DO NOT MODIFY THIS CODE */
        struct LList* cityList = createLList();
        printf("Sort Test\n-------------\n");

        addSortedNode(cityList, "Muncie (2)", 40.2, -85.4);
        addSortedNode(cityList, "San Francisco (0)", 37.8, -122.5);
        addSortedNode(cityList, "Rio de Janero (4)", -22.92, -43.23);
        addSortedNode(cityList, "Moscow (7)", 55.7, 37.6);
        addSortedNode(cityList, "Mumbai (9)", 19.0, 72.9);
        addSortedNode(cityList, "Budapest (6)", 47.5, 19.1);
        addSortedNode(cityList, "Barcelona (5)", 41.4, 2.2);
        addSortedNode(cityList, "New York City (3)", 40.7, -74.0);
        addSortedNode(cityList, "Dar es Salaam (8)", -6.83, 39.27);
        addSortedNode(cityList, "Tokyo (11)", 35.7, 139.7);
        addSortedNode(cityList, "Hong Kong (10)", 22.3, 114.1);
        addSortedNode(cityList, "Mexico City (1)", 19.4, -99.2);
        
        printf("The sorted list is:\n\n-------------");
        printList(cityList);
        printf("\n-------------\n\n");
} 

void remTest()
{
        /* Test removing a city.
        */
        /* DO NOT MODIFY THIS CODE */
        struct LList* cityList = createLList();
        printf("Removal Test\n-------------\n");
        addNode(cityList, "Good Place", 38.9005, -77.049318);
        addNode(cityList, "Bad Place", 38.889404, -77.035194);
        printList(cityList);
        remNode(cityList, "Bad Place");
        addNode(cityList, "Good Place 2", 36.9005, -76.049318);
        printf("The list should only have two Good Places:\n\n-------------");
        printList(cityList);
        printf("\n-------------\n\n");
} 

void clearTest()
{
        /* Create a list and then clear it out. */
        /* DO NOT MODIFY THIS CODE */
        struct LList *locationList = createLList();

        printf("Clear Test\n-------------\n");
        addNode(locationList, "My office", 38.9005, -77.049318);
        addNode(locationList, "Washington Monument", 38.889404, -77.035194);
        addNode(locationList, "Melbourne", -37.84232, 144.989318);
        printList(locationList);
        printf("Clearing list...\n");
        clearList(locationList);
        printf("Done clearning... should be empty\n");
        printList(locationList);
        printf("\n-------------\n\n");
}

void addTestSimple()
{
        /* A simple test of addNode where the first entry is added manually*/
        /* DO NOT MODIFY THIS CODE */
        int i;
        struct LList* locationList = createLList();
        struct LNode* office;
        
        printf("Add Test #1\n-------------\n");
        printf("creaing first entry...\n");
        office =  (struct LNode*) malloc(sizeof(struct LNode));
        office->name = "My office";
        office->latitude = 38.9005;
        office->longitude = -77.049318;
        office->next = NULL;
        locationList->head = office;
        printf("now adding more with function...\n");
        addNode(locationList, "Washington Monument", 38.889404, -77.035194);
        i = addNode(locationList, "Melbourne", -37.84232, 144.989318);
        if(i != 2){
                printf("ERROR: Not returning correct index in add!\n");
        }
        printf("Shold print list with 3 locations: My Office, Washington Monument, and Melbourne.\n");
        printList(locationList);
        printf("\n-------------\n\n");
}

void addTestFull()
{
        /* Test adding to both an empty and partially filled list. */
        /* DO NOT MODIFY THIS CODE */
        struct LList *locationList = createLList();

        printf("Add Test #2\n-------------\n");
        addNode(locationList, "My office", 38.9005, -77.049318);
        addNode(locationList, "Washington Monument", 38.889404, -77.035194);
        addNode(locationList, "Melbourne", -37.84232, 144.989318);
        printList(locationList);
        printf("\n-------------\n\n");
}

void remTestFull(){
        /* Complete removal test covering 
        * removing from an empty list, removing the first and last elements of a list,
        removing an element that doesn't exist from a full list and removing an element
        somewhere in the middle of a list
        */
        struct LList* cityList = createLList();
        
        printf("Test removing a point from an empty list\n-------------\n");
        remNode(cityList,"Fake Point");
        printf("\n-------------\n\n");
        printf("Basic Removal Test\n-------------\n");
        addNode(cityList, "Good Place", 38.9005, -77.049318);
        addNode(cityList, "Bad Place", 38.889404, -77.035194);
        printList(cityList);
        remNode(cityList, "Bad Place");
        printf("The list should only have the Good Place:\n\n-------------");
        printList(cityList);
        printf("\n-------------\n\n");
        printf("Test removing the first element in a list\n-------------\n");
        addNode(cityList, "Bad Place", 38.889404, -77.035194);
        addNode(cityList, "Okay Place", 32.889404, -54.035194);
        printList(cityList);
        remNode(cityList,"Good Place");
        printList(cityList);
        printf("\n-------------\n\n");
        printf("Test removing the last element in a list\n-------------\n");
        printList(cityList);
        remNode(cityList,"Okay Place");
        printList(cityList); 
        printf("\n-------------\n\n");
        printf("Test removing a middle element in a list\n-------------\n");
        addNode(cityList, "Okay Place", 32.889404, -54.035194);
        addNode(cityList, "Good Place", 38.9005, -77.049318);
        addNode(cityList, "Alright Place", 24.889404, -04.035194);
        addNode(cityList, "So So Place", 49.9005, -29.049318);
        printList(cityList);
        remNode(cityList,"Okay Place");
        printList(cityList); 
        printf("\n-------------\n\n");
        printf("Test removing a point that doesn't exist\n-------------\n");
        remNode(cityList,"Fake Point");
        printf("\n-------------\n\n");
}

int main()
{
        
        // Verify adding elements works
        addTestSimple();
        
        /*  Uncomment each of these to run the advanced tests   */
        addTestFull();
        sortTest();
        remTest();
        clearTest();
        remTestFull();
                
        return 0;
}