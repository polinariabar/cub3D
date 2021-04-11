# cub3D
A “realistic” 3D graphical representation of the inside of a maze from a first person perspective, using the Ray-Casting principles.
<img width="1000" alt="Screenshot 2021-04-11 at 14 04 07" src="https://user-images.githubusercontent.com/25934896/114301748-ca207f80-9ace-11eb-85a9-2be7582f55cd.png">


## How to launch:
* make start

or
* make
* ./cub3D information.cub

to make a screenshot
* make
* ./cub3D information.cub --save

## How to play:
* WASD - to move
* left and right arrows - to rotate

## Task
* You must use the miniLibX. Either the version that is available on the operating
system, or from its sources. If you choose to work with the sources, you will
need to apply the same rules for your libft as those written above in Common
Instructions part.
* The management of your window must remain smooth: changing to another window, minimizing, etc.
* Display different wall textures (the choice is yours) that vary depending on which
side the wall is facing (North, South, East, West).
* Your program must be able to display an item (sprite) instead of a wall.
* Your program must be able to set the floor and ceilling colors to two different ones.
* In case the Deepthought has eyes one day to evaluate your project, your program
must save the first rendered image in bmp format when its second argument is
"––save".
* If no second argument is supllied, the program displays the image in a window and
respects the following rules:
  * The left and right arrow keys of the keyboard must allow you to look left and
right in the maze.
  * The W, A, S and D keys must allow you to move the point of view through
the maze.
  * Pressing ESC must close the window and quit the program cleanly.
  * Clicking on the red cross on the window’s frame must close the window and
quit the program cleanly.
  * If the declared screen size in the map is greater than the display resolution,
the window size will be set depending to the current display resolution.
  * The use of images of the minilibX is strongly recommended.
* Your program must take as a first argument a scene description file with the .cub
extension.
  * The map must be composed of only 4 possible characters: 0 for an empty
space, 1 for a wall, 2 for an item and N,S,E or W for the player’s start
position and spawning orientation.
  * The map must be closed/surrounded by walls, if not the program must return
an error.
  * Except for the map content, each type of element can be separated by one or
more empty line(s).
  * Except for the map content which always has to be the last, each type of
element can be set in any order in the file.
  * Except for the map, each type of information from an element can be separated
by one or more space(s).
  * The map must be parsed as it looks like in the file. Spaces are a valid part of
the map, and is up to you to handle. You must be able to parse any kind of
map, as long as it respects the maps rules.
  * Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each
object in a strict order such as :
    * Resolution:
      * R x y
      * identifier: R
      * x render size
      * y render size
    * North texture:
      * NO ./path
      * identifier: NO
      * path to the texure
    * South texture:
      * SO ./path
      * identifier: SO
      * path to the texure
    * West texture:
      * WE ./path
      * identifier: WE
      * path to the texure
    * East texture:
      * EA ./path
      * identifier: EA
      * path to the texure
    * Sprite texture:
      * S ./path
      * identifier: S
      * path to the sprite texure
    * Floor color:
      * F r,g,b
      * identifier: F
      * R,G,B colors in range [0,255]: 0, 255, 255
    * Ceiling color:
      * C r,g,b
      * identifier: C
      * R,G,B colors in range [0,255]: 0, 255, 255
  * If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.
