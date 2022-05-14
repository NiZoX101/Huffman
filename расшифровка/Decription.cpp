#include <iostream>
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
		if (!code.empty())
			code.pop_back();
	}

	if (root->left == NULL && root->right == NULL)
	{

		table[root->c] = code;
		if (!code.empty())
			code.pop_back();
	}
}



int main(int argc, char* argv[])
{
	////// считаем частоты символов	
	ifstream in("D:\\in.txt",ios::binary);


	map<char, int> m;
	while (!in.eof())
	{
		char c=in.get();
		m[c]++;
	}

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
	setlocale(LC_ALL, "Russian");
	Node* root = t.front();
	BTable(root);
	in.close();
	in.clear(); in.seekg(0);
	ifstream inp("D:\\out.txt",ios::binary);
	ofstream out("D:\\Dec.txt");
	Node* p = root;
	int count = 0; char buf=inp.get();
	while (!inp.eof())
	{
		    if ((int)buf == 13) {char bu = inp.get();
			if ((int)bu != 10) inp.seekg(-1, ios::cur);
			else buf = bu;
			}
			bool b = buf & (1 << (7 - count));
			if (b)p = p->right; else p = p->left;
			if (p->left == NULL && p->right == NULL) {out << p->c; /*cout << p->c;*/ p = root; }
		
		count++;
		if (count == 8) { count = 0; buf=inp.get(); }
	}
	inp.close();
	return 0;
}