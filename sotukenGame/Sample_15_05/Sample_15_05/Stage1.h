#pragma once
#include "IStage.h"

/// <summary>
/// ステージ1クラス
/// </summary>
class RecoveryItem;
class DrBoar;
class DrTerrorBringer;
class Game;
class Stage1 : public IStage
{
public:
	Stage1();
	~Stage1();

	/// <summary>
	/// 更新関数が呼ばれる前に呼ばれる開始関数。
	/// </summary>
	/// <returns>trueを返すと一度だけ呼ばれる</returns>
	bool Start()override;

	/// <summary>
	/// 更新関数。
	/// </summary>
	void Update()override;
private:
	int ENEMY_NUM = 3;		//エネミーの数。
	//enum {
	//	ENEMY_NUM = 3		//エネミーの数。
	//};
	//DrBoar* m_drBoar[ENEMY_NUM] = { nullptr };		//ドラゴンボア(敵)のインスタンス。
	RecoveryItem* m_recoveryItem = nullptr;			//回復アイテムのインスタンス。
};

