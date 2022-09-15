/*Name: Bryan Berkey
  Date: 10/23/2018
  Class: C201
  Hw2: Create a image structure containing a integer id, char array of pixels,
  and a image pointer called next to point to the next structure in the linked 
  list. Then create a function called add_tail to add to a structure to the end
  linked list. */

#include <iostream>
using namespace std;


struct img{
	int id;
	char pxls[512][512];
	img* next;
}; // structure given to us on the assignment sheet

int add_tail(img* head); // adding on to the end of the linked list
void clear_pxls(img* head); // clear the char array in the new structure
img* init(img* head); //initialize the head of the linked list
void printlist(img* head); // print the id of each structure in the linked list

int main(){
	img* head = init(head); 
	cout << "Head is in main now " << head << endl; //to let me know init ran correctly and retured to the main.
	for(int i = 0; i < 10; i++) // adding 10 items to the linked list
		add_tail(head);
	
	printlist(head);
	}

/*                      Function: init ***(initialize)***
  Purpose: this will initailze the head of the linked list and start the linked list
  Input: Head: pointer to the start of the linked list.
  are wanting to zero out
  Output: it does not send anything back but the char array will have been cleared */


img* init(img* head){
	head = new img;
	cout << "Head is in init " << head << endl; //to let me know i made it into the init function and that head recieved an addresss
	head->id = 1; 
	clear_pxls(head);
	head->next = NULL;
	return head;
}

/*                      Function: clear_pxls
 Purpose: to zero out the char array pxls in the structure 
 Input: Head/Temp: This will point to the structure that contains the array you are wanting to zero out
 Output: it does not send anything back but the char array will have been cleared */


void clear_pxls(img* head){
	for (int i = 0;i < 512;i++){
		for (int j = 0;j < 512;j++)
			head->pxls[i][j] = 0;
 	}	
}

/*                      Function: add_tail
 Purpose: to add a image structure to the end of the linked list
 Input: Head: image pointer to the start of the linked list
 Output: 0 if successful. 1 if there was an error and head equaled NULL */


int add_tail(img* head){
	cout << "you are in add tail" << endl; //letting me know i made it into the function
	img* temp;
	if (head == NULL){cout << "error head = NULL";} //checking if head is pointing to something and does not equal NULL
	
	temp = head; //to make sure we do not change the value of head by putting it into a temporary place
	
	while(temp->next != NULL)
		{temp = temp->next;
		return 1;} //to move temp to the end of the linked list
	
	temp->next = new img;
	temp->next->id = temp->id+1;
	clear_pxls(temp);
	temp->next->next = NULL; // set the end of the linked list to NULL 
	cout << "leaving add tail" << endl; // Let you know its left the fucntion
	return 0;
	
}
/*			Function: printlist
 *Purpose: to print the id numbers of each structure in the linked list in order
  Input: Head: image pointer to the start of the linked list
  Output: None. Just a print function*/
void printlist(img* head){
	cout << "you are in printlist" << endl;
	img* temp;
	temp = head; // to make sure we do not mess with the value of head

	while(temp != NULL){
		cout << temp->id << " "; // print the id's of each structure in the linked list
		temp = temp->next; // move to the next structure in the linked list
	} 
}

/*Ouput:
Head is in init 0x7ff8dbf89010
Head is in main now 0x7ff8dbf89010
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in add tail
leaving add tail
you are in printlist
1 2 3 4 5 6 7 8 9 10 11 */