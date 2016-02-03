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
  DrawString(0 ,   5, "Escキーを押すとメニューに戻る", GetColor(255, 255, 255));
  DrawString(20,  45, "研究内容：", GetColor(255, 255, 255));
  DrawString(35,  65, "> FPGAを用いた画像処理システムのハードウェア化", GetColor(255, 255, 255));
  DrawString(35,  85, "> 画像のクラスタリング，識別器の学習", GetColor(255, 255, 255));
  DrawString(35, 105, "> MRI，NIRSを用いた解析・計測", GetColor(255, 255, 255));
}

#endif
