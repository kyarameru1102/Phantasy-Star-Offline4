#pragma once
#include "Physics/Character/CharacterController.h"
#include "SoulEaterAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"

/// <summary>
/// ドラゴンソウルイータークラス
/// </summary>
class DrSoulEater : public EnBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	DrSoulEater();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~DrSoulEater();
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
	/// 尻尾攻撃関数
	/// </summary>
	void TailAttack();
	/// <summary>
	/// 火炎弾攻撃関数。
	/// </summary>
	void FireballShoot();
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
		Scream_state,
		Attack_state,
		TailAttack_state,
		FireballShoot_state,
		GetDamage_state,
		Die_state
	};

	int					m_status = Idle_state;			//状態。
	int					changeTimer = 0;				//アニメーション変更タイマー。
	float				m_speedY = 0.0f;				//Y方向のスピード。
	int					m_animState = SoulEaterAnimInfo::enSo_Idle;			//アニメーションの状態。
	int					m_appearcolor = 0;				//配色No
	SoulEaterAnimation* m_souleAnim = nullptr;           //アニメーションのロード。
	std::vector<int>	soulcolor = { 1,2,3,4 };		//配色決定。
	bool				m_isAttack = false;				//攻撃しているか。

	bool				m_ATKoff = false;				//一回の攻撃でダメージを一回だけ入れるためのフラグ。
	int					m_count = 0;					//攻撃が入るまでのカウント。
	bool                m_screamflag = true;            //咆哮フラグ
	bool                m_isATK = true;                 //噛みつき攻撃をするフラグ
	bool                m_isTailATK = false;            //爪攻撃をするフラグ
	bool                m_isFireBallATK = false;           //火炎攻撃をするフラグ
	GhostObject			m_ghostObj;						//ゴースト。
	int					m_deathCount = 0;				//死んだときのカウント。
};

