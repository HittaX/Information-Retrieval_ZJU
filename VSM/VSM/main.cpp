#include <iostream>
#include <string>
#include <sstream>
#include "TermScore.h"

using namespace std;

int main()
{
	string line,str;
	vector<string> terms;
	TermScore *query;
	try
	{
		query = new TermScore();
		do
		{
			getline(cin, line);
			istringstream stream(line);
			if (line == "_exit")
				return 1;
			while (stream >> str)
				terms.push_back(str);
			query->ReadQuery(terms);
			query->Clear();
			terms.clear();
		} while (1);
		return 0;
	}
	catch (exception err)
	{
		cout << err.what() << endl;
	}
}