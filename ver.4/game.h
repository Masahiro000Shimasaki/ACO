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

//  ϊ»
void Game::Initialize()
{
  //mImageHandle = LoadGraph("report.png");
}

//  XV
void Game::Update()
{
  if(CheckHitKey(KEY_INPUT_ESCAPE) != 0)
  {
    mSceneChanger->ChangeScene(eScene_Menu);
  }
}

//  `ζ
void Game::Draw()
{
  BaseScene::Draw();
  DrawString( 0,   5, "EscL[π·Ζj[Ιίι", GetColor(255, 255, 255));
  DrawString(20,  45, "o[F", GetColor(255, 255, 255));
  DrawString(40,  65, "³―@@@@@ F―μ@F", GetColor(255, 255, 255));
  DrawString(40,  85, "mΫφ (SSP) FOJ@cΎCl{@FMCDang Tuan Linh", GetColor(255, 255, 255));
  DrawString(40, 105, "Cm2N @@ @FvV@«V", GetColor(255, 255, 255));
  DrawString(40, 125, "Cm1N @@ @Fθ@mGCΐͺ@Dl", GetColor(255, 255, 255));
  DrawString(40, 145, "w4N @@ @FΌc@κWCR{@Bη", GetColor(255, 255, 255));
}

#endif