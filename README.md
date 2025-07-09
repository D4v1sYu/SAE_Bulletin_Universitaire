# SAE_Bulletin_Universitaire

Projet réalisé en première année de BUT Informatique

Concept :
-

Le projet consiste à développer un interpréteur de commandes en langage C permettant de gérer une formation universitaire.  
L'objectif principal est de faciliter la gestion des informations relatives à la structure de la formation, des étudiants inscrits ainsi que de leurs notes.  
Il permet également de réaliser des tâches de fin de semestre et d’année : édition de relevés de notes, décisions de jury, statistiques, etc.

Fonctionnalités :
-
Voici les fonctionnalités principales implémentées dans le projet :

- Structure de la formation :
  - Définition du nombre d’UE
  - Ajout de matières et d’épreuves (avec coefficients et types d’évaluation)

- Gestion des étudiants :
  - Création de profils étudiants avec nom, prénom, numéro, etc
  - Inscription des étudiants à la formation
  - Consultation des informations individuelles (moyennes, passage à l’année suivante, etc)

- Gestion des notes :
  - Enregistrement/modification des notes pour chaque étudiant et épreuve.
  - Calcul de moyenne par matière, par UE, ou globale.

- Tâches de fin d’année :
  - Édition des relevés de notes
  - Établissement des décisions de jury (admis, ajourné, etc)
  - Génération de statistiques sur les résultats

Exemple :
-
*User : formation 3*  
$\textcolor{cyan}{\textsf{Le nombre d’UE est defini}}$  
*User : epreuve 1 Programmation Projet 1 2 0*  
$\textcolor{cyan}{\textsf{Matiere ajoutee}}$  
$\textcolor{cyan}{\textsf{Epreuve ajoutee}}$  
*User : epreuve 1 Programmation DST 2 3 0*  
$\textcolor{cyan}{\textsf{Epreuve ajoutee}}$  
*User : epreuve 1 SGBD Participation 0,5 0 0,5*  
$\textcolor{cyan}{\textsf{Matiere ajoutee}}$  
$\textcolor{cyan}{\textsf{Epreuve ajoutee}}$  
*User : epreuve 1 SGBD Rapport 1,5 0 1,5*  
$\textcolor{cyan}{\textsf{Epreuve ajoutee}}$  
*User : coefficients 1*  
$\textcolor{cyan}{\textsf{Coefficients corrects}}$  

*User : note 1 Paul Programmation Projet 12*  
$\textcolor{cyan}{\textsf{Etudiant ajoute a la formation}}$  
$\textcolor{cyan}{\textsf{Note ajoutee a l’etudiant}}$  
*User : note 1 Paul Programmation DST 9*  
$\textcolor{cyan}{\textsf{Note ajoutee a l’etudiant}}$  
*User : note 1 Paul SGBD Participation 16*  
$\textcolor{cyan}{\textsf{Note ajoutee a l’etudiant}}$  
*User : note 1 Paul SGBD Rapport 12*  
$\textcolor{cyan}{\textsf{Note ajoutee a l’etudiant}}$  
*User : releve 1 Paul*  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; $\textcolor{cyan}{\textsf{UE1 UE2 UE3}}$  
$\textcolor{cyan}{\textsf{Programmation 10,0 10,2 ND}}$  
$\textcolor{cyan}{\textsf{SGBD}}$ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; $\textcolor{cyan}{\textsf{13,0 ND 13,0}}$  
$\textcolor{cyan}{\textsf{- -}}$  
$\textcolor{cyan}{\textsf{Moyennes}}$ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; $\textcolor{cyan}{\textsf{11,2 10,2 13,0}}$  

**Ceci n’est qu’un extrait simplifié. Le projet complet permet de gérer plusieurs étudiants, matières, épreuves, décision finale, etc**

En pratique :
-
L'utilisation en ligne de commande impose d’entrer manuellement chaque note, matière et étudiant, ce qui devient fastidieux dès qu’il y a plus de quelques étudiants.  
La structure de données imposée était statique, ce qui signifie :
- une mémoire fixée à l’avance,
- une limite de données maximale codée en constantes,
- des tableaux à taille fixe (pas de réallocation dynamique).

Nous n'avions pas encore vu les tableaux dynamiques à ce moment là, mais cela aurait permis une bien meilleure flexibilité.  
Pour valider le programme, nous avons utilisé des tests en boîte noire (fichiers d’entrée/sortie attendus), ce qui permet :
- de tester toutes les fonctionnalités
- de simuler un usage réel

Mais cette méthode montre ses limites :
- le code peut être lent ou inefficace sans que cela soit détecté
- certains camarades ont mis plusieurs minutes pour exécuter les gros fichiers de test
- présence de redondances pour tester les limites mémoire
  
Conclusion :
-
C'est le premier projet universitaire que j'ai réalisé lors de ma formatique en BUT Informatique, l'objectif était de nous initier à l'algorithmique et au langage C.
J'ai pu appliquer mes connaissances en programmation dans le cadre d'un exercice assez concret. Les compétences que j'ai acquis au lycée mon énormement aidé pour réaliser ce projet.  
Notamment avec la maitrise du langage Python et ses similitudes avec le C, m'ont permis de me familiariser rapidement et efficacement sur ce nouveau langage assez primitif.
J'apprécie ce projet pour m'avoir montrer que chaque langage de programmation possède des ressemblances mais qu'au fond il renferme chacun leur propre spécificités.
