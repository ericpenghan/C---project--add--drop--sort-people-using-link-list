//
//  buddy.hpp
//  Project 4
//
//  Created by Eric Han on 11/28/18.
//  Copyright © 2018 Eric Han. All rights reserved.
//

#ifndef buddy_hpp
#define buddy_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class buddy {
  friend class buddyList;
  // TODO: declare class buddyList to be a friend of this class//done
  
public:
  buddy()  {
    first = last = phone = ""; next = NULL;
    cout << "Buddy allocated\n";
  }
  ~buddy(){
    if (next != NULL){
      delete next;
    }
     cout << "Buddy " << first << " " << last << " deallocated!\n";
  }
  
  // TODO: add destructor. Include this cout//problem
  //  cout << "Buddy " << first << " " << last << " deallocated!\n";//done maybe
  
  void set(string fname, string lname, string tele) {
    first = fname;
    last = lname;
    phone = tele;
  }
  void print() {
    cout << left << setw(15) << last << setw(15) << first << "  " << phone << endl;
  }
private:
  string first;
  string last;
  string phone;
  buddy * next;  // pointer to next buddy in the list
};

#endif /* buddy_hpp */
