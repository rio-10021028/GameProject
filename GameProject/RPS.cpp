#include <iostream>
using namespace std;

enum RPS
{
	ROCKS,
	SCISSORS,
	PAPERS
};

enum Result
{
	LOSE,	// 負け   0
	WIN,    // 勝ち   1
	DRAW    // あいこ 2
};

void initRand()
{
	srand((unsigned int)time(nullptr));
}

RPS cpuHand()
{
	return (RPS)(rand() % 3);
}

Result resultChecker(RPS player, RPS cpu)
{
	return (Result)((player - cpu + 2) % 3);
}

void RPSSimurator()
{
	initRand();

	cout << "三本先取！じゃんけんゲーム！" << endl;

	bool winFlag = true;
	int results[3] =
	{
		0, 0, 0
	};

	while (winFlag)
	{
		int playerHand;

		// playerHand 入力
		while(true)
		{
			cout << "じゃんけん・・・ > " << endl
				<< "グー > 0 " << endl
				<< "チョキ > 1 " << endl
				<< "パー > 2 " << flush;
			cin >> playerHand;

			if (playerHand == 0 || playerHand == 1 || playerHand == 2)
			{
				break;
			}
		};

		RPS cpu = cpuHand();

		//switch (resultChecker((RPS)playerHand, cpu))
		//{
		//case LOSE:

		//case WIN:
		//case DRAW:
		//}
	}
}