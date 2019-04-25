# ECL2048

Salut !

Cette equipe contiens -

1. Camillo Garcia Vergara
2. Ranganath Vaikuntham
3. Marie Diehl

Nous faisons un projet pour l'ècole Centrale de Lyon

##
Le jeu 2048


### VERSION FRANÇAISE ###

#Pour utiliser le jeu :#
1.Ouvrir le fichier du projet dans l'application QT.
2.Exécuter le fichier main.cpp en faisant clic sur le bouton vert.

#Dépendances :#
1. QT Creator suite logicielle
2. C++ compilateur

#Explication du fonctionnement interne du code :#

D'abbord, la classe Qresetbutton redémarre le jeu après perdre.
Il y a un bouton pour redémarrer le jeu.
'Encore une fois' apparaît sur une nouvelle fenêtre.
Une fois on fait un clic sur le bouton 'Eoncore une fois', le jeu est redémarré dans la même fenêtre principale du jeu antérieur


Deux classes pour les carreaux, Qtile et Tile

Qtile fonctionne comme frontend, Tile comme backend.
Tile contient la logique, c'est-à-dire la multiplication des valeurs, etc.
QTile est la partie visible avec les étiquettes (labels), les couleurs, etc.

QWinwindow, une nouvelle fenêtre pour montrer le succès
El montre le message "Tu as reussi le 2048, félicitacion ! Tu peux continuer le jeu pour augmenter ta score".
Essentiellement, elle donne l'oportunité au joueur de continuer après obtenir le 2048.
Cette fenêtre contient les boutons pour redémarrer et pour continuer, ainsi que l'étiquette (label) avec le message.

Le bouton Qreset envoie une signal pour redémarrer le jeu.
La signal est envoyé une fois l'événement mousepressevent en utilisant la méthode hérité clicked().
Cette méthode fait possible le redémarrage du jeu

Le constructeur de QGameboard attend pour l'émision de la signal clicked() après initialiser le tableau.
Cette signal est partie de QWidget. 
Maintenant la signal est assignée au button et connecté avec un slot à l'aide de la méthode connect().

'qgameboard.h' utilise une matrice d'éléments QTile pour montrer le tableau et
'board.h' utilise une matrice d'éléments Tile et a la logique de chaque carreau de la matcice montrée.

Par exemple, une fois keypressevent est appelé, le mouvement est montré en utilisant le objet du type qgameboard, alors que la logique de gérer les collisions entre les carreaux (multiplier les valeurs pour les carreaux qui correspondent) et la création de nouveaux carreaux est fait par l'objet de la classe board.


Ordre d'appel des classes :

qgameboard.h -> game.h -> board.h
 
Une observation est que la classe game fonctionne plutôt comme backend et la classe qgameboard comme frontend.

L'objet qgameboard a une instance de la clase QGameOverWindow qui est appelée si le jeu est fini.
QGameOverWindow est la fenêtre utilisée pour montrer que le joueur a perdu, c'est-à-dire, s'il n'y a plus de mouvement possibles.

On a implémenté le stockage du maximum score obtenu pour le joueur.
Tous les autres attributes sont faciles à comprendre selon sa position et nom.
 
#Travail à future/Projections :#

Améliorer l'apparition des nouveaux carreaux pour obtenir un niveau de complexité plus haut.
On peut changer aussi la manière comme on ajoute les carreaux avec 4, dont la méthode actuelle est seulement une probabilité de 10%.
La capacité de sauvegarder les jeux pour les finir plus tard.
Faire les mouvements des carreaux plus fluides.



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
We could also change the way we add random 4's, that now is just a probability of 10%.
The ability to save games and finish them later.
Make the movements of the tiles more fluidic. 
