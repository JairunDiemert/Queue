//File: Queue.cpp
//Author: Jairuhigh Diemert
//Class: COP3530
//Project: Class work
//Description: This is the member function file for Queue.

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Queue.h"

void Queue::create()
{
	int n;
	currNodePtr=new Queue;
	std::cout<<"\n\n Okay! Creating the list for you...." << std::endl;
	std::cout<<" Enter the integer data for the first node: ";
	char ch='y';
	std::cin>>currNodePtr->data;
	head=currNodePtr;
	tail=currNodePtr;
	//currNodePtr->previous = NULL;
	currNodePtr->next=NULL;
	std::cout<<"\n\n First Node successfully added.";
	std::cout<<"\n\n Do you wish to add another node? (y/n): ";
	std::cin>>ch;

	while( ch=='y')
	{
		newNodePtr=new Queue;
		std::cout<<"\n\n Enter the integer data for the Node: ";
		std::cin>>newNodePtr->data;
		currNodePtr->next=newNodePtr;
		newNodePtr->next=NULL;  //nullptr for C++11
		//newNodePtr->previous = currNodePtr;
		tail=newNodePtr; 
		currNodePtr=newNodePtr;
		std::cout << "\n Node successfully inserted!" << std::endl;
		std::cout<<"\n\n Do you wish to add another node? (y/n): ";
		std::cin>>ch;
	} //end while
} //end create()

void  Queue::enqueue()
{
	currNodePtr = tail;
	newNodePtr = new Queue;

	cout << "\n Please enter the data for this element: ";
	cin >> newNodePtr->data;

	if(head == NULL)
	{
		head = newNodePtr;
		tail = newNodePtr;
		newNodePtr->next = NULL;
		cout << "\n First element successfully inserted in the Queue!\n";
	}
	else
	{
		currNodePtr->next = newNodePtr;
		newNodePtr->next = NULL;
		tail = newNodePtr;
		cout << "\n Element successfully inserted at the end of the Queue!\n";
	}
}

void Queue::insert()
  {
    int  ch;

    newNodePtr=new Queue;

    std::cout<<"\n Insert at the beginning of the list - 1 \n Insert at the end of the list       - 2 \n Insert somewhere in the middle      - 3";
    std::cout<<"\n\n\t Please enter your choice (1/2/3): ";
    std::cin>>ch;

    std::cout<<"\n Please enter the data for this node: ";
    std::cin>>newNodePtr->data;
    currNodePtr=head;

    if(head==NULL)
    {
	head=newNodePtr;
	tail=newNodePtr;
	newNodePtr->next=NULL;
	newNodePtr->previous = NULL;//jairun
    }
    else
    switch(ch)
    {

      case 1:   newNodePtr->next=currNodePtr;
		head=newNodePtr;
		newNodePtr->previous = NULL; //Jairun
                std::cout << "\n Node successfully inserted!" << std::endl;
		break;
      case 2:
		while(currNodePtr->next!=NULL)
		   currNodePtr=currNodePtr->next;

		newNodePtr->next=NULL;
		newNodePtr->previous = currNodePtr;//Jairun
		currNodePtr->next=newNodePtr;
		tail=newNodePtr;//jairun
                std::cout << "\n Node successfully inserted!" << std::endl;
		break;

      case 3 :  std::cout<<"\n Enter after which Node (Please specify the Data of that Node)?: ";
	        int item;
	        std::cin>>item;
	        while(currNodePtr->next!=NULL  && currNodePtr->data!=item)
		    currNodePtr=currNodePtr->next;

                if(currNodePtr->data==item)
	         {
		    newNodePtr->next=currNodePtr->next;
		    currNodePtr->next=newNodePtr;
				newNodePtr->previous=currNodePtr;
                    std::cout << "\n Node successfully inserted!" << std::endl;
	         }
	        else
		    std::cout<<"\n No such Node exists!!";
	        break;

      default :  std::cout<<"\n\n No Node entered in the List yet. Please reconsider your choice.\n ";
   } //end switch

 } //end insert


