#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Stats {
	int vitLvl;
	int infLvl;
	int esoLvl;
	int bpLvl;
	int morLvl;
};

class Patient {
protected:
	string name;
	Stats stats;
public:
	Patient(const string& n = "unnamed") {
		name = n;
		stats.vitLvl = 85;
		stats.infLvl = 15;
		stats.esoLvl = 85;
		stats.bpLvl = 85;
		stats.morLvl = 85;
	}

	virtual string getType() const = 0;

	virtual ~Patient() {}

	virtual void take_PPI() {
		stats.infLvl -= 15;
		stats.vitLvl -= 15;
		setMaxMin();
	}

	virtual void take_dil() {
		stats.esoLvl += 15;
		stats.bpLvl -= 15;
		setMaxMin();
	}

	virtual void no_PPI() {
		stats.infLvl += 15;
		stats.vitLvl += 15;
		setMaxMin();
	}

	virtual void no_dil() {
		stats.esoLvl -= 15;
		stats.bpLvl += 15;
		setMaxMin();
	}

	virtual void live_bland() {
		stats.infLvl -= 15;
		stats.esoLvl += 15;
		stats.morLvl -= 15;
		setMaxMin();
	}

	virtual void live_live() {
		stats.infLvl += 15;
		stats.esoLvl -= 15;
		stats.morLvl += 15;
		setMaxMin();
	}

	virtual void next_Year() {
		stats.vitLvl -= 5;
		stats.infLvl += 5;
		stats.esoLvl -= 5;
		stats.bpLvl -= 5;
		stats.morLvl -= 5;
		setMaxMin();
	}

	virtual void printStats() const {
		cout << name << "'s Status" << endl;
		cout << "Vitamin Level: " << stats.vitLvl << endl;
		cout << "Inflammation Level: " << stats.infLvl << endl;
		cout << "Esophagael Function Level: " << stats.esoLvl << endl;
		cout << "Blood Pressue Level: " << stats.bpLvl << endl;
		cout << "Morale Level: " << stats.morLvl << endl;
	}

	virtual void saveGame(ostream& out) const {
		out << name << endl;
		out << stats.vitLvl << " " << stats.infLvl << " " << stats.esoLvl << " " << stats.bpLvl << " " << stats.bpLvl << endl;
	}

	virtual void loadGame(istream& in) {
		getline(in, name);
		in >> stats.vitLvl >> stats.infLvl >> stats.esoLvl >> stats.bpLvl >> stats.morLvl;
		in.ignore(10000, '\n');
	}

	bool lowLevels() const {
		if (stats.vitLvl <= 25) {
			cout << name << " has low vitamin levels!" << endl;
			return true;
		}

		if (stats.infLvl >= 75) {
			cout << name << " has high inflammation levels!" << endl;
			return true;
		}

		if (stats.esoLvl <= 25) {
			cout << name << " has low esophagael function levels!" << endl;
			return true;
		}

		if (stats.bpLvl <= 25) {
			cout << name << " has low blood pressure levels!" << endl;
			return true;
		}

		if (stats.morLvl <= 25) {
			cout << name << " has low morale levels!" << endl;
			return true;
		}
		return false;
	}

	bool gameIsOver() const {
		if (stats.vitLvl <= 0) {
			cout << name << " suffered hypovitaminosis, game over!" << endl;
			cout << name << " has been taken out of your care" << endl;
			return true;
		}
		if (stats.infLvl >= 100) {
			cout << name << " contracted stomach cancer, game over!" << endl;
			cout << name << " has been taken out of your care" << endl;
			return true;
		}
		if (stats.esoLvl <= 0) {
			cout << name << " experienced respitory failure, game over!" << endl;
			cout << name << " has been taken out of your care" << endl;
			return true;
		}
		if (stats.bpLvl <= 0) {
			cout << name << "'s organs failed, game over!" << endl;
			cout << name << " has been taken out of your care" << endl;
			return true;
		}
		if (stats.morLvl <= 0) {
			cout << name << " now has severe depression, game over!" << endl;
			cout << name << " has been taken out of your care" << endl;
			return true;
		}
		return false;
	}
private:
	void setMaxMin() {
		if (stats.vitLvl < 0) {
			stats.vitLvl = 0;
		}
		if (stats.vitLvl > 100) {
			stats.vitLvl = 100;
		}

		if (stats.infLvl < 0) {
			stats.infLvl = 0;
		}
		if (stats.infLvl > 100) {
			stats.infLvl = 100;
		}

		if (stats.esoLvl < 0) {
			stats.esoLvl = 0;
		}
		if (stats.esoLvl > 100) {
			stats.esoLvl = 100;
		}

		if (stats.bpLvl < 0) {
			stats.bpLvl = 0;
		}
		if (stats.bpLvl > 100) {
			stats.bpLvl = 100;
		}

		if (stats.morLvl < 0) {
			stats.morLvl = 0;
		}
		if (stats.morLvl > 100) {
			stats.morLvl = 100;
		}
	}

};

class PatientOne : public Patient {
public:
	PatientOne(const string& n = "Patient One") : Patient(n) {}

	virtual string getType() const { return "PatientOne"; }


	virtual void no_dil() {
		stats.esoLvl -= 20;
		stats.bpLvl += 15;
	}

	virtual void next_Year() {
		stats.vitLvl -= 5;
		stats.infLvl += 5;
		stats.esoLvl -= 10;
		stats.bpLvl -= 5;
		stats.morLvl -= 5;
	}
};

class PatientTwo : public Patient {
public:
	PatientTwo(const string& n = "Patient Two") : Patient(n) {}

