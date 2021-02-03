#pragma once
#include "Physics/Character/CharacterController.h"
#include "BoarAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"

/// <summary>
/// �h���S���{�A�N���X
/// </summary>
class DrBoar : public EnBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	DrBoar();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~DrBoar();
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
	/// �U����Ԃ̈ړ��֐�
	/// </summary>
	void AttackMove();
	/// <summary>
	/// �v���C���[�̕����ɑ̂�������֐��B
	/// </summary>
	void Turn();
	/// <summary>
	/// �U���֐��B
	/// </summary>
	void Attack();
	/// <summary>
	/// �p�U���֐��B
	/// </summary>
	void HornAttack();
	/// <summary>
	/// ���B
	/// </summary>
	void Die();
	void ReceiveDamage(int damage) override
	{
		m_hp -= damage;
		m_status = GetDamage_state;
	}

	const int& GetDeathCount()const
	{
		return m_deathCount;
	}
private:
	/// <summary>
	/// �G�l�~�[�̃X�e�[�g�B
	/// </summary>
	enum {
		Idle_state,
		Walk_state,
		Run_state,
		Attack_state,
		HornAttack_state,
		GetDamage_state,
		Die_state
	};
	int					m_status = Idle_state;			//��ԁB
	int					changeTimer = 0;				//�A�j���[�V�����ύX�^�C�}�[�B
	float				m_speedY = 0.0f;				//Y�����̃X�s�[�h�B
	int					m_animState = BoarAnimInfo::enBo_Idle;			//�A�j���[�V�����̏�ԁB
	int					m_appearcolor = 0;				//�z�FNo
	BoarAnimation*      m_boarAnim = nullptr;           //�A�j���[�V�����̃��[�h�B          
	std::vector<int>	boarcolor = { 1,2,3,4 };		//�z�F����B
	bool				m_isAttack = false;				//�U�����Ă��邩�B
	bool				m_ATKoff = false;				//���̍U���Ń_���[�W����񂾂�����邽�߂̃t���O�B
	bool                m_isATK = true;                 //���݂��U�����s������
	bool                m_isHornATK = false;            //�p�U�����s������
	bool                m_isMotion = false;             //�U���A�j���[�V�������s��������
	int                 m_isATKcount = 0;               //�U�������񐔂̃J�E���g
	bool                m_ishornATKFlag = false;        //�p�U�����������̃t���O
	int                 m_backtimer = 0;                //���ɉ�����^�C�}�[
	bool                m_jyosoufin = false;            //�������I��������̃t���O

	int					m_count = 0;					//�U��������܂ł̃J�E���g�B
	GhostObject			m_ghostObj;						//�S�[�X�g�B
	int					m_deathCount = 0;				//���񂾂Ƃ��̃J�E���g�B
};

