/*Name: Bryan Berkey
  Date: 10/30/2018
  Class: C201
  Hw3: Create a img struct containing and integer id, character array pixels, and a img pointer called next. Then create 6 functions add tail, add head, add id, delete id, delete head, delete tail.  */

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
img* add_head(img* head); // add to the head of the linked list
int add_id(img*& head,int id); // add at any point in the linked list 
int delete_id(img*& head, int id); // delete any point in the linked list
int delete_tail(img* head); // delete the tail of the linked list
int delete_head(img*& head); // delete the head of the linked list

int main(){
	img* head = init(head); 
	cout << "Head is in main now " << head << endl; //to let me know init ran correctly and retured to the main.
	for(int i = 0; i < 10; i++) // adding 10 items to the linked list
		add_tail(head);
	
	printlist(head);
	head = add_head(head);
        cout << "Head = " << head << endl; // verify head was set to point to the new head of the linked list
	printlist(head);

	add_id(head,-1); // to test out the add_id function with 3 different tests 
	add_id(head,6);
	add_id(head,15);
	printlist(head);

	delete_tail(head); // to test out the delete_tail function
	printlist(head);
	
	delete_head(head); // to test out the delete_head function
	printlist(head);

	delete_id(head,5); // to test out the delete_id function with 3 different tests.
	delete_id(head,0);
	delete_id(head,11);
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
	if (head == NULL){cout << "error head = NULL"; return 1;} //checking if head is pointing to something and does not equal NULL
	
	temp = head; //to make sure we do not change the value of head by putting it into a temporary place
	
	while(temp->next != NULL)
		{temp = temp->next;} //to move temp to the end of the linked list
	
	temp->next = new img;
	temp->next->id = temp->id+1;
	clear_pxls(temp);
	temp->next->next = NULL; // set the end of the linked list to NULL 
	cout << "leaving add tail" << endl; // Let you know its left the fucntion
	return 0;
	
}
/*
			Function: printlist
 *Purpose: to print the id numbers of each structure in the linked list in order
  Input: Head: image pointer to the start of the linked list
  Output: None. Just a print function*/
void printlist(img* head){
	cout << "you are in printlist" << endl;
	img* temp;
	temp = head; // to make sure we do not mess with the value of head

	while(temp != NULL){
		cout << temp->id << " "<< endl; // print the id's of each structure in the linked list
		temp = temp->next; // move to the next structure in the linked list
	} 
}

/*
 *                         Function: add_head
 Purpose: to add to the head of the linked list
 Input: Head: imgage point to the start of the linked list
 Output: Heads new value. Since we are adding to the head of the linked list we need to have the head equal the new head of the linked list by sending it back to the main */

img* add_head(img* head){
	if(head == NULL){cout << "Head = NULL" << endl;return head;}
	
	cout << "Head = " << head << endl; // check head initial location its pointing to

	img* p = new img; 
	p->id = head->id-1; // set the new id to one less of the initial head id since we are adding to the head of the linked list
	clear_pxls(p);
	p->next = head; // to set the new heads next to the old heads location it pointed to
	head = p; // have head point to the new head loctation
	cout << "Head = " << head << endl; // check that head is pointing to a new location
	return head; // return the new heads loctation it needs to point to
	
}
/*
 *                         Function: add_id
 Purpose: to add a struct at the point indicated by the id number passed in to the function
 Input: Head: Reference image pointer to the start of the linked list ID: integer for the id/location of the linked list we want to add a struct to
 Output: we will not send anything back to the main but if we had changed what head is pointing to then the reference variable created in function header will act as sending something back to the main so the order of the linked list is still good */
