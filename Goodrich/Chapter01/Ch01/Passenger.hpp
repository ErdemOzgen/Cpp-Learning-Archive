enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGETARIAN};

/*********************BEGIN*PASSENGEER*************************************/
class Passenger {
private:
	string 		name;
	MealType	mealPref;
	bool		isFreqFlyer;
	string		freqFlyerNo;
public:
	Passenger();
	Passenger(const string& nm, MealType mp, const string& ffn = "NONE"); 
	Passenger(const Passenger& pass); // copy constructor

	bool isFrequentFlyer() const;
	void makeFrequentFlyer(const string& newFreqFlyerNo);

	void print();

};

// Empty constructor:
Passenger::Passenger() {
	this->name 			= "--NO-NAME--";
	this->mealPref		= NO_PREF;
	this->isFreqFlyer	= false;
	this->freqFlyerNo	= "NONE";
}

// Populated constructor:
Passenger::Passenger(const string& nm, MealType mp, const string& ffn) : 
	name(nm), 
	mealPref(mp), 
	isFreqFlyer(ffn != "NONE"), 
	freqFlyerNo(ffn) {}
/* Passenger::Passenger(const string& nm, MealType mp, const string& ffn) {
	name 		= nm;
	mealPref	= mp;
	isFreqFlyer = (ffn != "NONE");
	freqFlyerNo	= ffn;
} */

// Copy constructor:
Passenger::Passenger (const Passenger& pass) {
	this->name 			= pass.name;
	this->mealPref 		= pass.mealPref;
	this->isFreqFlyer 	= pass.isFreqFlyer;
	this->freqFlyerNo 	= pass.freqFlyerNo;
}

// Functions:
bool Passenger::isFrequentFlyer() const { 
	return isFreqFlyer;
}

void Passenger::makeFrequentFlyer(const string& newFreqFlyerNo) { 
	isFreqFlyer = true;
	freqFlyerNo = newFreqFlyerNo;
}

void Passenger::print () {
	cout << "Name:\t" << this->name;
	cout << "\nMeal: \t" << this->mealPref;
	cout << "\nFreq?:\t" << this->isFreqFlyer;
	cout << "\nFF #: \t" << this->freqFlyerNo;
	cout << endl;
}

/**********************END*PASSENGER****************************************/