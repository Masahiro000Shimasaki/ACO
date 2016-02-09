#ifndef INCLUDED_CONFIG
#define INCLUDED_CONFIG

#include "DxLib.h"
#include "basescene.h"

//  設定画面クラス
class Config : public BaseScene
{
  public:
    Config(ISceneChanger *changer);
    void Initialize()	override;
//  void Finalize()		override;
    void Update()		override;
    void Draw()			override;  
};

Config::Config(ISceneChanger *changer) :  BaseScene(changer)
{
}

//  初期化
void Config::Initialize()
{
  mImageHandle = LoadGraph("ant.png");
}

//  更新
void Config::Update()
{
  if(CheckHitKey(KEY_INPUT_ESCAPE) != 0)
  {
    mSceneChanger->ChangeScene(eScene_Menu);
  }
}

//  描画
void Config::Draw()
{
  BaseScene::Draw();
  DrawString(20,  45, "描画したい内容を記述してください", GetColor(255, 255, 255));
  DrawString(35,  65, "> 描画したい内容を記述してください", GetColor(255, 255, 255));
  DrawString(35,  85, "> 描画したい内容を記述してください", GetColor(255, 255, 255));
  DrawString(35, 105, "> 描画したい内容を記述してください", GetColor(255, 255, 255));
}

#endif
