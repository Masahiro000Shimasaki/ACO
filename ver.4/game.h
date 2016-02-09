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
  DrawString( 0,   5, "描画したい内容を記述してください", GetColor(255, 255, 255));
  DrawString(20,  45, "ESCキーを押すと画面が変わります", GetColor(255, 255, 255));
}

#endif
