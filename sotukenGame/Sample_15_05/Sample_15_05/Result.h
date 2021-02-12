#pragma once
#include "FontNumber.h"

class Fade;
class Result : public IGameObject
{	
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	Result();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~Result();
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
	enum ResultState {
		Result_BackGround_Fade,			//ゲーム画面を少し暗くする。
		Result_BattleResult,			//戦闘結果Spriteの表示。
		Result_ScoreBoard,				//スコアボードの表示。
		Result_ClearTime_Score,			//クリアタイムのスコア表示。
		Result_ClearFloor_Score,		//突破階層のスコア表示。
		Result_LastLevel_Score,			//最終レベルのスコア表示。
		Result_DefaultBoss_Score,		//撃破ボスのスコア表示。
		Result_Total_Score,				//トータルスコア表示。
		Result_Total_ScoreCal,			//トータルスコア表示計算。	
		Result_Rank,					//スコア結果によってランクの表示する。
		Result_Player,					//ランクによってプレイヤーイラストを変更して表示する。
		Result_Next						//次の処理。
	};

private:
	void SpriteMove(SpriteRender* m_sprite);		//スプライトの下降移動処理。
	void SpriteIndicate(SpriteRender* m_sprite);	//スプライトの表示処理。
	void SpriteScaleUp(SpriteRender* m_sprite);		//スプライトの拡大表示処理。

	void BackGroundFade();		//ゲーム画面を少し暗くする。
	void BattleResult();		//戦闘結果Spriteの表示。
	void ScoreBoard();			//スコアボードの表示。
	void ClearTimeScore();		//クリアタイムのスコア表示。
	void ClearTimeScoreCal();	//クリアタイムのスコア計算。
	void ClearFloorScore();		//突破階層のスコア表示。
	void ClearFloorScoreCal();	//突破階層のスコア計算。
	void LastLevelScore();		//最終レベルのスコア表示。
	void LastLevelScoreCal();	//最終レベルのスコア計算。
	void DefaultBossScore();	//撃破ボスのスコア表示。
	void DefaultBossScoreCal();	//撃破ボスのスコア計算。
	void TotalScore();			//トータルスコア表示。	
	void TotalScoreCal();		//トータルスコア計算。	
	void RankSet();				//スコア結果によってランクの表示する。
	void PlayerSet();			//ランクによってプレイヤーイラストを変更して表示する。
	void Next();				//次の処理。

private:
	const enum {
		Result_BackGround,		//背景用テクスチャ。
		Result_Board,			//バトルリザルト文字ボード。
		Result_ScoreBoardFrame,	//スコアボード。
		Result_RankSprite,		//ランク文字。
		Result_Num				//リザルトのSprite数。
	};

