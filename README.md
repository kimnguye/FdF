#Fil de fer

FDF est un projet qui fait partie du tronc commun de l'ecole 42.
C'est mon premier projet graphique. A partir d'un fichier qui represente une carte au format ESRI grid

J'ai vraiment aime faire ce projet, je trouve qu'il en jette !

#Utilisation

1.	`make update` download or update submodule
2.	`make` build the executable file
3.	`./fdf <map_file>` read the file and execute program

- Touches `1` et `3` pour rotation autour de l'axe horizontal (x)
- Touches `4` et `6` pour rotation autour de l'axe vertical	(y)
- Touches `7` et `9` pour rotation autour de l'axe profondeur (z)
- Touches `2` et `8` pour reduire/augmenter l'altitude
- Bouton central de la souris (scroll) pour zooomer/dezoomer
- Touche `espace` pour une vue du dessus
- Touche `entree` pour reinitialiser la vue
- Touches directionnelles pour translation

#Technique

Le programme prend en argument un fichier texte qui represente une carte d'altitude (format ESRI Grid), la lit et l'affiche à l'ecran.

- Projet codé en langage C.
- Bibliotheque graphique de 42: la minilibX. Cette bibliothèque inclut des outils basiques permettant d’ouvrir une fenêtre, de créer des images et de gérer des événements clavier et souris.
- J'implemente l'algorithme de Bresenham pour tracer un segment entre 2 points.

Utilisation de `git submodule add` pour creer un submodule.

#Resultats

Un apercu du FdF avec la carte du Japon et celle de la France :

![Screenshot 2025-05-21 160325](https://github.com/user-attachments/assets/e06ce32b-36cb-4449-ae8b-77790e81a25e)

![Screenshot 2025-05-21 160459](https://github.com/user-attachments/assets/b7538cbd-e8b2-4af4-be59-9ae33fb950b8)

![Screenshot 2025-05-21 161553](https://github.com/user-attachments/assets/0a40b751-2d3c-4ec8-b406-315509117d24)

![Screenshot 2025-05-21 161707](https://github.com/user-attachments/assets/16c46f34-2124-4e96-86ee-1cbd5bcfd050)
