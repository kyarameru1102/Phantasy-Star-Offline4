#pragma once
namespace SoulEaterAnimInfo {
	const enum SoulEaterAnim {
		enSo_Idle,                  //�ҋ@01
		enSo_Walk,                    //����
		enSo_Run,                     //����
		enSo_BasicAttack,             //�U��
		enSo_TailAttack,              //�K���U��
		enSo_FireballShoot,           //�Ή��e�U��
		enSo_FlyFloat,                //���V
		enSo_FlyForward,              //��s�O�i
		enSo_FlyGlide,                //�΋�
		enSo_FlyLand,                 //����
		enSo_Takeoff,                 //����
		enSo_Defend,                  //�h��
		enSo_Sleep,                   //����
		enSo_Scream,                  //���K
		enSo_Gethit,                  //��_��
		enSo_Die,                     //���S
		enSoulEAnimClip_num        //�A�j���[�V�����̐�
	};
}
class SoulEaterAnimation : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	SoulEaterAnimation();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~SoulEaterAnimation();
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
	AnimationClip animClip[SoulEaterAnimInfo::enSoulEAnimClip_num];//�A�j���[�V�����N���b�v�B
};

