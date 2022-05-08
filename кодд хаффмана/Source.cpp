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
};


struct MyCompare
{
	bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
};





int main(int argc, char* argv[])
{
	////// считаем частоты символов	
	string s = "whenthelightsout";


	map<char, int> m;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		m[c]++;
	}
	map<char, int>::iterator i;
	for (i = m.begin(); i != m.end(); ++i)
		cout << i->first << ":" << i->second << endl;
	return 0;

	
}