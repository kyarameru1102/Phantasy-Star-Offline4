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
	//Game�N���X�������B
	m_game = FindGO<Game>("Game");
	//�o������G�̐���ݒ�B
	ENEMY_NUM += m_game->GetStage3ClearCount();
	for (int i = 0; i < ENEMY_NUM; i++) {
		//�G��NewGO����B
		DrUsurper* drUs = NewGO<DrUsurper>(0, "dragon");
		//���W��ݒ�B
		drUs->SetPosition(InitEnemyPos());
		//�U���͂̔{����ݒ�B
		float mag = m_game->GetStage3ClearCount() * MAG_AP_INCREASE + 1.0f;
		drUs->SetMagnificationAP(mag);
		//HP�̔{����ݒ�B
		drUs->SetMagnificationHP(mag);
		//���X�g�ɓ����B
		m_enemyList.push_back(drUs);
	}
	//�S�[�X�g�I�u�W�F�N�g�̍쐬�B
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