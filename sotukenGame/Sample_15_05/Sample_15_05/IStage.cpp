#include "stdafx.h"
#include "IStage.h"
#include "Player.h"
#include "Random.h"
#include "DrBoar.h"
#include "DrTerrorBringer.h"
#include "DrNightmare.h"
#include "DrSoulEater.h"
#include "DrUsurper.h"

void IStage::PutOutDrBoar(int enemyPower)
{
	MakeEnemesAppear<DrBoar>(m_drBoarNum, enemyPower);
}

void IStage::PutOutDrTerrorBringer(int enemyPower)
{
	MakeEnemesAppear<DrTerrorBringer>(m_drTerrorBringerNum, enemyPower);
}

void IStage::PutOutDrNightmare(int enemyPower)
{
	MakeEnemesAppear<DrNightmare>(m_drNightmareNum, enemyPower);
}

void IStage::PutOutDrSoulEater(int enemyPower)
{
	MakeEnemesAppear<DrSoulEater>(m_drSoulEaterNum, enemyPower);
}

void IStage::PutOutDrUsurper(int enemyPower)
{
	MakeEnemesAppear<DrUsurper>(m_drUsurperNum, enemyPower);
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
