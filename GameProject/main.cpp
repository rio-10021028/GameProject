#include <iostream>
#include "janken.h"
#include "kazuate.h"
#include "kyotu.h"
using namespace std;

enum Mode 
{
	FINISH,
	JANKEN,
	KAZUATE
};

Mode modeSelecter()
{
	while (true)
	{
		int num = 0;

		cout << "じゃんけんゲーム > 1" << endl
			<< "数当てゲーム > 2" << endl
			<< "終了 > 0" << endl
			<< "モードを選択してください > " << flush;
		cin >> num;

		cout << endl;

		switch (num)
		{
		case 0:
			return FINISH;
		case 1:
			return JANKEN;
		case 2:
			return KAZUATE;
		default:
			break;
		}

		cout << "0, 1, 2 を入力してください\n\n";
	}
}

int main()
{
	cout << "===== Game Project へようこそ！ =====\n\n";

	while (true)
	{
		switch (modeSelecter())
		{
		case JANKEN:
			RPSSimurator();
			break;
		case KAZUATE:
			kazuateSimurator();
			break;
		case FINISH:
			cout << "バイバイ！" << endl;
			return 0;
		}

		cout << "--------------------------\n" 
			<< "おかえりなさい！\n\n";
	}
}