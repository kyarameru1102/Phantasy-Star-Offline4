#include "stdafx.h"
#include "Stage1.h"
#include "BackGround.h"
#include "RecoveryItem.h"
#include "StageWave.h"
#include "Game.h"
Stage1::Stage1()
{
}

Stage1::~Stage1()
{
	DeleteGO(m_backGround);

	QueryGOs<RecoveryItem>("recoveryItem", [](RecoveryItem* recoveryItem)->bool
	{
		DeleteGO(recoveryItem);
		return true;
	});
	QueryGOs<EnBase>("dragon", [](EnBase * drBoar)->bool
		{
			if (drBoar->GetStageNumber() == enStageNum1) {
				DeleteGO(drBoar);
			}
			return true;
		});
}

bool Stage1::Start()
{
	m_stageNum = enStageNum1;
	m_backGround = NewGO<BackGround>(0);

	//Gameクラスを検索。
	m_game = FindGO<Game>("Game");

	//DrBoarの数を増やす。
	m_drBoarNum += m_game->GetStage3ClearCount();
	if (m_game->GetStage3ClearCount() <= 1) {
		PutOutDrBoar(en1);
	}
	else if (m_game->GetStage3ClearCount() <= 2) {
		PutOutDrBoar(en2);
	}
	else if (m_game->GetStage3ClearCount() <= 3) {
		PutOutDrBoar(en3);
	}
	else if (m_game->GetStage3ClearCount() <= 4) {
		PutOutDrBoar(en4);
	}
	
	m_recoveryItem = NewGO<RecoveryItem>(0, "recoveryItem");
	m_recoveryItem->SetPosition({1000.0f, 0.0f, -2500.0f});


	return true;
}

void Stage1::Update()
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

