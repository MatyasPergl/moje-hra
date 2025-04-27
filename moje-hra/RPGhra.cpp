#include <iostream>
using namespace std;

int atk;
int armor;
int HP;
int MAXHP;
int XP = 1;
int MP;

void pomoc(){
	cout << "pomoc = vypise vsechny prikazy" << "\n";
	cout << "vypis = vypise tvoje statistiky" << "\n";
	cout << "boj = vypise tvoje utoky" << "\n";
	cout << "pruzkum = posunes se dal v pribehu" << "\n";
	cout << "batoh = vypise predmety co mas u sebe" << "\n";
}

void vypis(){
    cout << "Sila = " << atk << "\n";
    cout << "Zivoty = " << HP << "\n";
    cout << "Mana = " << MP << "\n";
    cout << "Armor = " << armor << "\n";
    cout << "Level = " << XP << "\n";
}

void boj(){
	switch (claska){
		case 1:
            cout << "Si Mage a tvoje utoky jsou:\n";
			cout << "Fireball = velke poskozeni na vsechny nepratele \n";
            cout << "Stit = vyblokuje plne jeden utok nepritele \n";
			break;
		case 2:
            cout << "Si Rogue a tvoje utoky jsou:\n";
			cout << "Backstab = velke poskozeni na jednoho nepritele \n";
			break;
		case 3:
		    cout << "Si Fighter a nemas specialni utoky :c\n";
			break;
		case 4:
            cout << "Si Cleric a tvoje utoky jsou:\n";
			cout << "Heal = vylecis si trochu zivotu \n";
			break;
	}
}

// fakt nevim jak udelam inventarovej system :sob: ale verim si sem sigma
// HB Glacithorn
int main(){
    int claska;
    cout << "Vytej v skibidi svete" << endl;
    do {
    cout << "Vyber si class" << endl;
    cout << "1 = Mage \nPestra paleta utoku omezena manou \n2 = Rogue \nVelky damage za cenu maleho poctu zivotu \n3 = Fighter \nStatisticky silna ale nespecialni class \n4 = Cleric \nVysoky armor a leceni jinak dost slaba postava\n";
    cin >> claska;
    switch (claska){
        case 1:
            cout << "Stal se z tebe Mage!\n";
            atk = 3;
            armor = 1;
			MAXHP = 10;
            HP = 10;
            MP = 20;
            break;
        case 2:
            cout << "Stal se z tebe Rogue!\n";
            atk = 5;
            armor = 2;
			MAXHP = 15;
            HP = 15;
            MP = 0;
            break;
        case 3:
            cout << "Stal se z tebe Fighter!\n";
            atk = 3;
            armor = 3;
			MAXHP = 20
            HP = 20;
            MP = 0;
            break;
        case 4:
            cout << "Stal se z tebe Cleric!\n";
            atk = 1;
            armor = 5;
			MAXHP = 10;
            HP = 10;
            MP = 20;
            break;
        default:
            cout << "Nesnaž se bejt jinej jo?\n";
            claska = 0;
    }
    }while(claska == 0);
	pomoc();
}
