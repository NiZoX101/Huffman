﻿#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
using namespace std;

class Node
{
public:
	int a;
	char c;
	Node* left, * right;

	Node() { left = right = NULL; }

	Node(Node* L, Node* R)
	{
		left = L;
		right = R;
		a = L->a + R->a;
	}
	Node(int chis, char symb)
	{
		a = chis;
		c = symb;
	}
	bool operator <(Node t)const
	{
		return a < t.a;
	}
	
};


void print_derev(Node* root, unsigned level = 0)
{
	if (root != NULL)
	{
		print_derev(root->left, level + 3);
		for (unsigned i = 0; i < level; i++)
		{
			cout << "   ";
		}
		if (root->c)cout << root->a << " ===" << root->c << endl;
		else cout << root->a << endl;
		print_derev(root->right, level + 3);

	}
}
struct Compare
{
	bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
};


vector <bool> code;
map<char, vector<bool> >table;
void BTable(Node* root)
{
	if (root->left != NULL)
	{
		code.push_back(0);
		BTable(root->left);
	}

	if (root->right != NULL)
	{
		code.push_back(1);
		BTable(root->right);
		if(!code.empty())
		code.pop_back();
	}

	if (root->left == NULL && root->right == NULL)
	{
		
		table[root->c] = code;
		cout << root->c << ": ";
		for (int i = 0; i < code.size(); i++)cout << code[i];
		cout << endl;
		if (!code.empty())
		code.pop_back();
	}
}



int main(int argc, char* argv[])
{
	////// считаем частоты символов	
	ifstream in("D:\\in.txt");


	map<char, int> m;
	while (!in.eof())
	{
		char c;
		in>>c;
		m[c]++;
	}
	/*
	map<char, int>::iterator i;
	for (i = m.begin(); i != m.end(); ++i)
		cout << i->first << ":" << i->second << endl;
	return 0;
	*/
	list<Node*> t;
	map<char, int>::iterator ind;
	for (ind = m.begin(); ind != m.end(); ++ind)
	{
		Node* p = new Node;
		p->c = ind->first;
		p->a = ind->second;
		t.push_back(p);
	}

	t.sort(Compare());
/*
	list<Node*> ::iterator ind;
	for (ind = t.begin(); ind != t.end(); ind++)
	{
		cout << (*ind)->a << ": " << (*ind)->c << endl;
	}
	*/

	while (t.size() != 1)
	{
		t.sort(Compare());
		Node* l_son = t.front();
		t.pop_front();
		Node* r_son = t.front();
		t.pop_front();

		Node* parent = new Node(l_son, r_son);
		t.push_back(parent);
	}
	Node* root = t.front();
	print_derev(root);
	BTable(root);

	in.clear(); in.seekg(0);
	while (!in.eof())
	{
		char pstr;
		in >> pstr;
		vector<bool>str = table[pstr];

		for (int j = 0; j < str.size(); j++)
			cout << str[j];
		cout << " ";

	}

}