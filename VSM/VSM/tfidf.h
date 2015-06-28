#pragma once

#include <vector>
using namespace std;
class tfidf
{
public:
	int N;
	vector<int> df;
	vector<double> idf;
	vector<int> tf;
	vector<double> tf_idf;
	tfidf();
	~tfidf();
};

