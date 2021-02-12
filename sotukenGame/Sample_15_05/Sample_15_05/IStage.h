#pragma once
#include "GameObject.h"
#include "EnBase.h"
#include "Game.h" 
enum {
	StageNumber,
	enStageNum1,
	enStageNum2,
	enStageNum3
};
class Random;
class Game;
class BackGround;
class EnBase;
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
	/// DrBoarを生成。
	/// この関数の前にm_drBoarNumを設定することで数を設定できる。
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrBoar(int enemyPower = en1);
	/// <summary>
	/// DrTerrorBringerを生成。
	/// この関数の前にm_drTerrorBringerNumを設定することで数を設定できる。
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrTerrorBringer(int enemyPower = en1);
	/// <summary>
	/// DrNightmareを生成。
	/// この関数の前にm_drNightmareNumを設定することで数を設定できる。
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrNightmare(int enemyPower = en1);
	/// <summary>
	/// DrSoulEaterを生成。
	/// この関数の前にm_drSoulEaterNumを設定することで数を設定できる。
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrSoulEater(int enemyPower = en1);
	/// <summary>
	/// DrUsurperを生成。
	/// この関数の前にm_drUsurperNumを設定することで数を設定できる。
	/// </summary>
	/// <param name="stageNum"></param>
	/// <param name="enemyPower"></param>
	void PutOutDrUsurper(int enemyPower = en1);
	/// <summary>
	/// 敵を出す関数。
	/// </summary>
	template<class T>
	void MakeEnemesAppear(int enemyNum, int enemyPower)
	{
		if (enemyNum <= 0) {
			//生成する敵の数が0以下にならないようにする。
			enemyNum = 1;
		}
		for (int i = 0; i < enemyNum; i++) {
			//敵をNewGOする。
			EnBase* drB = NewGO<T>(0, "dragon");
			//座標設定。
			drB->SetPosition(InitEnemyPos());
			//強さを設定。
			drB->SetBasicStatusNum(enemyPower);
			//攻撃力の倍率を設定。
			float mag = m_game->GetStage3ClearCount() * MAG_AP_INCREASE + 1.0f;
			drB->SetMagnificationAP(mag);
			//HPの倍率を設定。
			drB->SetMagnificationHP(mag);
			//どのStageにいるかを設定。
			drB->SetStageNumber(m_stageNum);
			//敵の数を加算。
			ENEMY_NUM++;
			//リストに入れる。
			m_enemyList.push_back(drB);
		}
	}
	/// <summary>
	/// 敵の初期座標
	/// </summary>
	/// <returns></returns>
	Vector3 InitEnemyPos();
protected:
	BackGround* m_backGround = nullptr;		//ステージのインスタンス。
	std::vector<EnBase*> m_enemyList;       //敵の可変長配列。
	int m_downEnemy = 0;	//倒したエネミーの数。
	int m_timer = 0;		//タイマー。
	const int m_stageChangeTime = 50; //ステージ変更までの時間
	bool m_sceanChangeOK = false;	//シーンを切り替えていいかどうかのフラグ。

	Random* m_rand = nullptr;
	Game* m_game = nullptr;
	const float MAG_AP_INCREASE = 0.2f;//攻撃力の倍率の増加量。

	int m_stageNum = 0;
	int ENEMY_NUM = 0;		//エネミーの数。
	int m_drBoarNum = 2;//DrBoarの数。
	int m_drTerrorBringerNum = 1;//DrTerrorBringerの数。
	int m_drNightmareNum = 2;//DrNightmareの数。
	int m_drSoulEaterNum = 1;//DrSoulEaterの数。
	int m_drUsurperNum = 1;//DrUsurperの数。
};

