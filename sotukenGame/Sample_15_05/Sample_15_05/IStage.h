#pragma once
#include "GameObject.h"
//#include "Physics/GhostObject.h"
#include "EnBase.h"
class Random;
class Game;
class BackGround;
//class Player;
class IStage : public IGameObject
{
public:
	/// <summary>
	/// 更新関数が呼ばれる前に呼ばれる開始関数。
	/// </summary>
	/// <returns>trueを返すと一度だけ呼ばれる</returns>
	virtual bool Start()override { return 0; };

	/// <summary>
	/// 更新関数。
	/// </summary>
	virtual void Update()override {};

	/// <summary>
	/// シーンを切り替える。
	/// </summary>
	/// <returns>シーン切り替えのフラグ</returns>
	bool GetsceanChangeOK() const
	{
		return m_sceanChangeOK;
	}
protected:
	/// <summary>
	/// ゴーストオブジェクトとプレイヤーのキャラコンとの当たり判定処理。
	/// </summary>
	//void GhostContactCharaCon();
	/// <summary>
	/// 敵の初期座標
	/// </summary>
	/// <returns></returns>
	Vector3 InitEnemyPos();
	BackGround* m_backGround = nullptr;		//ステージのインスタンス。
	std::vector<EnBase*> m_enemyList;       //敵の可変長配列。
	int m_downEnemy = 0;	//倒したエネミーの数。
	int m_timer = 0;		//タイマー。
	const int m_stageChangeTime = 150; //ステージ変更までの時間
	bool m_sceanChangeOK = false;	//シーンを切り替えていいかどうかのフラグ。

	//GhostObject m_ghostObject;		//ゴーストオブジェクト。

	Vector3 m_ghostPosition = { -1400.0f, 0.0f, -2600.0f };		//ゴーストオブジェクトの座標。
	Quaternion m_ghostRotation = Quaternion::Identity;			//ゴーストオブジェクトの回転。
	Vector3 m_ghostScale = { 1200.0f, 50.0f, 900.0f };			//ゴーストオブジェクトの拡大率。
	Random* m_rand = nullptr;
	Game* m_game = nullptr;
	const float MAG_AP_INCREASE = 0.5f;//攻撃力の倍率の増加量。
};

