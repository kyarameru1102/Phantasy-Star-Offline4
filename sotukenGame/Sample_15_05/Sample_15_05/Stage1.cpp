#include "stdafx.h"
#include "Stage1.h"
#include "DrBoar.h"
#include "BackGround.h"
#include "Player.h"
#include "RecoveryItem.h"
#include "DrTerrorBringer.h"
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
	
	QueryGOs<DrBoar>("dragon", [](DrBoar* drBoar)->bool
	{
		DeleteGO(drBoar);
		return true;
	});

	QueryGOs<DrTerrorBringer>("dragon", [](DrTerrorBringer* drBoar)->bool
		{
			DeleteGO(drBoar);
			return true;
		});
}

bool Stage1::Start()
{
	m_backGround = NewGO<BackGround>(0);

	StageWave* wave = NewGO<StageWave>(0);
	wave->SetWaveSprite(StageWave::Wave_One);

	//Gameクラスを検索。
	m_game = FindGO<Game>("Game");
	//出現する敵の数を設定。
	ENEMY_NUM += m_game->GetStage3ClearCount();
	int a = ENEMY_NUM;
	a--;
	for (int i = 0; i < a; i++) {
		//敵をNewGOする。
		DrBoar* drB = NewGO<DrBoar>(0, "dragon");
		//座標設定。
		drB->SetPosition(InitEnemyPos());
		//攻撃力の倍率を設定。
		float mag = m_game->GetStage3ClearCount() * MAG_AP_INCREASE + 1.0f;
		drB->SetMagnificationAP(mag);
		//HPの倍率を設定。
		drB->SetMagnificationHP(mag);
		//リストに入れる。
		m_enemyList.push_back(drB);
	}
	DrTerrorBringer* drB = NewGO<DrTerrorBringer>(0, "dragon");
	//座標設定。
	drB->SetPosition(InitEnemyPos());
	//攻撃力の倍率を設定。
	float mag = m_game->GetStage3ClearCount() * MAG_AP_INCREASE + 1.0f;
	drB->SetMagnificationAP(mag);
	//HPの倍率を設定。
	drB->SetMagnificationHP(mag);
	//リストに入れる。
	m_enemyList.push_back(drB);

	m_recoveryItem = NewGO<RecoveryItem>(0, "recoveryItem");
	m_recoveryItem->SetPosition({1000.0f, 0.0f, -2500.0f});

	//ゴーストオブジェクトの作成。
	m_ghostObject.CreateBox(m_ghostPosition, m_ghostRotation, m_ghostScale);

	return true;
}

void Stage1::Update()
{
	if (m_downEnemy == ENEMY_NUM)
	{
		GhostContactCharaCon();
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

