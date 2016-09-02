1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
321
322
323
324
325
326
327
328
329
330
331
332
333
334
335
336
337
338
339
340
341
342
343
344
345
346
347
348
349
350
351
352
353
354
355
356
357
358
359
360
361
362
363
364
365
366
367
368
369
370
371
372
373
374
375
376
377
378
379
380
381
382
383
384
385
386
387
388
389
390
391
392
393
394
395
396
397
398
399
400
401
402
403
404
405
406
407
408
409
410
411
412
413
414
415
416
417
// tictactoe.cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "tictactoe.h"
 
 
TicTacToe::TicTacToe()
 
: xMax(7), yMax(6), player(1), numPlayers(2), rowSize(4), dropPieces(false)
 
{
    srand (time(0));    // randomize timer
 
    // default player config (will be overwritten during setup)
    playerType.push_back(1);    // player # 1 is human (1)
    playerType.push_back(0);    // player # 2 is comp (0)
    formatBoard();
}
 
void TicTacToe::setup()
{
     
    /* This is a barebones setup. It will not check for mistakes.
     * Enter your info carefully! */
     
    std::cout << "\nWhat size for X cooridinate? (3 - 99)\n";
    std::cin >> xMax;
     
    std::cout << "\nWhat size for Y cooridinate? (3 - 99)\n";
    std::cin >> yMax;
     
    formatBoard();
     
    std::cout << "\nHow many players? (1 - 99)\n";
    std::cin >> numPlayers;
     
    playerType.clear();
    for (int i = 1; i <= numPlayers; i++)
    {   
        int choice;
        std::cout << "\nIs player " << i << " a computer (0) or a human (1)?\n";
        std::cin >> choice;
        playerType.push_back(choice);    // player # 4 is comp (0)
    }
     
    std::cout << "\nWhich player is starting first?\n";
    std::cin >> player;
     
    std::cout << "\nWhat size is the row to win? (2 - 99)\n";
    std::cin >> rowSize;
     
    std::cout << "\nDo you want the pieces to drop like in Connect Four?"
    " 1 (yes) 0 (no)\n";
    std::cin >> dropPieces;
    std::cin.get();
}
 
void TicTacToe::welcome()
{
    std::cout <<  "\n~ Welcome to Connect Four! ~\n\n"
                    "Make " << rowSize << " in a row to win!\n\n"
                    "Press '0' for a computer assisted move\n\n"
                    "Good luck!\n";
}
 
void TicTacToe::formatBoard()
{
    board.clear();
     
    // Dynamic 2D Vector Array
    // format new game board
    for (int x = 0; x < xMax; x++)
    {
        board.push_back (std::vector<int>());
  
        for (int y = 0; y < yMax; y++)
            board[x].push_back (0);
    }
 
}
void TicTacToe::drawBoard()
{
 
    std::cout << "\n";
 
    for (int y = 0; y < yMax + 1; y++)
    {
 
        // draw game board and pieces
        for (int x = 0; x < xMax + 1; x++)
        {
 
 
            if (!x)
            {   // if board is over single digit then will need less space
                if (y < 10)
                {
                    if (y)  // don't print '0' on board
                        std::cout << " " << y << " ";
                    else
                        std::cout << "   ";
                }
                else
                    std::cout << " " << y;                    
            }else if (!y)
            {   // if board is over single digit then will need less space
                if (x < 10)
                    std::cout << " " << x << " ";
                else
                    std::cout << " " << x;                                
            }else{            
            // no piece then just draw space            
            if (!board[x - 1][y - 1])
                std::cout << "   ";
            else
                std::cout << " " << board[x - 1][y - 1] << " ";
            }
 
            // draw seperator if not end
            if (x < xMax)
                std::cout << "│";
        }
 
         
        std::cout << "\n";
 
        // draw seperator line between board
        for (int z = 0; z < xMax + 1; z++)
        {
            // draw seperator if not end
            if (y < yMax)
            {
                std::cout << "───";
                // draw connection if not end
                if (z < xMax)
                    std::cout << "┼";
            }
        }
 
        std::cout << "\n";    // next line
    }
}
 
