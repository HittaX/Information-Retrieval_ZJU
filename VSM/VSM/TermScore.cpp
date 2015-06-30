#include "TermScore.h"

TermScore::TermScore()
{
	Traverse();
	fileNum = fileName.size();
}

void TermScore::ReadQuery(string input)
{
	query = input;
	split(query, term, ' ');
	termNum = term.size();
	Calculate();
}

void TermScore::ReadQuery(vector<string> &terms)
{
	term = terms;
	termNum = term.size();
	Index();
	//	Calculate();
}

TermScore::~TermScore()
{
}

int TermScore::split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	unsigned int pos = txt.find(ch);
	unsigned int initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));
	return strs.size();
}

void TermScore::Traverse()
{
	_finddata_t fileDir;
	char* dir = "C:\\Users\\Song\\Information-Retrieval_ZJU\\VSM\\Reuters\\*.html";
	long lfDir;

	if ((lfDir = _findfirst(dir, &fileDir)) == -1l)
		printf("No file is found\n");
	else{
		do{
			fileName.push_back(fileDir.name);
		} while (_findnext(lfDir, &fileDir) == 0);
	}
	_findclose(lfDir);
}

void TermScore::Calculate()
{	
	string line;
	score.resize(termNum);
	for (int i = 0; i < fileNum; i++)
	{
		vector<string> split_res;
		string path = "C:\\Users\\Song\\Information-Retrieval_ZJU\\VSM\\Reuters\\"+fileName.at(i);
		fstream file(path);
		if (!file.is_open())
		{
			throw exception("Error when opening file");
		}
		while (!file.eof())
		{
			string str;
			getline(file, line);
			istringstream stream(line);
			while (stream >> str)
			{
				if (ispunct(str[str.size() - 1]))
					str = str.substr(0, str.size() - 1);
				split_res.push_back(str);
			}
		}
		N.push_back(split_res.size());
		for (int j = 0; j < termNum; j++)
		{
			int tfper = count(split_res.begin(), split_res.end(), term.at(j));
			score.at(j).tf.push_back(tfper);
			vector<string>::iterator it=find(split_res.begin(), split_res.end(), term.at(j));
			if (it != split_res.end())
			{
				score.at(j).df++;
			}
		}
		split_res.empty();
	}
	for (int j = 0; j < termNum; j++)
	{
		for (int i = 0; i < fileNum; i++)
		{
			score.at(j).tf_idf.push_back(tfidf::Calc_tfidf(score.at(j).tf.at(i), score.at(j).df, N.at(i)));
			cout << score.at(j).tf_idf.at(i) << endl;
		}
	}
}

int TermScore::insert(string a,int fN_index)//输入一个文档，参数a为文件名
{
	doc *newD, *nowD;
	token *newT;
	char str[40];//当前处理的词项 
	int i, j, flag;
	FILE *f1;
	f1 = fopen(a.c_str(), "r");

	while (!feof(f1))
	{
		string temp = fileName.at(fN_index);
		temp = temp.substr(0, temp.size() - 5);
		fscanf(f1, "%s", str);
		newD = (doc*)malloc(sizeof(doc));
		newD->docID = stoi(temp,nullptr,10);
		//词项已存在，直接加链表里 
		flag = 0;
		for (i = 0; i<tokNum; i++)
		{
			if (strcmp(str, tok[i]->term) == 0)
			{
				if (tok[i]->docFreq>0)
				{
					nowD = tok[i]->first;
					for (j = 1; j<tok[i]->docFreq; j++)
					{
						nowD = nowD->next;
					}
					nowD->next = newD;
				}
				else
				{
					tok[i]->first = newD;
				}
				flag = 1;
				tok[i]->docFreq++;
				break;
			}
		}

		//词项不存在，建立新词项 
		if (flag == 0)
		{
			newT = (token*)malloc(sizeof(token));
			strcpy(newT->term, str);
			newT->docFreq = 1;
			newT->first = newD;
			tok[tokNum] = newT;
			tokNum++;
		}
	}
	fclose(f1);
	return 0;
}


int TermScore::display(void)//打印倒排索引
{
	int i, j;
	doc *nowD;

	//逐个打印词项 
	for (i = 0; i<tokNum; i++)
	{
		printf("term:%s  ", tok[i]->term);
		printf("docFreq:%d  ", tok[i]->docFreq);
		printf("postings list: ");
		nowD = tok[i]->first;
		for (j = 1; j<tok[i]->docFreq; j++)
		{
			printf("%d ", nowD->docID);
			nowD = nowD->next;
		}
		printf("%d\n", nowD->docID);
	}
	return 0;
}

void TermScore::Index()
{
	for (int i = 0; i < fileNum; i++)
	{
		string path = "C:\\Users\\Song\\Information-Retrieval_ZJU\\VSM\\Reuters\\" + fileName.at(i);
		insert(path.c_str(),i);
	}
	display();
}