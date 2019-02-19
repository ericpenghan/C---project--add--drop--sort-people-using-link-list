//
//  buddyList.hpp
//  Project 4
//
//  Created by Eric Han on 11/28/18.
//  Copyright © 2018 Eric Han. All rights reserved.
//

#ifndef buddyList_hpp
#define buddyList_hpp

#include <stdio.h>
#include <string>
#include "buddy.hpp"
using namespace std;

class buddyList {
public:
  int drop(string fname, string lname);
  void sort();
  void read();
  buddyList();
  ~buddyList();
  // TODO: add prototype for destructor//done not sure
  void add(string fname, string lname, string phone);
  void print();
  
private:
  buddy * search(string fname, string lname);
  buddy * maxByName();
  void remove(buddy * r);
  buddy * head;
  void add(buddy * n);
};

#endif /* buddyList_hpp */
