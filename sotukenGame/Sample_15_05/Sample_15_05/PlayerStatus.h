#pragma once
#include "Player.h"
#include "FontNumber.h"
#include "PlayerStatusUI.h"

/// <summary>
/// プレイヤーのステータスクラス。
/// </summary>
class PlayerStatus : public IGameObject
{
public:
	PlayerStatus();
	~PlayerStatus();

	/// <summary>
	/// 更新関数が呼ばれる前に呼ばれる開始関数。
	/// </summary>
	/// <returns>trueを返すと一度だけ呼ばれる</returns>
	bool Start()override;

	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update()override;

private:
	const enum {
		en_playerStatusUI,		//プレイヤーステータスのUI。
		en_playerStatusLevel,	//プレイヤーのレベル。
		en_playerStatusHP,		//プレイヤーのHP。
		en_playerStatusAttack,	//プレイヤーの攻撃力の数値。
		en_playerStatusNum,		//プレイヤーステータスUIの数。
	};

	Player* m_player = nullptr;											//プレイヤーのインスタンス。
	PlayerStatusUI* m_playerStatusUI = nullptr;							//プレイヤーステータスUIのインスタンス。
	SpriteRender* m_spriteRender[en_playerStatusNum] = { nullptr };		//スプライトレンダー。
	FontNumber* m_fontNumber[en_playerStatusNum] = { nullptr };			//フォントナンバー。
};