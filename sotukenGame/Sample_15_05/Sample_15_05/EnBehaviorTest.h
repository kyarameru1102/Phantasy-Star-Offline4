#pragma once
/// <summary>
/// �G�����m�F�N���X
/// </summary>
#include "EnTest.h"
#include "DrBoar.h"
#include "BackGround.h";
#include "Player.h"
#include "GameCamera.h"
#include "DrNightmare.h"
#include "DrSoulEater.h"
#include "DrTerrorBringer.h"
#include "DrUsurper.h"

class PlayerStatusUI;
class EnBehaviorTest : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	EnBehaviorTest();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~EnBehaviorTest();
	/// <summary>
	/// �X�^�[�g�֐��B
	/// </summary>
	/// <returns></returns>
	bool Start() override;
	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update() override;
	EnTest* m_entest[2] = { nullptr };
	DrBoar* m_drBoar =  nullptr;
	DrNightmare* m_drNight = nullptr;
	DrSoulEater* m_drSoul = nullptr;
	DrTerrorBringer* m_drTerror = nullptr;
	DrUsurper* m_drUsurper = nullptr;
	BackGround* m_bg = nullptr;
	Player* m_player = nullptr;
	GameCamera* m_gameCam = nullptr;
	PlayerStatusUI* m_playerStatusUI = nullptr;
};

