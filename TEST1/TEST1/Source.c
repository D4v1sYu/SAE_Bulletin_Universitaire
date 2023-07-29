/* Sae Davis Yu 110 le 24/09 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#pragma warning(disable : 4996)

enum { maxChar = 30, maxMtr = 10, maxEprv = 5, maxEtu = 100, minUE = 3, maxUE = 6, nbSmtr = 2};
const float minNote = 0.f, maxNote = 20.f;

typedef char CHM[maxChar + 1];

typedef struct {
	CHM nom;
	float coef[maxUE];
} Epreuve;

typedef struct {
	CHM nom;
	unsigned int nbEpreuves;
	Epreuve epreuves[maxEprv];
} Matiere;

typedef struct {
	unsigned int nbtotal;
	unsigned int nbMatieres;
	Matiere matieres[maxMtr];
} Semestre;

typedef struct {
	float note;
	CHM epreuve;
	CHM matiere;
	unsigned int semestre; //Position du semestre
} Note;

typedef struct {
	CHM nom;
	unsigned int nbNotes;
	Note notes[maxMtr * maxEprv * nbSmtr];
} Etudiant;

typedef struct {
	unsigned int nbUE; // nombre de coef, commun à toutes les épreuves
	unsigned int nbEtu;
	Semestre semestres[nbSmtr];
	Etudiant etudiants[maxEtu];
} Formation;


// Verifie l'existence d'une epreuve
// [in] Formation, semestre, nom matiere et epreuve
// [out] Booleen, existance ou non
bool eprv_verif(const Formation* f, const unsigned int s, const CHM nM, const CHM nE) {

	int tmp = mtr_verif(f, s, nM);
	if (tmp != -1) { //

		for (int j = 0; j < f->semestres[s].matieres[tmp].nbEpreuves; ++j) {

			if (strcmp(f->semestres[s].matieres[tmp].epreuves[j].nom, nE) == 0) {

				return true;
			}
		}
	}

	return false;
}

// Retourne la position d'une matiere d'entree si elle existe
// [in] Formation, semestre et nom matiere
// [out] Indice de la matiere ou -1
int mtr_verif(const Formation* f, const unsigned int s, const CHM nM) {

	for (int i = 0; i < f->semestres[s].nbMatieres; ++i) {
		if (strcmp(f->semestres[s].matieres[i].nom, nM) == 0) return i;
	}
	return -1;
}

// Permet l'ajout d'une epreuve si les conditions sont respectées (semestre, coefs, non existence)
// [in] Formation
// [out] Ajout ou non d'une epreuve dans la formation
void epreuve(Formation* f) {
	int semestre;
	int statutCoef = true, allCoef = false;
	float lstCoef[maxUE];
	CHM nomMtr, nomEprv;

	scanf("%d %s %s", &semestre, &nomMtr, &nomEprv);
	for (int i = 0; i < f->nbUE; ++i) {
		scanf("%f", &lstCoef[i]);
		if (lstCoef[i] < 0) statutCoef = false; // Si valeur inferieur a 0
		if (lstCoef[i] > 0) allCoef = true; // Si une valeur est superieur a 0
	}

	semestre -= 1; //Avoir la position du semestre en question

	if (semestre<0 || semestre>nbSmtr - 1) { //Position entre 0 et nombre de semestre -1
		printf("Le numero de semestre est incorrect\n");
	}
	else if (eprv_verif(f, semestre, nomMtr, nomEprv)) {
		printf("Une meme epreuve existe deja\n");
	}
	else if (statutCoef == false || allCoef == false) { //Aucun coef ne doit etre inferieur a 0 ou au moins un coef doit etre superieur a 0
		printf("Au moins un des coefficients est incorrect\n");
	}
	else { //Apres toute verification, il ne reste que 2 possibilités

		int tmp = mtr_verif(f, semestre, nomMtr);
		if (tmp != -1) { //La matiere existe

			strcpy(f->semestres[semestre].matieres[tmp].epreuves[f->semestres[semestre].matieres[tmp].nbEpreuves].nom, nomEprv);

			for (int j = 0; j < f->nbUE; ++j) {
				f->semestres[semestre].matieres[tmp].epreuves[f->semestres[semestre].matieres[tmp].nbEpreuves].coef[j] = lstCoef[j];
			}

			f->semestres[semestre].matieres[tmp].nbEpreuves += 1;

			printf("Epreuve ajoutee a la formation\n");
		}

		else { //La matiere n'existe pas

			strcpy(f->semestres[semestre].matieres[f->semestres[semestre].nbMatieres].nom, nomMtr);
			strcpy(f->semestres[semestre].matieres[f->semestres[semestre].nbMatieres].epreuves[f->semestres[semestre].matieres[f->semestres[semestre].nbMatieres].nbEpreuves].nom, nomEprv);
			
			for (int j = 0; j < f->nbUE; ++j) {
				f->semestres[semestre].matieres[f->semestres[semestre].nbMatieres].epreuves[f->semestres[semestre].matieres[f->semestres[semestre].nbMatieres].nbEpreuves].coef[j] = lstCoef[j];
			}

			f->semestres[semestre].matieres[f->semestres[semestre].nbMatieres].nbEpreuves += 1;
			f->semestres[semestre].nbMatieres += 1;

			printf("Matiere ajoutee a la formation\n");
			printf("Epreuve ajoutee a la formation\n");

		}
		f->semestres[semestre].nbtotal += 1;
	}
}
// Iniatialise l'epreuve
// [in] Formation
// [out] Formation initialisée
void initFormation(Formation* f) {

	for (int i = 0; i < nbSmtr; ++i) {
		f->semestres[i].nbMatieres = 0;
		f->semestres[i].nbtotal = 0;

		for (int j = 0; j < maxMtr; ++j) {
			f->semestres[i].matieres[j].nbEpreuves = 0;
		}
	}

	f->nbEtu = 0;
	for (int i = 0; i < maxEtu; ++i) {
		f->etudiants[i].nbNotes = 0;
	}
}

// Verifie si le nombre UE existe
// [in]
// [out]
bool frmt_verif(const unsigned int n) {

	if (n == 0) {
		return false;
	}
	else
		return true;
}

// Initialise le nombre d'UE
// [in] Formation, nombre d'UE
// [out] Nombre d'UE, Formation initialisée
void formation(unsigned int* n, Formation* f) {

	if (*n != 0) { //Verifie le nombre d'UE
		printf("Le nombre d'UE est deja defini\n");
	}
	else {
		int tmp;
		scanf("%d", &tmp);
		if (tmp >= minUE && tmp <= maxUE) { //Encadrement de la valeur saisie
			*n = tmp;
			printf("Le nombre d'UE est defini\n");
			f->nbUE = tmp; //Affectation lorsque le nombre d'UE respecte bien les conditions
			initFormation(f); //Initialise la Formation
		}
		else {
			printf("Le nombre d'UE est incorrect\n");
		}
	}
}

// Verifie les coefs de chacun des UE d'un semestre
// [in] Formation, semestre
// [out] Booleen
bool coef_verif(const Formation* f, const int s) {

	for (int i = 0; i < f->nbUE; ++i) {
		int statutCoef = false;
		for (int j = 0; j < f->semestres[s].nbMatieres; ++j) {

			for (int k = 0; k < f->semestres[s].matieres[j].nbEpreuves; ++k) { //Pour chaque epreuve de l'UE
				if (f->semestres[s].matieres[j].epreuves[k].coef[i] > 0) { //Si il y a au moins un coef valable
					statutCoef = true;
				}
			}

		}
		if (statutCoef == false) return false; //Sinon aucun coef de l'UE n'est valable
	}
	return true;
}

// Verification des coefs de la Formation
// [in] Formation, semestre
// [out]
void coef(Formation* f) {
	int semestre;
	scanf("%d", &semestre);
	semestre -= 1;

	if (semestre<0 || semestre>nbSmtr - 1) {
		printf("Le numero de semestre est incorrect\n");
	}
	else if (f->semestres[semestre].nbMatieres == 0) {
		printf("Le semestre ne contient aucune epreuve\n");
	}
	else if (coef_verif(f, semestre) == false) {
		printf("Les coefficients d'au moins une UE de ce semestre sont tous nuls\n");
	}
	else {
		printf("Coefficients corrects\n");
	}

}

// Ajoute une note a l'etudiant
// [in] Formation, semestre, nom d'etudiant, de matiere, d'epreuve, note
// [out] Insertion du semestre, matiere, epreuve, note, incremente le nombre de note de l'etudiant
void insertNote(Formation* f, int s, CHM etu, CHM nM, CHM nE, float note){

	int indEtu = etudiant_verif(f, etu);
	strcpy(f->etudiants[indEtu].notes[f->etudiants[indEtu].nbNotes].epreuve, nE);
	strcpy(f->etudiants[indEtu].notes[f->etudiants[indEtu].nbNotes].matiere, nM);
	f->etudiants[indEtu].notes[f->etudiants[indEtu].nbNotes].semestre = s;
	f->etudiants[indEtu].notes[f->etudiants[indEtu].nbNotes].note = note;
	f->etudiants[indEtu].nbNotes += 1;

	printf("Note ajoutee a l'etudiant\n");
}

// Verifie l'existence de l'etudiant
// [in] Formation, nom etudiant 
// [out] ind de l'etudiant sinon -1
int etudiant_verif(const Formation* f, CHM etu) {
	for (int i = 0; i < f->nbEtu; ++i) {
		if (strcmp(f->etudiants[i].nom, etu) == 0) {
			return i;
		}
	}
	return -1;
}

// Verifie l'existence de la note d'un etudiant
// [in] Formation, semestre, indice etudiant, nom matiere et epreuve
// [out] La note de l'etudiant sinon -1
float note_existe(const Formation* f, int s, int etu, CHM nM, CHM nE) {
	for (int i = 0; i < f->etudiants[etu].nbNotes; ++i) {
		if ((strcmp(f->etudiants[etu].notes[i].epreuve, nE) == 0) && (f->etudiants[etu].notes[i].semestre == s) && (strcmp(f->etudiants[etu].notes[i].matiere, nM) == 0)) {
			return f->etudiants[etu].notes[i].note;
		}
	}
	return -1;
}

// Verifie l'existence de la note
// [in] Formation, semestre, nom etudiant, matiere, epreuve
// [out] booleen
bool note_verif(const Formation* f, int s, CHM etu, CHM nM, CHM nE) {
	int indEtu = etudiant_verif(f, etu);

	if (indEtu != -1 && note_existe(f,s,indEtu,nM,nE)!=-1){
		return true;
	}
	return false;
}

// Ajout d'une note a l'etudiant si les conditions sont respectées
// [in-out] Formation
void note(Formation* f) {
	int semestre;
	float note;
	CHM etudiant, nomMtr, nomEprv;
	scanf("%d %s %s %s %f", &semestre, &etudiant, &nomMtr, &nomEprv, &note);

	semestre -= 1;

	if (semestre <0 || semestre > nbSmtr - 1) {
		printf("Le numero de semestre est incorrect\n");
	}
	else if (mtr_verif(f, semestre, nomMtr) == -1) {
		printf("Matiere inconnue\n");
	}
	else if (eprv_verif(f, semestre, nomMtr, nomEprv) == false) {
		printf("Epreuve inconnue\n");
	}
	else if (note<minNote || note>maxNote) {
		printf("Note incorrecte\n");
	}
	else if (note_verif(f, semestre, etudiant, nomMtr, nomEprv)) {
		printf("Une note est deja definie pour cet etudiant\n");
	}
	else {
		if (etudiant_verif(f, etudiant) == -1) {
			strcpy(f->etudiants[f->nbEtu].nom, etudiant);
			f->nbEtu += 1;
			printf("Etudiant ajoute a la formation\n");
		}
		insertNote(f,semestre,etudiant,nomMtr,nomEprv,note);
	}
}

//
//
//
int nbNote_semestre(Formation* f, int etu, int s) {
	int compteur = 0;
	for (int i = 0; i < f->etudiants[etu].nbNotes; ++i) {
		if (f->etudiants[etu].notes[i].semestre == s) {
			++compteur;
		}
	}
	return compteur;
}

// Verifie que l'etudiant possede bien une note a toutes ses epreuves
// [in] Formation
// [out]
void notes(const Formation* f) {

	int semestre;
	CHM etudiant;
	scanf("%d %s", &semestre, &etudiant);

	int indEtu = etudiant_verif(f, etudiant);
	semestre -= 1;

	if (semestre < 0 || semestre > nbSmtr - 1) {
		printf("Le numero de semestre est incorrect\n");
	}
	else if (indEtu==-1) {
		printf("Etudiant inconnu\n");
	}
	else if (nbNote_semestre(f, indEtu, semestre) != f->semestres[semestre].nbtotal) {
		printf("Il manque au moins une note pour cet etudiant\n");
	}
	else {
		printf("Notes correctes\n");
	}
}

float noteEtudiant(const Formation* f, int etu, int s, CHM nM, CHM nE) {
	
	for (int i = 0; i < f->etudiants[etu].notes; ++i) {
		float note = note_existe(f, s, etu, nM, nE);
		if (note != -1) {
			return note;
		}
	}
	
}

void initNbr(const Formation* f, float lstNbr[]) {
	for (int i = 0; i < f->nbUE; ++i) {
		lstNbr[i] = 0;
	}
}
void espace(nb) {
	for (int i = 0; i < nb; ++i) {
		printf(" ");
	}
}

float tronque(const float note) {
	int tmp;
	tmp = note * 10;
	return (float)tmp / 10;
}

void affiche_releve(const Formation* f, int etu, int s) {
	int carac = strlen("Moyennes");
	float notetotal[maxUE], coeftotal[maxUE];
	initNbr(f, notetotal);
	initNbr(f, coeftotal);

	for (int i = 0; i < f->semestres[s].nbMatieres; ++i) {

		int tmp = strlen(f->semestres[s].matieres[i].nom);
		if (carac < tmp) carac = tmp;
	}

	espace(carac+1);
	for (int i = 1; i < f->nbUE+1; ++i) {
		printf(" UE%d ", i);
	}
	printf("\n");

	for (int i = 0; i < f->semestres[s].nbMatieres; ++i) {

		float notes[maxUE], coef[maxUE];
		initNbr(f, notes);
		initNbr(f, coef);

		for (int j = 0; j < f->semestres[s].matieres[i].nbEpreuves; ++j) {
			for (int k = 0; k < f->nbUE; ++k) {
				notes[k] += noteEtudiant(f, etu, s, f->semestres[s].matieres[i].nom, f->semestres[s].matieres[i].epreuves[j].nom) * f->semestres[s].matieres[i].epreuves[j].coef[k];
				coef[k] += f->semestres[s].matieres[i].epreuves[j].coef[k];
				notetotal[k] += noteEtudiant(f, etu, s, f->semestres[s].matieres[i].nom, f->semestres[s].matieres[i].epreuves[j].nom) * f->semestres[s].matieres[i].epreuves[j].coef[k];
				coeftotal[k] += f->semestres[s].matieres[i].epreuves[j].coef[k];
			}
		}

		printf("%s ", f->semestres[s].matieres[i].nom);
		espace(carac - strlen(f->semestres[s].matieres[i].nom));
		for (int k = 0; k < f->nbUE; ++k) {
			if (coef[k] == 0) {
				espace(2);
				printf("ND ");
			}
			else {
				if (tronque(notes[k] / coef[k]) < 10) {
					espace(1);
				}
				printf("%.1f ", tronque(notes[k] / coef[k]));
			}
			

		}
		printf("\n");
	}

	printf("--\n");
	printf("Moyennes ");
	espace(carac - strlen("Moyennes"));
	for (int k = 0; k < f->nbUE; ++k) {
		if (tronque(notetotal[k] / coeftotal[k]) < 10) {
			espace(1);
		}
		printf("%.1f ", tronque(notetotal[k] / coeftotal[k]));

	}
	printf("\n");
}

void releve(const Formation* f) {
	int semestre;
	CHM etudiant;
	scanf("%d %s", &semestre, &etudiant);

	int indEtu = etudiant_verif(f, etudiant);
	semestre -= 1;

	if (semestre < 0 || semestre > nbSmtr - 1) {
		printf("Le numero de semestre est incorrect\n");
	}
	else if (indEtu == -1) {
		printf("Etudiant inconnu\n");
	}
	else if (coef_verif(f, semestre) == false) {
		printf("Les coefficients de ce semestre sont incorrects\n");
	}
	else if (nbNote_semestre(f, indEtu, semestre) != f->semestres[semestre].nbtotal) {
		printf("Il manque au moins une note pour cet etudiant\n");
	}
	else {
		affiche_releve(f, indEtu, semestre);
	}
}

bool coef_verif_formation(const Formation* f) {
	for (int i = 0; i < nbSmtr; ++i) {
		if (coef_verif(f, i)==false) {
			return false;
		}
	}
	return true;
}
int nbEprv(const Formation* f) {
	int compteur = 0;
	for (int i = 0; i < nbSmtr; ++i) {
		compteur += f->semestres[i].nbtotal;
	}
	return compteur;
}

void affiche_decision(Formation* f, int etu) {
	int carac = strlen("Moyennes annuelles"), nbacqui=0;
	float notetotal[maxUE];
	initNbr(f, notetotal);

	espace(carac + 1);
	for (int i = 1; i < f->nbUE + 1; ++i) {
		printf(" UE%d ", i);
	}
	printf("\n");
	for (int s = 0; s < nbSmtr; ++s) {
		float notes[maxUE], coef[maxUE];
		initNbr(f, notes);
		initNbr(f, coef);
		for (int i = 0; i < f->semestres[s].nbMatieres; ++i) {
			for (int j = 0; j < f->semestres[s].matieres[i].nbEpreuves; ++j) {
				for (int k = 0; k < f->nbUE; ++k) {
					notes[k] += noteEtudiant(f, etu, s, f->semestres[s].matieres[i].nom, f->semestres[s].matieres[i].epreuves[j].nom) * f->semestres[s].matieres[i].epreuves[j].coef[k];
					coef[k] += f->semestres[s].matieres[i].epreuves[j].coef[k];
				}
			}
		}

		printf("S%d ", s + 1);
		espace(carac - 2);

		for (int k = 0; k < f->nbUE; ++k) {
			notetotal[k] += notes[k]/coef[k];
			if (tronque(notes[k] / coef[k]) < 10) {
				espace(1);
			}
			printf("%.1f ", tronque(notes[k] / coef[k]));
		}
		printf("\n");
	}
	printf("--\n");
	printf("Moyennes annuelles ");
	for (int k = 0; k < f->nbUE; ++k) {
		if (tronque(notetotal[k] / nbSmtr) < 10) {
			espace(1);
		}
		if (tronque(notetotal[k] / nbSmtr) >= 10) nbacqui += 1;
		printf("%.1f ", tronque(notetotal[k] / nbSmtr));

	}
	printf("\n");


	bool passage;

	passage = nbacqui > (f->nbUE/2) ? true : false;

	printf("Acquisition ");
	espace(carac-strlen("Acquisition"));
	if (nbacqui == 0) {
		printf("Aucune");
	}
	else {
		for (int k = 0; k < f->nbUE; ++k) {
			if (tronque(notetotal[k] / nbSmtr) >= 10) {
				printf("UE%d", k+1);
				if (nbacqui-1 > 0) {
					printf(", ");
					--nbacqui;
				}
			}

		}
	}
	printf("\n");

	printf("Devenir ");
	espace(carac - strlen("Devenir"));
	(passage == true) ? printf("Passage") : printf("Redoublement");
	printf("\n");
}

void decision(const Formation* f) {
	CHM etudiant;
	scanf("%s", &etudiant);

	int indEtu = etudiant_verif(f, etudiant);

	if (indEtu == -1) {
		printf("Etudiant inconnu\n");
	}
	else if (coef_verif_formation(f)==false) {
		printf("Les coefficients d'au moins un semestre sont incorrects\n");
	}
	else if (f->etudiants[indEtu].nbNotes != nbEprv(f)) {
		printf("Il manque au moins une note pour cet etudiant\n");
	}
	else {
		affiche_decision(f,indEtu);
	}
}

int main() {

	CHM cmd;
	Formation lstEprv;
	unsigned int nbUE = 0;

	do {
		scanf("%s", &cmd);

		if (strcmp(cmd, "formation") == 0) {
			formation(&nbUE, &lstEprv);
		}

		else if (strcmp(cmd, "epreuve") == 0) {

			if (frmt_verif(nbUE) == false) {
				printf("Le nombre d'UE n'est pas defini\n");
			}
			else {
				epreuve(&lstEprv);
			}
		}
		else if (strcmp(cmd, "coefficients") == 0) {

			if (frmt_verif(nbUE) == false) {
				printf("Le nombre d'UE n'est pas defini\n");
			}
			else {
				coef(&lstEprv);
			}
		}
		else if (strcmp(cmd, "note") == 0) {
			if (frmt_verif(nbUE) == false) {
				printf("Le nombre d'UE n'est pas defini\n");
			}
			else {
				note(&lstEprv);
			}
		}
		else if (strcmp(cmd, "notes") == 0) {
			if (frmt_verif(nbUE) == false) {
				printf("Le nombre d'UE n'est pas defini\n");
			}
			else {
				notes(&lstEprv);
			}
		}
		else if (strcmp(cmd, "releve") == 0) {
			if (frmt_verif(nbUE) == false) {
				printf("Le nombre d'UE n'est pas defini\n");
			}
			else {
				releve(&lstEprv);
			}
		}
		else if (strcmp(cmd, "decision") == 0) {
			if (frmt_verif(nbUE) == false) {
				printf("Le nombre d'UE n'est pas defini\n");
			}
			else {
				decision(&lstEprv);
			}
		}
	} while (strcmp(cmd, "exit") != 0);

}
