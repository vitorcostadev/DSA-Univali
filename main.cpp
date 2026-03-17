#include <iostream>
#include <cstring>

#define DEFAULT_CAPACITY 10

#include "List\List.cpp"
#include "List\DynamicList.cpp"
#include "LinkedList\SingleLinkedList\LinkedList.cpp"
#include "LinkedList\DoubleLinkedList\DoubleLinkedlist.cpp"

using namespace std;

void testStaticList() {
    cout << "\n=== Static List Tests ===" << endl;
    
    List<int, 10> list;
    create(list);
    
    cout << "Size after create: " << size(list) << endl;
    cout << "Has space: " << hasSpace(list) << endl;
    
    add(list, 10, 0);
    add(list, 20, 1);
    add(list, 30, 2);
    cout << "Size after 3 adds: " << size(list) << endl;
    
    cout << "Get index 0: " << get(list, 0) << endl;
    cout << "Get index 1: " << get(list, 1) << endl;
    cout << "Get index 2: " << get(list, 2) << endl;
    
    cout << "Contains 20: " << contains(list, 20) << endl;
    cout << "Contains 99: " << contains(list, 99) << endl;
    
    cout << "IndexOf 20: " << indexOf(list, 20) << endl;
    cout << "IndexOf 99: " << indexOf(list, 99) << endl;
    
    remove(list, 1);
    cout << "Size after remove index 1: " << size(list) << endl;
    cout << "Get index 1 after remove: " << get(list, 1) << endl;
    
    log(list);
    cout << endl;
}

void testDynamicList() {
    cout << "\n=== Dynamic List Tests ===" << endl;
    
    DynamicList<int> list = create<int>();
    
    cout << "Size after create: " << size(list) << endl;
    cout << "Capacity: " << list.capacity << endl;
    cout << "Has space: " << hasSpace(list) << endl;
    
    add(list, 5, 0);
    add(list, 15, 1);
    add(list, 25, 2);
    cout << "Size after 3 adds: " << size(list) << endl;
    
    cout << "Get index 0: " << get(list, 0) << endl;
    cout << "Get index 1: " << get(list, 1) << endl;
    cout << "Get index 2: " << get(list, 2) << endl;
    
    cout << "Contains 15: " << contains(list, 15) << endl;
    cout << "Contains 99: " << contains(list, 99) << endl;
    
    cout << "IndexOf 15: " << indexOf(list, 15) << endl;
    cout << "IndexOf 99: " << indexOf(list, 99) << endl;
    
    int arr[] = {100, 200, 300};
    of(list, arr, 3);
    cout << "Size after of(): " << size(list) << endl;
    
    remove(list, 1);
    cout << "Size after remove: " << size(list) << endl;
    
    destroy(list);
    cout << "Destroyed" << endl;
}

void testSingleLinkedList() {
    cout << "\n=== Single Linked List Tests ===" << endl;
    
    LinkedList<int> list;
    create(list);
    
    cout << "Is empty after create: " << isEmpty(list) << endl;
    cout << "Size after create: " << size(list) << endl;
    
    add(list, 7, 0);
    add(list, 14, 1);
    add(list, 21, 2);
    cout << "Size after 3 adds: " << size(list) << endl;
    cout << "Is empty: " << isEmpty(list) << endl;
    
    cout << "Get index 0: " << get(list, 0) << endl;
    cout << "Get index 1: " << get(list, 1) << endl;
    cout << "Get index 2: " << get(list, 2) << endl;
    
    cout << "Contains 14: " << contains(list, 14) << endl;
    cout << "Contains 99: " << contains(list, 99) << endl;
    
    cout << "IndexOf 14: " << indexOf(list, 14) << endl;
    cout << "IndexOf 99: " << indexOf(list, 99) << endl;
    
    LinkedList<int> list2;
    create(list2);
    add(list2, 50, 0);
    add(list2, 60, 1);
    add(list2, 70, 2);
    cout << "of() list size: " << size(list2) << endl;
    
    remove(list, 1);
    cout << "Size after remove: " << size(list) << endl;
    
    cout << "List: ";
    log(list);
    cout << endl;
    
    destroy(list);
    destroy(list2);
}

void testDoubleLinkedList() {
    cout << "\n=== Double Linked List Tests ===" << endl;
    
    DoubleLinkedList<int> list;
    create(list);
    
    cout << "Is empty after create: " << isEmpty(list) << endl;
    cout << "Size after create: " << size(list) << endl;
    
    add(list, 3, 0);
    add(list, 6, 1);
    add(list, 9, 2);
    cout << "Size after 3 adds: " << size(list) << endl;
    cout << "Is empty: " << isEmpty(list) << endl;
    
    cout << "Get index 0: " << get(list, 0) << endl;
    cout << "Get index 1: " << get(list, 1) << endl;
    cout << "Get index 2: " << get(list, 2) << endl;
    
    cout << "Contains 6: " << contains(list, 6) << endl;
    cout << "Contains 99: " << contains(list, 99) << endl;
    
    cout << "IndexOf 6: " << indexOf(list, 6) << endl;
    cout << "IndexOf 99: " << indexOf(list, 99) << endl;
    
    DoubleLinkedList<int> list2;
    create(list2);
    add(list2, 11, 0);
    add(list2, 22, 1);
    add(list2, 33, 2);
    cout << "of() list size: " << size(list2) << endl;
    
    remove(list, 1);
    cout << "Size after remove: " << size(list) << endl;
    
    cout << "List: ";
    log(list);
    cout << endl;
    
    destroy(list);
    destroy(list2);
}

int main() {
    try {
        testStaticList();
        testDynamicList();
        testSingleLinkedList();
        testDoubleLinkedList();
    } catch(const char* err) {
        cout << "Error: " << err << endl;
    }
    
    return 0;
}