int add_id(img*& head,int id){
	
	img* temp = head;

	if(id <= temp->id){
		img* p = new img;
		p->id = id;
		clear_pxls(p);
		p->next = temp;
		head = p;
		return 0;} // this is basically the "add_head" function but sends back 0 instead of the new head since we have the reference variable head
	if(temp->next == NULL){
		add_tail(temp);
		while(temp->next != NULL)
			temp = temp->next;
		temp->id = id;
		return 0;
	} // if the head is also the tail we will be calling the "add_tail" function since the head is also the tail making
	while(temp->next->id < id && temp->next->next != NULL){
		temp = temp->next;
	} // keep going through the linked list until you reach the end of the linked list or the spot in the linked list you want to add to 
	if(temp->next->id < id && temp->next->next == NULL){
		img* p = new img;
		p->id = id;
		clear_pxls(p);
		p->next = NULL;
		temp->next->next = p;
		return 0;	
	} // if you reach the end of the linked list and the id is still greater than you will add to the tail
	if(temp->id < id && temp->next != NULL){
		img* p = new img;
		p->id = id;
		clear_pxls(p);
		p->next = temp->next;
		temp->next = p;
		return 0;} // if you reach the spot in the linked list you want to add to and its not the head or tail

}
/*
 *                         Function: delete_tail
 Purpose: to delete the tail of the linked list and set the 2nd to last struct to be the new tail
 Input: Head: image pointer to the start of the linked list
 Output: Nothing: we will not be sending anything back just deleting the tail of the linked list*/
int delete_tail(img* head){
	while(head->next->next != NULL)
		head = head->next; // move to the end of the linked list
	delete head->next->next; // delete the tail of the linked list
	head->next = NULL; //set the new end of the linked list to NULL
	return 0;
}
/*
 *                         Function: delete_head
 Purpose: to delete the head of the linked list and point head to the next structure after the first struct
 Input: Head: reference image pointer to the start of the linked list
 Output: We will not be sending anything directly back to the main but the reference variable to head will be making sure the head in main is pointing to the next struct in the linked list since we are deleting the head of the linked list*/
int delete_head(img*& head){
	img* temp = head; // set a temporary variable to avoid losing the linked list
	temp = head->next; // set the temporary pointer to point to the second struct in the list
	delete head; // delete the struct head points to 
	head = temp; // set head to point to what temp points to which is the second struct in the old list which is the new head of the new linked list
	return 0;
}
/*
                            Function: delete_id
 Purpose: delete any structure in the linked list by using the id number passed in to find that structure in the linked list
 Input: Head: reference image pointer to the start of the linked list. ID: the id number of the struct you are wanting to delete
 Output: We will not be sending anything directly back to the main but the reference variable will make sure that the head in the main and the "head" in the function match so the linked list is not lost.*/
int delete_id(img*& head, int id){
	img* temp = head;
	if(id <= temp->id){
		temp = head->next;
		delete head;
		head = temp;
		return 0;} // this is like the function delete_head
	while(temp->next->id < id && temp->next->next != NULL)
		temp = temp->next; //move through the linked to the id number that was called or to the end if list if the id was not found
	if(temp->next->id = id && temp->next->next == NULL){
		delete temp->next->next; 
		temp->next = NULL;
		return 0;} // if the id number is found at the tail of the linked list then we will delete the tail of the list and set the second to last struct to NULL
	if(temp->id = id && temp->next != NULL){
		img* tobedeleted = temp->next;
		temp->next = temp->next->next;
		delete tobedeleted;
		return 0;} // if the id number is found in between the head and tail we will set the struct before to point to the struct after the id we found and then delete the struct with the id number we called for
}

/*
 Head is in init 0x7f65bf8d8010
Head is in main now 0x7f65bf8d8010
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
1
2
3
4
5
6
7
8
9
10
11
Head = 0x7f65bf8d8010
Head = 0x7f65bf60d010
Head = 0x7f65bf60d010
you are in printlist
0
1
2
3
4
5
6
7
8
9
10
11
you are in printlist
-1
0
1
2
3
4
5
6
6
7
8
9
10
11
15
you are in printlist
-1
0
1
2
3
4
5
6
6
7
8
9
10
11
you are in printlist
0
1
2
3
4
5
6
6
7
8
9
10
11
you are in printlist
1
2
3
1
6
6
7
8
9
10
[beberkey@cs03 hw3]$
*
 * */	
