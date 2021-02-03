#pragma once
#include "IStage.h"


class DrNightmare;
class Game;
class Stage3 : public IStage
{
public:
	Stage3();
	~Stage3();

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

	DrNightmare* m_drNight = nullptr;
};

