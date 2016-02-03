#ifndef INCLUDED_KEYBOARD
#define INCLUDED_KEYBOARD

#include "DxLib.h"

static int m_key[256];

//  キーの入力状態を更新
void Keyboard_Update()
{
  char tmp_key[256];
  GetHitKeyStateAll(tmp_key);
  for(int i = 0; i < 256; i++)
  {
    if(tmp_key[i] != 0) m_key[i]++;
    else                m_key[i] = 0;
  }
}

//  key_codeのキーの入力状態を取得する
int Keyboard_Get(int key_code)
{
  return m_key[key_code];
}



#endif
