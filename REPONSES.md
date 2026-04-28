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

*************************************************
##Q3.1

- Il est une bonne idée de faire hériter CultureDish de Drawable car c'est une classe qu'on dessine sur l'écran et de Updtable pour déclencher la mise à jour de ses listes internes. 
- Pour Nutrient il est une bonne idée de faire hériter de Drawable et de Updatable car non seulement on affiche les nutrients à l'écran mais aussi ils évoluent dans le temps. 
- Cette approche permet de traiter des objets de types différents de manière uniforme via le polymorphisme, ce qui simplifie la gestion globale du simulateur tout en facilitant l'ajout futur de nouvelles entités sans modifier le code existant.
*************************************************
##Q3.2

- On définit les méthodes drawOn et uptdate comme virtuelles afin de pouvoir les redéfinir dans leurs classes filles respectives.
*************************************************
##Q3.3

- La méthode GetConfig doit-être définie comme virtuelle pure dans la classe Nutrient pour qu'elle puisse être redefinie dans les sous-classes A et B. 
-La classe Nutrient devient donc une classe abstraite car on ne va plus instancier de nutriments, on va maintenant avoir uniquement des Nutrients A ou B.
*************************************************
##Q3.4

- Grâce au polymorphisme et donc à la résolution dynamique des liens. Etant donné que GetConfig est une méthode virtuelle pure, elle est redéfinie dans les sous-classes NutrientA et NutrientB. 
- Le GetConfig appelée dépend de celui qui l'appelle et donc permet de différencier les deux nutriments. 
*************************************************
##Q3.5

- Modification : Ajouter un attribut privé de type NutrientGenerator à la classe Laboratory.

- Méthode : Appeler la méthode update(dt) de cet attribut à l'intérieur de la méthode Laboratory::update(sf::Time dt).
*************************************************
##Q3.6

- On a du ajouter dans le JSON sous : ["generator"]["nutrient"]["max"] un nouveau paramètre de la simulation.
- Dans la méthode addNutrient de CultureDish, on vérifie la quantité de nutrients présents avant d'en ajouter un nouveau.
*************************************************
##Q3.7

- On a créé une fonction clamp qui permet de vérifier si les valeurs sont dans les bornes et qui les adaptent si besoin
- La fonction setValue appelle donc la fonction clamp au moment d'initialiser la valeur 
- toutes les autres fonctions qui modifient la valeur appellent la fonction setValue, qui vérifie deja les bornes. Donc pas besoin de revérifier.

*************************************************
##Q3.8


*************************************************
##Q3.9

- Classe : On propose que la classe soit abstraite car son comportement de déplacement dépend du type de la bactérie
- Héritage : On veut que Bacterium hérite de CircularBoundary car les bactéries sont des corps circulaires, de Updatable et Drawable car les bactéries doivent être affiché à l'écran et sont misent à jour dans le temps
- Attribut : La classe Bacterium possède les attributs suivants : MutableColor color_; Vec2d direction_; bool abstinence_; Quantity energy_; std::map<std::string, MutableNumber> mutables_; permettant de modéliser toutes les caractéristiques de la bactérie
- Méthodes : La classe aura une méthode move, update, drawOn, un constructeur qui initialise tout les paramètres (notamment isAbsinent à false par défaut), une méthode vérifiant l'état de vie de la bactérie et un destructeur. 
*************************************************
##Q3.10

- Les méthodes drawOn et update peuvent être virtuelle permettant la redéfiniton par les sous-classes car ces méthodes possède une logique de base commune, mais spécialisable : si certaine bactérie possède des particularités qui ne sont pas gérées par Bacterium.
- La méthode move est virtuelle pure car nous ne savons pas défenir cette méthode de façon générique à ce niveau là.
- Comme la classe contient des méthodes virtuelles, il est judicieux de mettre le desctructeur comme virtual. 
*************************************************
##Q3.11

- Oui selon nous la méthode j::Value GetConfig() est une méthode virtuelle pure pour qu'elle puisse être redefinie dans les sous-classes. 
*************************************************
##Q3.12

- En appelant la fonction getColor() de MutableColor. ?!?!?!?!? A COMPLETER
*************************************************
##Q3.13

- Non le fait que la méthode move(dt) ne soit pas encore définie ne pose aucun problème car cette une méthode virtuelle et sera définie plus tard par les sous-classes.
*************************************************
##Q3.14

- Pour y avoir accès, on passe par le Laboratoire grâce à getAppEnv() et le laboratoire appelle checkCollidingNutriment sur un de ces CultureDish
- Depuis CultureDish on a bien accès au nutriments. 
*************************************************
##Q3.15

- Pour encapsuler la logique consommation. Si on retournait un Nutriment*, la bactérie devrait gérer elle-même la modification du nutriment. 
- En faisant une méthode check..., on centralise la gestion des collisions et des effets (énergie/quantité) au même endroit.
*************************************************
##Q3.16

- La méthode à modifier est CultureDish::update(sf::Time dt). Elle doit désormais parcourir la collection des bactéries pour appeler leur propre méthode update, 
- tout en gérant la suppression des individus morts afin de libérer la mémoire.
*************************************************
##Q3.17

- Il faut modifier la méthode update dans la classe CultureDish car c'est cette classe qui a accès aux Nutrient et Bacterium. 
- Il faut ajouter une boucle for qui itère sur chaque bactérie et nutriments et vérifie si leur quantité est plus grande que 0 ou non, dans le cas échéant,
- il faut le supprimer correctement. 
*************************************************
##Q3.18

- En utilisant un lien d'héritage; on peut considérer, dans notre simulation, qu'une bactérie est une équation mathématique. L'avantage est que la bactérie peut accéder directement à ses propres variables internes pour calculer la force sans avoir besoin d'intermédiaire. 
- Il faut donc faire hériter à la classe Bacterium la classe DiffEqFunction.
- Comme DiffEqFunction est une classe abstraite on doit définir dans les sous-classes la méthode f(). 
- On y définit donc la méthode f(), comme MonotrichousBacterium est une DiffEqFunction, on peut passer en argument un MonotrichousBacterium à une méthode de la classe DiffEqFunction et cette méthode pourra alors agir de façons polymorphique. 


*************************************************
##Q3.19

- Le temps t est un attribut des MonotrichousBacterium, car il est spécifique à la bactérie en question.
- Il est initialisé dans le constructeur de MonotrichousBacterium, et est modifié dans la fonction move de MonotrichousBacterium après chaque déplacement.

*************************************************
##Q3.20

- On a ajouté un attribut à la classe Bacterium angle_direction_ comme toute les bactéries possède un angle. 
- Ainsi on initalise cette attribut dans le constructeur de la classe Bacterium et on la modifie dans la méthode move à chaque changement de direction. 


*************************************************
##Q4.1

- La fonction getPositionscore de Laboratory appelle la fonction getPositionscore de CultureDish car c'est elle qui a accès a la liste de Nutrient.

































