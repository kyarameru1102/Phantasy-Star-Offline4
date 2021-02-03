#pragma once
namespace NightmAnimInfo {
	const enum  NightmAnim {
		enNi_Idle01,                   //�ҋ@01
		enNi_Idle02,                   //�ҋ@02
		enNi_Walk,                    //����
		enNi_WalkBack,                //������
		enNi_WalkLeft,                //������
		enNi_WalkRight,               //�E����
		enNi_Run,                     //����
		enNi_Scream,                  //���K
		enNi_BasicAttack,             //�U��
		enNi_ClawAttack,              //�܍U��
		enNi_HornAttack,              //�p�U��
		enNi_Defend,                  //�h��
		enNi_Sleep,                   //����
		enNi_Gethit,                  //��_��
		enNi_Die,                     //���S
		enNightmAnimClip_num       //�A�j���[�V�����̐�
	};
}
class NightmareAnimation : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	NightmareAnimation();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~NightmareAnimation();
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
	/// �A�j���[�V�����N���b�v��Ԃ��B
	/// </summary>
	/// <returns></returns>
	AnimationClip* GetAnimationClip()
	{
		return animClip;
	}
private:
	AnimationClip animClip[NightmAnimInfo::enNightmAnimClip_num];//�A�j���[�V�����N���b�v�B
};