void TicTacToe::printTurn()
{
    std::cout << "Player " << player << "'s turn.\n";
}
 
bool TicTacToe::nextTurn()
{
    // start again at first player if last player went
    if (++player > numPlayers)    // ++ advance player
        player = 1;
     
    return true;
}
 
bool TicTacToe::playerHuman()
{
    return playerType[player - 1]; // -1; compensate for 0 vector element
}
 
void TicTacToe::humanMove()
{
 
    int moveX, moveY = 0;
 
    do
    {
        std::cout << "\nEnter x: ";
        std::cin >> moveX;
         
        // if 0 entered computer moves piece
        if (!moveX)
            computerMove();
        else if (!dropPieces)
        {    // no need to enter Y value if pieces drop anyways
            std::cout << "\nEnter y: ";
            std::cin >> moveY;
            --moveY;
        }
 
    }    // '--' adjusts to be suitable for array 
    while (moveX && !placePieces(--moveX, moveY));
 
}
 
void TicTacToe::computerMove()
{
    findWinner(false);    // false = don't search for winner, make a move
}
 
// cont code from tictactoe.cpp
 
bool TicTacToe::placePieces(const int &x, int &y)
{
    // if within boundaries and place not taken then move    
    if (x < 0 || x > xMax - 1 || y < 0
        || y > yMax - 1 || board[x][y])
        return false;    // cannot move here
     
    // if empty spot below then keep dropping piece
    if (dropPieces) // start from top and drop the piece
        for(y = 0; y < yMax - 1 && !board[x][y + 1]; y++) {}
     
    // put the piece in the board
    board[x][y] = player;
     
    return true;        // move was successful
}
 
bool TicTacToe::findWinner(const bool &findMove) // is there a way to make a default?
{
     
    /* This function acts as both a winner checker and a game piece mover.
     
    findMove = true:
    This check for a winner; a complete row with no empty spaces. If it finds it
    then someone has won the game. It will also check to see if there are still
    possible moves. If its not able to find any then it calls a tie game.
 
    findMove = false:
    We're going to try to move to a position that will allow us to win within
    one move; can we win now? If we find this we'll move there. If not, we'll
    check to see if the other players can win on their next move. If so,
    we'll block that move. If not we'll search to see if we can win within
    2 turns. If not we'll check to see if any of the other players can win
    with 2 turns, and so on.
     
    howManyToWin:
    The amount of moves it will take to win. So if howManyToWin is 0, then
    there is already a winner. If it is 1 then the winner can win now. if it is
    2 then the winner can move now, and win on the next turn, provided the
    other player doesn't move there of course ;) ... and so on. */
 
    int playerPiece;    // the current piece we are checking for
     
    // Clear to make room or new possible moves
    posMoveX.clear();
    posMoveY.clear();
 
     
    arrangeTurns.clear(); // clear the last arrangeTurns list
    std::vector<int>::iterator it;
 
    /* Make a sorted list of who's pieces to check for first.
    The current player will always be first. This is because maybe
    the current player can win right now. If not, the player will
    need to check the other players moves to see if they can win
    in the next turn. */
     
    for(int i = 1; i <= numPlayers; i++)
    {
        if (player == i) // curent player at beginning of vector list
            arrangeTurns.insert(arrangeTurns.begin(), i);
        else
            arrangeTurns.push_back(i); // other players later after first       
    }
     
     
    // check for a row match of this size
    for(int howManyToWin = 0; howManyToWin <= rowSize; howManyToWin++)
    {
         
        // check this player right now
        for(int i = 0; i < numPlayers; i++)
        {
            playerPiece = arrangeTurns[i]; // check this piece right now
 
             
            // fully check all possible moves and store them
            for(int x = 0; x < xMax; x ++)
            {
                for(int y = 0; y < yMax; y++)
                {
                    searchLine(x, y, +0, +1, howManyToWin, playerPiece);
                    searchLine(x, y, +1, +0, howManyToWin, playerPiece);
                    searchLine(x, y, +1, +1, howManyToWin, playerPiece);
                    searchLine(x, y, -1, +1, howManyToWin, playerPiece);
                }
            }
             
             
            // Are we checking or moving a game piece?
            if (findMove)   // we are just checking
                 
            {
                // full row and moves in memory means somebody won!
                if (!howManyToWin && posMoveX.size())
                {
                    sayWinner();
                     
                    std::cout << "Winning cooridinates:\n\n";
                     
                    for (unsigned int j = 0; j < posMoveX.size(); j++)
                    {
                        std::cout << "x: " << posMoveX[j] + 1 << " y: "
                        << posMoveY[j] + 1 << "\n";
                         
                        // make a space bettween winning rows
                        if ((j+1) % rowSize == 0)
                            std::cout << "\n";
                    }                       
                         
                    return true;    // game over
                }
                 
                // we didn't find any moves so tie game!
                if (howManyToWin == rowSize && !posMoveX.size())
                {
                    tieGame();
                    return true;    // game over
                }
                 
            }else   // we're not checking for moves. we're moving
            {    
                 
                // are there any available moves to play?
                if (posMoveX.size())    // is a move available?
                {
                    // tell us what kind of move we're making
                    if (playerPiece == player)
                        std::cout << "\nFound offensive move to make ";
                    else
                        std::cout << "\nFound defensive move to block player "
                        << playerPiece << " from getting ";
                     
                    std::cout << rowSize - howManyToWin + 1 <<
                    " in a row!\n\n";
                     
                    // Pick a random possible move
                    int pickMove = rand() % posMoveX.size();
                         
                    // Make that move!
                    placePieces(posMoveX[pickMove], posMoveY[pickMove]);
                         
                    return false;   // we made a move but the game isn't over
                }
                            
            }
             
             
        }
    }
     
    return false;   // no winner found; true = winner        
         
}
 
