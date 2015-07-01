#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <io.h>
#include <functional>
#include "tfidf.h"
#include "pair.h"

using namespace std;

class TermScore
{
	struct doc
	{
		int docID;
		struct doc *next;
	};

	struct token
	{
		char term[40];
		int docFreq;
		struct doc *first;
	};

	typedef struct doc doc;
	typedef struct token token;

	token *tok[50000];
	const string routes = "C:\\Users\\Song\\Information-Retrieval_ZJU\\VSM\\Reuters\\";
	string query;				//查询的语句
	vector<string> term;		//查询的关键词(由query分割得到)
	vector<string> fileName;	//语料库的文件名称 xxx.html(不含路径)
	int fileNum;
	int termNum;
	int tokNum=0;
	vector<tfidf> score;		//VSM的得分
	vector<int> N;				//每个文档词的个数
public:
	TermScore::TermScore();
	void ReadQuery(string input);
	void ReadQuery(vector<string> &terms);
	int split(const string &txt, vector<string> &strs, char ch);
	void Traverse();
	void Calculate();
	int insert(string a,int fN_index);//输入一个文档，参数a为文件名 
	int display(void);			//打印倒排索引
	double QueryVector();
	void Index();
	~TermScore();
};

