#ifndef INCLUDED_SCENEMGR
#define INCLUDED_SCENEMGR

#include "iscenechanger.h"
#include "basescene.h"
#include "DxLib.h"
#include "game.h"
#include "config.h"
#include "menu.h"
#include "extra.h"

class SceneMgr : public ISceneChanger, Task
{
  public:
    SceneMgr();
    void Initialize()	override;
    void Finalize()		override;
    void Update()		override;
    void Draw()			override;

    void ChangeScene(eScene NextScene)	override;
  private:
    BaseScene *mScene;
    eScene mNextScene;
};

SceneMgr::SceneMgr() : mNextScene(eScene_None)
{
  mScene = (BaseScene *) new Menu(this);
}

//  初期化
void SceneMgr::Initialize()
{
  mScene->Initialize();
}

//  終了処理
void SceneMgr::Finalize()
{
  mScene->Finalize();
}

//  更新
void SceneMgr::Update()
{
  if(mNextScene != eScene_None)
  {
    mScene->Finalize();
    delete mScene;
    switch(mNextScene)
    {
      case eScene_Menu:
        mScene = (BaseScene *) new Menu(this);
        break;
      case eScene_Game:
        mScene = (BaseScene *) new Game(this);
        break;
      case eScene_Config:
        mScene = (BaseScene *) new Config(this);
        break;
      case eScene_Extra:
        mScene = (BaseScene *) new Extra(this);
        break;
    }
    mNextScene = eScene_None;	//  次のシーン情報をクリア
    mScene->Initialize();		//  シーンを初期化
  }
  mScene->Update();	//  シーンの更新
}

//  描画
void SceneMgr::Draw()
{
  mScene->Draw();
}

//  引数nextSceneにシーンを変更する
void SceneMgr::ChangeScene(eScene NextScene)
{
  mNextScene = NextScene;
}

#endif
