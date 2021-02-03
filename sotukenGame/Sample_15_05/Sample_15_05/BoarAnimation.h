#pragma once
namespace BoarAnimInfo {
	const enum  BoarAnim {
		enBo_Idle,                    //待機
		enBo_Walk,                    //歩き
		enBo_Run,                     //走り
		enBo_Scream,                  //咆哮
		enBo_Attack,                  //攻撃
		enBo_Hornattack,              //角攻撃
		enBo_Gethit,                  //被ダメ
		enBo_Die,                     //死亡
		enBoarAnimClip_num        //アニメーションクリップの数
	};
}

class BoarAnimation : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	BoarAnimation();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~BoarAnimation();
	/// <summary>
	/// スタート関数。
	/// </summary>
	/// <returns></returns>
	bool Start() override;
	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update() override;
	/// <summary>
	/// アニメーションクリップを返す。
	/// </summary>
	/// <returns></returns>
	AnimationClip* GetAnimationClip()
	{
		return animClip;
	}
private:
	AnimationClip animClip[BoarAnimInfo::enBoarAnimClip_num];//アニメーションクリップ。
};



