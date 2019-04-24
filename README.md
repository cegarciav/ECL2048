# ECL2048

Salut !

Cette equipe contiens -

1. Camillo Garcia Vergara
2. Ranganath Vaikuntham
3. Marie Diehl

Nous faisons un projet pour l'ècole Centrale de Lyon

##
Le jeu 2048

### ENGLISH VERSION ###

#Running the game:#
1.Open the project file in QT application.
2.Run the main.cpp by clicking the green run button.

#Dependancies:#
1. QT Creator software suite
2. C++ Compiler

#Explanation of the internal functioning of the code:#

First, the Qresetbutton resets the game after loss.
Just a button to restart the game.
Encore une fois appears in a new window.
Then upon clicking encore une fois the game restarts in the same olg game window


Two tiles -Qtile and the Tile class

Qtile is frontend, Tile is the  backend.
Tile contains the logic in backend multiply the values etc.
QTile is the visual part with the labels, colors etc.

QWinwindow - New window for displaying the success
It displays the 'Congrats you have won! Would you like to continue?'.
Essentially giving the opportunity to the player to continue after scoring 2048.
This window contains reset and also continue button and the label with the message.

The Qreset button sends a signal to restart the game.
The signal is sent upon mousepressevent which in turn triggers 
an inherited method clicked.
This method  of clicked calls the resr

The QGameboard constructor after initiialising the bpard waits for a signal called clicked().
This signal is built in. 
Now the button is assigned with that signal using the help of connect.

Now when the signal arrives, the resetGame function of the QGameboard class is called.
This inturn restarts the game .

'qgameboard.h' using a matrix of QTile class to display the board and 
'board.h' used a matrix of Tile class and has the logic or backend of
each tile of the matrix being displayed.

For example, upon keypressevent the movement is displayed using the qgameboard object,
whereas the backend logic of handling the collisions between tiles(multiplying the corresponding
numbers in the tiles) and creating new tiles is done by the 'board.h' 

Object call structure:

qgameboard.h -> game.h -> board.h
 
An observation is that the class game is the backend and qgameboard is the frontend.

qgameboard object as an instance of QGameOverWindow that can be called under certain conditions.
QGameOverWindow is the window used to display a new window when the game is over and there are nomore moves left.

The feature of the high score implemented using 
All the other attributes are quite trivial to understand their sense from their position and name.
 
#Future Work/Projections:#

Making some improvements in the random tiles, adding a level of complexity.
We could also add random 4's to spawn with a probability of 10%. (DONE)
The ability to save games and finish them later.
Make the movements of the tiles more fluidic. 
