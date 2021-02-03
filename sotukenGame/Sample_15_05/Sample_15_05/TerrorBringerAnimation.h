#pragma once
namespace TerrorBringerAnimInfo {
	const enum TerrorBringerAnim {
		enTe_Idle01,                  //待機01
		enTe_Idle02,                  //待機02
		enTe_FlyIdle,                 //浮遊待機
		enTe_Walk,                    //歩き
		enTe_Run,                     //走り
		enTe_BasicAttack,             //攻撃
		enTe_FlyAttack,               //飛行攻撃
		enTe_WingClawAttack,          //爪攻撃
		enTe_FlameAttack,             //火炎攻撃
		enTe_FlyForward,              //飛行前進
		enTe_FlyGlide,                //対空
		enTe_Land,                    //着陸
		enTe_Takeoff,                 //離陸
		enTe_Defend,                  //防御
		enTe_Sleep,                   //睡眠
		enTe_Scream,                  //咆哮
		enTe_Gethit,                  //被ダメ
		enTe_Die,                     //死亡
		enTerrorBringerAnimClip_num      //アニメーションの数
	};
}
class TerrorBringerAnimation : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	TerrorBringerAnimation();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~TerrorBringerAnimation();
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
	AnimationClip animClip[TerrorBringerAnimInfo::enTerrorBringerAnimClip_num];//アニメーションクリップ。
};

