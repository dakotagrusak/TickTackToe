# Objectives REVIEW and TODO

NOTE:

-   use printf() to draw the base gameboard
-   Need an array of switch() cases to determine the winner
-   Also need to have an incrementer that alternates 1 and 0 for the two player.
-   This will notify the other functions of the currently playing player.
-   The draw_O and draw_X functions will take a bool input to determine the player.
-   Use printf and then probably gotoxy
-   This function will output the location of the placed maker
-   Or does the draw_O/X function recieve a location from place marker
-   The place_marker() takes a user input location as an indexed integer, which

# Requirements

* * *

## int main()


-   must use switch()
-   user input --> int 1-10
-   game data --> stored in 3X3 array

* * *

## void draw_board()

NOTE:

-   dimensions: > 40 X 40
-   number-squares: 9
-   number-label: 1-9
-   number-location: top corner of each square

TODO:

-   currently, the base gameboard is complete
-   defined with printf functions

* * *

### void draw_X()

NOTE:

-   take in P1 or P2 and the location of the X on the grid
-   therefore two elements or has the program already decided which player
-   Must fill square

* * *

### void draw\_()

Actions:

-   Must fill square

Input Parameters:

Returns/Outputs:

* * *

### void place_marker()

-   pass --> \*\*pointer to game matrix
-   use --> \*\*switch() to place the appropriate marker

* * *

### void checkfor_Win()

-   use --> for loop
