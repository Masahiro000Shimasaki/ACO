//****************************************************************************/
//
//  Fieldクラス
//  フィールドの大きさ：300×300
//  属性：フェロモン情報，コロニー情報，餌場情報
//
//****************************************************************************/
#ifndef INCLUDED_CLASS
#define INCLUDED_CLASS

#include <stdlib.h>

class Field
{
  public:
    Field();
    void SetColony(int x, int y);
    void SetFeedingGround(int x, int y);
    int GetPheromoneQuality(int x, int y);
    void SetPheromoneQuality(int x, int y, int quality);
    int GetColonyX();
    int GetColonyY();
    void VaporizePheromone();
    void SearchDone(int x, int y);
    bool SearchCheck(int x, int y);
  private:
    int pheromone[300][300];
    bool colony[300][300];
    bool feeding_ground[300][300];
    bool search[300][300];
};

Field::Field()
{
  for(int i = 0; i < 300; i++)
  {
	  for(int j = 0; j < 300; j++)
    {
      pheromone[i][j] = 0;
	  colony[i][j] = false;
	  search[i][j] = false;
    }
  }
}

void Field::SetColony(int x, int y)
{
  colony[y][x] = true;

  return;
}

void Field::SetFeedingGround(int x, int y)
{
  feeding_ground[y][x] = true;

  return ;
}

int Field::GetPheromoneQuality(int x, int y)
{
  return pheromone[y][x];
}

void Field::SetPheromoneQuality(int x, int y, int quality)
{
  pheromone[y][x] = quality;

  return;
}

int Field::GetColonyX()
{
  int x = 0;
  for(int i = 0; i < 300; i++)
  {
    for(int j = 0; j < 300; j++)
    {
	  if(colony[i][j] == true) x = j;
	}
  }

  return x;
}

int Field::GetColonyY()
{
  int y = 0;
  for(int i = 0; i < 300; i++)
  {
    for(int j = 0; j < 300; j++)
    {
	  if(colony[i][j] == true) y = i;
	}
  }

  return y;
}

void Field::VaporizePheromone()
{
  for(int i = 0; i < 300; i++)
  {
	  for(int j = 0; j < 300; j++)
    {
		if(pheromone[i][j] > 0)
        {
          pheromone[i][j] = pheromone[i][j] - 1;
		}
		else
		{
		}
    }
  }
}

void Field::SearchDone(int x, int y)
{
  search[y][x] = true;

  return ;
}

bool Field::SearchCheck(int x, int y)
{
  return search[y][x];
}


/*****************************************************************************/
//
//  Antクラス
//  移動できる範囲(Fieldの大きさ)：300×300
//
/*****************************************************************************/
class Ant
{
  public:
    int GetAntX();
    int GetAntY();
    void DropPheromone(Field *field);
    void AntMove(int x1, int y1, int x2, int y2, Field *field);
    void PheromoneWalk(Field *field, int colony_x, int colony_y);
    void RandomWalk(Field *field);
	void RandomWalk_AX();
	void RandomWalk_VCX(Field *field);
    Ant();
    Ant(int x, int y);
  private:
    int ant_x;
    int ant_y;
    int life;
    bool food;
};

Ant::Ant()
{
  ant_x = 50;
  ant_y = 50;
  life = 500;
  food = false;
}

Ant::Ant(int x, int y)
{
  ant_x = x;
  ant_y = y;
  life = 500;
  food = false;
}

int Ant::GetAntX()
{
  return ant_x;
}

int Ant::GetAntY()
{
  return ant_y;
}

void Ant::DropPheromone(Field *field)
{
  int quality = 0;
  quality = field->GetPheromoneQuality(ant_x, ant_y);

  if(quality > 10000)
  {
  }
  else
  {
    quality = quality + 100;
  }
  
  field->SetPheromoneQuality(ant_x, ant_y, quality);

  return;
}

