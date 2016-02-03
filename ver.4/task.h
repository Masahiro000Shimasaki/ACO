#ifndef INCLUDED_TASK
#define INCLUDED_TASK

//  タスククラス．何かのモジュールはすべてこのTaskクラスを継承する
class Task
{
  public:
    virtual ~Task(){}
    virtual void Initialize()	{}		//  初期化処理は実装しなくてもいい
    virtual void Finalize()		{}		//  終了処理は実装しなくてもいい
    virtual void Update()		= 0;	//  更新処理は必ず継承先で実装する
    virtual void Draw()			= 0;	//  描画処理は必ず継承先で実装する
};

#endif
