#ifndef INCLUDED_ISCENECHANGER
#define INCLUDED_ISCENECHANGER

typedef enum
{
  eScene_Menu,		//  メニュー画面
  eScene_Game,		//  ゲーム画面
  eScene_Config,	//  設定画面
  eScene_Extra,

  eScene_None,		//  無し
} eScene;

//  シーンを変更するためのインタフェイスクラス
class ISceneChanger
{
  public:
    virtual ~ISceneChanger()	= 0;
    virtual void ChangeScene(eScene NextScene)	= 0;	//  指定シーンに変更する
};

ISceneChanger::~ISceneChanger()
{
}

#endif
