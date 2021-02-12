#include "stdafx.h"
#include "Stage3.h"
#include "BackGround.h"
#include "StageWave.h"
#include "Game.h"
Stage3::Stage3()
{
}

Stage3::~Stage3()
{
	DeleteGO(m_backGround);
	QueryGOs<EnBase>("dragon", [](EnBase * drBoar)->bool
		{
			if (drBoar->GetStageNumber() == enStageNum3) {
				DeleteGO(drBoar);
			}
			return true;
		});
}

bool Stage3::Start()
{
	m_backGround = NewGO<BackGround>(0);
	

	m_game = FindGO<Game>("Game");

	if (m_game->GetStage3ClearCount() <= 1) {
		PutOutDrTerrorBringer(enStageNum3, en1);
	}
	else if (m_game->GetStage3ClearCount() <= 2) {
		PutOutDrTerrorBringer(enStageNum3, en2);
	}
	else if (m_game->GetStage3ClearCount() <= 3) {
		PutOutDrTerrorBringer(enStageNum3, en3);
	}
	else {
		PutOutDrTerrorBringer(enStageNum3, en4);
	}
	
    return true;
}

void Stage3::Update()
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
