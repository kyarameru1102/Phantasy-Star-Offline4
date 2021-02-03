#pragma once
namespace BoarAnimInfo {
	const enum  BoarAnim {
		enBo_Idle,                    //�ҋ@
		enBo_Walk,                    //����
		enBo_Run,                     //����
		enBo_Scream,                  //���K
		enBo_Attack,                  //�U��
		enBo_Hornattack,              //�p�U��
		enBo_Gethit,                  //��_��
		enBo_Die,                     //���S
		enBoarAnimClip_num        //�A�j���[�V�����N���b�v�̐�
	};
}

class BoarAnimation : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	BoarAnimation();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~BoarAnimation();
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
	AnimationClip animClip[BoarAnimInfo::enBoarAnimClip_num];//�A�j���[�V�����N���b�v�B
};