void Ant::RandomWalk_AX()
{
  int a = rand() % 8;

  if(a == 1)
  {
    if(ant_x == 1 || ant_y == 1)
    {
    }
    else
    {
      ant_x = ant_x - 1;
      ant_y = ant_y - 1;
    }
  }
  else if(a == 2)
  {
    if(ant_y == 1)
    {
    }
    else
    {
      ant_x = ant_x;
      ant_y = ant_y - 1;
    }
  }
  else if(a == 3)
  {
    if(ant_x == 399 || ant_y == 1)
    {
    }
    else
    {
      ant_x = ant_x + 1;
      ant_y = ant_y - 1;
    }
  }
  else if(a == 4)
  {
    if(ant_x == 1)
    {
    }
    else
    {
      ant_x = ant_x - 1;
      ant_y = ant_y;
    }
  }
  else if(a == 5)
  {
    if(ant_x == 399)
    {
    }
    else
    {
      ant_x = ant_x + 1;
      ant_y = ant_y;
    }
  }
  else if(a == 6)
  {
    if(ant_x == 1 || ant_y == 399)
    {
    }
    else
    {
      ant_x = ant_x - 1;
      ant_y = ant_y + 1;
    }
  }
  else if(a == 7)
  {
    if(ant_y == 399)
    {
    }
    else
    {
      ant_x = ant_x;
      ant_y = ant_y + 1;
    }
  }
  else
  {
    if(ant_x == 399 || ant_y == 399)
    {
    }
    else
    {
      ant_x = ant_x + 1;
      ant_y = ant_y + 1;
    }
  }

  return ;
}

void Ant::RandomWalk_VCX(Field *field)
{

  while(1)
  {
    int a = rand() % 9;

    if( (field->SearchCheck(ant_x - 1, ant_y - 1) != true) && (a == 1) )
    {
      if(ant_x == 1 || ant_y == 1)
      {
        break;
      }
      else
      {
        ant_x = ant_x - 1;
        ant_y = ant_y - 1;
        field->SearchDone(ant_x, ant_y);
        break;
      }
    }
    else if( (field->SearchCheck(ant_x, ant_y - 1) != true) && (a == 2) )
    {
      if(ant_y == 1)
      {
        break;
      }
      else
      {
        ant_x = ant_x;
        ant_y = ant_y - 1;
        field->SearchDone(ant_x, ant_y);
        break;
      }
    }
    else if( (field->SearchCheck(ant_x + 1, ant_y - 1) != true) && (a == 3) )
    {
      if(ant_x == 299 || ant_y == 1)
      {
        break;
      }
      else
      {
        ant_x = ant_x + 1;
        ant_y = ant_y - 1;
        field->SearchDone(ant_x, ant_y);
        break;
      }
    }
    else if( (field->SearchCheck(ant_x - 1, ant_y) != true) && (a == 4) )
    {
      if(ant_x == 1)
      {
        break;
      }
      else
      {
        ant_x = ant_x - 1;
        ant_y = ant_y;
        field->SearchDone(ant_x, ant_y);
        break;
      }
    }
    else if( (field->SearchCheck(ant_x + 1, ant_y) != true) && (a == 5) )
    {
      if(ant_x == 299)
      {
        break;
      }
      else
      {
        ant_x = ant_x + 1;
        ant_y = ant_y;
        field->SearchDone(ant_x, ant_y);
        break;
      }
    }
    else if( (field->SearchCheck(ant_x - 1, ant_y + 1) != true) && (a == 6) )
    {
      if(ant_x == 1 || ant_y == 299)
      {
        break;
      }
      else
      {
        ant_x = ant_x - 1;
        ant_y = ant_y + 1;
        field->SearchDone(ant_x, ant_y);
        break;
      }
    }
    else if( (field->SearchCheck(ant_x, ant_y + 1) != true) && (a == 7) )
    {
      if(ant_y == 299)
      {
        break;
      }
      else
      {
        ant_x = ant_x;
        ant_y = ant_y + 1;
        field->SearchDone(ant_x, ant_y);
        break;
      }
    }
    else if( (field->SearchCheck(ant_x + 1, ant_y + 1) != true) && (a == 8) )
    {
      if(ant_x == 299 || ant_y == 299)
      {
        break;
      }
      else
      {
        ant_x = ant_x + 1;
        ant_y = ant_y + 1;
        field->SearchDone(ant_x, ant_y);
        break;
      }
    }
    else
    {
      ant_x = ant_x;
      ant_y = ant_y + 1;
      break;
    }
  }

  return ;
}

void Ant::RandomWalk(Field *field)
{

  //  8方向全て探索済みの場合
  if((field->SearchCheck(ant_x - 1, ant_y - 1) == true) ||
     (field->SearchCheck(ant_x    , ant_y - 1) == true) ||
     (field->SearchCheck(ant_x + 1, ant_y - 1) == true) ||
     (field->SearchCheck(ant_x - 1, ant_y    ) == true) ||
     (field->SearchCheck(ant_x + 1, ant_y    ) == true) ||
     (field->SearchCheck(ant_x - 1, ant_y + 1) == true) ||
     (field->SearchCheck(ant_x    , ant_y + 1) == true) ||
     (field->SearchCheck(ant_x - 1, ant_y + 1) == true)
    )
  {
    //  ランダムに歩く
    RandomWalk_AX();
  }
  //  未探索領域が存在する場合
  else
  {
    //  進む未探索領域をランダムに決定
    RandomWalk_VCX(field);
  }

  return ;
}

