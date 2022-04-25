#include "deck.h"

#include "constants.h"

#include <string>
#include <iostream>
using namespace std;

Deck::Deck()
{
  nonDestroyedCards=MAX_CARDS;
  totalCards=MAX_CARDS;
  int indexInArrayOfCards=0;
  for(int i=0; i<NUM_SUITS; i++)
  {
    for(int j=0; j<NUM_VALUES; j++)
    {
      char suit;
      switch(i){
        case 0:
          suit='H';
          break;
        case 1:
          suit='C';
          break;
        case 2:
          suit='S';
          break;
        case 3:
          suit='D';
          break;
      }

      char value;
      switch(j){
        case 0:
          value='2';
          break;
        case 1:
          value='3';
          break;
        case 2:
          value='4';
          break;
        case 3:
          value='5';
          break;
        case 4:
          value='6';
          break;
        case 5:
          value='7';
          break;
        case 6:
          value='8';
          break;
        case 7:
          value='9';
          break;
        case 8:
          value='X';
          break;
        case 9:
          value='J';
          break;
        case 10:
          value='Q';
          break;
        case 11:
          value='K';
          break;
        case 12:
          value='A';
          break;
      }
      arrayOfCards[indexInArrayOfCards] = Card(value, suit);
      indexInArrayOfCards++;
    }
  }
}

Deck::Deck(Card arr[], const int arraySize)
{
  for(int i=0; i<arraySize; i++)
  {
    Card temp(arr[i]);  //using copy constructor
    arrayOfCards[i] = temp;
  }
  nonDestroyedCards=arraySize;
  totalCards=arraySize;
}



void Deck::shuffle()
{
  int randIndex1, randIndex2;
  int numOfSwaps=rand() % (MAX_SWAPS_FOR_SHUFFLE - MIN_SWAPS_FOR_SHUFFLE + 1) + MIN_SWAPS_FOR_SHUFFLE;
  for(int i=0; i<numOfSwaps; i++)
  {
    randIndex1=rand() % totalCards;
    randIndex2=rand() % totalCards;
    Card temp(arrayOfCards[randIndex1]);
    arrayOfCards[randIndex1] = arrayOfCards[randIndex2];
    arrayOfCards[randIndex2] = temp;
  }
  return;
}

void Deck::addCard(const Card cardIn)
{
  int indexOfFirstDestroyed = 0;
  while( !(arrayOfCards[indexOfFirstDestroyed].getIsDestroyed()) && indexOfFirstDestroyed<nonDestroyedCards )
  {
    indexOfFirstDestroyed++;
  }
  Card temp(cardIn);
  arrayOfCards[indexOfFirstDestroyed]=temp;
  return;
}



Card Deck::getCard(const int index) const
{
  return arrayOfCards[index];
}

int Deck::getNonDestroyedCards() const
{
  return nonDestroyedCards;
}

int Deck::getTotalCards() const
{
  return totalCards;
}



void Deck::changeNonDestroyedCardsValue(const bool increase)
{
  if(increase)
  {
    nonDestroyedCards++;
  }
  else
  {
    nonDestroyedCards--;
  }
  return;
}

void Deck::changeTotalCardsValue(const bool increase)
{
  if(increase)
  {
    totalCards++;
  }
  else
  {
    totalCards--;
  }
  return;
}