	//文字たち。
	//バトルリザルト
	const enum BattleResult{
		Result_BattleResult_B,			//バトルリザルト B
		Result_BattleResult_a,			//バトルリザルト a
		Result_BattleResult_t,			//バトルリザルト t
		Result_BattleResult_t2,			//バトルリザルト t2
		Result_BattleResult_l,			//バトルリザルト l
		Result_BattleResult_e,			//バトルリザルト e
		Result_BattleResult_R,			//バトルリザルト R
		Result_BattleResult_e2,			//バトルリザルト e
		Result_BattleResult_s,			//バトルリザルト s
		Result_BattleResult_u,			//バトルリザルト u
		Result_BattleResult_l2,			//バトルリザルト l2
		Result_BattleResult_t3,			//バトルリザルト t3
		Result_BattleResult_Num			//バトルリザルトのSprite数。

	};
	//タイム。
	const enum TimeScore {
		Result_TimeScore_Icon,		//タイムアイコン
		Result_TimeScore_T,			//タイム T
		Result_TimeScore_i,			//タイム i
		Result_TimeScore_m,			//タイム m
		Result_TimeScore_e,			//タイム e
		Result_TimeScore_Num		//タイムのSprite数。
	};
	//クリアフロア。
	const enum ClearFloorScore {
		Result_ClearFloorScore_Icon,	//クリアフロアアイコン
		Result_ClearFloorScore_C,		//クリアフロア C
		Result_ClearFloorScore_l,		//クリアフロア l
		Result_ClearFloorScore_e,		//クリアフロア e
		Result_ClearFloorScore_a,		//クリアフロア a
		Result_ClearFloorScore_r,		//クリアフロア r
		Result_ClearFloorScore_F,		//クリアフロア F
		Result_ClearFloorScore_l2,		//クリアフロア l
		Result_ClearFloorScore_o,		//クリアフロア o
		Result_ClearFloorScore_o2,		//クリアフロア o
		Result_ClearFloorScore_r2,		//クリアフロア r
		Result_ClearFloorScore_Num		//クリアフロアのSprite数。

	};
	//最終レベル。
	const enum LastLevelScore {
		Result_LastLevelScore_Icon,	//クリアフロアアイコン
		Result_LastLevelScore_L,		//クリアフロア L
		Result_LastLevelScore_a,		//クリアフロア a
		Result_LastLevelScore_s,		//クリアフロア s
		Result_LastLevelScore_t,		//クリアフロア t
		Result_LastLevelScore_L2,		//クリアフロア L
		Result_LastLevelScore_e,		//クリアフロア e
		Result_LastLevelScore_v,		//クリアフロア v
		Result_LastLevelScore_e2,		//クリアフロア e
		Result_LastLevelScore_l3,		//クリアフロア l
		Result_LastLevelScore_Num		//クリアフロアのSprite数。
	};
	const enum EnemyScore {
		Result_EnemyScore_Icon,	//撃破ボスアイコン
		Result_EnemyScore_D,		//撃破ボス D
		Result_EnemyScore_e,		//撃破ボス e
		Result_EnemyScore_f,		//撃破ボス f
		Result_EnemyScore_e2,	//撃破ボス e
		Result_EnemyScore_a,		//撃破ボス r
		Result_EnemyScore_t,		//撃破ボス t
		Result_EnemyScore_E3,	//撃破ボス E
		Result_EnemyScore_n,		//撃破ボス n
		Result_EnemyScore_e4,	//撃破ボス e
		Result_EnemyScore_m,		//撃破ボス m
		Result_EnemyScore_y,		//撃破ボス y
		Result_EnemyScore_Num	//撃破ボスのSprite数。
	};	//スコア。
	const enum Score {
		Result_Score_S,		//スコア S
		Result_Score_c,		//スコア c
		Result_Score_o,		//スコア o
		Result_Score_r,		//スコア r
		Result_Score_e,		//スコア e
		Result_Score_Num	//スコアのSprite数。
	};

	const enum ScoreNum {
		Result_ClearFloorScore,		//スコア S
		Result_LastLevelScore,		//スコア c
		Result_DfeartEnemyScore,		//スコア o
		Result_TotalScore,		//スコア r
		Result_ScoreNum	//スコアのSprite数。
	};

	const enum Rank {
		Rank_S,
		Rank_A,
		Rank_B,
		Rank_C,
		Rank_D,
		Rank_Num
	};

private:

	SpriteRender* m_spriteRender[Result_Num] = { nullptr };			//スプライトレンダー。
	Vector3 m_position = { Vector3::Zero };							//座標。
	Vector4 m_spriteMulColor[Result_Num] = { Vector4::White };		//スプライトの乗算カラー。
	ResultState m_resultState = Result_BackGround_Fade;				//状態。
	FontNumber* m_fontNumber[Result_ScoreNum] = { nullptr };			//フォントナンバー。

	SpriteRender* m_battleResultSR[Result_BattleResult_Num] = { nullptr };							//スプライトレンダー。
	SpriteRender* m_timeSR[Result_TimeScore_Num] = { nullptr };							//スプライトレンダー。
	SpriteRender* m_clearFloorSR[Result_ClearFloorScore_Num] = { nullptr };							//スプライトレンダー。
	SpriteRender* m_lastLevelSR[Result_LastLevelScore_Num] = { nullptr };							//スプライトレンダー。
	SpriteRender* m_enemyScoreSR[Result_EnemyScore_Num] = { nullptr };							//スプライトレンダー。
	SpriteRender* m_scoreSR[Result_Score_Num] = { nullptr };							//スプライトレンダー。
	SpriteRender* m_rankSR[Rank_Num] = { nullptr };							//スプライトレンダー。

