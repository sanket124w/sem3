/*Department of Computer Engineering has student's club named
'Pinnacle Club'. Students of second, third and final year of
department can be granted membership on request. Similarly
one may cancel the membership of club. First node is reserved
for president of club and last node is reserved for secretary of
club. Write C++ program to maintain club member‘s information
using singly linked list. Store student PRN and Name. Write
functions to:
a) Add and delete the members as well as president or even
secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two
lists.*/

#include<iostream>
using namespace std;

class node
{
	public:
		string PRN;
		string name;
		node *next;

		node()
		{	
			next = NULL;
		}
};

class club
{
	public:
		node *president, *secretary;

		club()
		{
			president = NULL;
			secretary = NULL;
		}

		void create();
		void display();
		void add_members();
		void delete_members();
		void add_president();
		void delete_president();
		void add_secretary();
		void delete_secretary();
		int count_members();
		void concate_list(club &c2);
};

void club ::create()
{
    president = new node();
    secretary = new node();
    cout << "Enter the President's PRN: ";
    cin >> president->PRN;
    cout << "Enter President's Name: ";
    cin >> president->name;
    cout << "Enter the Secretary's PRN: ";
    cin >> secretary->PRN;
    cout << "Enter Secretary's Name: ";
    cin >> secretary->name;
	president->next=secretary;
}

void club ::display()
{
	cout << "Club Members:" << endl;
    cout << "President : PRN - " << president->PRN << ", Name - " << president->name << endl;
    node* curr = president->next;
    while (curr != secretary) 
	{
        cout << "PRN - " << curr->PRN << ", Name - " << curr->name << endl;
        curr = curr->next;
    }
    cout << "Secretary : PRN - " << secretary->PRN << ", Name - " << secretary->name << endl;
}


void club ::add_members()
{
	node* newMember = new node();
	node* curr = president;
    
	cout << "Enter PRN: ";
    cin >> newMember->PRN;
    cout << "Enter Name: ";
    cin >> newMember->name;

	while (curr->next != secretary)
	{
        curr = curr->next;
    }
    curr->next = newMember;
    newMember->next = secretary;
}

void club::delete_members()
{
	if (president->next == secretary) 
	{
        cout << "No members to delete." << endl;
        return;
    }

    string prnNo;
    cout << "Enter the PRN of the member to delete: ";
    cin >> prnNo;

    node* prev = president;
    node* curr = president->next;
    while (curr != secretary) 
	{
        if (curr->PRN == prnNo) 
		{
            prev->next = curr->next;
            delete curr;
            cout << "Member Deleted Successfully !!" << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Member not found" << endl;
}

void club ::add_president()
{
	node* newPresident = new node();
    cout << "Enter PRN: ";
    cin >> newPresident->PRN;
    cout << "Enter Name: ";
    cin >> newPresident->name;

    newPresident->next = president;
    president = newPresident;
	cout << "New President Added Successfully !!" << endl;
}

void club ::delete_president()
{
    node* temp = president;
    president = president->next;
    delete temp;
    cout << "President deleted successfully." << endl;
}

void club ::add_secretary()
{
	node* newSecretary = new node();
    cout << "Enter PRN: ";
    cin >> newSecretary->PRN;
    cout << "Enter Name: ";
    cin >> newSecretary->name;

    node* curr = president;
    while (curr->next != secretary) {
        curr = curr->next;
    }
    curr->next = newSecretary;
    newSecretary->next = secretary;
	cout << "New Secretary Added Successfuly !!";
}

void club ::delete_secretary()
{
    node* prev = president;
    node* curr = president->next;
    while (curr->next != secretary) 
	{
        prev = curr;
        curr = curr->next;
    }
    prev->next = secretary;
    delete curr;
	cout << "Secretary Deleted Successfuly !!"<<endl;
}

int club ::count_members()
{
	int count = 0;
    node* temp = president;
    while (temp != secretary) 
	{
        count++;
        temp = temp->next;
    }
	count++;
    return count;
}

void club ::concate_list(club &c2)
{
	node* temp = president;
    while (temp->next != secretary) 
	{
        temp = temp->next;
    }
    temp->next = c2.president;
    delete c2.secretary;

    secretary = c2.secretary;
    c2.president = NULL;
    c2.secretary = NULL;
}

int main()
{
	club c;
	cout<<"Welcome to Pinnacle Club !!"<<endl;
	c.create();
	club c2;
	int ch;
	do
	{
		cout<<"----------------------------------------------------------"<<endl;
		cout << "\n\n* * * MENU * * *" << endl;
		cout << "1. Addition of Members" << endl;
		cout << "2. Deletion of Members" << endl;
		cout << "3. Addition of President" << endl;
		cout << "4. Deletion of President" << endl;
		cout << "5. Addition of Secretary" << endl;
		cout << "6. Deletion of Secretary" << endl;
		cout << "7. Counting Total Members of the Club" << endl;
		cout << "8. Display Members of the Club" << endl;
		cout << "9. Concatenation of Two Lists " << endl;
		cout << "10.Exit" << endl;
		cout << "Enter your Choice :";
		cin >> ch;
		cout<<"----------------------------------------------------------"<<endl;

		switch (ch)
		{
		case 1:
			c.add_members();
			break;

		case 2:
			c.delete_members();
			break;

		case 3:
			c.add_president();
			break;

		case 4:
			c.delete_president();
			break;

		case 5:
			c.add_secretary();
			break;

		case 6:
			c.delete_secretary();
			break;

		case 7:
			cout<<"Members in Pinancle Club : "<<c.count_members()<<endl;
			break;

		case 8:
			c.display();
			break;

		case 9:
			cout << "Creating 2nd List....Enter the members for 2nd List !!" << endl;
			c2.create();
			c2.add_members();
			c.concate_list(c2);
			cout << "Concatenated List is :" << endl;
			c.display();
			break;

		case 10:
			break;

		default:
			cout << "Wrong Input !!" << endl;
		}

	} while (ch != 10);

	return 0;
}

// Output
/*
Welcome to Pinnacle Club !!
Enter the President's PRN: 123
Enter President's Name: ABC
Enter the Secretary's PRN: 987
Enter Secretary's Name: XYZ
----------------------------------------------------------


* * * MENU * * *
1. Addition of Members
2. Deletion of Members
3. Addition of President
4. Deletion of President
5. Addition of Secretary
6. Deletion of Secretary
7. Counting Total Members of the Club
8. Display Members of the Club
9. Concatenation of Two Lists 
10.Exit
Enter your Choice :1
----------------------------------------------------------
Enter PRN: 456
Enter Name: MNO
----------------------------------------------------------


* * * MENU * * *
1. Addition of Members
2. Deletion of Members
3. Addition of President
4. Deletion of President
5. Addition of Secretary
6. Deletion of Secretary
7. Counting Total Members of the Club
8. Display Members of the Club
9. Concatenation of Two Lists
10.Exit
Enter your Choice :8
----------------------------------------------------------
Club Members:
President : PRN - 123, Name - ABC
PRN - 456, Name - MNO
Secretary : PRN - 987, Name - XYZ
----------------------------------------------------------


* * * MENU * * *
1. Addition of Members
2. Deletion of Members
3. Addition of President
4. Deletion of President
5. Addition of Secretary
6. Deletion of Secretary
7. Counting Total Members of the Club
8. Display Members of the Club
9. Concatenation of Two Lists
10.Exit
Enter your Choice :10
----------------------------------------------------------
*/

