#pragma once
namespace SoulEaterAnimInfo {
	const enum SoulEaterAnim {
		enSo_Idle,                  //待機01
		enSo_Walk,                    //歩き
		enSo_Run,                     //走り
		enSo_BasicAttack,             //攻撃
		enSo_TailAttack,              //尻尾攻撃
		enSo_FireballShoot,           //火炎弾攻撃
		enSo_FlyFloat,                //浮遊
		enSo_FlyForward,              //飛行前進
		enSo_FlyGlide,                //対空
		enSo_FlyLand,                 //着陸
		enSo_Takeoff,                 //離陸
		enSo_Defend,                  //防御
		enSo_Sleep,                   //睡眠
		enSo_Scream,                  //咆哮
		enSo_Gethit,                  //被ダメ
		enSo_Die,                     //死亡
		enSoulEAnimClip_num        //アニメーションの数
	};
}
class SoulEaterAnimation : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	SoulEaterAnimation();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~SoulEaterAnimation();
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
	AnimationClip animClip[SoulEaterAnimInfo::enSoulEAnimClip_num];//アニメーションクリップ。
};

