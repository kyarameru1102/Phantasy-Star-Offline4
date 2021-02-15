#include "stdafx.h"
#include "PlayerStatus.h"

PlayerStatus::PlayerStatus()
{
}

PlayerStatus::~PlayerStatus()
{
	for (int i = 0; i < en_playerStatusNum; i++) {
		DeleteGO(m_spriteRender[i]);
		DeleteGO(m_fontNumber[i]);
	}
}

bool PlayerStatus::Start()
{
	m_player = FindGO<Player>("player");
	m_playerStatusUI = FindGO<PlayerStatusUI>("playerStatusUI");

	//画像の初期化。
	//ステータスUI。
	m_spriteRender[en_playerStatusUI] = NewGO<SpriteRender>(0);
	m_spriteRender[en_playerStatusUI]->Init("Assets/image/PlayerStatusUI.DDS", 400, 304);
	m_spriteRender[en_playerStatusUI]->SetPosition({ -250.0f, 50.0f, 0.0f });
	//プレイヤーのレベル。
	m_spriteRender[en_playerStatusLevel] = NewGO<SpriteRender>(0);
	m_spriteRender[en_playerStatusLevel]->Init("Assets/image/PlayerStatusLevelText.DDS", 70, 80);
	m_spriteRender[en_playerStatusLevel]->SetPosition({ -165.0f, 140.0f, 0.0f });
	//プレイヤーのHP。
	m_spriteRender[en_playerStatusHP] = NewGO<SpriteRender>(0);
	m_spriteRender[en_playerStatusHP]->Init("Assets/image/PlayerStatusHpText.DDS", 30, 40);
	m_spriteRender[en_playerStatusHP]->SetPosition({ -150.0f, 40.0f, 0.0f });
	//プレイヤーの攻撃力。
	m_spriteRender[en_playerStatusAttack] = NewGO<SpriteRender>(0);
	m_spriteRender[en_playerStatusAttack]->Init("Assets/image/PlayerStatusAttackText.DDS", 50, 150);
	m_spriteRender[en_playerStatusAttack]->SetPosition({ -200.0f, -60.0f, 0.0f });

	//プレイヤーステータスのフォントを初期化。
	//プレイヤーのレベル。
	m_fontNumber[en_playerStatusLevel] = NewGO<FontNumber>(0);
	m_fontNumber[en_playerStatusLevel]->SetScale({ 0.4f, 0.4f, 0.4f });
	//プレイヤーのHP。
	m_fontNumber[en_playerStatusHP] = NewGO<FontNumber>(0);
	m_fontNumber[en_playerStatusHP]->SetScale({ 0.4f, 0.4f, 0.4f });
	//プレイヤーの攻撃力。
	m_fontNumber[en_playerStatusAttack] = NewGO<FontNumber>(0);
	m_fontNumber[en_playerStatusAttack]->SetScale({ 0.4f, 0.4f, 0.4f });

	return true;
}

void PlayerStatus::Update()
{
	//スタートボタンを押した。
	if (g_pad[0]->IsTrigger(enButtonStart)) {
		DeleteGO(this);
	}

	//プレイヤーのHPが0になった。
	if (m_player->GetHP() <= 0.0f) {
		DeleteGO(this);
	}

	//プレイヤーステータスのフォントナンバーを設定。
	//プレイヤーのレベル。
	m_fontNumber[en_playerStatusLevel]->SetDisplayNum(m_player->GetPlayerLevel());
	m_fontNumber[en_playerStatusLevel]->SetPosition({ -350.0f, 140.0f, 0.0f });
	//プレイヤーのHP。
	m_fontNumber[en_playerStatusHP]->SetDisplayNum(m_player->GetMaxHP());
	m_fontNumber[en_playerStatusHP]->SetPosition({ -350.0f, 40.0f, 0.0f });
	//プレイヤーの攻撃力。
	m_fontNumber[en_playerStatusAttack]->SetDisplayNum(m_player->GetmAtaackPow());
	m_fontNumber[en_playerStatusAttack]->SetPosition({-350.0f, -60.0f, 0.0f});

}