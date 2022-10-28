#include "iostream"
#include "iomanip"
#include <time.h>
#include "fstream"
using namespace std;

int kol = 0; //������� ��������� �������

struct Node
{
	int data;
	Node* Next;
};
typedef Node* PNode;
void AddToSpis(PNode& MyNode, PNode& Head, int data)
{

	PNode NextNode = MyNode;
	if (MyNode == NULL)
	{
		MyNode = new Node;
		MyNode->data = data;
		MyNode->Next = NULL;
		Head = MyNode;
	}
	else
	{
		NextNode = new Node;
		MyNode->Next = NextNode;
		NextNode->data = data;
		NextNode->Next = NULL;
		MyNode = NextNode;
	}
}
void Del(int k, PNode& Head, PNode tek, PNode prev) //�������� ������ ������
{
	PNode p, p1;
	switch (k)
	{
	case 1: 
		p = Head;
		p1 = p->Next;

		while (p != tek)
		{
			delete p;
			p = p1;
			p1 = p1->Next;
		}
		Head = tek->Next;
		break;
	case 2:
		p = prev->Next;
		p1 = p->Next;

		while (p != tek)
		{
			delete p;
			p = p1;
			p1 = p1->Next;
		}
		prev->Next = tek->Next;

		break;
	case 3:
		p = Head;
		p1 = p->Next;
		while (p->Next != NULL)
		{
			delete p;
			p = p1;
			p1 = p1->Next;
		}
		Head = NULL;
		tek = prev = NULL;
		break;

	case 4:
		p = prev->Next;
		p1 = p->Next;
		while (p->Next != NULL)
		{
			delete p;
			p = p1;
			p1 = p1->Next;
		}
		prev->Next = NULL;
		break;
	case 5:
		p = prev->Next->Next;
		p1 = p->Next;
		while (p->Next != NULL)
		{
			delete p;
			p = p1;
			p1 = p1->Next;
		}
		prev->Next->Next = NULL;
		break;
	case 6:
		p = prev->Next;
		p1 = p->Next;

		while (p != tek)
		{
			delete p;
			p = p1;
			p1 = p1->Next;
		}
		prev->Next = tek->Next;
		break;
	default:
		break;
	}
}
void proxod(PNode& Head, int n, PNode tek, PNode prev, int k) //������ ���� �������� �� < 3, tek - �������, prev - ���������� �������
{
	bool Pi = false; //���������� �������� �������, ��� ��������� prev ��� head �������� ��������� ������
	int i = 0;
	if (Head == NULL || Head->Next == NULL)
	{
		return;
	}
	tek = Head->Next;
	prev = Head;
	if (tek->data == prev->data)
	{
		k += 1;
		Pi = true;
	}

	while (tek->Next != NULL && (k >= 3 || i + 1 < n))
	{
		if (tek->Next != NULL && tek->data == tek->Next->data)
		{
			k++;
		}
		else
		{
			if (tek->Next != NULL && k >= 2 && tek->Next->data != tek->data)
			{
				break;
			}
			else
				k = 0;
		}

		tek = tek->Next;
		if (tek->Next != NULL && tek->data != prev->Next->data)
		{
			prev = prev->Next;
		}
		i++;

	}
	if (k >= 2)
	{
		k++;
		kol += k;
		if (Pi)
		{
			if (kol != n)
			{
				if (Head == prev) //��� ������� ��� ���� �������� ���������� � ������

					Del(1, Head, tek, prev);
				else
					Del(2, Head, tek, prev);
			}
			else
			{
				Del(3, Head, tek, prev);
				return;
			}
		}
		else
		{
			if (tek->Next == NULL)
			{
				if (prev->Next->data == tek->data)

					Del(4, Head, tek, prev);
				else

					Del(5, Head, tek, prev);
			}
			else
			{
				Del(6, Head, tek, prev);
			}
		}
		proxod(Head, n, tek, prev, 0);
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	PNode Head, MyNode, PrevNode;
	Head = MyNode = PrevNode = NULL;
	int n, data; //���������� ������� � ������
	cout << "������� ���������� ������� � �������" << endl;
	cin >> n;
	cout << "������� �������� ������� �������" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		AddToSpis(MyNode, Head, data);
	}
	int k = 0; //���������� ������������� ������ ������ ��������
	proxod(Head, n, MyNode, PrevNode, k);
	cout << "���������� ��������� �������: ";
	cout << kol << endl;
}
