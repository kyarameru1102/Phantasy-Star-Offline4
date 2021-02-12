#include "stdafx.h"
#include "Game.h"
#include "PlayerStatusUI.h"
#include "Menu.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Random.h"
<<<<<<< HEAD

#include "Result.h"
=======
#include "StageWave.h"
>>>>>>> 5735714fe9f9105b6036d19439e917c70f6833a0

Game::Game()
{

}

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_gameCam);
	DeleteGO(m_playerStatusUI);
	QueryGOs<IStage>("stage", [](IStage* stage)->bool
		{
			DeleteGO(stage);
			return true;
		});
}

bool Game::Start()
{
	m_stage1 = NewGO<Stage1>(0,"stage");
	m_currentStage++;
	//ウェーブのスプライト。
	StageWave* wave = NewGO<StageWave>(0);
	wave->SetNum(m_currentStage);

	m_player = NewGO<Player>(0, "player");
	m_gameCam = NewGO<GameCamera>(0, "gameCamera");
	m_rand = NewGO<Random>(0, "rnad");
	m_rand->Init((unsigned long)time(NULL));
	return true;
}

void Game::Update()
{
	if (g_pad[0]->IsTrigger(enButtonStart) && m_menu != nullptr) {
		//メニュー画面を開いていて、STARTボタンを押したら、
		//メニュー画面を閉じる。
		DeleteGO(m_menu);
		m_menu = nullptr;
	}
	else if (g_pad[0]->IsTrigger(enButtonStart) && m_menu == nullptr) {
		//メニュー画面を閉じていて、STARTボタンを押したら、
		//メニュー画面を開く。
		m_menu = NewGO<Menu>(0);
    }

	if (m_stage1 != nullptr) {
		if (m_stage1->GetsceanChangeOK()) {
			m_enemyDeadNum += m_stage1->GetDeathEnemyNum();
			DeleteGO(m_stage1);
			m_stage1 = nullptr;
			m_clearFloorNum++;
			m_stage2 = NewGO<Stage2>(0, "stage");
			m_currentStage++;
			//ウェーブのスプライト。
			StageWave* wave = NewGO<StageWave>(0);
			wave->SetNum(m_currentStage);
		}
	}
	if (m_stage2 != nullptr) {
		if (m_stage2->GetsceanChangeOK()) {
			m_enemyDeadNum += m_stage2->GetDeathEnemyNum();
			DeleteGO(m_stage2);
			m_stage2 = nullptr;
			m_clearFloorNum++;
			m_stage3 = NewGO<Stage3>(0, "stage");
			m_currentStage++;
			//ウェーブのスプライト。
			StageWave* wave = NewGO<StageWave>(0);
			wave->SetNum(m_currentStage);
		}
	}
	if (m_stage3 != nullptr) {
		if (m_stage3->GetsceanChangeOK()) {
			m_enemyDeadNum += m_stage3->GetDeathEnemyNum();
			DeleteGO(m_stage3);
			m_stage3 = nullptr;
			m_stage3ClearCount++;
			m_clearFloorNum++;
			m_stage1 = NewGO<Stage1>(0, "stage");
			m_currentStage++;
			//ウェーブのスプライト。
			StageWave* wave = NewGO<StageWave>(0);
			wave->SetNum(m_currentStage);
		}
	}
	m_playerDeath = m_player->GetDeathFlag();
	if (m_playerDeath != false) {
		//りざるとNewGOしてね。
		NewGO<Result>(0, "result");

	}
}