void Ant::PheromoneWalk(Field *field, int colony_x, int colony_y)
{
  //  巣から遠い位置に存在するフェロモンの方向へ歩く
  int a = rand() % 9;
  int div[8];

  if(field->GetPheromoneQuality(ant_x - 1, ant_y - 1))
  {
    div[0] = abs(colony_x - (ant_x - 1)) + abs(colony_y - (ant_y - 1));
  }
  else
  {
    div[0] = 0;
  }

  if(field->GetPheromoneQuality(ant_x, ant_y - 1))
  {
    div[1] = abs(colony_x - (ant_x)) + abs(colony_y - (ant_y - 1));
  }
  else
  {
    div[1] = 0;
  }

  if(field->GetPheromoneQuality(ant_x + 1, ant_y - 1))
  {
    div[2] = abs(colony_x - (ant_x + 1)) + abs(colony_y - (ant_y - 1));
  }
  else
  {
    div[2] = 0;
  }

  if(field->GetPheromoneQuality(ant_x - 1, ant_y))
  {
    div[3] = abs(colony_x - (ant_x - 1)) + abs(colony_y - (ant_y));
  }
  else
  {
    div[3] = 0;
  }

  if(field->GetPheromoneQuality(ant_x + 1, ant_y))
  {
    div[4] = abs(colony_x - (ant_x + 1)) + abs(colony_y - (ant_y));
  }
  else
  {
    div[4] = 0;
  }

  if(field->GetPheromoneQuality(ant_x - 1, ant_y + 1))
  {
    div[5] = abs(colony_x - (ant_x - 1)) + abs(colony_y - (ant_y + 1));
  }
  else
  {
    div[5] = 0;
  }

  if(field->GetPheromoneQuality(ant_x, ant_y + 1))
  {
    div[6] = abs(colony_x - (ant_x)) + abs(colony_y - (ant_y + 1));
  }
  else
  {
    div[6] = 0;
  }

  if(field->GetPheromoneQuality(ant_x + 1, ant_y + 1))
  {
    div[7] = abs(colony_x - (ant_x + 1)) + abs(colony_y - (ant_y + 1));
  }
  else
  {
    div[7] = 0;
  }


  while(1)
  {
    if((a == 1) && (div[0] > div[4]) && (div[0] > div[6]) && (div[0] > div[7]) )
    {
      ant_x = ant_x - 1;
      ant_y = ant_y - 1;
      break;
    }
    else if((a == 2) && (div[1] > div[5]) && (div[1] > div[6]) && (div[1] > div[7]) )
    {
      ant_x = ant_x;
      ant_y = ant_y - 1;
      break;
    }
    else if((a == 3) && (div[2] > div[3]) && (div[2] > div[5]) && (div[2] > div[6]) )
    {
      ant_x = ant_x + 1;
      ant_y = ant_y - 1;
      break;
    }
    else if((a == 4) && (div[3] > div[2]) && (div[3] > div[4]) && (div[3] > div[7]) )
    {
      ant_x = ant_x - 1;
      ant_y = ant_y;
      break;
    }
    else if((a == 5) && (div[4] > div[0]) && (div[4] > div[3]) && (div[4] > div[5]) )
    {
      ant_x = ant_x + 1;
      ant_y = ant_y;
      break;
    }
    else if((a == 6) && (div[5] > div[1]) && (div[5] > div[2]) && (div[5] > div[4]) )
    {
      ant_x = ant_x - 1;
      ant_y = ant_y + 1;
      break;
    }
    else if((a == 7) && (div[6] > div[0]) && (div[6] > div[1]) && (div[6] > div[2]) )
    {
      ant_x = ant_x;
      ant_y = ant_y + 1;
      break;
    }
    else if((a == 8) && (div[7] > div[0]) && (div[7] > div[1]) && (div[7] > div[3]) )
    {
      ant_x = ant_x + 1;
      ant_y = ant_y + 1;
      break;
    }
    else
    {
      a = rand() % 9;
    }
  }

  return ;
}

