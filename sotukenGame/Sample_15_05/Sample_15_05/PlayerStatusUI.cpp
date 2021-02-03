#include "stdafx.h"
#include "PlayerStatusUI.h"

PlayerStatusUI::PlayerStatusUI()
{
}

PlayerStatusUI::~PlayerStatusUI()
{
	for (int i = 0; i < en_playerUINum; i ++) 
	{
		DeleteGO(m_spriteRender[i]);
	}

	for (int i = 0; i < en_playerStatusNum; i++)
	{
		DeleteGO(m_fontNumber[i]);
	}
}

bool PlayerStatusUI::Start()
{
	m_player = FindGO<Player>("player");

	//画像の初期化。
	//ステータス。
	m_spriteRender[en_playerUIStatus] = NewGO<SpriteRender>(0);
	m_spriteRender[en_playerUIStatus]->Init("Assets/image/status.DDS", 151.0f, 404.0f);
	//HPバー。
	m_spriteRender[en_playerUIHPBer] = NewGO<SpriteRender>(1);
	m_spriteRender[en_playerUIHPBer]->Init("Assets/image/hp_pp_ber.DDS", 26.0f, 266.0f);
	//SPバー。
	m_spriteRender[en_playerUISPBer] = NewGO<SpriteRender>(1);
	m_spriteRender[en_playerUISPBer]->Init("Assets/image/hp_pp_ber.DDS", 26.0f, 266.0f);
	//HP。
	m_spriteRender[en_playerUIHP] = NewGO<SpriteRender>(1, "Sprite");
	m_spriteRender[en_playerUIHP]->Init("Assets/image/hp.DDS", 20.0f, 260.0f);
	//SP。
	m_spriteRender[en_playerUISP] = NewGO<SpriteRender>(1);
	m_spriteRender[en_playerUISP]->Init("Assets/image/pp.DDS", 20.0f, 260.0f);
	//HPのスラッシュ。
	m_spriteRender[en_playerUIHPSlash] = NewGO<SpriteRender>(1);
	m_spriteRender[en_playerUIHPSlash]->Init("Assets/image/slash.DDS", 20.0f, 10.0f);
	//Levelテキスト。
	m_spriteRender[en_playerUILevelText] = NewGO<SpriteRender>(1);
	m_spriteRender[en_playerUILevelText]->Init("Assets/image/PlayerStatusLevelText.DDS", 50.0f, 60.0f);

	//画像のピボットを設定。
	//HPバー。
	m_spritePivot[en_playerUIHPBer] = { 1.0f, 1.0f };
	m_spriteRender[en_playerUIHPBer]->SetPivot(m_spritePivot[en_playerUIHPBer]);
	//SPバー。
	m_spritePivot[en_playerUISPBer] = { 1.0f, 1.0f };
	m_spriteRender[en_playerUISPBer]->SetPivot(m_spritePivot[en_playerUISPBer]);
	//HP。
	m_spritePivot[en_playerUIHP] = { 1.0f, 1.0f };
	m_spriteRender[en_playerUIHP]->SetPivot(m_spritePivot[en_playerUIHP]);
	//SP。
	m_spritePivot[en_playerUISP] = { 1.0f, 1.0f };
	m_spriteRender[en_playerUISP]->SetPivot(m_spritePivot[en_playerUISP]);

	//画像の座標を設定。
	//ステータス。
	m_spritePosition[en_playerUIStatus] = { 430.0f, -250.0f, 0.0f };
	//HPバー。
	m_spritePosition[en_playerUIHPBer] = { 503.0f, -237.0f, 0.0f };
	//SPバー。
	m_spritePosition[en_playerUISPBer] = { 503.0f, -277.0f, 0.0f };
	//HP。
	m_spritePosition[en_playerUIHP] = { 500.0f, -240.0f, 0.0f };
	//SP。
	m_spritePosition[en_playerUISP] = { 500.0f, -280.0f, 0.0f };
	//HPスラッシュ。
	m_spritePosition[en_playerUIHPSlash] = { 547.0f, -250.0f, 0.0f };
	//Levelテキスト。
	m_spritePosition[en_playerUILevelText] = { 570.0f, -210.0f, 0.0f };

	//プレイヤーステータスのフォントの初期化。
	//プレイヤーのレベル。
	m_fontNumber[en_playerStatusLevel] = NewGO<FontNumber>(0);
	m_fontNumber[en_playerStatusLevel]->SetScale({ 0.3f, 0.3f, 0.3f });
	//プレイヤーのHP。
	m_fontNumber[en_playerStatusHP] = NewGO<FontNumber>(0);
	m_fontNumber[en_playerStatusHP]->SetScale({ 0.15f, 0.15f, 0.15f });
	//プレイヤーの最大HP。
	m_fontNumber[en_playerStatusMaxHP] = NewGO<FontNumber>(0);
	m_fontNumber[en_playerStatusMaxHP]->SetScale({ 0.15f, 0.15f, 0.15f });

	return true;
}

