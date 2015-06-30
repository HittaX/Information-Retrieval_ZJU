#include "tfidf.h"


tfidf::tfidf()
{
	df = 0;
	idf = 0;
}


tfidf::~tfidf()
{
}

double tfidf::Calc_tfidf(int tf, double df,int N)
{
	double tf_idf;
	tf_idf = tf*(log(N) - log(df));
	return tf_idf;
}