#pragma once
#include "Physics/Character/CharacterController.h"
#include "TerrorBringerAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"

/// <summary>
/// ドラゴンテラーブリンガークラス
/// </summary>
class DrTerrorBringer : public EnBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	DrTerrorBringer();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~DrTerrorBringer();
	/// <summary>
	/// スタート関数。
	/// </summary>
	/// <returns></returns>
	bool Start();
	/// <summary>
	/// 更新関数。
	/// </summary>
	/// <returns></returns>
	void Update();
	/// <summary>
	/// プレイヤーに向かっていく関数。
	/// </summary>
	void Move();

	/// <summary>
	/// プレイヤーの方向に体を向ける関数。
	/// </summary>
	void Turn();
	/// <summary>
	/// 咆哮関数
	/// </summary>
	void Scream();
	/// <summary>
	/// 攻撃関数。
	/// </summary>
	void Attack();
	/// <summary>
	/// 飛行攻撃関数
	/// </summary>
	void FlyAttack();
	/// <summary>
	/// 爪攻撃関数
	/// </summary>
	void WingClawAttack();
	/// <summary>
	/// 火炎攻撃
	/// </summary>
	void FlameAttack();
	/// <summary>
	/// 死。
	/// </summary>
	void Die();
	void ReceiveDamage(int damage) override
	{
		m_hp -= damage;
		m_status = GetDamage_state;
	}

	const int& GetDeathCount()const
	{
		return m_deathCount;
	}
private:
	/// <summary>
	/// エネミーのステート。
	/// </summary>
	enum {
		Idle_state,
		Walk_state,
		Run_state,
		Fly_state,
		FlyMove_state,
		FlyLand_state,
		Scream_state,
		Attack_state,
		FlyAttack_state,
		WingClawAttack_state,
		FlameAttack_state,
		GetDamage_state,
		Die_state
	};

	int					m_status = Idle_state;			//状態。
	int					changeTimer = 0;				//アニメーション変更タイマー。
	float				m_speedY = 0.0f;				//Y方向のスピード。
	int					m_animState = TerrorBringerAnimInfo::enTe_Idle01;			//アニメーションの状態。
	int					m_appearcolor = 0;				//配色No
	TerrorBringerAnimation* m_terrorbAnim = nullptr;    //アニメーションのロード。
	std::vector<int>	terrorcolor = { 1,2,3,4 };		//配色決定。
	bool				m_isAttack = false;				//攻撃しているか。
	bool				m_ATKoff = false;				//一回の攻撃でダメージを一回だけ入れるためのフラグ。
	int					m_count = 0;					//攻撃が入るまでのカウント。
	bool                m_screamflag = true;            //咆哮フラグ
	bool                m_isFangATK = true;             //噛みつき攻撃をするフラグ
	bool                m_isClawATK = false;            //爪攻撃をするフラグ
	bool                m_isFlameATK = false;           //火炎攻撃をするフラグ
	bool                m_FlyFlag = false;              //飛行フラグ
	bool                m_SetFly = false;               //飛行設定
	bool                m_LandFlag = false;             //着陸フラグ
	int                 m_FangATKCount = 0;             //噛みつき攻撃のカウント
	int                 m_ClawATKCont = 0;              //爪攻撃のカウント
	int                 m_FlameATKCount = 0;            //火炎攻撃のカウント
	int                 m_Flametotal = 0;
	bool                m_ATKOne = true;                //パターン１
	bool                m_ATKTwe = false;               //パターン２
	bool                m_TweStart = false;             //パターン２スタート
	GhostObject			m_ghostObj;						//ゴースト。
	int					m_deathCount = 0;				//死んだときのカウント。
	int                 m_basicStatusNum = 0;                   //基礎ステータスの数値。EnPowerの数値のいずれかが入る。
	int                 m_stageNumber = 0;                      //敵のいるステージの番号。

	//顎のボーンの情報
	int m_jawboneNum = 0;
	Vector3             m_jawpos = Vector3::Zero;
	Vector3             m_jawscale = Vector3::Zero;
	Quaternion          m_jawrot = Quaternion::Identity;
	Vector3             m_toJawPlayer = Vector3::Zero;
	//腕のボーン情報
	int m_armboneNum = 0;
	Vector3             m_armpos = Vector3::Zero;
	Vector3             m_armscale = Vector3::Zero;
	Quaternion          m_armrot = Quaternion::Identity;
	Vector3             m_toArmPlayer = Vector3::Zero;
	Skeleton m_skelton;
};