bool TicTacToe::searchLine(const int &x, const int &y, const int &xAdd, const int &yAdd, const int &howManyToWin, const int &playerPiece)
{
    // is the row we want to check within the maps range?
    if (x + xAdd*(rowSize-1) < 0 || x + xAdd*(rowSize-1) >= xMax
        || y + yAdd*(rowSize-1) < 0 || y + yAdd*(rowSize-1) >= yMax)
    {
        // not enough space for a row so exit early
        return false;
    }
     
    /* Holds the location of blank spaces for reference later as a possible
     * location to move to. */
    std::vector<int>tempx;
    std::vector<int>tempy;
    int blanks = 0;    // stores how many blank pieces found in a row
     
    for (int i = 0; i < rowSize; i++)
    {
         
        /* This code finds the next available move by searching for
        blank spaces and making sure the rest of the pieces are
        the current players. If howManyToWin = 0 then this function
        simply acts to check for a winner. */
 
        if (!board[x + i*xAdd][y + i*yAdd] && ++blanks <= howManyToWin)
        {
            // store all blanks in memory incase we get a row match
            tempx.push_back(x + i*xAdd);
            tempy.push_back(y + i*yAdd);
             
        }else if (board[x + i*xAdd][y + i*yAdd] == playerPiece)
        {           
            // if checking for full row then save player pieces
            if(!howManyToWin)
            {
                tempx.push_back(x + i*xAdd);
                tempy.push_back(y + i*yAdd);
            }
             
        }else{
            // the board piece is another players so there is no match
            return false;   // cannot move here so exit early
        }
 
    }
     
    // store all possible moves to choose from later
    for (unsigned int i = 0; i < tempx.size(); i++)
    {
        posMoveX.push_back(tempx[i]);
        posMoveY.push_back(tempy[i]);
    }
     
    return true;    // found a move!
}
 
void TicTacToe::sayWinner()
{
    std::cout << "\nPlayer " << player << " wins!\n\n";
}
 
void TicTacToe::tieGame()
{
    std::cout << "\nTie game. No possible moves left!\n\n";
}
