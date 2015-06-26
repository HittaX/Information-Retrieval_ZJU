#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <io.h>
using namespace std;

class TermScore
{
	string query;
	vector<string> term;
	vector<string> fileName;
 	int DocuNum;
	double **df;
	double **idf;
	int **tf;
	double **tf_idf;
	double *Score;
public:
	TermScore(string input);
	int split(const std::string &txt, std::vector<std::string> &strs, char ch);
	void traverse(string direName);
	~TermScore();
};

