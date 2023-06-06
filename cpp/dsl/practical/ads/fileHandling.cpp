#include <bits/stdc++.h>
using namespace std;

struct Student
{
	string a;
	string b;
	string c;
	string d;
};

int main()
{
	ofstream file("sample.txt", ios::app);
	if (file.is_open())
	{
		file << "hello i am sahil\n";
		file.close();
	}
	
	ifstream ofile("sample.txt", ios::out);
	string data;
	Student st;
	while (ofile >> st.a >> st.b >> st.c >> st.d)
	{
		cout << st.a << st.b << st.c << st.d << endl;
	}
	ofile.close();

	rename("sample.txt", "rename.txt");
	remove("sample.txt");
}