void PlayerStatusUI::Update()
{
	//HPゲージのX軸を計算。(0.0～1.0)
	m_hp = m_currentPlayerHP / m_player->GetMaxHP();
	m_spriteScale[en_playerUIHP].x = m_hp;
	//SPゲージのX軸を計算。(0.0～1.0)
	m_sp = m_currentPlayerSP / PLAYER_MAX_SP;
	m_spriteScale[en_playerUISP].x = m_sp;

	//if (g_pad[0]->IsPress(enButtonRight)/* && m_currentPlayerHP < PLAYER_MAX_HP*/) {
	//	m_currentPlayerSP += 1.0f;
	//}
	//if (g_pad[0]->IsPress(enButtonLeft)/* && m_currentPlayerHP > 0.0f*/) {
	//	m_currentPlayerSP -= 1.0f;
	//}

	//HPのスケールを設定。
	m_spriteRender[en_playerUIHP]->SetScale(m_spriteScale[en_playerUIHP]);
	//SPのスケールを設定。
	m_spriteRender[en_playerUISP]->SetScale(m_spriteScale[en_playerUISP]);

	//ステータス画像の座標を設定。
	m_spriteRender[en_playerUIStatus]->SetPosition(m_spritePosition[en_playerUIStatus]);
	//HPバー画像の座標を設定。
	m_spriteRender[en_playerUIHPBer]->SetPosition(m_spritePosition[en_playerUIHPBer]);
	//SPバー画像の座標を設定。
	m_spriteRender[en_playerUISPBer]->SetPosition(m_spritePosition[en_playerUISPBer]);
	//HP画像の座標を設定。
	m_spriteRender[en_playerUIHP]->SetPosition(m_spritePosition[en_playerUIHP]);
	//SP画像の座標を設定。
	m_spriteRender[en_playerUISP]->SetPosition(m_spritePosition[en_playerUISP]);
	//HPスラッシュ画像の座標を設定。
	m_spriteRender[en_playerUIHPSlash]->SetPosition(m_spritePosition[en_playerUIHPSlash]);
	//Levelテキスト画像の座標を設定。
	m_spriteRender[en_playerUILevelText]->SetPosition(m_spritePosition[en_playerUILevelText]);

	//プレイヤーステータスのフォントナンバーを設定。
	//プレイヤーのレベル。
	m_fontNumber[en_playerStatusLevel]->SetDisplayNum(m_player->GetPlayerLevel());
	m_fontNumber[en_playerStatusLevel]->SetPosition({ 450.0f, -210.0f, 0.0f });
	//プレイヤーのHP。
	m_fontNumber[en_playerStatusHP]->SetDisplayNum(m_player->GetHP());
	m_fontNumber[en_playerStatusHP]->SetPosition({ 560.0f, -250.0f, 0.0f });
	//プレイヤーの最大HP。
	m_fontNumber[en_playerStatusMaxHP]->SetDisplayNum(m_player->GetMaxHP());
	m_fontNumber[en_playerStatusMaxHP]->SetPosition({ 510.0f, -250.0f, 0.0f });
}
