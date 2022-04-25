#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "constants.h"

#include <iostream>
using namespace std;

class Deck{
  public:
    //desc: this constructor creates a Deck object that has the arrayOfCards[] of a usual deck of cards (the normal 52)
    //pre: none
    //post: a Deck object is created with an arrayOfCards[] of all the cards in a normal deck. nonDestroyedCards=52 and totalCards=52.
    Deck();
    //desc: this constructor creates a Deck object that has the arrayOfCards[] equal to arr[].
    //pre: arraySize must be between 1 and MAX_CARDS inclusive.
    //post: a Deck object is created with an arrayOfCards[] equal to arr[]. nonDestroyedCards=arraySize and totalCards=arraySize.
    Deck(Card arr[], const int arraySize);

    //desc: picks random indexes of arrayOfCards[] and swaps them a random amount of times based on some constants.
    //pre: none
    //post: elements of arrayOfCards[] are randomly swapped and therefore, "shuffled"
    void shuffle();
    //desc: the Card parameter is placed in arrayOfCards[] wherever the first destroyed card is, or if there is none, at the end.
    //pre: none
    //post: the parameter is successfully added to arrayOfCards[]
    void addCard(const Card cardIn);

    //desc: gets a Card object at arrayOfCards[index] and returns it
    //pre: none
    //post: the Card object at arrayOfCards[index] is returned
    Card getCard(const int index) const;
    //desc: gets the private int nonDestroyedCards and returns its value.
    //pre: none
    //post: the value of nonDestroyedCards is returned
    int getNonDestroyedCards() const;
    //desc: gets the private int totalCards and returns its value.
    //pre: none
    //post: the value of totalCards is returned
    int getTotalCards() const;

    //desc: increases or decreases nonDestroyedCards by 1 based on the value of increase.
    //pre: none
    //post: if increase == true, nonDestroyedCards is increased by one. and vice versa.
    void changeNonDestroyedCardsValue(const bool increase);
    //desc: increases or decreases totalCards by 1 based on the value of increase.
    //pre: none
    //post: if increase == true, totalCards is increased by one. and vice versa.
    void changeTotalCardsValue(const bool increase);
  private:
    Card arrayOfCards[MAX_CARDS];
    int nonDestroyedCards; //# of nondestroyed cards
    int totalCards; //# of destroyed and nondestroyed
};

#endif
