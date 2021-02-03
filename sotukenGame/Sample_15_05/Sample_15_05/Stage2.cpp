#include "stdafx.h"
#include "Stage2.h"
#include "BackGround.h"
#include "DrUsurper.h"
#include "Game.h"
Stage2::Stage2()
{
}

Stage2::~Stage2()
{
	DeleteGO(m_backGround);
	QueryGOs<DrUsurper>("dragon", [](DrUsurper* drUsurper)->bool
	{
		DeleteGO(drUsurper);
		return true;
	});
}

bool Stage2::Start()
{
	m_backGround = NewGO<BackGround>(0);
	//Gameクラスを検索。
	m_game = FindGO<Game>("Game");
	//出現する敵の数を設定。
	ENEMY_NUM += m_game->GetStage3ClearCount();
	for (int i = 0; i < ENEMY_NUM; i++) {
		//敵をNewGOする。
		DrUsurper* drUs = NewGO<DrUsurper>(0, "dragon");
		//座標を設定。
		drUs->SetPosition(InitEnemyPos());
		//攻撃力の倍率を設定。
		float mag = m_game->GetStage3ClearCount() * MAG_AP_INCREASE + 1.0f;
		drUs->SetMagnificationAP(mag);
		//HPの倍率を設定。
		drUs->SetMagnificationHP(mag);
		//リストに入れる。
		m_enemyList.push_back(drUs);
	}
	//ゴーストオブジェクトの作成。
	m_ghostObject.CreateBox(m_ghostPosition, m_ghostRotation, m_ghostScale);

	return true;
}

void Stage2::Update()
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