	virtual string getType() const { return "PatientTwo"; }


	virtual void take_PPI() {
		stats.infLvl -= 15;
		stats.vitLvl -= 20;
	}

	virtual void next_Year() {
		stats.vitLvl -= 10;
		stats.infLvl += 5;
		stats.esoLvl -= 5;
		stats.bpLvl -= 5;
		stats.morLvl -= 5;
	}
};

class PatientThree : public Patient {
public:
	PatientThree(const string& n = "PatientThree") : Patient(n) {}

	virtual string getType() const { return "PatientThree"; }

	virtual void no_PPI() {
		stats.infLvl += 20;
		stats.vitLvl += 15;
	}

	virtual void live_bland() {
		stats.infLvl -= 15;
		stats.esoLvl += 15;
		stats.morLvl -= 20;
	}

	virtual void next_Year() {
		stats.vitLvl -= 5;
		stats.infLvl += 10;
		stats.esoLvl -= 5;
		stats.bpLvl -= 5;
		stats.morLvl -= 10;
	}
};

void mainMenu() {
	cout << "Menu Options" << endl;
	cout << "[1] Admit new patient" << endl;
	cout << "[2] Load previous patient" << endl;
	cout << "[3] Save current patient" << endl;
	cout << "[4] Administer treatment" << endl;
	cout << "[5] Show patient's status" << endl;
	cout << "[6] Quit game" << endl;
	cout << endl;
}

int validInput(int minVal, int maxVal) {
	int aVal;
	while (true) {
		cout << "Enter an option between " << minVal << " to " << maxVal << ": ";
		if (cin >> aVal && aVal >= minVal && aVal <= maxVal) {
			cin.ignore(1000, '\n');
			return aVal;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input, try again." << endl;
		}
	}
}

Patient* newPatient() {
	cout << "Choose between these patients" << endl;
	cout << "Patient #1" << endl;
	cout << "Patient #2" << endl;
	cout << "Patient #3" << endl;

	int admit = validInput(1, 3);
	string name;
	cout << "Record your patients name: " << endl;
	getline(cin, name);

	Patient* patient = 0;
	if (admit == 1) {
		patient = new PatientOne(name);
	}
	else if (admit == 2) {
		patient = new PatientTwo(name);
	}
	else {
		patient = new PatientThree(name);
	}
	return patient;
}

void saveToFile(const Patient* patient) {
	if (patient == 0) {
		cout << "No exiting patient" << endl;
		return;
	}

	string filename;
	cout << "Enter the save files name: ";
	getline(cin, filename);

	ofstream out(filename.c_str());
	if (!out.is_open()) {
		cout << "File not open" << endl;
		return;
	}

	out << patient->getType() << endl;
	patient->saveGame(out);
	cout << "Patient saved to " << filename << endl;
}

Patient* loadPatient() {
	string filename;
	cout << "Enter filename to load from: ";
	getline(cin, filename);

	ifstream in(filename.c_str());
	if (!in.is_open()) {
		cout << "File not open" << endl;
		return 0;
	}

	string type;
	getline(in, type);

	Patient* patient = 0;
	if (type == "PatientOne") {
		patient = new PatientOne();
	}
	else if (type == "PatientTwo") {
		patient = new PatientTwo();
	}
	else if (type == "PatientThree") {
		patient = new PatientThree();
	}
	else {
		cout << "Invalid Patient" << endl;
	}

	patient->loadGame(in);
	cout << "Patient loaded from " << filename << endl;
	return patient;
}

void treatment(Patient* patient) {
	cout << "1 to prescribe PPIs, 2 not to" << endl;
	int PPI = validInput(1, 2);
	if (PPI == 1) {
		patient->take_PPI();
	}
	else if (PPI == 2) {
		patient->no_PPI();
	}

	cout << "1 to prescribe diltiazem, 2 not to" << endl;
	int dil = validInput(1, 2);
	if (dil == 1) {
		patient->take_dil();
	}
	else if (dil == 2) {
		patient->no_dil();
	}

	cout << "1 to recommend a restricted lifestyle, 2 to allow a normal lifestyle" << endl;
	int life = validInput(1, 2);
	if (life == 1) {
		patient->live_bland();
	}
	else if (life == 2) {
		patient->live_live();
	}
	patient->next_Year();
	patient->lowLevels();
}

int main() {
	Patient* currentPat = 0;
	bool running = true;

	string player;
	cout << "Enter your name" << endl;
	cin >> player;
	cout << "Welcome to Trial & Error Hospital, Dr. " << player << endl;
	cout << endl;

	while (running) {
		mainMenu();
		int option = validInput(1, 6);

		if (option == 1) {
			delete currentPat;
			currentPat = newPatient();
			currentPat->printStats();
			cout << endl;
		}
		else if (option == 2) {
			delete currentPat;
			currentPat = loadPatient();
			if (currentPat != 0) {
				currentPat->printStats();
			}
			cout << endl;
		}
		else if (option == 3) {
			saveToFile(currentPat);
			cout << endl;
		}
		else if (option == 4) {
			if (currentPat != 0) {
				treatment(currentPat);
				if (currentPat->gameIsOver()) {
					currentPat = 0;
				}
			}
			else {
				cout << "No patients currently" << endl;
			}
			cout << endl;
		}
		else if (option == 5) {
			if (currentPat != 0) {
				currentPat->printStats();
			}
			else {
				cout << "No patients currently" << endl;
			}
			cout << endl;
		}
		else if (option == 6) {
			running = false;
		}
	}
	delete currentPat;
	cout << "Goodbye, Dr. " << player << endl;
	return 0;
}