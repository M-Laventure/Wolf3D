# wolf3d

## Doc utile
https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/ <br/>
http://projet-moteur-3d.e-monsite.com/pages/raycasting/raycasting.html<br/>
https://lodev.org/cgtutor/raycasting.html</br>
https://permadi.com/1996/05/ray-casting-tutorial-1/#INTRODUCTION<br/>
toutes les textures: http://i.imgur.com/xHuJa69.png
</br></br>
https://zestedesavoir.com/tutoriels/1014/utiliser-la-sdl-en-langage-c/

## Format de la map

0000000000000 <br/>
0**11111111111111**0 <br/>
0**1**P**1**00000**1**00**1**0 <br/>
0**1**0**111111111**00**1**0 <br/>
0**1**000000000**11**0 <br/>
0**1111111111111**00 <br/>
0000000000000 <br/>


![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)</br>
![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)</br>
![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/f03c15/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)</br>
![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)</br>
![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)</br>
![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/1589F0/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)</br>
![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)![#f03c15](https://placehold.it/15/cccccc/000000?text=+)</br>

- La map sera toujours en forme de carré/rectangle.
- Les 0 sont des endroits où le joueur peut se déplacer librement
- Les 1 sont les murs qui ne peuvent pas être franchis
- Le P est la position de départ du joueur et vaut 0.
- Taille maxi de la map: 25x25
