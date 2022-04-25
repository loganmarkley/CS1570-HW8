//Programmer: Logan Markley
//Student ID: 12579435
//MST Username: lcmkbc
//Instructor Name: San Yeung
//Section: 109
//Date: 4/25/22
//File: main.cpp
//Purpose: make a card wars program in C++ (HW 8)

#include "card.h"
#include "deck.h"
#include "constants.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
  srand(RANDOM_SEED);

  cout<<endl<<"This is war!"<<endl;

  string defenderName, attackerName;
  cout<<"Input Defender Name: ";
  cin>>defenderName;
  cout<<"Input Attacker Name: ";
  cin>>attackerName;
  cout<<endl<<"Battle Commence!!!"<<endl<<endl<<"DEF | ATK"<<endl;

  Deck deck1;
  deck1.shuffle();

  Card attackersCards[MAX_CARDS], defendersCards[MAX_CARDS];
  for(int i=0; i<(MAX_CARDS/2); i++)
  {
    attackersCards[i]=deck1.getCard(i);
    defendersCards[i]=deck1.getCard(i+(MAX_CARDS/2));
  }

  Deck defendersDeck(defendersCards, (MAX_CARDS/2));
  Deck attackersDeck(attackersCards, (MAX_CARDS/2));

  bool continuePlaying=true;
  int indexInDefendersDeck=0;
  int indexInAttackersDeck=0;
  do {
    while( (defendersDeck.getCard(indexInDefendersDeck)).getIsDestroyed() )
    {
      indexInDefendersDeck++;
      if(indexInDefendersDeck==defendersDeck.getTotalCards())
      {
        indexInDefendersDeck=0;
      }
    }
    while( (attackersDeck.getCard(indexInAttackersDeck)).getIsDestroyed() )
    {
      indexInAttackersDeck++;
      if(indexInAttackersDeck==attackersDeck.getTotalCards())
      {
        indexInAttackersDeck=0;
      }
    }

    cout<<defendersDeck.getCard(indexInDefendersDeck)<<"  |  "<<attackersDeck.getCard(indexInAttackersDeck)<<"  - ";
    int sum = defendersDeck.getCard(indexInDefendersDeck) + attackersDeck.getCard(indexInAttackersDeck);
    if( attackersDeck.getCard(indexInAttackersDeck) == defendersDeck.getCard(indexInDefendersDeck) || sum == SUM_TO_DESTROY )
    {
      ~(attackersDeck.getCard(indexInAttackersDeck));
      attackersDeck.changeNonDestroyedCardsValue(false);
      ~(defendersDeck.getCard(indexInDefendersDeck));
      defendersDeck.changeNonDestroyedCardsValue(false);
      cout<<"Destroyed!\t"<<defenderName<<" now has "<<defendersDeck.getNonDestroyedCards()<<" cards. ";
      cout<<attackerName<<" now has "<<attackersDeck.getNonDestroyedCards()<<" cards."<<endl;
    }
    else if( attackersDeck.getCard(indexInAttackersDeck) > defendersDeck.getCard(indexInDefendersDeck) )
    {
      attackersDeck.addCard(defendersDeck.getCard(indexInDefendersDeck));
      ~(defendersDeck.getCard(indexInDefendersDeck));
      attackersDeck.changeNonDestroyedCardsValue(true);
      attackersDeck.changeTotalCardsValue(true);
      defendersDeck.changeNonDestroyedCardsValue(false);
    cout<<attackerName<<" wins!\t"<<defenderName<<" now has "<<defendersDeck.getNonDestroyedCards()<<" cards. ";
      cout<<attackerName<<" now has "<<attackersDeck.getNonDestroyedCards()<<" cards."<<endl;
    }
    else
    {
      defendersDeck.addCard(attackersDeck.getCard(indexInAttackersDeck));
      ~(attackersDeck.getCard(indexInAttackersDeck));
      attackersDeck.changeNonDestroyedCardsValue(false);
      defendersDeck.changeNonDestroyedCardsValue(true);
      defendersDeck.changeTotalCardsValue(true);
      cout<<defenderName<<" wins!\t"<<defenderName<<" now has "<<defendersDeck.getNonDestroyedCards()<<" cards. ";
      cout<<attackerName<<" now has "<<attackersDeck.getNonDestroyedCards()<<" cards."<<endl;
    }

    indexInDefendersDeck++;
    indexInAttackersDeck++;
    if(attackersDeck.getNonDestroyedCards() <= CARDSLEFT_TO_END)
    {
      continuePlaying=false;
      cout<<endl<<endl<<"-Game Over-"<<endl<<endl;
      cout<<"Congratulations "<<defenderName<<", you have won! Enjoy your new country!"<<endl;
    }
    if(defendersDeck.getNonDestroyedCards() <= CARDSLEFT_TO_END)
    {
      continuePlaying=false;
      cout<<endl<<endl<<"-Game Over-"<<endl<<endl;
      cout<<"Congratulations "<<attackerName<<", you have won! Enjoy your new country!"<<endl;
    }
  }while(continuePlaying);
}
