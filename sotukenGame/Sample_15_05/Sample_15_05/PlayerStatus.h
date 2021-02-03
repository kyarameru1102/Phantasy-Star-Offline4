#pragma once
#include "Player.h"
#include "FontNumber.h"
#include "PlayerStatusUI.h"

/// <summary>
/// �v���C���[�̃X�e�[�^�X�N���X�B
/// </summary>
class PlayerStatus : public IGameObject
{
public:
	PlayerStatus();
	~PlayerStatus();

	/// <summary>
	/// �X�V�֐����Ă΂��O�ɌĂ΂��J�n�֐��B
	/// </summary>
	/// <returns>true��Ԃ��ƈ�x�����Ă΂��</returns>
	bool Start()override;

	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update()override;

private:
	const enum {
		en_playerStatusUI,		//�v���C���[�X�e�[�^�X��UI�B
		en_playerStatusLevel,	//�v���C���[�̃��x���B
		en_playerStatusHP,		//�v���C���[��HP�B
		en_playerStatusAttack,	//�v���C���[�̍U���͂̐��l�B
		en_playerStatusNum,		//�v���C���[�X�e�[�^�XUI�̐��B
	};

	Player* m_player = nullptr;											//�v���C���[�̃C���X�^���X�B
	PlayerStatusUI* m_playerStatusUI = nullptr;							//�v���C���[�X�e�[�^�XUI�̃C���X�^���X�B
	SpriteRender* m_spriteRender[en_playerStatusNum] = { nullptr };		//�X�v���C�g�����_�[�B
	FontNumber* m_fontNumber[en_playerStatusNum] = { nullptr };			//�t�H���g�i���o�[�B
};