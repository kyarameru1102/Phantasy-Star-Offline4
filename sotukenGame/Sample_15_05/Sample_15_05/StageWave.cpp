#include "stdafx.h"
#include "StageWave.h"
#include "Game.h"


StageWave::StageWave()
{

}
StageWave::~StageWave()
{
	//�폜�B
	DeleteGO(m_spriteRender);
}

bool StageWave::Start()
{
	return true;
}
void StageWave::SetWaveSprite(StageNumWave SWave)
{
	Game* game = FindGO<Game>("Game");
	game->SetIsWave(true);
	m_waveNumState = SWave;
	//�\������E�F�C�u�X�v���C�g�̐ݒ�B
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
	//�t�F�[�h�C���B
	m_spriteRender->DeltaAlpha(WAVE_FADE_DELTA_ALPHA);
	
	if (m_spriteRender->GetAlpha() >= 1.0f) {
		//���̏����ցB
		m_state = Wave_Indicate;
	}
}
void StageWave::WaveIndicate()
{
	//�E�F�C�u��\�����B(�Z����)
	m_timer++;

	if (m_timer >= WAVE_INDICATE_TIME) {
		//���Ԃ��o�߂����̂Ŏ��̏����ֈڂ�B
		m_state = Wave_FadeOut;
	}
}
void StageWave::WaveFadeOut()
{
	//�t�F�[�h�A�E�g�B
	m_spriteRender->DeltaAlpha(-WAVE_FADE_DELTA_ALPHA);

	if (m_spriteRender->GetAlpha() <= 0.0f) {
		//�������I������̂ŁA�폜����B
		Game* game = FindGO<Game>("Game");
		game->SetIsWave(false);
		DeleteGO(this);
	}
}

void StageWave::DoNothing()
{
	//�E�F�C�u��Sprite���ݒ肳�ꂽ��A�����Ɉڂ�B
	if (m_spriteRender != nullptr) {
		m_state = Wave_FadeIn;
	}
}

void StageWave::Update()
{
	//�E�F�C�u���蒆�̎��ɂ̂ݎ��s����B
	switch (m_state)
	{
	case StageWave::Wave_FadeIn:
		WaveFadeIn();		//�t�F�[�h�C���B
		break;
	case StageWave::Wave_Indicate:
		WaveIndicate();		//�E�F�C�u��\�����B(�Z����)
		break;
	case StageWave::Wave_FadeOut:
		WaveFadeOut();		//�t�F�[�h�A�E�g�B
		break;
	case StageWave::Wave_DoNothing:
		DoNothing();		//�������Ȃ��B
		break;
	}
}