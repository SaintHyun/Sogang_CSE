#include "solve.hpp"

int solve(Party *party)
{

	// TODO

	int i, tmp = 0;
	pair<int, int> question;

	// AknowB = party->askAToKnowB (i, j);
	// BknowA = party->askAToKnowB (j, i);

	for (i = 1; i < party->getN(); i++)
	{
		if (party->askAToKnowB(tmp, i))
		{
			question.first = tmp;
			tmp = i;
			question.second = i;
		}
	}
	//return tmp;
	// printf("%d %d\n",question.first,question.second);
	for (i = 0; i < party->getN(); i++)
	{
		if (i != tmp)
		{
			if ((question.first != i || question.second != tmp) && !party->askAToKnowB(i, tmp))
			{
				return -1;
			}
		}
	}
	for (i = 0; i < party->getN(); i++)
	{
		if (i != tmp)
		{
			if ((question.first != tmp || question.second != i) && !party->askAToKnowB(tmp, i))
			{
			}
			else return -1;
		}
	}
	return tmp;
	// return -1;
}
