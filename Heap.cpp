// Rohan Panuganti
// 5/28/17
// Heap.cpp


#include "Heap.h"
#include "Process.h"
#include <iostream>
using namespace std;

// constructor
Heap::Heap (int cap = 100){
  theHeap = new Process[cap];
  capacity = cap;
  size = 0;
}

// destructor
Heap::~Heap(){
  delete [] theHeap;
}

// resize the array
void Heap::resize(){
  if(size-1 == capacity)
    capacity *= 2;
  Process * leHeap = new Process[capacity];
  for(int i = 0; i < size; i++){
    leHeap[i] = theHeap[i];
  }
  delete [] theHeap;
  theHeap = leHeap;
}

// check if empty
bool Heap::isEmpty() const{
  if(size == 0)
    return true;
  return false;
}

// insert values
void Heap::insert(int i, int p) {
  size++;
  theHeap[size - 1].setID(i);
  theHeap[size - 1].setPr(p);
  percolateUp(size - 1);
}

// sift up
void Heap::percolateUp(int pos){
  int parent;
  if(pos){
    parent = (pos-1)/2;
    if(theHeap[pos] < theHeap[parent]){
      Process temp = theHeap[parent];
      theHeap[parent] = theHeap[pos];
      theHeap[pos] = temp;
      percolateUp(parent);
    }
  }
}

// sift down
void Heap::percolateDown(int pos){
  int left, right, min;
  left = 2 * pos + 1;
  right = 2 *pos + 2;

  if(right >= size){

    if(left >= size){
      return;
    } else {
      min = left;
    }

  } else {

    if(theHeap[left] <= theHeap[right]){
      min = left;
    } else {
      min = right;
    }
  }
  if(theHeap[min] < theHeap[pos]){
    Process temp = theHeap[min];
    theHeap[min] = theHeap[pos];
    theHeap[pos] = temp;
    percolateDown(min);
  }
}

// return the min priority and id
int Heap::getMin() const{
  cout << theHeap[0].getID() << "&";
  return theHeap[0].getPr();
}

// delete the root value
void Heap::deleteMin() {
  theHeap[0] = theHeap[size-1];
  size--;
  if(size > 0){
    percolateDown(0);
  }
}

// print the heap
void Heap::print() const{
  for (int i = 0; i < size; i++){
    cout << theHeap[i].getID() << "&" << theHeap[i].getPr() << " ";
  }
  cout << endl;
}

// sort the heap
void Heap::heapSort() {
  int s = size;
  while(s-1 > 0) {
    Process temp = theHeap[0];
    theHeap[0] = theHeap[s-1];
    theHeap[s-1] = temp;
    s--;
    percolateDown(0);
  }
}

// change the priority of the a certain position
void Heap::addValToPos(int pos, int p){
  theHeap[pos].setPr(p);
  percolateDown(pos);
}

// change the min node
void Heap::replaceMin(int i, int p){
  theHeap[0].setID(i);
  theHeap[0].setPr(p);
  percolateDown(0);
}

// delete a certain position
void Heap::deleteAtPos(int p){
  theHeap[p] = theHeap[size - 1];
  size--;
  percolateDown(p);
}

// delete all even priorities
void Heap::flushEvenVal(){
  for(int i=0; i < size; i++){
    if(theHeap[i].getPr()%2 == 0){
      theHeap[i] = theHeap[size - 1];
      size--;
      percolateDown(i);
    }
  }
}
