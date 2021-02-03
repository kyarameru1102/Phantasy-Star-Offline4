#pragma once
namespace UsurperAnimInfo {
	const enum UsurperAnim {
		enUs_Idle01,                  //待機01
		enUs_Idle02,                  //待機02
		enUs_FlyIdle,                 //浮遊待機
		enUs_Walk,                    //歩き
		enUs_Run,                     //走り
		enUs_HandAttack,              //腕攻撃
		enUs_MouthAttack,             //噛みつき攻撃
		enUs_FlameAttack,             //火炎攻撃
		enUs_FlyFlame,                //浮遊火炎攻撃
		enUs_FlyForward,              //飛行前進
		enUs_FlyGlide,                //対空
		enUs_Land,                    //着陸
		enUs_Takeoff,                 //離陸
		enUs_Defend,                  //防御
		enUs_Sleep,                   //睡眠
		enUs_Scream,                  //咆哮
		enUs_Gethit,                  //被ダメ
		enUs_Die,                     //死亡
		enUsurperAnimClip_num      //アニメーションの数
	};
}
class UsurperAnimation : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	UsurperAnimation();
	/// <summary>
	/// コンストラクタ
	/// </summary>
	~UsurperAnimation();

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
	AnimationClip animClip[UsurperAnimInfo::enUsurperAnimClip_num];//アニメーションクリップ。
};

