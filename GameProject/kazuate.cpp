#include <iostream>
#include "kyotu.h"
using namespace std;

enum Compare
{
	EQUAL,		 // 両者は等しい     0
	BIGGER_IS_A, // 前者の方が大きい 1
	BIGGER_IS_B  // 後者の方が大きい 2
};

const char* resultMessage[] =
{
	"正解！！ クリア！！",
	"不正解... それより大きい数字です！",
	"不正解... それより小さい数字です！",
};

static int numSetter()
{
	return numRand(10, 1);
}

static Compare numCompare(const int a, const int b)
{
	if (a == b)
	{
		return EQUAL;
	}
	else if (a > b)
	{
		return BIGGER_IS_A;
	}
	else
	{
		return BIGGER_IS_B;
	}
}


static void kazuate()
{
	int answer = numSetter();

	for(int i = 1; i <= 5; i++)
	{
		int num = 0;

		cout << "----- " << i << " 手目 -----" << endl
			<< "1 から 10 の数字を入力してください > " << flush;
		cin >> num;

		Compare result = numCompare(answer, num);

		cout << resultMessage[result] << endl << endl;

		if (result == EQUAL)
		{
			return;
		}
	}

	cout << "残念... 正解は " << answer << " でした。\n\n";
}

void kazuateSimurator()
{
	initRand();

	cout << "===== 数当てゲーム！！ =====\n\n"
		<< "5 手以内に当ててね\n\n";

	kazuate();
}