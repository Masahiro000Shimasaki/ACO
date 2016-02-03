/*****************************************************************************/
//
//  July. 31, 2015
//  Name : Masahiro Shimasaki
//  Company : KUT, Electronic Engineering, Hoshino's Lab
//  Project : Ant Colony Optimization Ver.3
//  変更機能 : 
//    ランダム探索 → 一度探索した場所をなるべく通らないように餌の探索を行う
//
/*****************************************************************************/
#include "DxLib.h"
#include "class.h"
#include "scenemgr.h"
#include "keyboard.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  //  初期処理
  if(ChangeWindowMode(FALSE) != 0) return 0;
  if(DxLib_Init() != 0) return 0;
  if(SetDrawScreen(DX_SCREEN_BACK) != 0)
  {
    DxLib_End();
	return 0;
  }

  int sound_handle;
  sound_handle = LoadSoundMem("a.mp3");
  PlaySoundMem(sound_handle, DX_PLAYTYPE_LOOP);


  SceneMgr sceneMgr;
  sceneMgr.Initialize();

  while(1)
  {
    if(ScreenFlip() != 0) break;
    else if(ProcessMessage() != 0) break;
    else if(ClearDrawScreen() != 0) break;

	Keyboard_Update();

    sceneMgr.Update();
    sceneMgr.Draw();

   if(CheckHitKey(KEY_INPUT_E) != 0) break;
  }

  sceneMgr.Finalize();

  /*
  Field field;
  Field *p_field = &field;
  field.SetColony(50, 50);
  field.SetFeedingGround(85, 85);
  int color_colony = GetColor(0, 255, 0);
  int color_feeding = GetColor(0, 0, 255);

  Ant ant[100];
  int color_ant = GetColor(255, 255, 255);

  //  メインループ
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
  }

  for(int i = 0; i < 300; i++)
  {
	for(int j = 0; j < 300; j++)
	{
      DrawPixel(i, j, GetColor(field.GetPheromoneQuality(i, j), 0, 0));
    }
  }
  */

  //  終了処理
  DxLib_End();
  return 0;
}
