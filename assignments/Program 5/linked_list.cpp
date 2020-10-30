/*****************************************************************************
 * Program: linked_list.cpp
 * Author: Carlos Gonzalez
 * Date: 3/12/20
 * Description: function definitions for linked list class
 * Input:
 * Output:
 * **************************************************************************/
#include "linked_list.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/**********************************************************
 * Function: Linked_List()
 * Description: constructor for linked list object
 * Preconditions:
 * Postconditions: linked list object of length 0, no data
 * ********************************************************/
Linked_List::Linked_List(){
    length = 0;
    head = NULL;
}


/**********************************************************
 * Function: get_length()
 * Description: returns length of list
 * Preconditions:
 * Postconditions:
 * ********************************************************/
int Linked_List::get_length(){
    return length;
}


/**********************************************************
 * Function: print()
 * Description: travels through list and prints each value
 * Preconditions: 
 * Postconditions:
 * ********************************************************/
void Linked_List::print(){
    Node* current = head;
    cout << "Your linked list is: ";
    while(current != NULL){
        cout << current->val << " ";
        current = current->next; //move through nodes until we get to the tail
    }
    cout << "" << endl;	
}

/**********************************************************
 * Function: clear()
 * Description: travels through list, delete allocated memory for each node, resets length to zero
 * Preconditions: 
 * Postconditions: empty list
 * ********************************************************/
void Linked_List::clear(){
    Node* current = head;
    Node* temp;
    while(current != NULL){
        temp = current->next; //need to store address of next node before deleting current node
        delete current;
        current = temp; //current is now the next node
    }
    head = NULL;
    length = 0;
}

/**********************************************************
 * Function: push_front()
 * Description: adds a new node to the front of the list
 * Preconditions: 
 * Postconditions: new list with added node to the front
 * ********************************************************/
unsigned int Linked_List::push_front(int x){
    Node* n = new Node(); //allocate mem for new node
    n->val = x; //add data to node
    n->next = head; //node n's next is the previously first node in list, making n the first node now
    head = n; //make the head point to n since head is always points to first node in the list
    length++;
	return length; 
}

/**********************************************************
 * Function: push_back
 * Description: adds a new node to the end of the list
 * Preconditions:
 * Postconditions: new list with node at the end
 * ********************************************************/
unsigned int Linked_List::push_back(int x){
    Node* n = new Node(); //allocate mem
    n->val = x; //add data to node
    n->next = NULL; //tail points to null
    Node* end = head;
    while(end->next != NULL){ //travel through nodes
	end = end->next;
    }
    end->next = n; //previous tail now points to new node n
    length++;
	return length;
}

/**********************************************************
 * Function: insert
 * Description: inserts a node in a specific position in the list
 * Preconditions:
 * Postconditions: new list with node in specified position
 * ********************************************************/
unsigned int Linked_List::insert(int x, unsigned int index){
	
	int count = 0; //tracks position in list
	if(index == 0){ 
		push_front(x); //if adding to position 0, then its just a push_front
	}else{
		Node* n = new Node(); //allocate mem
		n->val = x; //add data
	
		Node* current = head;
		while(count != index-1){ //travel to node thats behind desired list position
			current = current->next;
			count++;
		}
		n->next = current->next; //new node n's next node is current next
		current->next = n; //current's next now points to node n
	}
	length++;
	return length;
}

/**********************************************************
 * Function: MergeSort
 * Description: sorts the list by breaking down the list, sorting them, then merging them back together
 * Preconditions: list
 * Postconditions: sorted list
 * ********************************************************/
void Linked_List::MergeSort(Node** tmp){

	Node* ptr1, *ptr2;
	Node* h = *tmp;
	
	if(h == NULL || h->next == NULL){ //if list has 0-1 elements, return
		return;
	}


	SplitList(h, &ptr1, &ptr2); //split list into two seperate lists
	
	MergeSort(&ptr1); //recursively pass split list until base case
	MergeSort(&ptr2);

	*tmp = MergeSortedList(ptr1, ptr2); //merge split lists until one complete list
}

/**********************************************************
 * Function: SplitList
 * Description: responsible for splitting a list 
 * Preconditions:
 * Postconditions: split list
 * ********************************************************/
