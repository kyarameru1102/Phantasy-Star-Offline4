#pragma once
#include "Player.h"
#include "FontNumber.h"

/// <summary>
/// �v���C���[�X�e�[�^�X��UI�N���X�B
/// </summary>
class PlayerStatusUI : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	PlayerStatusUI();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~PlayerStatusUI();

	/// <summary>
	/// �X�V�֐����Ă΂��O�ɌĂ΂��J�n�֐��B
	/// </summary>
	/// <returns>true��Ԃ��ƈ�x�����Ă΂��B</returns>
	bool Start()override;

	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	void Update()override;

	/// <summary>
	/// ���݂̃v���C���[HP��ݒ�B
	/// </summary>
	/// <param name="currentHP">���݂̃v���C���[��HP��ݒ�</param>
	void SetCurrentPlayerHP(const float& currentHP)
	{
		m_currentPlayerHP = currentHP;
	}

	/// <summary>
	/// ���݂̃v���C���[HP���擾�B
	/// </summary>
	/// <returns>���݂̃v���C���[��HP</returns>
	const float& GetCurrentPlayerHP() const
	{
		return m_currentPlayerHP;
	}

	/// <summary>
	/// ���݂̃v���C���[SP���擾�B
	/// </summary>
	/// <param name="currentSP">���݂̃v���C���[��SP</param>
	void SetCurrentPlayerSP(const float& currentSP)
	{
		m_currentPlayerSP = currentSP;
	}

	/// <summary>
	/// �v���C���[�̍ő�HP���擾�B
	/// </summary>
	/// <returns>�ő�HP</returns>
	const float& GetMaxPlayerHP()const
	{
		return PLAYER_MAX_HP;
	}

	/// <summary>
	/// �v���C���[�̍ő�SP���擾�B
	/// </summary>
	/// <returns>�ő�SP</returns>
	const float& GetMaxPlayerSP()const
	{
		return PLAYER_MAX_SP;
	}
private:

	//UI�B
	const enum {
		en_playerUIHP,			//�v���C���[HP��UI�B
		en_playerUISP,			//�v���C���[SP��UI�B
		en_playerUIHPBer,		//HPBer��UI�B
		en_playerUISPBer,		//SPBer��UI�B
		en_playerUIStatus,		//�X�e�[�^�X��UI�B
		en_playerUIHPSlash,		//���݂�HP�ƍő�HP�𕪂��邽�߂̃X���b�V���B
		en_playerUILevelText,	//Level�e�L�X�g�B
		en_playerUINum			//�v���C���[UI�̐��B
	};

	//�t�H���g�i���o�[�B
	const enum {
		en_playerStatusLevel,	//�v���C���[�̃��x���B
		en_playerStatusHP,		//�v���C���[��HP�B
		en_playerStatusMaxHP,	//�v���C���[�̍ő�HP�B
		en_playerStatusNum		//�v���C���[�X�e�[�^�X�̐��B
	};

	const float PLAYER_MAX_HP = 100.0f;  //�v���C���[�̍ő�HP�B
	const float PLAYER_MAX_SP = 100.0f;  //�v���C���[�̍ő�SP�B

	Player* m_player = nullptr;		//�v���C���[�̃C���X�^���X�B

	FontNumber* m_fontNumber[en_playerStatusNum] = { nullptr };		//�t�H���g�i���o�[�B

	SpriteRender* m_spriteRender[en_playerUINum] = { nullptr };					//�X�v���C�g�����_�[�B
	Vector3 m_spritePosition[en_playerUINum] = { Vector3::Zero };				//�X�v���C�g�̍��W�B
	Vector3 m_spriteScale[en_playerUINum] = { Vector3::One, Vector3::One };		//�X�v���C�g�̊g�嗦�B
	Vector2 m_spritePivot[en_playerUINum] = { { 0.5f, 0.5f } };					//�X�v���C�g�̃s�{�b�g�B

	float m_currentPlayerHP = 0.0f;		//�v���C���[�̌��݂�HP�B
	float m_hp = 0.0f;					//�v���C���[�̌��݂�HP��ۑ�����ϐ��B
	float m_currentPlayerSP = 0.0f;		//�v���C���[�̌��݂�SP�B
	float m_sp = 0.0f;					//�v���C���[�̌��݂�SP��ۑ�����ϐ��B
};

