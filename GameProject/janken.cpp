#include <iostream>
#include "kyotu.h"
#include "janken.h"
using namespace std;

const char* showHands[] =
{
	"グー",
	"チョキ",
	"パー",
};

const char* showResults[] =
{
	"負け ...",
	"勝ち！！",
};

void initRand()
{
	srand((unsigned int)time(nullptr));
}

static RPS cpuHand()
{
	return (RPS)(rand() % 3);
}

static Result resultChecker(RPS player, RPS cpu)
{
	return (Result)((player - cpu + 2) % 3);
}

// じゃんけん関数
static Result RPSGame()
{
	RPS playerHand = ROCKS;
	Result thistimeResult = DRAW;

	// あいこがおわるまでループ
	while (true)
	{
		playerHand = ROCKS;

		// playerHand 入力
		while (true)
		{
			int input = -1;


			cout << "グー > 0 " << endl
				<< "チョキ > 1 " << endl
				<< "パー > 2 " << endl
				<< "じゃんけん・・・ > " << flush;
			cin >> input;

			if (input == 0 || input == 1 || input == 2)
			{
				playerHand = (RPS)input;
				break;
			}
			cout << "0, 1, 2 を入力してください\n\n";
		};

		RPS cpu = cpuHand();

		cout << "\nあなた > " << showHands[playerHand] << endl
			<< "CPU > " << showHands[cpu] << endl;

		thistimeResult = resultChecker(playerHand, cpu);

		if (thistimeResult != DRAW)
		{
			break;
		}

		cout << "\nあいこ！　もう一度！\n\n";
	}

	return thistimeResult;
}

// 本体（3 本先取）
void RPSSimurator()
{
	initRand();

	cout << "三本先取！じゃんけんゲーム！\n\n";

	bool finishFlag = true;
	int rounds = 1;
	RPS playerHand = ROCKS;
	RPS cpu = ROCKS;
	int results[2] =
	{
		0, 0,
	};

	// じゃんけん実行
	while (finishFlag)
	{
		Result thistimeResult = DRAW;

		cout << "===== 第 " << rounds << " 回戦 =====" << endl;

		// じゃんけん関数へ
		thistimeResult = RPSGame();

		// スコア加算
		results[thistimeResult]++;

		// 3 本取ったらbreak
		if (results[WIN] == 3 || results[LOSE] == 3)
		{
			break;
		}

		// 継続の場合、現在の結果を表示
		cout << showResults[thistimeResult] << endl
			<< "--- 現在のスコア ---" << endl
			<< "勝ち > " << results[WIN] << endl
			<< "負け > " << results[LOSE] << endl << endl;

		// ラウンド数を加算
		rounds++;
	}

	cout << "===== 最終結果 ===== " << endl
		<< "勝ち > " << results[WIN] << endl
		<< "負け > " << results[LOSE] << endl
		<< "あなたの"
		<< (results[WIN] == 3 ? showResults[WIN] : showResults[LOSE]);
}