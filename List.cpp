// CPuls1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node
{
public:
	char data;
	int key;
	Node* next;
};

class List
{
	Node* head = NULL;
	Node* cursor = NULL;
	Node* prev = NULL;
public:
	List() {

	}
	~List() {
		MakeListEmpty();
	}
	bool ListIsEmpty() const {
		return (head == NULL);
	}
	bool CurIsEmpty() const {
		return(cursor == NULL);
	}
	void ToFirst() {
		cursor = head;
		prev = NULL;
	}
	bool AtFirst() {
		return (cursor == head);
	}

	void Advance() {
		prev = cursor;
		cursor = cursor->next;
	}

	void ToEnd()
	{
		ToFirst();
		if (!ListIsEmpty()) {
			while (cursor->next != NULL)
				Advance();
		}
	}
	//  هل انت في الأخر؟
	bool atEnd() const {
		// الهيد مش فاضي
		if (ListIsEmpty())
			return true;
		// الهيد مش فاضي لكن الركنت == فاضي
		else if (CurIsEmpty())
			return false;
		// الهيد مش فاضي والكرنت مش فاضي شوف هل النيكست فاضي؟
		else return (cursor->next == NULL);
	}
	int ListSize() const {
		Node* q; int count;
		q = head; count = 0;
		while (q != NULL)
		{
			count++;
			q = q->next;
		}
		return count;
	}
	void UpdatData(const char& d)
	{
		cursor->data = d;
	}

	void RetrieveData(int& k, char& d)const
	{
		d = cursor->data;
		k = cursor->key;
	}

	void RetrievveKey(int& k)const
	{
		k = cursor->key;
	}
	void InsertFirst(const int& k, const char& d)
	{
		Node* pNew;
		pNew = new Node;

		pNew->data = d;
		pNew->key = k;
		pNew->next = head;

		head = pNew;
		cursor = head;
		prev = NULL;
	}

	void InsertAfter(const int& k, const char& d)
	{
		Node* pNew;
		pNew = new Node;

		pNew->data = d;
		pNew->key = k;
		pNew->next = cursor->next;
		cursor->next = pNew;
		prev = cursor;
		cursor = pNew;
	}
	void InsertBefore(const int& k, const char& d) {
		Node* pNew;
		pNew = new Node;

		pNew->data = d;
		pNew->key = k;

		pNew->next = cursor;
		prev->next = pNew;
		cursor = pNew;
	}

	void InsertEnd(const int& k, const char& d) {
		if (ListIsEmpty())
			InsertFirst(k, d);
		else {
			ToEnd();
			InsertAfter(k, d);
		}
	}

	void DeleteNode()
	{
		Node* q;

		if (!CurIsEmpty()) {
			if (AtFirst()) {
				q = cursor;
				cursor = cursor->next;
				head = cursor;
				delete q;
			}
			else {
				q = cursor;
				cursor = cursor->next;
				prev->next = cursor;
				delete q;
			}
		}
	}
	void DeleteFirst() {
		if (!ListIsEmpty())
		{
			ToFirst();
			DeleteNode();
		}
	}
	void DeleteEnd() {
		if (!ListIsEmpty())
		{
			ToEnd();
			DeleteNode();
		}
	}
	void MakeListEmpty()
	{
		ToFirst();
		while (!ListIsEmpty())
		{
			DeleteNode();
		}
	}
	bool Search(const int& k)
	{
		bool found = false;
		ToFirst();
		while ((!found) && (cursor != NULL))
		{
			if (k == cursor->key)
				found = true;
			else
				Advance();
		}
	}
	void OrderInsert(const int& k, const char& d)
	{
		ToFirst();
		while (cursor != NULL && k > cursor->key)
			Advance();
		if (prev == NULL)
			InsertFirst(k, d);
		else
			InsertBefore(k, d);

	}
	void Traverse()
	{
		ToFirst();
		while (!CurIsEmpty())
		{
			cout << cursor->key << " " << cursor->data << endl;
			Advance();
		}
	}
};
int CoutZero(List& l) {
	int count = 0; int k; char d;
	l.ToFirst();
	while (!l.CurIsEmpty()) {
		l.RetrieveData(k, d);
		if (k == 0)
			count++;
		l.Advance();
	}
	return count;
}
int SumKey(List &l) {
	int count = 0; int k; char d;
	l.ToFirst();
	while (!l.CurIsEmpty()) {
		l.RetrieveData(k, d);
		count += k;
		l.Advance();
	}
	return count;
}

int main()
{
	List list;
	list.InsertEnd(1, 'a');
	list.InsertEnd(2, 'b');
	list.InsertEnd(3, 'c');
	list.InsertEnd(5, 'e');
	list.OrderInsert(1, 'd');
	list.Traverse();
	cout << "count: " << CoutZero(list);
	cout << "count: " << SumKey(list);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
