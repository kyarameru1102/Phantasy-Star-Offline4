#include "stdafx.h"
#include "EnBehaviorTest.h"
#include "PlayerStatusUI.h"

EnBehaviorTest::EnBehaviorTest()
{
}

EnBehaviorTest::~EnBehaviorTest()
{
}

bool EnBehaviorTest::Start()
{
	m_player = NewGO<Player>(0, "player");
	m_gameCam = NewGO<GameCamera>(0, "gameCamera");
	m_bg = NewGO<BackGround>(0, "backGround");
	m_drNight = NewGO<DrNightmare>(0, "drnight");
	m_drNight->SetPosition({ 1000.0f, 0.0f, -500.0f });
	//m_drBoar = NewGO<DrBoar>(0, "drboar");
	//m_drBoar->SetPosition({ 1000.0f, 0.0f, 500.0f });
	//m_drSoul = NewGO<DrSoulEater>(0, "drsoul");
	//m_drSoul ->SetPosition({ -1000.0f, 0.0f, 500.0f });
	//m_drTerror = NewGO<DrTerrorBringer>(0, "drterror");
	//m_drTerror->SetPosition({ -1000.0f, 0.0f, -500.0f });
    //m_drUsurper = NewGO<DrUsurper>(0, "drusurper");
	//m_drUsurper->SetPosition({ -1000.0f, 0.0f, 1000.0f });

	return true;
}

void EnBehaviorTest::Update()
{
	
}