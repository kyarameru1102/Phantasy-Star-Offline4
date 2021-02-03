#pragma once
namespace UsurperAnimInfo {
	const enum UsurperAnim {
		enUs_Idle01,                  //�ҋ@01
		enUs_Idle02,                  //�ҋ@02
		enUs_FlyIdle,                 //���V�ҋ@
		enUs_Walk,                    //����
		enUs_Run,                     //����
		enUs_HandAttack,              //�r�U��
		enUs_MouthAttack,             //���݂��U��
		enUs_FlameAttack,             //�Ή��U��
		enUs_FlyFlame,                //���V�Ή��U��
		enUs_FlyForward,              //��s�O�i
		enUs_FlyGlide,                //�΋�
		enUs_Land,                    //����
		enUs_Takeoff,                 //����
		enUs_Defend,                  //�h��
		enUs_Sleep,                   //����
		enUs_Scream,                  //���K
		enUs_Gethit,                  //��_��
		enUs_Die,                     //���S
		enUsurperAnimClip_num      //�A�j���[�V�����̐�
	};
}
class UsurperAnimation : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	UsurperAnimation();
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	~UsurperAnimation();

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
	AnimationClip animClip[UsurperAnimInfo::enUsurperAnimClip_num];//�A�j���[�V�����N���b�v�B
};

