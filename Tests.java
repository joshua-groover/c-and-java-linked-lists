public class Tests {

  
  public static void addTestSimple() {
    LList list = new LList();
    int i;
    System.out.printf("Add Test #1\n-------------\n");
    System.out.printf("creaing first entry...\n");
    LNode office = new LNode("My office", 38.9005, -77.049318);
    list.head = office;
    office.next = null;
    list.head = office;
    System.out.printf("now adding more with function...\n");
    list.addNode("Washington Monument", 38.889404, -77.035194);
    i = list.addNode("Melbourne", -37.84232, 144.989318);
    if(i != 2){
      System.out.printf("ERROR: Not returning correct index in add!\n");
    }
    System.out.printf("Shold print list with 3 locations: My Office, Washington Monument, and Melbourne.\n");
    list.printList();
    System.out.printf("\n-------------\n\n");
  }
  
  public static void main (String[] argv) {
    //test add and remove
    LList list = new LList();
    list.addNode("Hello", 1231, 123);
    list.addNode("Hello1", 1232, 123);
    list.addNode("Hello2", 1233, 123);
    list.remNode("Hello");
    list.printList();

    //test add and remove
    LList list2 = new LList();
    list2.addNode("Hello", 1231, 123);
    list2.addNode("Hello1", 1232, 123);
    list2.addNode("Hello2", 1233, 123);
    list2.remNode("Hello1");
    list2.printList();

    //test add and remove
    LList list3 = new LList();
    list3.addNode("Hello", 1231, 123);
    list3.addNode("Hello1", 1232, 123);
    list3.addNode("Hello2", 1233, 123);
    list3.remNode("Hello2");
    list3.printList();

    //test clear
    LList list4 = new LList();
    list4.addNode("Hello", 1231, 123);
    list4.addNode("Hello1", 1232, 123);
    list4.addNode("Hello2", 1233, 123);
    list4.clearList();
    list4.printList();

    //test sort
    LList list5 = new LList();
    list5.addNode("Hello", 1231, 10);
    list5.addNode("Hello1", 1232, 1);
    list5.addNode("Hello2", 1233, 3);
    list5.addNode("Hello2", 1233, 9);
    list5.sortList(4);
    list5.printList();

    LList list6 = new LList();
    list6.addNode("Hello", 1231, 6);
    list6.addNode("Hello1", 1232, 1);
    list6.addNode("Hello2", 1233, 2);
    list6.addNode("Hello1", 1232, 10);
    list6.addNode("Hello2", 1233, 2);
    list6.sortList(5);
    list6.printList();

    //test addSortedNode
    LList list7 = new LList();
    list7.addNode("Hello", 1231, 6);
    list7.addNode("Hello1", 1232, 1);
    list7.addNode("Hello2", 1233, 2);
    list7.addNode("Hello3", 1234, 10);
    list7.addNode("Hello4", 1235, 2);
    int pos = list7.addSortedNode("Hello5", 1236, 4);
    System.out.println("New node is in position: " + pos);
    list7.printList();

    addTestSimple();
  }
}