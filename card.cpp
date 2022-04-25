#include "card.h"

#include <string>
#include <iostream>
using namespace std;

Card::Card(char valueIn, char suitIn)
{
  value=valueIn;
  suit=suitIn;
  isDestroyed=false;
}



int Card::getNumericalValue(bool maxValOf10) const
{
  int numericalValue;
  if(value=='2')
  {
    numericalValue=2;
  }
  else if(value=='3')
  {
    numericalValue=3;
  }
  else if(value=='4')
  {
    numericalValue=4;
  }
  else if(value=='5')
  {
    numericalValue=5;
  }
  else if(value=='6')
  {
    numericalValue=6;
  }
  else if(value=='7')
  {
    numericalValue=7;
  }
  else if(value=='8')
  {
    numericalValue=8;
  }
  else if(value=='9')
  {
    numericalValue=9;
  }
  else if(maxValOf10 || value=='X')
  {
    numericalValue=10;
  }
  else if(value=='J')
  {
    numericalValue=11;
  }
  else if(value=='Q')
  {
    numericalValue=12;
  }
  else if(value=='K')
  {
    numericalValue=13;
  }
  else if(value=='A')
  {
    numericalValue=14;
  }
  return numericalValue;
}

bool Card::getIsDestroyed() const
{
  return isDestroyed;
}


int Card::operator + (const Card & cardIn)
{
  int valCard = getNumericalValue(true);
  int valCardIn = cardIn.getNumericalValue(true);
  return valCard + valCardIn;
}

bool Card::operator > (const Card & cardIn)
{
  bool numericallyGreaterThan = getNumericalValue(false) > cardIn.getNumericalValue(false);
  if(suit != cardIn.suit)
  {
    if(value=='A' && cardIn.value=='2')
    {
      return false;
    }
    else if(value=='2' && cardIn.value=='A')
    {
      return true;
    }
    else
    {
      return numericallyGreaterThan;
    }
  }
  else
  {
    if(value=='A' && cardIn.value=='2')
    {
      return true;
    }
    else if(value=='2' && cardIn.value=='A')
    {
      return false;
    }
    else
    {
      return !numericallyGreaterThan;
    }
  }
}

bool Card::operator < (const Card & cardIn)
{
  bool numericallyLessThan = getNumericalValue(false) < cardIn.getNumericalValue(false);
  if(suit != cardIn.suit)
  {
    if(value=='A' && cardIn.value=='2')
    {
      return true;
    }
    else if(value=='2' && cardIn.value=='A')
    {
      return false;
    }
    else
    {
      return numericallyLessThan;
    }
  }
  else
  {
    if(value=='A' && cardIn.value=='2')
    {
      return false;
    }
    else if(value=='2' && cardIn.value=='A')
    {
      return true;
    }
    else
    {
      return !numericallyLessThan;
    }
  }
}

bool Card::operator == (const Card & cardIn)
{
  return ( getNumericalValue(false)==cardIn.getNumericalValue(false) );
}

bool Card::operator != (const Card & cardIn)
{
  return ( getNumericalValue(false)!=cardIn.getNumericalValue(false) );
}

void Card::operator ~ ()
{
  isDestroyed=true;
  return;
}

ostream & operator << (ostream & os, const Card & cardIn)
{
  if(cardIn.value=='X')
  {
    os<<"10"<<cardIn.suit;
  }
  else
  {
    os<<cardIn.value<<cardIn.suit;
  }
  return os;
}
