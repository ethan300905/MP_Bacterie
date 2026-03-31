#Projet programmation orientée objet (SSV)

##REPONSES du groupe 8 (Gabriel Dubault & Ethan Bello) 

*************************************************
##Q1.1

- ...

*************************************************
##Q1.2

- ...

*************************************************
##Q1.3

- ...

*************************************************
##Q2.1
 
-Une boite est-un contour circulaire, on peut donc définir une relation d'héritage ou la classe CultureDish hérite de la classe Circularboundary.
*************************************************
##Q2.2

- Il faut déclarer comme const les méthodes suivantes :
1) drawOn() car elle est chargée d'afficher à l'écran les éléments, elle ne doit donc en aucun cas modifier l'état interne de la boîte. 

2) Les getters 
*************************************************
##Q2.3

- Pour empecher la copie et l'affection on doit faire une surchrage interne et supprimer explicitement le constucteur de copie et l'opérateur d'affectation dans la déclaration de classe en rajoutant le "=delete"
*************************************************
##Q2.4

-  Lors de la destruction il faudra bien effacer les objets bactéries et nutrient qui se trouvent dans la boite. On ne peut pas utiliser une méthode existante car update() ou drawOn() n'ont pas le rôle de libérer la mémoire.
*************************************************
##Q2.5

- On appelle DrawOn() uniquement sur l'instance courante de CultureDish pour ne pas surcharger l'écran
- On appelle update() sur chaque CultureDish car elles doivent évoluer même si on ne les voit pas 
*************************************************
##Q2.6

- Pour modéliser les sources de nutriments, on utilise l'héritage en faisant en sorte que notre classe Nutrient "est-un" CircularBoundary.
*************************************************
##Q2.7

- Le type Quantity défini comme un double permet une meilleure modularisation du code ainsi qu'une documentation induite, cela nous permet de mieux comprendre le code écrit.
*************************************************
##Q2.8

- On doit ajouter la fonction addNutrient à Laboratory qui va appeler la fonction addNutrient de CultureDish.
- On doit modifier la fonction drawOn de CultureDish pour lui permettre de dessiner ses propres Nutrients, elle devra aussi dessiner ses bactéries par la suite.
*************************************************
##Q2.9

- Récupération de l'environnement : On utilise l'appel getAppEnv().contains(*this). Ici, la fonction getAppEnv() retourne l'instance actuelle du laboratoire (le gestionnaire global de l'application).

- Délégation à la classe Laboratoire : Une méthode contains a été ajoutée à la classe Laboratoire. Cette dernière possédant une référence vers l'objet CultureDish, elle peut ainsi lui déléguer la vérification.

- Vérification géométrique : Enfin, la classe CultureDish appelle sa propre fonction contains (héritée de CircularBoundary), permettant de déterminer si l'objet se situe bien à l'intérieur des limites circulaires.


