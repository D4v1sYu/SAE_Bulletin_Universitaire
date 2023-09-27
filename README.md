# SAE_Bulletin_Universitaire


Concept :
-

Le projet consiste à développer un interpréteur de commandes en langage C qui permettra de gérer une formation universitaire. 
L'objectif principal de cet interpréteur est de faciliter la gestion des informations relatives à la structure de la formation, aux étudiants inscrits, ainsi qu'aux notes qui leur sont attribuées. 
Il doit également permettre d'effectuer différentes tâches liées à la fin du semestre et de l'année universitaire, telles que l'édition des relevés de notes et l'établissement des décisions du jury.

Options :
-

Pour atteindre cet objectif, l'interpréteur devra prendre en compte différentes commandes. Voici quelques-unes des fonctionnalités développées :

- Définir la structure de la formation : définir les différentes matières et évaluations qui composent la formation universitaire catégorisées dans des semestres différents. Des commandes pour ajouter de nouvelles matières et des évaluations liées à ces dernières.

- Gérer les étudiants inscrits : créer des profils étudiants, comprenant des informations telles que le nom, le prénom, le numéro d'étudiant, etc. Des commandes pour inscrire des étudiants à la formation. Il est également possible de consulter les informations relatives à chaque étudiant, savoir si il passe l'année ou non.

- Affecter des notes : enregistrer et de gérer les notes des étudiants pour chaque matière. Des commandes permettant d'ajouter ou de modifier des notes pour des étudiants spécifiques, ainsi que des commandes pour calculer la moyenne des étudiants dans une matière donnée.

- Tâches de fin de semestre et d'année : proposer des commandes pour effectuer des tâches de fin de semestre et d'année universitaire, telles que l'édition de relevés de notes pour chaque étudiant, l'établissement des décisions du jury (admis, ajourné, etc.) ou la génération de statistiques sur les résultats des étudiants.



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

Ce n'est qu'une petite partie du projet, effectivement l'exemple n'intègre qu'un seul étudiant et n'inclut pas la décision finale d'obtention du diplome.

En pratique :
-

Conclusion :
-
