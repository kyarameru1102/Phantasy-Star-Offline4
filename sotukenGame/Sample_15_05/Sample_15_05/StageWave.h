#pragma once
class StageWave : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	StageWave();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~StageWave();
	/// <summary>
	/// �J�n�֐��B
	/// </summary>
	bool Start()override;
	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update()override;

public:
	//Wave�����B
	enum StageNumWave {
		Wave_One,		//�E�F�C�u1�B
		Wave_Two,		//�E�F�C�u2�B
		Wave_Three,		//�E�F�C�u3�B
		Wave_Boss,		//�E�F�C�u�{�X�B
		Wave_Num,		//�E�F�C�u�̐��B
	};
	/// <summary>
	/// Wave�\������Stage�K�w�X�v���C�g�̐ݒ�B
	/// </summary>
	void SetWaveSprite(StageNumWave SWave);

private:
	//��ԁB
	enum State {
		Wave_FadeIn,		//�E�F�C�u���t�F�[�h�C���B
		Wave_Indicate,		//�E�F�C�u��\�����B(�Z����)
		Wave_FadeOut,		//�E�F�C�u���t�F�[�h�A�E�g�B
		Wave_DoNothing		//�������Ȃ��B
	};
private:
	void WaveFadeIn();				//�t�F�[�h�C���B
	void WaveIndicate();			//�E�F�C�u��\�����B(�Z����)
	void WaveFadeOut();				//�t�F�[�h�A�E�g�B
	void DoNothing();				//�������Ȃ��B

private:
	SpriteRender* m_spriteRender = nullptr;			//�X�v���C�g�����_�[�B

	StageNumWave m_waveNumState = Wave_Num;		//�K�w���ɍ��킹���E�F�C�u�B
	State	m_state = Wave_DoNothing;			//��ԁB
	float m_timer = 0.0f;							//�E�F�C�u�̕\���p�^�C�}�[�B

private:
	const float WAVE_FADE_TIME = 30.0f;					//�E�F�C�u���t�F�[�h�����鎞�ԁB
	const float WAVE_FADE_DELTA_ALPHA = 1.0f / 30.0f;		//�E�F�C�u�̓����x��ψʂ�����l�B
	const float WAVE_INDICATE_TIME = 5.0f;					//�u�͂��߂�v�̓����x��ψʂ�����l�B
};


