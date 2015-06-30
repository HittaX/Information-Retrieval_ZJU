#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <io.h>
#include "tfidf.h"
using namespace std;

class TermScore
{
	string query;
	vector<string> term;
	vector<string> fileName;
	int fileNum;
	int termNum;
	vector<tfidf> score;
	vector<int> N;
public:
	TermScore::TermScore();
	void ReadQuery(string input);
	void ReadQuery(vector<string> &terms);
	int split(const string &txt, vector<string> &strs, char ch);
	void Traverse();
	void Calculate();
	~TermScore();
};

