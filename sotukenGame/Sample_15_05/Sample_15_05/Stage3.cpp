#include "stdafx.h"
#include "Stage3.h"
#include "BackGround.h"
#include "DrNightmare.h"
#include "StageWave.h"
#include "Game.h"
Stage3::Stage3()
{
}

Stage3::~Stage3()
{
	DeleteGO(m_backGround);
	QueryGOs<DrNightmare>("dragon", [](DrNightmare * drUsurper)->bool
		{
			DeleteGO(drUsurper);
			return true;
		});
	//DeleteGO(m_drNight);
}

bool Stage3::Start()
{
	m_backGround = NewGO<BackGround>(0);
	//ウェーブのスプライト。
	StageWave* wave = NewGO<StageWave>(0);
	wave->SetWaveSprite(StageWave::Wave_Boss);

	m_game = FindGO<Game>("Game");
	m_drNight = NewGO<DrNightmare>(0, "dragon");
	m_drNight->SetPosition(InitEnemyPos());
	float mag = m_game->GetStage3ClearCount() * MAG_AP_INCREASE + 1.0f;
	m_drNight->SetMagnificationAP(mag);
	m_drNight->SetMagnificationHP(mag);
	
	//ゴーストオブジェクトの作成。
	m_ghostObject.CreateBox(m_ghostPosition, m_ghostRotation, m_ghostScale);
    return true;
}

void Stage3::Update()
{
	if (m_downEnemy == 1)
	{
		m_timer++;
		if (m_timer > 150) {
			//m_sceanChangeOK = true;
			GhostContactCharaCon();
		}
	}

	if (m_drNight != nullptr) {
		if (m_drNight->GetDeath()) {
			m_downEnemy++;
			m_drNight = nullptr;
		}
	}

}
