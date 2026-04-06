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

- On fait alors usage du mot clé override permettant au classes filles de les redefinir plus tard. 
*************************************************
##Q3.3

- La méthode GetConfig doit-être définie comme virtuelle pure dans la classe Nutrient pour qu'elle puisse être redefinie dans les sous-classes A et B. 
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
- Ensuite dans la méthode qui ajoute les nutrients : Laboratory::addNutrient(), on effectue une vérification si le nombre de Nutrients dans le CultureDish courante est inférieure au nouveau paramètre. 
- On a donc aussi ajouter un getter dans CultureDish qui permet de récuperer le nombre de Nutriments il y a dans son instance. 
- Le choix de mettre la vérification dans Laboratory::addNutrient() permet de centraliser le code et d'effectuer la vérification qu'une seule fois
- Cela nécessite en contre partie de la centralisation un delete car une nouvelle instance de Nutrient est crée sans qu'elle puisse être ajoutée à la CultureDish. 
