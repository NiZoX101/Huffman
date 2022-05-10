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
	ifstream in("D:\\in.txt");


	map<char, int> m;
	while (!in.eof())
	{
		char c;
		in >> c;
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
	Node* root = t.front();
	BTable(root);
	in.close();
	
	ifstream inp("D:\\out.txt");
	Node* p = root;
	int count = 0; char buf;
	inp >> buf;
	while (!inp.eof())
	{
		bool b = buf & (1 << (7 - count) );
		if (b)p = p->right; else p = p->left;
		if (p->left == NULL && p->right == NULL) { cout << p->c; p = root; }
		count++;
		if (count == 8) { count = 0; inp >> buf; }
	}
	inp.close();
}