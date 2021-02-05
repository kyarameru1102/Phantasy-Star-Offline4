#pragma once
#include "sound/SoundSource.h"

/// <summary>
/// タイトルシーン。
/// </summary>
class Fade;
class Title : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	Title();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~Title();
	/// <summary>
	/// 開始関数。
	/// </summary>
	bool Start()override;
	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update()override;
private:
	//状態。
	enum TitleState {
		Title_FadeIn,		//フェードイン。
		Title_Font,			//タイトル名、ボタンの表示。
		Title_Select,		//ボタン選択。
		Title_FadeOut,		//フェードアウト。
	};

	//選択ボタン
	enum EButton {
		Button_Start,
		Button_Load
	};

private:
	void TitleMoveBackGround();		//背景の移動処理。

	void TitleFadeIn();				//フェードイン。
	void TitleFont();				//タイトル名、ボタンの表示。
	void TitleSelect();				//ボタン選択。
	void TitleFadeOut();			//フェードアウト。

private:
	const enum {
		Title_BackGround1,				//背景1。
		Title_BackGround2,				//背景2。		
		Title_Player,					//プレイヤーイラスト。
		Title_Name,						//タイトル名。
		Title_Start,					//スタートボタン。
		Title_End,						//エンドボタン。
		Title_SelectIcon,				//選択中アイコン。
		Title_Num						//タイトルのSprite数。
	};

	SpriteRender* m_spriteRender[Title_Num] = { nullptr };		//スプライトレンダー。
	Vector4 m_spriteMulColor[Title_Num] = { Vector4::White };		//スプライトの乗算カラー。

	TitleState m_titleState = Title_FadeIn;			//状態。
	EButton m_buttonState = Button_Start;			//選択中のボタン状態。
private:

	//Sprite設定座標。
	const Vector3 TITLE_BACKGROUND1_POS = { 0.0f,0.0f,0.0f };		//背景1の初期設定座標。
	const Vector3 TITLE_BACKGROUND2_POS = { 1280.0f,0.0f,0.0f };	//背景2の初期設定座標。
	const Vector3 TITLE_PLAYER_POS = { -450.0f,0.0f,0.0f };	//プレイヤーの初期設定座標。
	const Vector3 TITLE_NAME_POS = { 300.0f,200.0f,0.0f };			//タイトル名の初期設定座標。
	const Vector3 TITLE_STARTBUTTON_POS = { 315.0f,-125.0f,0.0f };	//スタートボタンの初期設定座標。
	const Vector3 TITLE_ENDBUTTON_POS = { 325.0f,-225.0f,0.0f };	//エンドボタンの初期設定座標。
	const Vector3 TITLE_SELECTICON_POS = { 425.0f,-130.0f,0.0f };	//セレクトアイコンの初期設定座標。

	//共通
	const Vector4 FADEIN_FINISHED = { 1.0f,1.0f,1.0f,1.0f };	//フェードインが終わる値。
	const Vector4 FADEOUT_FINISHED = { 0.0f,0.0f,0.0f,1.0f };	//フェードアウトが終わる値。
	const Vector4 TITLE_SET_MULCOLOR = { 0.0f,0.0f,0.0f,1.0f };	//初期乗算カラー。
	const float SET_ALPHA = 0.0f;								//初期透明度。

	//background関連
	const float FADEIN_TIME = 1.0f;					//フェードインさせる時間。単位：フレーム。
	const float m_backTexXPos = 1280.0f;				//二枚目のX座標の位置。
	Vector3 m_backTexpos1 = Vector3::Zero;				//背景の座標1。
	Vector3 m_backTexpos2 = Vector3::Zero;				//背景の座標2。
	const float m_backMove = -0.1f;						//背景の移動速度。

	//ボタン関連
	Vector3	m_iconPos = Vector3::Zero;		//座標。
	int m_spriteFontTimer = 0;			//文字用タイマー。
	const float TITLENAME_FADE_TIME = 120.0f;					//タイトル名をフェードさせる時間。
	const float TITLENAME_FADE_FONT_TIME = 180.0f;				//フォントをフェードさせる時間。
	const float TITLENAME_FADE_DELTA_ALPHA = 1.0f / 120.0f;		//タイトル名の透明度を変位させる値。
	const float STARTFONT_FADE_DELTA_ALPHA = 1.0f / 60.0f;		//「はじめる」の透明度を変位させる値。
	const float LOADFONT_FADE_DELTA_ALPHA = 0.3f / 46.0f;		//「つづける」の透明度を変位させる値。
	const float SELECTICON_SET_START_POS = -130.0f;				//セレクトアイコンのスタートボタン選択中のY軸の座標。
	const float SELECTICON_SET_END_POS = -230.0f;				//セレクトアイコンのエンドボタン選択中のY軸の座標。
	const float BUTTON_SELECT = 1.0f;							//選択中のボタン。
	const float BUTTON_NOT_SELECT = 0.3f;						//選択外のボタン。

	//フェードアウト関連。
	const float FADEOUT_TIME = 1.0f;							//フェードアウトさせる時間。単位：フレーム。
	Fade* fadein[3] = { nullptr };
	Fade* fadeout[7] = { nullptr };

	//サウンド関連。
	CSoundSource* m_bgmTitle = nullptr;		//タイトルのBGM。
	void GameStartSE();						//ゲームスタートした時に音を再生する。
	void SelectSE();						//選択した時に音を再生する。
};