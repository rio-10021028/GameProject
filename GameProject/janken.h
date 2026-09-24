#pragma once
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

void RPSSimurator();