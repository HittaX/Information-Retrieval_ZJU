#include <iostream>
#include <string>
#include "TermScore.h"
using namespace std;
int main()
{
	string line;
	TermScore *query;
	do
	{
		getline(cin,line);
		if (line == "_exit")
			return 1;
		query = new TermScore(line);
	} while (1);
	return 0;
}