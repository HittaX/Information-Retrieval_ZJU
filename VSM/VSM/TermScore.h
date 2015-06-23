#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TermScore
{
	string query;
	vector<string> term;
	int DocuNum;
	double **df;
	double **idf;
	int **tf;
	double **tf_idf;
	double *Score;
public:
	TermScore(string input);
	int split(const std::string &txt, std::vector<std::string> &strs, char ch);
	~TermScore();
};

