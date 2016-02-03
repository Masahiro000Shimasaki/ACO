#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include "DxLib.h"
#include "basescene.h"

class Game : public BaseScene
{
  public:
    Game::Game(ISceneChanger *changer);
    void Initialize()	override;
//  void Finalize()		override;
    void Update()		override;
    void Draw()			override;
};

Game::Game(ISceneChanger *changer) : BaseScene(changer)
{}

//  初期化
void Game::Initialize()
{
  //mImageHandle = LoadGraph("report.png");
}

//  更新
void Game::Update()
{
  if(CheckHitKey(KEY_INPUT_ESCAPE) != 0)
  {
    mSceneChanger->ChangeScene(eScene_Menu);
  }
}

//  描画
void Game::Draw()
{
  BaseScene::Draw();
  DrawString( 0,   5, "Escキーを押すとメニューに戻る", GetColor(255, 255, 255));
  DrawString(20,  45, "メンバー：", GetColor(255, 255, 255));
  DrawString(40,  65, "教官　　　　　 ：星野　孝総", GetColor(255, 255, 255));
  DrawString(40,  85, "博士課程 (SSP) ：三谷　慶太，四宮　友貴，Dang Tuan Linh", GetColor(255, 255, 255));
  DrawString(40, 105, "修士2年 　　 　：久坊　将之", GetColor(255, 255, 255));
  DrawString(40, 125, "修士1年 　　 　：島崎　仁宏，安岡　優斗", GetColor(255, 255, 255));
  DrawString(40, 145, "学部4年 　　 　：松田　一晃，山本　達也", GetColor(255, 255, 255));
}

#endif