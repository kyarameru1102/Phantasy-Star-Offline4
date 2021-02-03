#pragma once
//特殊攻撃のアニメーションは分割してるから、
//enSpecialAttack_01からenSpecialAttack_03で1つの攻撃。
const enum PlayerAnim {
	enStay_blad,            //ブレイド状態。
	enStay_sword,            //ソード状態。
	enWalk_blad,           //ブレイド状態で歩く。
	enWalk_sword,           //ソード状態で歩く。
	enRun_blad,            //ブレイド状態で走る。
	enRun_sword,            //ソード状態で走る。
	enJumpStart_blad,       //ブレイド状態でジャンプする。
	enJumpStart_sword,      //ソード状態でジャンプする。
	enStayInTheAir_blad,   //ブレイド状態で滞空。
	enStayInTheAir_sword,  //ソード状態で滞空。
	enChange_blad,          //ブレイドからソードに変更。
	enChange_sword,         //ソードからブレイドに変更。
	enKaihi_blad,           //ブレイド状態で回避。
	enKaihi_sword,          //ソード状態で回避。
	enHit_blad,           //ブレイド状態で怯む。
	enHit_sword,          //ソード状態で怯む。
	enDeath_blad,         //ブレイド状態で死亡。
	enDeath_sword,         //ソード状態で死亡。
	enAttack01_blad,         //ブレイド状態の攻撃1
	enAttack01_sword,        //ソード状態の攻撃1
	enAttack02_blad,         //ブレイド状態の攻撃2
	enAttack02_sword,         //ソード状態の攻撃2
	enAttack03_blad,         //ブレイド状態の攻撃3
	enAttack03_sword,         //ソード状態の攻撃3
	enAttack04_blad,         //ブレイド状態の攻撃4
	enAttack04_sword,         //ソード状態の攻撃4
	enAttack05_blad,         //ブレイド状態の攻撃5
	enAttack05_sword,         //ソード状態の攻撃5
	enAttack06_blad,         //ブレイド状態の攻撃6
	enAttack06_sword,         //ソード状態の攻撃6
	enAttack07_blad,         //ブレイド状態の攻撃7
	enAttack07_sword,         //ソード状態の攻撃7
	enAttack08_blad,         //ブレイド状態の攻撃8
	enAttack08_sword,         //ソード状態の攻撃8
	enAttack09_blad,         //ブレイド状態の攻撃9
	enAttack09_sword,         //ソード状態の攻撃9
	//特殊攻撃。
	enSpecialAttack_01_blad, //ブレイド状態の特殊攻撃1/3
	enSpecialAttack_02_blad,//ブレイド状態の特殊攻撃2/3
	enSpecialAttack_03_blad,//ブレイド状態の特殊攻撃3/3
	enSpecialAttack_01_sword,//ソード状態の特殊攻撃1/4
	enSpecialAttack_02_sword,//ソード状態の特殊攻撃2/4
	enSpecialAttack_03_sword,//ソード状態の特殊攻撃3/4
	enSpecialAttack_04_sword,//ソード状態の特殊攻撃4/4
	enAnimationClipNum, //アニメーションクリップの数。
};
class PlayerAnimation : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	PlayerAnimation();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~PlayerAnimation();
	/// <summary>
	/// スタート関数。
	/// </summary>
	/// <returns></returns>
	bool Start() override;
	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update() override;

	void InitAnimation();

	/// <summary>
	/// アニメーションクリップを返す。
	/// </summary>
	/// <returns></returns>
	AnimationClip* GetAnimationClip()
	{
		return animClip;
	}
	/// <summary>
	/// 攻撃アニメーションの時間を設定する配列を返す。
	/// </summary>
	/// <returns></returns>
private:
	AnimationClip animClip[enAnimationClipNum];//アニメーションクリップ。
};