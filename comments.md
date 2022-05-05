- -5: Incorrect output (program does not destroy cards)
- -2.5: Function documentation
- +5: Function documentation

Score: 97.5

## Comments:
- Because you were returning the card by value from your `getCard` function, it created a copy of the card before returning, which caused your `~` operator to not affect the actual card in the array.
- Your `getCard` function's pre-condition neglected to mention that `index` had to be between 0 and `MAX_CARDS`, inclusive.
- Your function documentation was generally descriptive.

Overall, very well written and thought out. Keep up the good work!