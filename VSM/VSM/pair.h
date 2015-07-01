#pragma once

class Pair
{
public:
	double tf_idf;
	int id;
	bool operator > (const Pair &m)const {
		return tf_idf > m.tf_idf;
	}
	Pair(double tfidf,int i);
	~Pair();
};

