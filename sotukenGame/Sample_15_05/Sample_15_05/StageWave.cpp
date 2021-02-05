#include "stdafx.h"
#include "StageWave.h"
#include "Game.h"


StageWave::StageWave()
{

}
StageWave::~StageWave()
{
	//削除。
	DeleteGO(m_spriteRender);
	DeleteGO(m_fontNumber);
}

bool StageWave::Start()
{
	Game* game = FindGO<Game>("Game");
	game->SetIsWave(true);
	m_spriteRender = NewGO<SpriteRender>(0);
	m_spriteRender->Init("Assets/image/NewWave.DDS", 300.0f, 600.0f);
	m_spriteRender->SetPosition({ 0.0f,0.0f,0.0f });
	m_spriteRender->SetAlpha(0.0f);
	m_fontNumber= NewGO<FontNumber>(0);
	m_fontNumber->SetScale({ 0.5f, 0.5f, 0.5f });

	return true;
}
void StageWave::SetWaveSprite(StageNumWave SWave)
{
	Game* game = FindGO<Game>("Game");
	game->SetIsWave(true);
	m_waveNumState = SWave;
	//表示するウェイブスプライトの設定。
	{
		m_spriteRender = NewGO<SpriteRender>(0);
		switch (m_waveNumState)
		{
		case StageWave::Wave_One:
			m_spriteRender->Init("Assets/image/NewWave.DDS", 300.0f, 600.0f);
			break;
		case StageWave::Wave_Two:
			m_spriteRender->Init("Assets/image/NewWave.DDS", 300.0f, 600.0f);
			break;
		case StageWave::Wave_Three:
			m_spriteRender->Init("Assets/image/NewWave.DDS", 300.0f, 600.0f);
			break;
		case StageWave::Wave_Boss:
			m_spriteRender->Init("Assets/image/NewWave.DDS", 300.0f, 600.0f);
			break;
		}
	}
	m_spriteRender->SetPosition({ 0.0f,0.0f,0.0f });
	m_spriteRender->SetAlpha(0.0f);

}

void StageWave::WaveFadeIn()
{
	//フェードイン。
	m_spriteRender->DeltaAlpha(WAVE_FADE_DELTA_ALPHA);
	
	if (m_spriteRender->GetAlpha() >= 1.0f) {
		//次の処理へ。
		m_state = Wave_Indicate;
	}
}
void StageWave::WaveIndicate()
{
	//ウェイブを表示中。(短時間)
	m_timer++;

	if (m_timer >= WAVE_INDICATE_TIME) {
		//時間が経過したので次の処理へ移る。
		m_state = Wave_FadeOut;
	}
}
void StageWave::WaveFadeOut()
{
	//フェードアウト。
	m_spriteRender->DeltaAlpha(-WAVE_FADE_DELTA_ALPHA);

	if (m_spriteRender->GetAlpha() <= 0.0f) {
		//処理が終わったので、削除する。
		Game* game = FindGO<Game>("Game");
		game->SetIsWave(false);
		DeleteGO(this);
	}
}

void StageWave::DoNothing()
{
	//ウェイブのSpriteが設定されたら、処理に移る。
	if (m_spriteRender != nullptr) {
		m_state = Wave_FadeIn;
	}
}

void StageWave::Update()
{
	//ウェイブ判定中の時にのみ実行する。
	switch (m_state)
	{
	case StageWave::Wave_FadeIn:
		WaveFadeIn();		//フェードイン。
		break;
	case StageWave::Wave_Indicate:
		WaveIndicate();		//ウェイブを表示中。(短時間)
		break;
	case StageWave::Wave_FadeOut:
		WaveFadeOut();		//フェードアウト。
		break;
	case StageWave::Wave_DoNothing:
		DoNothing();		//何もしない。
		break;
	}
	m_fontNumber->SetDisplayNum(m_stageNum);
	m_fontNumber->SetPosition({ -40.0f,60.0f,0.0f });
}