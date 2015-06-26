#include "TermScore.h"


TermScore::TermScore(string input)
{
	query = input;
	split(query, term, ' ');
	for (auto &i : term)
	{
		cout << i << endl;
	}
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

void TermScore::traverse(string direName)
{
	_finddata_t fileDir;
	char* dir = "C:\\Users\\Song\\Information-Retrieval_ZJU\\VSM\\Reuters\\*.*";
	long lfDir;

	if ((lfDir = _findfirst(dir, &fileDir)) == -1l)
		printf("No file is found\n");
	else{
		printf("file list:\n");
		do{
			printf("%s\n", fileDir.name);

		} while (_findnext(lfDir, &fileDir) == 0);
	}
	_findclose(lfDir);
}