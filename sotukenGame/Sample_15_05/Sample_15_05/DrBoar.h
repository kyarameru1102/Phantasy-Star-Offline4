#pragma once
#include "Physics/Character/CharacterController.h"
#include "BoarAnimation.h"
#include "EnBase.h"
#include "Physics/GhostObject.h"

/// <summary>
/// ドラゴンボアクラス
/// </summary>
class DrBoar : public EnBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	DrBoar();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~DrBoar();
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
	/// 攻撃状態の移動関数
	/// </summary>
	void AttackMove();
	/// <summary>
	/// プレイヤーの方向に体を向ける関数。
	/// </summary>
	void Turn();
	/// <summary>
	/// 攻撃関数。
	/// </summary>
	void Attack();
	/// <summary>
	/// 角攻撃関数。
	/// </summary>
	void HornAttack();
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
		Attack_state,
		HornAttack_state,
		GetDamage_state,
		Die_state
	};
	int					m_status = Idle_state;			//状態。
	int					changeTimer = 0;				//アニメーション変更タイマー。
	float				m_speedY = 0.0f;				//Y方向のスピード。
	int					m_animState = BoarAnimInfo::enBo_Idle;			//アニメーションの状態。
	int					m_appearcolor = 0;				//配色No
	BoarAnimation*      m_boarAnim = nullptr;           //アニメーションのロード。          
	std::vector<int>	boarcolor = { 1,2,3,4 };		//配色決定。
	bool				m_isAttack = false;				//攻撃しているか。
	bool				m_ATKoff = false;				//一回の攻撃でダメージを一回だけ入れるためのフラグ。
	bool                m_isATK = true;                 //噛みつき攻撃を行う判定
	bool                m_isHornATK = false;            //角攻撃を行う判定
	bool                m_isMotion = false;             //攻撃アニメーションを行った判定
	int                 m_isATKcount = 0;               //攻撃した回数のカウント
	bool                m_ishornATKFlag = false;        //角攻撃をしたかのフラグ
	int                 m_backtimer = 0;                //後ろに下がるタイマー
	bool                m_jyosoufin = false;            //助走が終わったかのフラグ

	int					m_count = 0;					//攻撃が入るまでのカウント。
	GhostObject			m_ghostObj;						//ゴースト。
	int					m_deathCount = 0;				//死んだときのカウント。

	
};