	Fade* fadein[1] = { nullptr };
private:
	//定数たち（各処理ごとに分けてます。）
	const Vector3 RESULT_BACKGROUND_POS = { 0.0f,0.0f,0.0f };	//背景用テクスチャの座標。
	const Vector3 RESULT_BOARD_POS = { 0.0f,0.0f,0.0f };	//リザルトボードの座標。

	const Vector4 SET_MULCOLOR = { 0.0f,0.0f,0.0f,1.0f };	//初期乗算カラー。

	const float FADE_DELTA_ALPHA = 0.92f / 30.0f;		//ウェイブの透明度を変位させる値。
	const float BOARD_DELTA_ALPHA = 1.0f / 30.0f;		//ウェイブの透明度を変位させる値。
	const float SET_ALPHA = 0.0f;							//初期透明度。

	const Vector4 FADEIN_FINISHED = { 1.0f,1.0f,1.0f,1.0f };	//フェードインが終わる値。
	const Vector4 FADEOUT_FINISHED = { 0.0f,0.0f,0.0f,1.0f };	//フェードアウトが終わる値。
	const float FADEIN_TIME = 1.0f;					//フェードインさせる時間。単位：フレーム。

	//文字たち
	const Vector3 BATTLERESULT_POS = { 300.0f,475.0f,0.0f };
	const Vector3 TIME_POS = { 450.0f,120.0f,0.0f };
	const Vector3 CLEARFLOOR_POS = { 380.0f,150.0f,0.0f };
	const Vector3 LASTLEVEL_POS = { 385.0f,30.0f,0.0f };
	const Vector3 ENEMYSCORE_POS = { 360.0f,-100.0f,0.0f };
	const Vector3 SCORE_POS = { 500.0f,-225.0f,0.0f };
	const Vector3 RANK_POS = { -525.0f,-225.0f,0.0f };


	const Vector3 TIMEICOM_POS = { 560.0f,125.0f,0.0f };
	const Vector3 FLOORICOM_POS = { 560.0f,155.0f,0.0f };
	const Vector3 LEVELICOM_POS = { 560.0f,35.0f,0.0f };
	const Vector3 ENEMYICOM_POS = { 560.0f,-95.0f,0.0f };

	int m_timer = 0;
	const float m_fallMoveSpeed = -25.0f;			//下降速度。
	const float m_Indicate = 0.1f;				//表示させる値。
	const int m_timeLag[12] = { 0,5,10,15,20,25,30,35,40,45,50,55 };				//時間差の各タイム。
	const int m_timeSpriteLag[5] = { 0,6,8,10,12 };				//時間差の各タイム。
	const int m_crearFloorSpriteLag[11] = { 0,6,8,10,12,14,16,18,20,22,24 };				//時間差の各タイム。
	const int m_laseLevelSpriteLag[10] = { 0,6,8,10,12,14,16,18,20,22 };				//時間差の各タイム。
	const int m_EnemyScoreSpriteLag[12] = { 0,6,8,10,12,14,16,18,20,22,24,26 };				//時間差の各タイム。
	const int m_scoreSpriteLag[5] = { 0,2,4,6,8 };				//時間差の各タイム。


	//スコア関係です。
	int m_clearFloor = 0;		//クリア回数をスコア計算したものを格納。
	int m_laseLevel = 0;		//クリア時をスコア計算したものをレベル格納。
	int m_defeatEnemy = 0;		//クリア時の倒した敵の数をスコア計算したものを格納。
	int m_totalScore = 0;		//トータルスコアを格納。

	bool m_CFflag = false;
	bool m_LLflag = false;
	bool m_DEflag = false;
	bool m_TSflag = false;

};

