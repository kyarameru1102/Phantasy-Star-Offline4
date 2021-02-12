#include "stdafx.h"
#include "IStage.h"
#include "Player.h"
#include "Random.h"
#include "DrBoar.h"
#include "DrTerrorBringer.h"
#include "DrNightmare.h"
#include "DrSoulEater.h"
#include "DrUsurper.h"

void IStage::PutOutDrBoar(int stageNum, int enemyPower)
{
	MakeEnemesAppear<DrBoar>(stageNum, m_drBoarNum, enemyPower);
}

void IStage::PutOutDrTerrorBringer(int stageNum, int enemyPower)
{
	MakeEnemesAppear<DrTerrorBringer>(stageNum, m_drTerrorBringerNum, enemyPower);
}

void IStage::PutOutDrNightmare(int stageNum, int enemyPower)
{
	MakeEnemesAppear<DrNightmare>(stageNum, m_drNightmareNum, enemyPower);
}

void IStage::PutOutDrSoulEater(int stageNum, int enemyPower)
{
	MakeEnemesAppear<DrSoulEater>(stageNum, m_drSoulEaterNum, enemyPower);
}

void IStage::PutOutDrUsurper(int stageNum, int enemyPower)
{
	MakeEnemesAppear<DrUsurper>(stageNum, m_drUsurperNum, enemyPower);
}

Vector3 IStage::InitEnemyPos()
{
	//Random�N���X�������B
	m_rand = FindGO<Random>("rnad");
	//�G��X���W��Z���W��͈͓��Ń����_���Ō��߂�B
	float rand = m_rand->GetRandDouble();
	float posX = m_rand->Lerp(rand, -1969.4f, 1847.9f);
	rand = m_rand->GetRandDouble();
	float posZ = m_rand->Lerp(rand, -1157.0f, 874.5f);
	return { posX , 0.0f, posZ };
}
