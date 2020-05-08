## Phase 1: Algorithms
Before writing your code you must prepare pseudo code algorithms for each of the different functions. You must submit these in your Readme.md file in the Algorithms folder *by Wednesday 3/04 at 11:00PM*. You are encouraged to submit much sooner so that you can make progress on your coding -- if you submit sooner, you will get feedback sooner! Keep in mind that your algorithms should be language agnostic since you will be using this for both C and Java.

`addNode:` This should add a location to the end of the list.
  * Inputs: name, latitude, and longitude of the new location
  * Return the index of where the element was added (i.e., if the list was empty, it should return 0; if the new entry is the 4th entry, it should return 3), or -1 on an error.
  * Note: Our LList data structure only contains a reference to the head of the list, so you will *not* be able to directly add to the rear like was done in our class example!

```
if length of the linked list is zero:
    create a new node with the name, latitude, and longitude data points
    set the head equal to the new node
    set the next element from the head equal to null
    increment the length of the linked list by one
else
    create a new node with the name, latitude, and longitude data points
    create an index node and set it equal to the head
    while index node next does not equal null:
        set the index note equal to the next index node
    set the index node's next equal to the new node
    set the new node's next equal to null
    increment the length of the linked list by one
    
return the legnth of the list minus one
        
```

`addSortedNode:` Add a location to the list sorted by longitude (i.e. the one that changes as you go east/west).
  * Inputs: name, latitude, and longitude of the new location
  * Return the index of where the element was added (i.e., if the list was empty, it should return 0; if the new entry is the 4th entry, it should return 3), or -1 on an error.
  * You can assume that if a user wants a list to be sorted, they will only use `addSortedNode` (not a mix of that and `addNode`).

```
call the addNode function with the name, latitude, and longitude inputs

iterate on a number i from 0 to the number of elements in the list minus one:
    create a node and set it equal to head next next next and name it frontSnake
    create a node and set it equal to head next next and name it ch1
    create a node and set it equal to head next and name it ch2
    create a node and set it equal to head and name it backSnake
    iterate on number j from 0 to the number of elements in the list minus three:
        if j equals zero:
            if frontSnake longitude is greater than ch1 longitude:
                set head equal to ch1
                set head next equal to frontSnake
                set frontSnake next equal to ch2
        else if j equals elements in the list minus 4:
            if backSnake longitude is less than ch2 longitude:
                set ch1 next equal to backSnake
                set backSnake next equal to ch2
                set ch2 next equal to null
        else:
            if ch1 longitude is greater than ch2 longitude:
                set frontSnake next equal to ch2
                set ch2 next equal to ch1
                set ch1 next equal to backSnake
        set frontSnake equal to frontSnake next
        set ch1 equal to ch1 next
        set ch2 equal to ch2 next
        set backSnake equal to backSnake next

create node and set it equal to the head and call it snakey
creat int called pos and set it equal to zero
iterate on a number i from 0 to the number of elements in the list minus one:
    if snakey name is input name and snakey longitude is input longitude and snakey latitide is input latitude:
        return pos
    increment pos
return -1
```

`remNode:` Remove a location by name
  * Input: The name of the location to remove.
  * Note: If there happen to be two entries in the list with the same name, you should remove the entry closest to the head of the list.
  * Implementation tip: you cannot test if two strings are equal with `==` in C or Java! In C you will have to learn to use the [strcmp](https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm) function and in Java you will want to use `.equals`
  * Return the index where the element was removed, or -1 on an error.

```
create a node and set it equal to head and call it prev
create a node and set it equal to the head next and call is tester
create a int called position and set it equal to zero

if prev longitude equals name of location to remove:
    set head equal to tester
    free the data in prev
    decrease the length of the list by one
    return position
else
    iterate i from 1 to the length of the list minus 1:
        if tester longitude equals name of location to remove:
            set prev next equal to tester next
            free data in tester
            decrease the length of the list by one
            return position
        increment position

return -1

```

`clearList:` Clear a list
  * Remove all locations in the list
  * Return the total number of entries that were removed.

```
create a node and set it equal to head and call it cur
create a node and set it equal to the head next and call is next
create a int called numRemoved and set it equal to zero

increment i from one to length of list minus one:
    free the data in cur
    set cur equal to next
    set next equal to next next
    increment numRemoved
    
free the data in cur
set head equal to null
increment numRemoved
set length of the list to zero
return numRemoved

```
