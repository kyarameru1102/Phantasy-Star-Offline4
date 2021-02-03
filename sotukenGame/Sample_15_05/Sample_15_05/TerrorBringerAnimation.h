#pragma once
namespace TerrorBringerAnimInfo {
	const enum TerrorBringerAnim {
		enTe_Idle01,                  //�ҋ@01
		enTe_Idle02,                  //�ҋ@02
		enTe_FlyIdle,                 //���V�ҋ@
		enTe_Walk,                    //����
		enTe_Run,                     //����
		enTe_BasicAttack,             //�U��
		enTe_FlyAttack,               //��s�U��
		enTe_WingClawAttack,          //�܍U��
		enTe_FlameAttack,             //�Ή��U��
		enTe_FlyForward,              //��s�O�i
		enTe_FlyGlide,                //�΋�
		enTe_Land,                    //����
		enTe_Takeoff,                 //����
		enTe_Defend,                  //�h��
		enTe_Sleep,                   //����
		enTe_Scream,                  //���K
		enTe_Gethit,                  //��_��
		enTe_Die,                     //���S
		enTerrorBringerAnimClip_num      //�A�j���[�V�����̐�
	};
}
class TerrorBringerAnimation : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	TerrorBringerAnimation();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~TerrorBringerAnimation();
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
	AnimationClip animClip[TerrorBringerAnimInfo::enTerrorBringerAnimClip_num];//�A�j���[�V�����N���b�v�B
};

