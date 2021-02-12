#include "stdafx.h"
#include "Stage2.h"
#include "BackGround.h"
#include "StageWave.h"
#include "Game.h"
Stage2::Stage2()
{
}

Stage2::~Stage2()
{
	DeleteGO(m_backGround);
	QueryGOs<EnBase>("dragon", [](EnBase * drBoar)->bool
		{
			if (drBoar->GetStageNumber() == enStageNum2) {
				DeleteGO(drBoar);
			}
			return true;
		});
}

bool Stage2::Start()
{
	m_backGround = NewGO<BackGround>(0);

	//GameƒNƒ‰ƒX‚ğŒŸõB
	m_game = FindGO<Game>("Game");
	
	if (m_game->GetStage3ClearCount() <= 1) {
		PutOutDrNightmare(enStageNum2, en1);
	}
	else if (m_game->GetStage3ClearCount() <= 2) {
		PutOutDrNightmare(enStageNum2, en2);
	}
	else if (m_game->GetStage3ClearCount() <= 3) {
		PutOutDrNightmare(enStageNum2, en3);
		PutOutDrUsurper(enStageNum2, en1);
	}
	else if (m_game->GetStage3ClearCount() <= 4) {
		PutOutDrNightmare(enStageNum2, en4);
		PutOutDrUsurper(enStageNum2, en2);
	}
	return true;
}

void Stage2::Update()
{
	if (m_downEnemy == ENEMY_NUM)
	{
		m_timer++;
		if (m_timer > m_stageChangeTime) {
			m_sceanChangeOK = true;
		}
	}

	for (int i = 0; i < ENEMY_NUM; i++) {
		if (m_enemyList[i] != nullptr) {
			if (m_enemyList[i]->GetDeath()) {
				m_downEnemy++;
				m_enemyList[i] = nullptr;
			}
		}
	}
}