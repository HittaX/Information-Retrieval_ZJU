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
	if (tf == 0)
		return 0;
	else
	{
		tf_idf = tf*(log(N) - log(df));
		return tf_idf;
	}
}