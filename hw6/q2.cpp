// B. The Bessie Shuffle
// https://www.xinyoudui.com/contest?courses=453&books=474&pages=13318&fragments=34849&problemId=15081
/*
Problem 3: The Bessie Shuffle [Mark Gordon, 2013] 

Bessie is practicing her card tricks. She has already mastered the Bessie- 
shuffle -- a shuffle on M (2 <= M <= 100,000) cards that reorganizes the 
cards so the i-th card from the top is now the P[i]-th card from the top. 

Now Bessie is practicing shuffles on larger decks. She has a deck of N 
cards (M <= N <= 100,000) conveniently labeled 1 to N. She shuffles 
this deck by taking the first M cards and performing the Bessie-shuffle on 
them, placing the shuffled cards back on top of the deck. She then removes 
the top card from the deck and places it face down. She repeats this 
process, placing the top cards successively on top of each other, until she 
is out of cards. When Bessie has less than M cards left, she no longer 
performs the Bessie-shuffle, but continues to place the top card on top of 
the others. 

Bessie knows that the deck initially started in sorted order, with 1 on 
top, 2 next, and N on the bottom. Given the description of the 
Bessie-shuffle, help Bessie compute which cards end up located at Q 
different specified positions (1 <= Q <= N, Q <= 5,000) in the deck. 

PROBLEM NAME: shuffle 

INPUT FORMAT: 
* Line 1: A single line containing N, M and Q separated by a space. 

* Lines 2..1+M: Line i+1 indicates the position from the top, P[i], of 
the i-th card in the Bessie-shuffle (1 <= P[i] <= M). 

* Lines 2+M..1+M+Q: Line i+1+M contains a single integer q_i 
describing the i-th query. You are to compute the label on 
the card located in position q_i from the top (1 <= q_i <= N). 

SAMPLE INPUT (file shuffle.in): 
5 3 5 
3 
1 
2 
1 
2 
3 
4 
5 

INPUT DETAILS: 
Bessie has a deck of 5 cards initially ordered as [1, 2, 3, 4, 5]. Her 
shuffle is on 3 cards and has the effect of moving the top card to the 
bottom. There are 5 queries querying each position in the deck. 

OUTPUT FORMAT: 
* Lines 1..Q: On the i-th line, print a single integer indicating the 
card at position q_i from the top. 

SAMPLE OUTPUT (file shuffle.out): 
4 
5 
3 
1 
2 

OUTPUT DETAILS: 
The shuffle proceeds as: 
[1, 2, 3, 4, 5] -> [2, 3, 1, 4, 5] (put 2 face down) 
[3, 1, 4, 5] -> [1, 4, 3, 5] (put 1 face down) 
[4, 3, 5] -> [3, 5, 4] (put 3 face down) 
[5, 4] (put 5 face down) 
[4] (put 4 face down) 

This produces the final order of [4, 5, 3, 1, 2] 
*/
