// Rohan Panuganti
// p5.cpp
// 5/28/17
/*
  PURPOSE: The purpose of this program is to test a heap array

  INPUT: A file containing values is used as well as other values
  directly inputted

  PROCESS: The values are inserted into a node which is contained in
  an array. The heap has nodes removed or sifted through the array.
  Each function is tested.

  OUTPUT: The array is printed after each function is tested.
*/
#include <iostream>
#include <sstream>
#include "Heap.h"
#include <fstream>
using namespace std;

int main() {
  Heap h(100); // heap initialized

  // opening the file
  string filename = "input.txt";
  ifstream inputFile;
  inputFile.open(filename.c_str());

  if (inputFile.fail()) {
    cout << "Error loading the file... Program exiting.\n";
    return -1;
  }

  cout << "File loaded!\n\n";

  int id;
  int pr;
  string s;
  
  while (getline(inputFile, s)) {
    istringstream ss(s);
    ss >> id;
    ss.ignore();
    ss.ignore();
    ss >> pr;
    h.insert(id, pr);
  }

  cout << "1. Print the heap: " << endl; 
  h.print();
  cout << endl;
  cout << endl;

  cout << "2. Check if the heap is empty: "<< endl;
  if(h.isEmpty()){
    cout << "Empty!" << endl;
  } else {
    cout << "Not empty!" << endl;
  }
  cout << endl;
  cout << endl;

  cout << "3. Check if the insert works: " << endl;
  h.insert(9999, 9);
  h.print();
  cout << endl;
  cout << endl;

  cout << "4. See if getMin works: " << endl;
  cout << h.getMin() << endl;
  cout << endl;
  cout << endl;

  cout <<"5. Check the addValToPos function: " << endl;
  h.addValToPos(9, 5);
  h.print();
  cout << endl;
  cout << endl;

  cout << "6. Make sure replaceMin is working: " << endl;
  h.replaceMin(1002, 11);
  h.print();
  cout << endl;
  cout << endl;

  cout << "7. See if the deleteAtPos functions: " << endl;
  h.deleteAtPos(9);
  h.print();
  cout << endl;
  cout << endl;

  cout << "8. Delete all the even priorities: " << endl;
  h.flushEvenVal();
  h.print();
  cout << endl;
  cout << endl;

  cout << "9. Check if heapSort works: " << endl;
  h.heapSort();
  h.print();
  cout << endl;
  cout << endl;
  
  return 0;
}
