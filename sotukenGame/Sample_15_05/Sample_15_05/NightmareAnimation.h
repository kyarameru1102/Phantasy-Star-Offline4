#pragma once
namespace NightmAnimInfo {
	const enum  NightmAnim {
		enNi_Idle01,                   //待機01
		enNi_Idle02,                   //待機02
		enNi_Walk,                    //歩き
		enNi_WalkBack,                //後ろ歩き
		enNi_WalkLeft,                //左歩き
		enNi_WalkRight,               //右歩き
		enNi_Run,                     //走り
		enNi_Scream,                  //咆哮
		enNi_BasicAttack,             //攻撃
		enNi_ClawAttack,              //爪攻撃
		enNi_HornAttack,              //角攻撃
		enNi_Defend,                  //防御
		enNi_Sleep,                   //睡眠
		enNi_Gethit,                  //被ダメ
		enNi_Die,                     //死亡
		enNightmAnimClip_num       //アニメーションの数
	};
}
class NightmareAnimation : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	NightmareAnimation();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~NightmareAnimation();
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
	AnimationClip animClip[NightmAnimInfo::enNightmAnimClip_num];//アニメーションクリップ。
};

