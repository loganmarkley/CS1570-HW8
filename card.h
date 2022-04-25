#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card{
  public:
    //desc: this constructor creates a Card object that has random values (just here to confirm compilation)
    //pre: none
    //post: a uninitialized Card object is created
    Card(){}
    //desc: this constructor creates a fully initialized object with values for value, suit, and isDestroyed.
    //pre: valueIn should be any of these chars: 2,3,4,5,6,7,8,9,X,J,Q,K,A.
    //     suitIn should be any of these chars: H,C,S,D.
    //     these chars are the only ones that should make up a card.
    //post: the new Card object has value = valueIn, suit = suitIn, and isDestroyed = false.
    Card(char valueIn, char suitIn);

    //desc: gets the numerical value of a card object. If maxValOf10 is true,
    //      cards with values of 'J', 'Q', 'K', or 'A' will return a value of 10.
    //      If false, J will return 11, Q returns 12, K returns 13, and A returns 14.
    //pre: none
    //post: an int value based on the card's value (and maxValOf10) is returned.
    int getNumericalValue(bool maxValOf10) const;
    //desc: gets the private bool isDestroyed and returns its value.
    //pre: none
    //post: the value of isDestroyed is returned
    bool getIsDestroyed() const;

    //desc: returns the two Cards' value added together after converting from char to int
    //pre: the char value of these Cards must be 2,3,4,5,6,7,8,9,X,J,Q,K,or A
    //post: the int value of these Cards is returned
    int operator + (const Card & cardIn);
    //desc: based on the suit and value, returns true if the calling Card is greater than the parameter Card.
    //pre: the char value of these Cards must be 2,3,4,5,6,7,8,9,X,J,Q,K,or A
    //     the suit value of these Cards must be H,C,S, or D
    //post: true or false is returned based on if the calling Card is greater than the parameter Card
    bool operator > (const Card & cardIn);
    //desc: based on the suit and value, returns true if the calling Card is less than the parameter Card.
    //pre: the char value of these Cards must be 2,3,4,5,6,7,8,9,X,J,Q,K,or A
    //     the suit value of these Cards must be H,C,S, or D
    //post: true or false is returned based on if the calling Card is less than the parameter Card
    bool operator < (const Card & cardIn);
    //desc: uses getNumericalValue(false) to return a bool that's true if these Cards have the exact same value
    //pre: the char value of these Cards must be 2,3,4,5,6,7,8,9,X,J,Q,K,or A
    //post: true or false is returned based on if these two Cards have the same value
    bool operator == (const Card & cardIn);
    //desc: uses getNumericalValue(false) to return a bool that's true if these Cards have a different value
    //pre: the char value of these Cards must be 2,3,4,5,6,7,8,9,X,J,Q,K,or A
    //post: true or false is returned based on if these two Cards have a different value
    bool operator != (const Card & cardIn);
    //desc: sets the calling Card's isDestroyed variable to false
    //pre: none
    //post: isDestroyed is set to true for the calling Card
    void operator ~ ();

    //desc: displays a Card as value<<suit (like 9H) using os. if value is 'X', 10<<suit is displayed instead.
    //pre: none
    //post: value<<suit is successfully coutted to the user
    friend ostream & operator << (ostream & os, const Card & cardIn);
  private:
    char value;
    char suit;
    bool isDestroyed=true;

};

#endif
