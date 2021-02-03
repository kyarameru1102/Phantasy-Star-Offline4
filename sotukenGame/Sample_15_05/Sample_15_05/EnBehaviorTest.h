#pragma once
/// <summary>
/// 敵挙動確認クラス
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
	/// コンストラクタ。
	/// </summary>
	EnBehaviorTest();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~EnBehaviorTest();
	/// <summary>
	/// スタート関数。
	/// </summary>
	/// <returns></returns>
	bool Start() override;
	/// <summary>
	/// 更新関数。
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

