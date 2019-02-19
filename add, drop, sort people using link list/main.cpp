//-----------------------------------------------------------
//                  CS 215 - Fall 2018 - Project 4
//                    Eric Han - 005
//-----------------------------------------------------------
#include <iostream>
#include "buddyList.hpp"

char askMenuOpt() {
  char opt;
  string input;
  
  cout << "\n===== Buddy List Pro =====\n";
  cout << "A - Add buddy \n";
  cout << "D - Delete buddy\n";
  cout << "P - Print list\n";
  cout << "S - Sort list\n";
  cout << "X - Exit\n";
  cout << "===> ";
  cin >> input;
  opt = toupper(input[0]);
  return opt;
}

int main() {
  {
    buddyList b;
    string first, last, phone;
    char opt;
    int rc;
    b.read();
    
    do {
      opt = askMenuOpt();
      switch (opt) {
        case 'A':
          cout << "Enter buddy's First Last Phone: ";
          cin >> first >> last >> phone;
          b.add(first, last, phone);
          cout << "Buddy added!\n\n";
          break;
        case 'D':
          cout << "Enter buddy's First Last: ";
          cin >> first >> last;
          rc = b.drop(first, last);
          if (rc == 0)
            cout << "Buddy dropped!\n\n";
          else
            cout << "No buddy with that name!\n";
          break;
        case 'S':
          b.sort();
          cout << "List sorted!\n";
          break;
        case 'P': b.print(); break;
        case 'X': break;
        default: cout << "Invalid option!\n";
      }
    } while (opt != 'X');
  }
  system("pause");
  return 0;
}
