#ifndef INCLUDED_EXTRA
#define INCLUDED_EXTRA

#include "DxLib.h"
#include "basescene.h"
#include "class.h"

//  Extraクラス
class Extra : public BaseScene
{
  public:
    Extra(ISceneChanger *changer);
    void Initialize()	override;
//  void Finalize()		override;
    void Update()		override;
    void Draw()			override;  
};

Extra::Extra(ISceneChanger *changer) :  BaseScene(changer)
{
}

//  初期化
void Extra::Initialize()
{
}

//  更新
void Extra::Update()
{
  if(CheckHitKey(KEY_INPUT_ESCAPE) != 0)
  {
    mSceneChanger->ChangeScene(eScene_Menu);
  }
}

//  描画
void Extra::Draw()
{
  Field field;

  Field *p_field = &field;
  field.SetColony(50, 50);
  field.SetFeedingGround(85, 85);
  int color_colony = GetColor(0, 255, 0);
  int color_feeding = GetColor(0, 0, 255);

  Ant ant[100];
  int color_ant = GetColor(255, 255, 255);

  while(1)
  {
    if(ScreenFlip() != 0) break;
    else if(ProcessMessage() != 0) break;
    else if(ClearDrawScreen() != 0) break;

    for(int i = 0; i < 100; i++)
	{
	  ant[i].AntMove(50, 50, 85, 85, p_field);
	  DrawCircle(ant[i].GetAntX(), ant[i].GetAntY(), 1, color_ant, TRUE);
	}
    field.VaporizePheromone();

    DrawBox(50, 50, 55, 55, color_colony, TRUE);
    DrawBox(85, 85, 90, 90, color_feeding, TRUE);


	if(CheckHitKey(KEY_INPUT_ESCAPE) != 0)
    {
      mSceneChanger->ChangeScene(eScene_Menu);
      break;
    }
  }
}

#endif
