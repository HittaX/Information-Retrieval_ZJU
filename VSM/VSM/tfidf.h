#pragma once

#include <vector>
using namespace std;
class tfidf
{
public:
	int df;
	double idf;
	vector<int> tf;
	vector<double> tf_idf;
	tfidf();
	static double Calc_tfidf(int tf,double df,int N);
	~tfidf();
};

