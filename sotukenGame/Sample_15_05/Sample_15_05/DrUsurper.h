#pragma once
#include "Physics/Character/CharacterController.h"
#include "UsurperAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"

/// <summary>
/// �h���S�����[�T�[�v�N���X
/// </summary>
class DrUsurper : public EnBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	DrUsurper();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~DrUsurper();

	/// <summary>
	/// �X�^�[�g�֐��B
	/// </summary>
	/// <returns></returns>
	bool Start();
	/// <summary>
	/// �X�V�֐��B
	/// </summary>
	/// <returns></returns>
	void Update();

	/// <summary>
	/// �v���C���[�Ɍ������Ă����֐��B
	/// </summary>
	void Move();
	/// <summary>
	/// �v���C���[�̕����ɑ̂�������֐��B
	/// </summary>
	void Turn();
	/// <summary>
	/// ���K�֐�
	/// </summary>
	void Scream();
	/// <summary>
	/// �r�U���֐��B
	/// </summary>
	void HandAttack();
	/// <summary>
	/// ���݂��U���֐��B
	/// </summary>
	void MouthAttack();
	/// <summary>
	/// �Ή��U���֐��B
	/// </summary>
	void FlameAttack();
	/// <summary>
	/// ���V�Ή��U��
	/// </summary>
	void FlyFlame();
	/// <summary>
	/// ���B
	/// </summary>
	void Die();

private:
	/// <summary>
	/// �G�l�~�[�̃X�e�[�g�B
	/// </summary>
	enum {
		Idle_state,
		Walk_state,
		Run_state,
		Scream_state,
		HandAttack_state,
		MouthAttack_state,
		FlameAttack_state,
		FlyFlame_state,
		GetDamage_state,
		Die_state
	};

	int					m_status = Idle_state;			//��ԁB
	int					changeTimer = 0;				//�A�j���[�V�����ύX�^�C�}�[�B
	float				m_speedY = 0.0f;				//Y�����̃X�s�[�h�B
	int					m_animState = UsurperAnimInfo::enUs_Idle01;			//�A�j���[�V�����̏�ԁB
	int					m_appearcolor = 0;				//�z�FNo
	UsurperAnimation* m_usurperAnim = nullptr;        //�A�j���[�V�����̃��[�h�B
	std::vector<int>	usurpercolor = { 1,2,3,4 };		//�z�F����B
	bool				m_isAttack = false;				//�U�����Ă��邩�B
	bool				m_ATKoff = false;				//���̍U���Ń_���[�W����񂾂�����邽�߂̃t���O�B
	int					m_count = 0;					//�U��������܂ł̃J�E���g�B
	bool                m_screamflag = true;            //���K�̃t���O
	bool                m_isHandATK = true;             //�r�U��������t���O
	bool                m_isMouthATK = false;           //���݂��U��������t���O
	bool                m_isFlameATK = false;           //�Ή��U��������t���O

	GhostObject			m_ghostObj;						//�S�[�X�g�B
	int					m_deathCount = 0;				//���񂾂Ƃ��̃J�E���g�B
};

