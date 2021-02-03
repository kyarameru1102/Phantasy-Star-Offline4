#include "stdafx.h"
#include "Stage3.h"
#include "BackGround.h"
#include "DrNightmare.h"
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
	m_game = FindGO<Game>("Game");
	m_drNight = NewGO<DrNightmare>(0, "dragon");
	m_drNight->SetPosition(InitEnemyPos());
	float mag = m_game->GetStage3ClearCount() * MAG_AP_INCREASE + 1.0f;
	m_drNight->SetMagnificationAP(mag);
	m_drNight->SetMagnificationHP(mag);
	
	//�S�[�X�g�I�u�W�F�N�g�̍쐬�B
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
