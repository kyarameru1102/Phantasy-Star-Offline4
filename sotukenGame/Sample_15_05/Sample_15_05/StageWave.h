#pragma once
#include "FontNumber.h"

class StageWave : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	StageWave();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~StageWave();
	/// <summary>
	/// 開始関数。
	/// </summary>
	bool Start()override;
	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update()override;

public:
	//Waveたち。
	enum StageNumWave {
		Wave_One,		//ウェイブ1。
		Wave_Two,		//ウェイブ2。
		Wave_Three,		//ウェイブ3。
		Wave_Boss,		//ウェイブボス。
		Wave_Num,		//ウェイブの数。
	};
	/// <summary>
	/// Wave表示するStage階層スプライトの設定。
	/// </summary>
	void SetWaveSprite(StageNumWave SWave);
	void SetNum(int num) {
		m_stageNum = num;
	}
private:
	//状態。
	enum State {
		Wave_FadeIn,		//ウェイブをフェードイン。
		Wave_Indicate,		//ウェイブを表示中。(短時間)
		Wave_FadeOut,		//ウェイブをフェードアウト。
		Wave_DoNothing		//何もしない。
	};
private:
	void WaveFadeIn();				//フェードイン。
	void WaveIndicate();			//ウェイブを表示中。(短時間)
	void WaveFadeOut();				//フェードアウト。
	void DoNothing();				//何もしない。

private:
	SpriteRender* m_spriteRender = nullptr;			//スプライトレンダー。

	StageNumWave m_waveNumState = Wave_Num;		//階層数に合わせたウェイブ。
	State	m_state = Wave_DoNothing;			//状態。
	float m_timer = 0.0f;							//ウェイブの表示用タイマー。
	int m_stageNum = 0;
	FontNumber* m_fontNumber = nullptr;

private:
	const float WAVE_FADE_TIME = 30.0f;					//ウェイブをフェードさせる時間。
	const float WAVE_FADE_DELTA_ALPHA = 1.0f / 30.0f;		//ウェイブの透明度を変位させる値。
	const float WAVE_INDICATE_TIME = 5.0f;					//「はじめる」の透明度を変位させる値。
};


