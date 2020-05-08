public class LList {

  public LNode head;
  /* You may not add more data members to this class. */
  
  public void printList(){
    LNode entry = head;
    System.out.println("List Contents:");
    while (entry != null) {
      System.out.printf("  %s is at %f, %f\n", entry.name, entry.latitude, entry.longitude);
      entry = entry.next;
    }
  }

  public int addNode(String name, double lat, double lon){
    //set things up
    LNode newNode = new LNode(name, lat, lon);
    int pos = 0;

    if (head==null){
      //if the list is empty add in this element as the first node
      this.head = newNode;
    }
    else{
      LNode iteratorNode = head;
      //go through the list until the end
      while(iteratorNode.next != null){
        pos++;
        iteratorNode = iteratorNode.next;
      }
      pos++;
      //add the element
      iteratorNode.next = newNode;
    }
    return pos;
  }

  public int remNode(String name){
    //if list is empty there is nothing to remove
    if (head == null){
      return -1;
    }

    //set things up
    LNode prev = head;
    LNode tester = head.next;
    int pos = 0;

    //if the names of the first element and input name are the same, remove the list element
    if (prev.name.equals(name)){
      head = tester;
      return pos;
    }

    //iterate through the list and look for the name, if found remove it and return the pos
    pos++;
    while (tester != null){
      if (tester.name.equals(name)){
        prev.next = tester.next;
        return pos;
      }
      pos++;
      prev = tester;
      tester = tester.next;
    }
    //if not found return -1
    return -1;  
  }

  public void sortList(int len){
    if (len == 2){
      //if list length is two, check/change the elements so they are in order
      if(head.longitude > head.next.longitude){
        LNode first = head;
        LNode second = head.next;
        first.next = null;
        second.next = first;
        head = second;
      }
    }
    else if (len >= 3){
      //create pointers to go through the list
      LNode first = head;
      LNode comp1 = head.next;
      LNode comp2 = head.next.next;

      //do a basic sort on the list
      for (int i=1; i<len; i++){
        first = head;
        comp1 = first.next;
        comp2 = comp1.next;
        for (int j=0; j<len-1; j++){
          if (j==0){
            //see if the first two elements are in order/correct them if not
            if (first.longitude > comp1.longitude){
              first.next = comp2;
              comp1.next = first;
              head = comp1;
              first = head;
              comp1 = head.next;
              comp2 = comp1.next;
            }
          }
          else{
            //check the rest of the elements, swap them to the correct order
            if (comp1.longitude > comp2.longitude){
              first.next = comp2;
              comp1.next = comp2.next;
              comp2.next = comp1;
            }
            first = first.next;
            comp1 = first.next;
            comp2 = comp1.next;
          }
        }
      }
    }
  }

  public int findElement(String name, double lat, double lon){
    LNode iterator = head;
    int pos = 0;
    
    //go through the list and look for the matching node
    while (iterator != null){
      if (iterator.name.equals(name) && iterator.latitude == lat && iterator.longitude == lon){
        return pos;
      }
      iterator = iterator.next;
      pos++;
    }
    //if couldnt find it, return -1
    return -1;
  }

  public int addSortedNode(String name, double lat, double lon){
    //add the node into the list
    addNode(name, lat, lon);
    
    //set things up and get the len of the list
    int len = 0;
    LNode node = head;
    while (node != null){
      len++;
      node = node.next;
    }

    //sort the list
    sortList(len);

    //find the original element in the list and return the pos
    int pos = findElement(name, lat, lon);
    return pos;  
  }

  public int clearList(){
    //if the list is empty return -1
    if (head == null){
      return 0;
    }

    //free the first element and set everything up
    LNode tester = head;
    LNode line = head.next;
    int count = 1;
    
    tester.name = null;
    tester.latitude = 0;
    tester.longitude = 0;

    //go through all the elements and free them
    while (line != null){
      tester.name = null;
      tester.latitude = 0;
      tester.longitude = 0;
      tester.next = null;
      count++;
      tester = line;
      line = line.next;
    }

    //set the head equal to null
    head = null;
    return count;  
  }
}