void Ant::AntMove(int x1, int y1, int x2, int y2, Field *field)
{
  int colony_x, colony_y, food_x, food_y;
  colony_x = x1;
  colony_y = y1;
  food_x = x2;
  food_y = y2;

  //  餌を持ち帰る
  if(food)
  {
    int distance_colony_x, distance_colony_y;
	distance_colony_x = colony_x - ant_x;
	distance_colony_y = colony_y - ant_y;

    //  巣に到着した場合
    if((ant_x == colony_x) && (ant_y == colony_y))
	{
	  food = false;
	  life = 500;
	}
	//  帰り道の場合
	else
	{
	  //  巣が8近傍にある
	  if(((distance_colony_x >= -1) && (distance_colony_x <= 1)) && 
		 ((distance_colony_y >= -1) && (distance_colony_y <= 1)))
	  {
	    DropPheromone(field);
		//  巣に入る
        ant_x = colony_x;
		ant_y = colony_y;
	  }
	  //  巣の方向が右上
	  else if((ant_x <= colony_x) && (ant_y >= colony_y))
	  {
	    //  現在値にフェロモンを落とす
	    DropPheromone(field);
		//  移動方向を決める
		int a = rand() % 3;
		if(a == 1)
		{
		  ant_x = ant_x;
		  ant_y = ant_y - 1;
		}
		else if(a == 2)
		{
		  ant_x = ant_x + 1;
		  ant_y = ant_y - 1;
		}
		else
		{
		  ant_x = ant_x + 1;
		  ant_y = ant_y;
		}
	  }
	  //  巣の方向が右下
	  else if((ant_x <= colony_x) && (ant_y <= colony_y))
	  {
	    DropPheromone(field);
		//  移動方向を決める
		int a = rand() % 3;
		if(a == 1)
		{
		  ant_x = ant_x;
		  ant_y = ant_y + 1;
		}
		else if(a == 2)
		{
		  ant_x = ant_x + 1;
		  ant_y = ant_y + 1;
		}
		else
		{
		  ant_x = ant_x + 1;
		  ant_y = ant_y;
		}
	  }
	  //  巣の方向が左下
	  else if((ant_x >= colony_x) && (ant_y <= colony_y))
	  {
	    DropPheromone(field);
		//  移動方向を決める
		int a = rand() % 3;
		if(a == 1)
		{
		  ant_x = ant_x - 1;
		  ant_y = ant_y ;
		}
		else if(a == 2)
		{
		  ant_x = ant_x - 1;
		  ant_y = ant_y + 1;
		}
		else
		{
		  ant_x = ant_x;
		  ant_y = ant_y + 1;
		}
	  }
	  //  巣の方向が左上
	  else if((ant_x >= colony_x) && (ant_y >= colony_y))
	  {
	    DropPheromone(field);
		//  移動方向を決める
		int a = rand() % 3;
		if(a == 1)
		{
		  ant_x = ant_x - 1;
		  ant_y = ant_y;
		}
		else if(a == 2)
		{
		  ant_x = ant_x - 1;
		  ant_y = ant_y - 1;
		}
		else
		{
		  ant_x = ant_x;
		  ant_y = ant_y - 1;
		}
	  }
	}
  }
  //  餌を探す
  else
  {
	int distance_food_x, distance_food_y;
	distance_food_x = food_x - ant_x;
	distance_food_y = food_y - ant_y;

	int view = abs(distance_food_x) + abs(distance_food_y);

	life = life - 1;

    if(life != 0)
    {
      if((ant_x == food_x) && (ant_y == food_y))
	  {
	    //  餌場に到着した場合
	    food = true;
	  }
	  //  餌場が視野範囲内に存在する
      else if(view < 5)
      {
        //  餌場に入る
        ant_x = food_x;
        ant_y = food_y;
      }
      //  周囲8方向でフェロモンを探す(フェロモンあり)
      else if(
        (field->GetPheromoneQuality(ant_x - 1, ant_y - 1) > 0) ||
        (field->GetPheromoneQuality(ant_x    , ant_y - 1) > 0) ||
        (field->GetPheromoneQuality(ant_x + 1, ant_y - 1) > 0) ||
        (field->GetPheromoneQuality(ant_x - 1, ant_y    ) > 0) ||
        (field->GetPheromoneQuality(ant_x + 1, ant_y    ) > 0) ||
        (field->GetPheromoneQuality(ant_x - 1, ant_y + 1) > 0) ||
        (field->GetPheromoneQuality(ant_x    , ant_y + 1) > 0) ||
        (field->GetPheromoneQuality(ant_x + 1, ant_y + 1) > 0)
      )
      {
        //  フェロモンの存在する方向に歩く
        PheromoneWalk(field, colony_x, colony_y);
      }
      //  ランダムに歩く(周囲にフェロモン情報なし)
      else
      {
	    RandomWalk(field);
      }
	}
    else
    {
      ant_x = colony_x;
	  ant_y = colony_y;
	  life = 500;
    }
  }

  return ;
}

#endif
