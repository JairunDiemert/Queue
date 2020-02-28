//File: Queue.h
//Author: Jairun Diemert
//Class: COP3530
//Project: Class work
//Description: This is the header file for the Queue class

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue
 {
  int  data;
  Queue *next;
	Queue *previous;
	Queue *currNodePtr;
	Queue *newNodePtr;
	Queue *head = NULL;
	Queue *tail = NULL;  //nullptr for C++11

  public :
  Queue(){};
  void  create();
  void  insert();
  int   del();
  void  display();
	void  size();
	void  displayBackward();
	void  searchList();
	void  replace();
	void  push();
	int   peek();
	void  enqueue();
	int   dequeue();
};


#endif 
