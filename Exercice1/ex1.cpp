#include<iostream>
#include<vector>
using namespace std;

void saisirNotes(vector<double>& notes, int n) {
	for (int i(0); i < n; i++) {
		double note;
		cout << "Entrez la note de l'etudiant " << i + 1 << " :";
		cin >> note;
		notes.push_back(note);
	}
}

void afficherNotes(vector<double> notes) {
	cout << "Notes des etudiants : ";
	for (size_t i(0); i < notes.size(); i++) {
		cout << notes[i] << " ";
	}
}

double calculerMoyenne(vector<double> notes) {
	double moy(0.0);
	for (auto elt : notes) {
		moy = moy + elt;
	}
	moy = moy / notes.size();
	return moy;
}

double trouverNoteMaximale(vector<double> notes) {
	double max(0.0);
	for (size_t i(0); i < notes.size(); i++) {
		if (notes[i] > max) {
			max = notes[i];
		}
	}
	return max;
}

void ajouterNotes(vector<double>& notes, int n2) {
	vector<double> notes2(n2);
	for (int i(0); i < n2; i++) {
		double note;
		cout << "Entrez la note de l'etudiant " << i + 1 << " :";
		cin >> note;
		notes2[i]=note;
	}
	for (auto& elt : notes2) {
		notes.push_back(elt);
	}
}
int main() {
	vector<double> notes;
	int N1, N2;
	cout << "Combien d'etudiants dans la classe initiale ? ";
	cin >> N1;
	saisirNotes(notes, N1);
	afficherNotes(notes);
	cout << endl;
	double moyenne = calculerMoyenne(notes);
	cout << "Moyenne des notes : " <<
	moyenne << endl;
	double noteMax = trouverNoteMaximale(notes);
	cout << "Note maximale : " << noteMax << endl;
	cout << "Combien de nouveaux etudiants rejoignent la classe ?	";
	cin >> N2;
	ajouterNotes(notes, N2);
	afficherNotes(notes);
	moyenne = calculerMoyenne(notes);
	cout << "Nouvelle moyenne des notes : " << moyenne << endl;
	noteMax = trouverNoteMaximale(notes);
	cout << "Nouvelle note maximale : " << noteMax << endl;
	return 0;
}