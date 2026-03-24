#Projet programmation orientée objet (SSV)

##REPONSES du groupe 8 (Gabriel Dubault & Ethan Bello) 

*************************************************
##Q1.1


- réponse à la question 1.1

*************************************************
##Q1.2


- réponse à la question 1.2

*************************************************
##Q1.3


- réponse à la question 1.3

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

##Q2.6


- Pour modéliser les sources de nutriments, on utilise l'héritage en faisant en sorte que notre classe Nutrient dérive directement de CircularBoundary.
- Comme une source de nutriments possède par définition une forme circulaire, elle "est" une frontière circulaire. 

*************************************************
