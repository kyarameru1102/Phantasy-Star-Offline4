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
	m_stageNum = enStageNum2;
	m_backGround = NewGO<BackGround>(0);

	//GameƒNƒ‰ƒX‚ğŒŸõB
	m_game = FindGO<Game>("Game");
	
	if (m_game->GetStage3ClearCount() <= 1) {
		PutOutDrNightmare(en1);
	}
	else if (m_game->GetStage3ClearCount() <= 2) {
		PutOutDrNightmare(en2);
	}
	else if (m_game->GetStage3ClearCount() <= 3) {
		PutOutDrNightmare(en3);
		PutOutDrUsurper(en1);
	}
	else if (m_game->GetStage3ClearCount() <= 4) {
		PutOutDrNightmare(en4);
		PutOutDrUsurper(en2);
	}
	else {
		m_drNightmareNum = 3;
		PutOutDrNightmare(en4);

		m_drUsurperNum = 3;
		PutOutDrUsurper(en3);
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