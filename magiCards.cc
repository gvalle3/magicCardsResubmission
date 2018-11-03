/*
W15664768, Lupe Valle
Magic Cards Homework Resubmission:
Reflect knowledge of ch 7,
have array of 21 integers,
display the elements; have user think of number between 21 elements
now ask user to proceed to play game by pressing 0
distribute cards into 3 piles of 7 cards in breadthwise order
remember how we dealt the cards into piles in class
give user choice of pile 1,2,3
pile they pick must always be in middle of 21 arrays
do pile separation for total of 3 times
card is always 11th from top in 21 pile
check with user if got right
*/
#include <iostream>

using namespace std;

int shuffle1(int deck1[], int deck2[], int deck3[], int SMALL, int go);
int shuffle2(int deck1[], int deck2[], int deck3[], int SMALL);
void display(int arr[], int size);
int main()
{
  int SIZE = 20;
  int deck[SIZE] = {1, 2, 3, 4,
                   5, 6, 7, 8, 9,
                   10, 11, 12, 13, 14,
                   15, 16, 17, 18,
                   19, 20, 21};
  cout << endl;
  for (int a = 0; a <= SIZE; a++)
    cout << deck[a] << " ";
  cout << "\nPick a card between 1 & 21\n";
  int SMALL = 6;
  
  cout << "Deck1: ";
  int deck1[SMALL];
  for (int e = 0; e <= SMALL; e++ )
  {
    if (e <= SMALL)
    {
      deck1[e] = deck[e];
    }
    cout << deck1[e] << " ";
  }
  
  cout << "\nDeck2: ";
  int deck2[SMALL];
  for (int i = 0; i <= SMALL; i++)
  {
    if ( deck[7 + i] > 7 && deck[7 + i] <= 14)
    {
      deck2[i] = deck[7 + i];
    }
    cout << deck2[i] << " ";
  }
  
  cout << "\nDeck3: ";
  int deck3[SMALL];
  for (int o = 0; o <= SMALL; o++)
  {
    if (deck[14 + o] > 14 && deck[14 + o] <= 21)
    {
      deck3[o] = deck[14 + o];
    }
    cout << deck3[o] << " ";
  }
  int deckChoice;
  int go = 2;
  cout << "\nWhat deck is the card you chose in: ";
  cin >> deckChoice;
  int answer;
  if (deckChoice == 1)
    answer = shuffle1(deck1,deck2,deck3,SMALL, go);
  if (deckChoice == 2)
    answer = shuffle1(deck2, deck1, deck3, SMALL, go);
  if (deckChoice == 3)
    answer = shuffle1(deck3, deck1, deck2, SMALL, go);

  return 0;
}
int shuffle1(int deck1[], int deck2[], int deck3[], int small, int g)
{
  int SMALL = small;
  int newDeck1[SMALL] = {deck1[0], deck1[3], deck1[6], deck2[2], deck2[5], deck3[1], deck3[4]};
  int newDeck2[SMALL] = {deck1[1], deck1[4], deck2[0], deck2[3], deck2[6], deck3[2], deck3[5] };
  int newDeck3[SMALL] = {deck1[2], deck1[5], deck2[1], deck2[4], deck3[0], deck3[3], deck3[6]} ;
  cout << "\nNew Deck1: ";
  for (int a = 0; a <= SMALL; a++)
    cout << newDeck1[a] << " ";
  cout << "\nNew Deck2: ";
  for (int e = 0; e <= SMALL; e++)
    cout << newDeck2[e] << " ";
  cout << "\nNew Deck3: ";
  for (int i = 0; i <= SMALL; i++)
    cout << newDeck3[i] << " ";
  int deckChoice, last;
  if (g == 1)
  {
    last = shuffle2(newDeck1,newDeck2,newDeck3,SMALL);
    return last;
  }
  else
  {
    cout << "\nWhat deck is your card in now?: ";
    cin >> deckChoice;
    int go = 1;
    if (deckChoice == 1)
    {
      shuffle1(newDeck1,newDeck2,newDeck3,SMALL, go);
      deckChoice = 4;
    }
    if (deckChoice == 2)
    {
      shuffle1(newDeck2, newDeck1, newDeck3, SMALL, go);
      deckChoice = 4;
    }
    if (deckChoice == 3)
    {
      shuffle1(newDeck3, newDeck1, newDeck2, SMALL, go);
      deckChoice = 4;
    }
  }
  return 1;
}

int shuffle2(int deck1[], int deck2[], int deck3[], int small)
{
  int deckChoice;
  cout << "\nNow what deck is your card in?: ";
  cin >> deckChoice;
  switch (deckChoice)
  {
    case (1):
      cout << "\nDeck1: ";
      display(deck2, small);
      cout << "\nDeck2: ";
      display(deck1, small);
      cout << "\nDeck3: ";
      display(deck3, small);
      cout << "\nDid it work?: " << deck1[0] << endl;
      break;
  
    case (2):
      cout << "\nDeck1: ";
      display(deck1, small);
      cout << "\nDeck2: ";
      display(deck2, small);
      cout << "\nDeck3: ";
      display(deck3, small);
      cout << "\nDid it work?: " << deck2[0] << endl;
      break;
    case (3):
      cout << "\nDeck1: ";
      display(deck1, small);
      cout << "\nDeck2: ";
      display(deck3, small);
      cout << "\nDeck3: ";
      display(deck2, small);
      cout << "\nDid it work?: " << deck3[0] << endl;
      break;
    default: cout << "Invalid deck\n";
  }
  return deckChoice;
}

void display(int arr[], int size)
{
  for (int a = 0; a <=size; a++)
    cout << arr[a] << " ";
}
/*
[gvalle3@hills MagicCards]$ g++ magiCards.cc[gvalle3@hills MagicCards]$ ./a.out

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
Pick a card between 1 & 21
Deck1: 1 2 3 4 5 6 7
Deck2: 8 9 10 11 12 13 14
Deck3: 15 16 17 18 19 20 21
What deck is the card you chose in: 1

New Deck1: 1 4 7 10 13 16 19
New Deck2: 2 5 8 11 14 17 20
New Deck3: 3 6 9 12 15 18 21
What deck is your card in now?: 1

New Deck1: 1 10 19 8 17 6 15
New Deck2: 4 13 2 11 20 9 18
New Deck3: 7 16 5 14 3 12 21
Now what deck is your card in?: 3

Deck1: 1 10 19 8 17 6 15
Deck2: 7 16 5 14 3 12 21
Deck3: 4 13 2 11 20 9 18
Did it work?: 7
[gvalle3@hills MagicCards]$ ls
a.out  magiCards.cc
[gvalle3@hills MagicCards]$
*/