int Queue::del()
{
	int element;
  currNodePtr=head;

  if(head==NULL)
  {
		std::cout<<"\n No elements in the Queue!";
	}

  else if(currNodePtr->next==NULL)
  {
		element = currNodePtr-> data;
	  std::cout<<"\n Deleted .... No more elements in the List!";
	  head=NULL;
  }
	else
	{
		element = currNodePtr-> data;
		head=currNodePtr->next;
		free(currNodePtr);
		std::cout<<"\n Element " << element << " Deleted.";
	}
	return element;
}


void Queue::searchList()
{
	currNodePtr=head;

       if(head==NULL)
       {
	        std::cout<<"\n No Node in the List!";
	     }

			 std::cout<<"\n Which Node do you wish to seach? Please specify its integer data: " ;
		       int item,i=1;
		       std::cin>>item;
		       currNodePtr=head;

		       while(currNodePtr->next!=NULL && currNodePtr->data !=item)
		       {
		          i++;
							currNodePtr=currNodePtr->next;
		       }

		       if(currNodePtr->data==item)
		       {
		         std::cout<<"\n Node Data : "<<currNodePtr->data << " \nLocate at index: " << i <<"\n";
					 }
		       else
		         std::cout<<"\n No Node Found! " ;
}

void Queue::display()
{
   currNodePtr=head;

   if(head==NULL)
       std::cout<<"\n No Node yet!\n";
   else
   {
      while(currNodePtr->next!=NULL)
      {
	 std::cout<<"\n Node Data : "<<currNodePtr->data;
	 currNodePtr=currNodePtr->next;
      }
      std::cout<<"\n Node Data : "<<currNodePtr->data;
   } //end else
} //end display()

void Queue::displayBackward()
{
	currNodePtr=head;

   if(head==NULL)
       std::cout<<"\n No Node yet!\n";

	else
	{
		currNodePtr=tail;
		while(currNodePtr->previous!=NULL)
		{
			std::cout<<"\n Node Data : "<<currNodePtr->data;
	    currNodePtr=currNodePtr->previous;
		}
		std::cout<<"\n Node Data : "<<currNodePtr->data;
	}
}


void Queue::size()
{
	currNodePtr=head;
	int size = 1;

	if(head==NULL)
		std::cout << "\n No elements in list.\n";
	else
	{
		while(currNodePtr->next!=NULL)
		{
			++size;
			currNodePtr=currNodePtr->next;
		}
		std::cout << "\n There are " << size << " elements in the list.\n";
	}
	
}

void Queue::replace()
{
	
	currNodePtr=head;
	newNodePtr=new Queue;

	if(head==NULL)
  {
		std::cout<<"\n No Node in the List!";
	}
	else
	{
		std::cout<<"\n Enter which Node to replace(Please specify the Data of that Node)?: ";
	  int item;
	  std::cin>>item;

	  while(currNodePtr->next!=NULL  && currNodePtr->data!=item)
		{
		  currNodePtr=currNodePtr->next;
		}
    if(currNodePtr->data==item)
	  {
			std::cout<<"\n Please enter the data for this node: ";
    	std::cin>>newNodePtr->data;
			currNodePtr->data = newNodePtr->data;
		}
		else
			std::cout<<"\n No such Node exists!!";
	}
}

void Queue::push()
{
	newNodePtr = new Queue();
	std::cout<<"\n Please enter the data for this node: ";
  std::cin>>newNodePtr->data;
  currNodePtr=head;
	if(head==NULL)
    {
			head=newNodePtr;
			newNodePtr->next = NULL;
			std::cout << "\n Node successfully inserted!" << std::endl;
    }
  else
    {
			newNodePtr->next=currNodePtr;
		  head=newNodePtr;
      std::cout << "\n Node successfully inserted!" << std::endl;
		}
}

int Queue::peek()
{
	int element;
  currNodePtr=head;

  if(head==NULL)
  {
		std::cout<<"\n No elements in the Queue!";
	}
	else
	{
		element = currNodePtr-> data;
		std::cout<<"\n Element " << element << " is at the top of the Queue.";
	}
	return element;
}
