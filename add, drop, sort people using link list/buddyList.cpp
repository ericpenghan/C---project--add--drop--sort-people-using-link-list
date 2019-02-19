//
//  buddyList.cpp
//  Project 4
//
//  Created by Eric Han on 11/28/18.
//  Copyright © 2018 Eric Han. All rights reserved.
//

#include "buddyList.hpp"
#include <iostream>
#include <fstream>

buddyList::buddyList(){
  head = NULL;
  cout << "List allocated!\n";
}

buddyList::~buddyList(){
  if (head != NULL) delete head;
  cout << "List destroyed!\n";
}
//------------------------------------------------------------------
//                    constructor and destructor
//------------------------------------------------------------------
// TODO: add constructor. include this cout
// cout << "List allocated!\n";

// TODO: add destructor. include this cout
// cout << "List destroyed!\n";//done maybe

//------------------------------------------------------------------
//                            add
//------------------------------------------------------------------
void buddyList::add(string fname, string lname, string phone) {
  buddy * p = new buddy;
  p -> set( fname, lname, phone);
  add(p);
  
  // TODO: allocate/populate a dynamic buddy; invoke 2nd add()
} // add(fields)//done

void buddyList::add(buddy * p) {
  p -> next = head;
  head = p;
  // TODO: add to top (head) of list (see Stack push())//done
  
} // add(ptr)

//------------------------------------------------------------------
//                            print
//------------------------------------------------------------------
void buddyList::print() {
  cout << "\nBuddy List: =========================================\n";
  buddy * p = head;
  while (p){
    p -> print();
    p = p -> next;
  }
  // TODO: add loop to ->print() all nodes in the list
  
  cout << "======================================================\n\n";
} // print()

//------------------------------------------------------------------
//                            read
//------------------------------------------------------------------
void buddyList::read() {
  ifstream f;
  f.open("buddyList.txt");
  if (f.fail()) {
    cout << "Error opening input file!\n";
    return;
  }
  
  string fname, lname, tele;
  while (!f.eof()) {
    f >> fname >> lname >> tele;
    add(fname, lname, tele);
  }
  f.close();
} // read()

buddy* buddyList::search(string fname, string lname){
  buddy * p = head;
  while(p != NULL){
    if (p -> first == fname && p -> last == lname){
      return p;//return the found one 
    }
    p = p-> next;//go to the next node
  }
  return NULL;
}

buddy* buddyList::maxByName(){
  buddy * curr = head, * max = head;//start from beginning
  while(curr){
    if((curr -> last > max -> last)|| ( curr -> last == max -> last && curr-> first > max -> first )){
      max = curr;
    }
    curr = curr -> next;//check the next one
  }
  return max;//return name
}

void buddyList::remove(buddy * r){
  if (r == head)
    head = head -> next;
  else {//must find node before one being removed
    bool flag = false;
    buddy * b4 = head;
    while (b4 && !flag){
      if (b4 -> next == r)
        flag = true;
      else
        b4 = b4 -> next;
    } // end of while
    b4 -> next = r -> next;
  }
  r -> next = NULL;//detach following node
}

int buddyList::drop(string fname, string lname){
  buddy * p = search(fname, lname);//call search function
  if (p == NULL) return -1;//just in case there is an empty list
  remove(p); // call previous fucntion to removed
  delete p;
  return 0;
}

void buddyList::sort(){
  buddyList temp;//declare a tem list
  buddy* p; //pinter
  while(head){
    p = maxByName();//call max by name, find the max
    remove(p);//call remove to remove the item from the list
    temp.add(p);//add to the tem list 
  }
  head = temp.head; // “this” head points to the list pointed to by temp’s head
  temp.head = NULL; // disconnect temp’s head from the linked list
}