void Linked_List::SplitList(Node* source, Node** front, Node** end){
	
	Node* ptr1, *ptr2;
	ptr2 = source;
	ptr1 = source->next;
	
	while(ptr1 != NULL){ //ptr1 travels through list twice as fast
		ptr1 = ptr1->next;
		if(ptr1 != NULL){
			ptr2 = ptr2->next;
			ptr1 = ptr1->next; 
		}
	}
	
	*front = source;
	*end = ptr2->next;
	ptr2->next = NULL;
}

/**********************************************************
 * Function: MergeSortedList
 * Description: responsible for merging list back together in ascending order
 * Preconditions:
 * Postconditions: sorted list
 * ********************************************************/
Node* Linked_List::MergeSortedList(Node* list1, Node* list2){
	
	Node* result = NULL;
	
	if(list1 == NULL){	
		return list2;
	}else if (list2 == NULL){
		return list1;
	}
	
	if(list1->val <= list2->val){
		result = list1;
		result->next = MergeSortedList(list1->next, list2);
	}else{
		result = list2;
		result->next = MergeSortedList(list1, list2->next);
	}
	
return result;
}

/**********************************************************
 * Function: sort_ascending
 * Description: public function that calls the merge sort process
 * Preconditions:
 * Postconditions: sorted list
 * ********************************************************/	
void Linked_List::sort_ascending(){
	Node** n = &head;	
	MergeSort(n);
}

/**********************************************************
 * Function: swapnodes
 * Description: responsible for swapping nodes during selection sort process
 * Preconditions:
 * Postconditions: swapped nodes
 * ********************************************************/
void Linked_List::swapnodes(Node** head_ref, Node* currX, Node* currY, Node* prevY){
	
	*head_ref = currY;
	
	prevY->next = currX;
	
	Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

/**********************************************************
 * Function: SelectionSort
 * Description: sorts linked list using recursive selection sort
 * Preconditions: 
 * Postconditions: sorted list in descending order
 * ********************************************************/
Node* Linked_List::SelectionSort(Node* h){
	
	if(h->next == NULL){
		return h;
	}
	
	Node* Max  = h;
	Node* beforeMax = NULL;
	Node* ptr;

	for(ptr = h; ptr->next != NULL; ptr=ptr->next){ //travel through list
		if(ptr->next->val > Max->val){ //if value is greater than currently set max value, set new max
			Max = ptr->next;
			beforeMax = ptr;
		}
	}

	if(Max != h){
		swapnodes(&h, h, Max, beforeMax);
	}
	
	h->next = SelectionSort(h->next);
	
return h;
}

/**********************************************************
 * Function: sort
 * Description: calls the Selection sort funtion by passing the head node
 * Preconditions:
 * Postconditions:
 * ********************************************************/
void Linked_List::sort(Node** h){
	
	if((*h) == NULL){
		return;
	}

	*h = SelectionSort(*h);
}

/**********************************************************
 * Function: sort_descending
 * Description: public function calls selection sort process
 * Preconditions:
 * Postconditions: sorted list in descending order
 * ********************************************************/
void Linked_List::sort_descending(){
	sort(&head);
} 

/**********************************************************
 * Function: CheckPrime
 * Description: checks if passed value is a prime number
 * Preconditions:
 * Postconditions: returns false if not prime, returns true otherwise
 * ********************************************************/
bool Linked_List::CheckPrime(int x){

	if(x <= 1 && x >= -1){
		return false;
	}
	if(x == 2){ //2 is the only even prime number
		return true;
	}
	for(int i = 2; i < x; i++){
		if( x % i == 0){ //if value is divisible by other values other than 1 or itself
			return false; //not a prime
		}
	}
	return true;
}

/**********************************************************
 * Function: check_primes
 * Description: travels through list, checking each value if prime, prints number of primes 
 * Preconditions:
 * Postconditions:
 * ********************************************************/
void Linked_List::check_primes(){
	Node* tmp = head;
	int num_primes = 0;
	bool is_prime = false;
	while(tmp != NULL){	
		if( CheckPrime(tmp->val) == true){
			num_primes++;
		}
		tmp = tmp->next;	
	}
	cout << "You have " << num_primes << " prime number(s) in your list." << endl;
}









	
