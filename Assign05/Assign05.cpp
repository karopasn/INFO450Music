// Assign05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

class node
{
	int data;
	char song[25];
	char artist[25];
	node *next;
public:
	void setnode(char s[], char a[]);
	friend class linkedList;
};

void node::setnode(char s[], char a[])
{
	strcpy_s(song, s);
	strcpy_s(artist, a);
}
class linkedList
{
	node *head;
	node *tail;
	char filename[100];
public:
	linkedList();
	void addNodeToEnd(node *nptr);
	void addNodeToHead(node *nptr);
	int insertAfter(node *ptr, int i);
	void Menu();
	void displayList();
	void playSong();
	void skipSong(int j);
	int removeSong(char r[]);
	void readList();
	void setFile(char f[]);
};

linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
}

void linkedList::displayList()
{
	node *ptr;
	ptr = head;
	cout << "----Playlist----" << endl;
	if (ptr == NULL)
	{
		cout << "The playlist is empty." << endl;
		return;
	}
	cout << "(head is " << head->song << "tail is " << tail->data << ")" << endl;
	while (ptr != NULL)
	{
		cout << "Next song is " << ptr->song << endl;
		ptr = ptr->next;
	}
}

void linkedList::addNodeToEnd(node *ptr)
{
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		tail->next = ptr;
		tail = ptr;
	}
}

void linkedList::addNodeToHead(node *ptr)
{
	if (head == NULL)
	{
		head = ptr;
		tail = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
}

int linkedList::insertAfter(node *newnode, int i)
{
	node *ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == i)
		{
			newnode->next = ptr->next;
			ptr->next = newnode;
			if (tail == ptr)
				tail = newnode;
			return 0;
		}
		ptr = ptr->next;
	}
	return -1;
}

void linkedList::playSong()
{
	node *ptr;
	ptr = head;
	if (ptr == NULL)
	{
		cout << "There are currently no songs in this playlist" << endl;
		return;
	}
	else
	{
		cout << "Playing: " << ptr->song << "by " << ptr->artist << endl;
	}
}
void linkedList::skipSong(int j)
{
	node *ptr;
	ptr = head;
	if (int j = 1)
	{
		ptr = ptr->next;
	}
}
int linkedList::removeSong(char r[])
{
	node *ptr = head;
	if (ptr == NULL)
	{
		return -1;
	}
	if (strcmp(head->song, r) == 0)
	{
		if (head == tail)
		{
			
			head = NULL;
			tail = NULL;
			
		}
		else
		{
			head = head->next;
			delete ptr;
			cout << "Song has been deleted." << endl;
			return 0;
		}
	}

}
void linkedList::Menu()
{
	node *ptr;
	ptr = head;
	while (1 == 1)
	{
		char answer;
		cout << "Main Menu" << endl;
		cout << "[P]lay....Press P to play the first song in the playlist" << endl;
		cout << "[S]kip....Press S to skip the song" << endl;
		cout << "[D]elete....Press D to delete a song from the playlist" << endl;
		cout << "[Q]uit....Press Q to exit the main menu." << endl;
		cin >> answer;

		if (answer == 'P' || answer == 'p')
		{
			if (ptr == NULL)
				ptr = head;
			cout << "Playing: " << ptr->song << " by " << ptr->artist << endl;
			ptr = ptr->next;
		}
		else if (answer == 'S' || answer == 's')
		{
			int skip = 1;
			skipSong(skip);
		}
		else if (answer == 'D' || answer == 'd')
		{
			char r[25];
			cout << "Please enter the song name you wish to delete(Warning: Case sensitive)" << endl;
			cin.clear();
			cin.ignore();
			cin.getline(r, 25);
			removeSong(r);
		}
		else
		{
			break;
		}
	}
}
void linkedList::readList()
{
	ifstream infile(filename);
	if (!infile)
	{
		cout << "The playlist you submitted is unreadable." << endl;
		return;
	}
	while (!infile.eof())
	{
		char s[25];
		char a[25];

		infile.getline(s, 25, ',');
		if (strlen(s))
		{
			infile.getline(s, 25, ',');
			node *ptr = new node();
			ptr->setnode(s, a);
		}
	}
	infile.close();
}
void linkedList::setFile(char f[])
{
	strcpy_s(filename, f);
}
int main()
{

	linkedList *myList = new linkedList();
	char file[30];
	cout << "Please enter the file name of the playlist" << endl;
	cin >> file;
	cin.clear();
	cin.ignore();
	myList->setFile(file);
	myList->readList();
	myList->Menu();
}

