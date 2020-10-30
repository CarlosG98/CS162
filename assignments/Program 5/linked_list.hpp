/*****************************************************************************
 * Program: linked_list.hpp
 * Author: Carlos Gonzalez
 * Date: 3/12/20
 * Description: header file for linked list class
 * Input:
 * Output:
 * **************************************************************************/
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "node.hpp"

class Linked_List {
    private:
        unsigned int length;
        Node* head;
        void MergeSort(Node**);
        void SplitList(Node*,Node**,Node**);
        Node* MergeSortedList(Node*,Node*);
        void sort(Node**);
        Node* SelectionSort(Node*);
        void swapnodes(Node**, Node*, Node*, Node*);
        bool CheckPrime(int);
   public:
        Linked_List();
        int get_length();
        void print();
        void clear();
        unsigned int push_front(int);
        unsigned int push_back(int);
        unsigned int insert(int, unsigned int);
        void sort_ascending();
        void sort_descending();
        void check_primes();
};

#endif
