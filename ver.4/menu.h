#ifndef INCLUDED_MENU
#define INCLUDED_MENU

#include "DxLib.h"
#include "scenemgr.h"
#include "keyboard.h"

const static int SEL1_Y	= 230;
const static int SEL2_Y	= 255;
const static int SEL3_Y = 280;

static int NowSelect = eScene_Game;

//  ���j���[��ʃN���X
class Menu : public BaseScene
{
  public:
    Menu(ISceneChanger *changer);
    void Initialize()	override;
//  void Finalize()		override;
    void Update()		override;
    void Draw()			override;
};

Menu::Menu(ISceneChanger *changer) : BaseScene(changer)
{
}

//  ������
void Menu::Initialize()
{
  mImageHandle = LoadGraph("menu.png");
}

//  �X�V
void Menu::Update()
{
  if(Keyboard_Get(KEY_INPUT_DOWN) == 1) NowSelect = (NowSelect+1) % 3;
  if(Keyboard_Get(KEY_INPUT_UP  ) == 1) NowSelect = (NowSelect+2) % 3;

  if(Keyboard_Get(KEY_INPUT_RETURN) == 1)
  {
    switch(NowSelect)
    {
      case 0:
        mSceneChanger->ChangeScene(eScene_Game);
        break;
      case 1:
        mSceneChanger->ChangeScene(eScene_Config);
        break;
      case 2:
        mSceneChanger->ChangeScene(eScene_Extra);
        break;
    }
  }
}

//  �`��
void Menu::Draw()
{
  BaseScene::Draw();
  DrawString(50, 200, "���ڂ�I�����ăG���^�[�L�[�������Ă�", GetColor(0, 0, 0));
  DrawString(80, SEL1_Y, "�����o�[�\��", GetColor(0, 0, 0));
  DrawString(80, SEL2_Y, "�������e", GetColor(0, 0, 0));
  DrawString(80, SEL3_Y, "���܂�", GetColor(0, 0, 0));
  int y = 0;
  switch(NowSelect)
  {
    case 0:
      y = SEL1_Y;
      break;
    case 1:
      y = SEL2_Y;
      break;
	case 2:
      y = SEL3_Y;
      break;
  }
  DrawString(60, y, "��", GetColor(255, 0, 0));
}


#endif
