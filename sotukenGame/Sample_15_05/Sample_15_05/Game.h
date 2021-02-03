#pragma once
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Menu.h"
#include "DrBoar.h"
#include "FontNumber.h"



/// <summary>
/// �Q�[���V�[���B
/// </summary>

class Stage1;
class Stage2;
class Stage3;
class PlayerStatusUI;
class Random;
class Game : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	Game();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~Game();
	/// <summary>
	/// �X�^�[�g�֐��B
	/// </summary>
	/// <returns></returns>
	bool Start() override;
	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update() override;

	/// <summary>
	/// Wave���Ȃ̂�ݒ肷��֐��B
	/// </summary>
	void SetIsWave(const bool flag)
	{
		m_isWave = flag;
	}
	/// <summary>
	/// Wave���ł����H
	/// </summary>
	bool GetIsWave() const
	{
		return m_isWave;
	}
	/// <summary>
	/// ����X�e�[�W3���N���A��������Ԃ��B
	/// </summary>
	/// <returns></returns>
	const int GetStage3ClearCount() const
	{
		return m_stage3ClearCount;
	}

private:
	SkinModelRender* m_ladySkinModelRender = nullptr;
	Player* m_player = nullptr;
	GameCamera* m_gameCam = nullptr;
	PlayerStatusUI* m_playerStatusUI = nullptr;
	Menu* m_menu = nullptr;				//���j���[�̃C���X�^���X�B
	bool m_isWave = false;				//�E�F�C�u�����ǂ�������B

	Stage1* m_stage1 = nullptr;
	Stage2* m_stage2 = nullptr;
	Stage3* m_stage3 = nullptr;
	FontNumber* m_test = nullptr;
	Random* m_rand = nullptr;
	int m_stage3ClearCount = 0; //stage3���N���A����x�ɃJ�E���g���Ă����B
};

