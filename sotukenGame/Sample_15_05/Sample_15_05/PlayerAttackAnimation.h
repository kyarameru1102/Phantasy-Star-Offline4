#pragma once
const enum AttackAnimTime {
	enAttackTime01_blad,
	enAttackTime02_blad,
	enAttackTime03_blad,
	enAttackTime04_blad,
	enAttackTime05_blad,
	enAttackTime06_blad,
	enAttackTime07_blad,
	enAttackTime08_blad,
	enAttackTime09_blad,
	enAttackTime01_sword,
	enAttackTime02_sword,
	enAttackTime03_sword,
	enAttackTime04_sword,
	enAttackTime05_sword,
	enAttackTime06_sword,
	enAttackTime07_sword,
	enAttackTime08_sword,
	enAttackTime09_sword,
	enAttackTimeNum
};
class Player;
class PlayerAnimation;
class EnBase;
class PlayerAttackAnimation : public IGameObject
{
public:
	PlayerAttackAnimation();
	~PlayerAttackAnimation();
	/// <summary>
	/// �U���A�j���[�V�����̎��Ԃ�ݒ�B
	/// </summary>
	void SetAttackAnimationTime();
	/// <summary>
	/// �G���U������Ă��Ȃ���Ԃɂ���B
	/// </summary>
	void MakeTheEnemyUnattacked();
	/// <summary>
	/// �ʏ�U���B
	/// </summary>
	void NormalAttack();
	/// <summary>
	/// �u���C�h��Ԃ̓���U���B
	/// </summary>
	void SpecialAttackStateBlad();
	/// <summary>
	/// �\�[�h��Ԃ̓���U���B
	/// </summary>
	void SpecialAttackStateSword();

	void AttackFlag(int attackTime01_blad, int* attackAnimNum, int attackTime01_sword);
	/// �U���I���֐��B
	/// </summary>
	void AttackEnd();
	/// <summary>
	/// �U���B
	/// </summary>
	void Attack();

	bool Start() override;

	void Update() override;

	/// <summary>
	/// �U���ԍ���Ԃ��B
	/// </summary>
	/// <returns></returns>
	const int GetAttackNum() const
	{
		return m_attackNum;
	}
	/// <summary>
	/// ���ɂȂ�U���͂�ݒ肷��B
	/// </summary>
	/// <param name="power"></param>
	void SetBaseAttackPow(const int power)
	{
		m_baseAttackPow = power;
	}
private:
	Player* m_player = nullptr;
	PlayerAnimation* m_playerAnim = nullptr;
	int attackTimer = 0; //�U���^�C�}�[�B
	int m_attackAnimNum = 0; //X�{�^����Y�{�^���̍U���A�j���[�V�����̐��B
	int m_attackAnimationTimeNum = 0; //�U���A�j���[�V�����̎��Ԃ���ꂽ�z��̔ԍ��B
	int m_totalAttackAnimationTime = 0; //�U���A�j���[�V�����̍��v�̎��ԁB
	int m_continuousAttackTime = 0;  //�A������ۂ̃A�j���[�V�����̍��v�̎��ԁB
	int m_attackNum = 0; //�U���ԍ��B
	int m_attackAnimationTime[enAttackTimeNum];//�U���A�j���[�V�����̎��Ԃ�ݒ肷��z��B
	int m_switchAttackTime[enAttackTimeNum];//�U���̐؂�ւ��̎��Ԃ�ݒ肷��z��B
	bool m_specialAttackStartFlag = false;//����U���̃X�^�[�g�t���O�B
	float m_speed = 50.0f;
	int m_timer = 0;
	int m_accumulateTimer = 0; //���߂�^�C�}�[�B
	int m_accumulateTime = 60; //���߂鎞�ԁB
	int m_magnification = 1; //�{���B
	float m_baseAttackPow = 0.0f;//���ɂȂ�U���́B
	bool m_setPowerFlag = false;//�U���͐ݒ肷��Ƃ��g���t���O�B
	bool m_swordSpecialAttackAnim2Or3 = false;//�\�[�h��Ԃ̓���U���ŁA
	                                           //2�̃A�j���[�V�����Ȃ�false,
	                                           //3�̃A�j���[�V�����Ȃ�true��Ԃ��B
};

