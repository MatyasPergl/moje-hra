
#include <iostream>
using namespace std;

int atk;
int armor;
int HP;
int MAXHP;
int XP = 1;
int MAXMP;
int MP;
int claska;
int pocetheal;
int pocetmana;
int gold = 20;
int heal_potak = 2;
int mana_potak = 2;
int stit_potak = 2;
int pozice = 0;
bool stit1 = false;
void rozcestnik();
int zamereni;

void pomoc(){
	cout << "pomoc = vypise vsechny prikazy\n";
	cout << "vypis = vypise tvoje statistiky\n";
	cout << "utoky = vypise tvoje utoky\n";
	cout << "batoh = vypise predmety co mas u sebe\n";
}

void vypis(){
    cout << "Sila = " << atk << "\n";
    cout << "Zivoty = " << HP << "\n";
    cout << "Mana = " << MP << "\n";
    cout << "Armor = " << armor << "\n";
    cout << "Level = " << XP << "\n";
}

void utoky(){
	switch (claska){
		case 1:
            cout << "Si Mage a tvoje utoky jsou:\n";
			cout << "Fireball = velke poskozeni na vsechny nepratele (10 mana cost)\n";
            cout << "Stit = vyblokuje plne jeden utok nepritele (4 mana cost)\n";
			break;
		case 2:
            cout << "Si Rogue a tvoje utoky jsou:\n";
			cout << "Backstab = velke poskozeni na jednoho nepritele (0 mana cost)\n";
			break;
		case 3:
		    cout << "Si Fighter a nemas specialni utoky :c\n";
			break;
		case 4:
            cout << "Si Cleric a tvoje utoky jsou:\n";
			cout << "Heal = vylecis si trochu zivotu (4 mana cost)\n";
			break;
    cout << "Take muzes pouzit nejake z potionu jestli mas\n";
    cout << "Heal_potion = pouzij aby sis vylecil trochu zivot(" << heal_potak << " mas u sebe)\n";
    cout << "Stit_potion = pouzij aby sis nahodil stit(" << stit_potak << " mas u sebe)\n";
    cout << "Mana_potion = pouzij aby sis doplnil trochu many(" << mana_potak << "  mas u sebe)\n";
    cout << "A take samozrejme muzes pouzit standartni utok\nUtok = uhodis nepritele za " << atk << " damage (meni se na zaklade tve sily)";
	}
}

void batoh() {
    cout << "Tvuj batoh obsahuje:\n";
    cout << "Zlato: " << gold << "\n";
    cout << "Heal potion: " << heal_potak << "\n";
    cout << "Shield potion: " << stit_potak << "\n";
    cout << "Mana potion: " << mana_potak << "\n";
}

void heal_potion(){
    if (heal_potak < 1){
    cout << "nemas potky troubo";
    return;
    }
    else {
        heal_potak -= 1;
    pocetheal = MAXHP - HP;
    cout << "vylecil si se o " << pocetheal/2 << " zivotu";
    HP = HP + pocetheal/2;
    }
}

void stit_potion(){
    if (stit1 = true){
    cout << "uz mas stit troubo";
    return;
    }
    else if (mana_potak < 1) {
    cout << "nemas dostatek many troubo";
    return;
    }
    else {
        mana_potak -= 1;
    cout << "Zapnul si stit\n";
    stit1 = true;
    }
}

void mana_potion(){
    if (mana_potak < 1){
    cout << "nemas potky troubo";
    return;
    }
    else {
        mana_potak -= 1;
    pocetmana = MAXMP - MP;
    cout << "doplnil sis " << pocetmana/2 << " many";
    MP = MP + pocetmana/2;
    }
}

void utok(){

}

void fireball(){

}

void stit(){
    if (stit1 = true){
    cout << "uz mas stit troubo";
    return;
    }
    else if (MP < 4) {
    cout << "nemas dostatek many troubo";
    return;
    }
    else {
        MP -= 4;
    }
    cout << "Zapnul si stit\n";
    stit1 = true;
}

void backstab(){

}

void heal(){
    if (MP < 4){
    cout << "nemas dostatek many troubo";
    return;
    }
    else {
        MP -= 4;
    pocetheal = MAXHP - HP;
    cout << "vylecil si se o " << pocetheal/2 << " zivotu";
    HP = HP + pocetheal/2;
    }
}

void lvlup(){
XP++;
atk = atk + 1;
armor = armor + 1;
MAXHP = MAXHP + 2;
HP = HP + 2;
MAXMP = MAXMP * 2;
}

void vesnice(){
int volba;
    cout << "Vitej ve skibidi vesnici\n";

do {
    cout << "\nCo chces delat?\n";
    cout << "1 - Koupit heal potion (5 zlata)\n";
    cout << "2 - Koupit shield potion (8 zlata)\n";
    cout << "3 - Koupit mana potion (4 zlata)\n";
    cout << "4 - Zobrazit batoh\n";
    cout << "5 - Odejit z vesnice\n";
cin >> volba;
switch (volba) {
    case 1:
        if (gold >= 5) {
            gold -= 5;
            heal_potak++;
            cout << "Koupil jsi heal potion\n";
        } else {
            cout << "Nemas dost zlata\n";
        }
        break;
    case 2:
        if (gold >= 8) {
            gold -= 8;
            stit_potak++;
            cout << "Koupil jsi shield potion\n";
        } else {
            cout << "Nemas dost zlata\n";
        }
    case 3:
        if (gold >= 4) {
            gold -= 4;
            mana_potak++;
            cout << "Koupil jsi mana potion\n";
        } else {
            cout << "Nemas dost zlata\n";
        }
        break;
    case 4:
        batoh();
        break;
    case 5:
        cout << "Opoustis vesnici...\n";
        pozice++;
        rozcestnik();
        break;
    default:
        cout << "Nesnaz se bejt jinej jo?\n";
        }
    }while(volba != 5);
}

void monstrum(){
int HPenemaka1 = 2 + XP * 4;
int atkenemaka1 = XP * 2;
int armorenemaka1 = XP;
bool zivy1 = true;
cout << "Stoji pred tebou nepritel\n";
cout << "Divas se na jeho zbroj a vidis ze ma tak " << HPenemaka1 << " HP a tak " << atkenemaka1 << " damage\n";
do{
if (HP <= 0){
    cout << "chicpls bracho je to jover";
    return 0;
} else {
cout << "Vyber si jak chces na nej zautocit";
utoky();

poskozenienemaka = atkenemaka1 - armor;
if (poskozeni enemaka <= 0) {
    poskozeni enemaka = 0;
}
if (stit1 = true){
    cout << "nepritel se po tobe ohnal ale vsechen damage vzal tvuj stit";
    stit1 = false;
} else {
HP = HP - poskozeni enemaka;
cout << "Vrhne se na tebe a uderi te za " << poskozeni enemaka << " damage AU!\n";
}
}
}while(zivy1=true);
gold = gold + 15 + XP * 10;
cout << "Vylootil si vsechen loot a nasel si zlato a vybaveni o cenne " << 15 + XP * 10 << " mas tedy celkove " << gold << " zlata\n";
lvlup();
cout << "Jsi nyní level "<< XP << " GJ bro\n";
pozice++;
rozcestnik();
}

void dvamonstrum(){
int HPenemaka1 = 2 + XP * 4;
int atkenemaka1 = XP * 2;
bool zivy1 = true;
int HPenemaka2 = 2 + XP * 2;
int atkenemaka2 = XP;
bool zivy2 = true;
}

void trimonstrum(){
int HPenemaka1 = 2 + XP * 2;
int atkenemaka1 = XP;
bool zivy1 = true;
int HPenemaka2 = 2 + XP * 2;
int atkenemaka2 = XP;
bool zivy2 = true;
int HPenemaka3 = 2 + XP * 2;
int atkenemaka3 = XP;
bool zivy3 = true;
}

void miniboss(){

}

void druhejminiboss(){

}

void Glacithorn(){

}

void rozcestnik(){
    switch (pozice){
    case 0:
    case 5:
    case 10:
    case 14:
        vesnice();
        break;
    case 1:
    case 2:
    case 6:
        monstrum();
        break;
    case 3:
    case 7:
    case 8:
    case 11:
    case 12:
        dvamonstrum();
        break;
    case 13:
        trimonstrum();
        break;
    case 4:
        miniboss();
            break;
    case 9:
        druhejminiboss();
            break;
    case 15:
        Glacithorn();
            break;
        default:
        cout << "Vyhral si hru (asi) blahopreju si GOAT";
    }
}


int main(){
    int claska;
    cout << "Vitej v skibidi svete" << endl;
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
            MAXMP = 50;
            MP = 50;
            break;
        case 2:
            cout << "Stal se z tebe Rogue!\n";
            atk = 5;
            armor = 2;
			MAXHP = 15;
            HP = 15;
            MAXMP = 0;
            MP = 0;
            break;
        case 3:
            cout << "Stal se z tebe Fighter!\n";
            atk = 3;
            armor = 3;
			MAXHP = 20;
            HP = 20;
            MAXMP = 0;
            MP = 0;
            break;
        case 4:
            cout << "Stal se z tebe Cleric!\n";
            atk = 1;
            armor = 5;
			MAXHP = 10;
            HP = 10;
            MAXMP = 20;
            MP = 20;
            break;
        default:
            cout << "Nesnaz se bejt jinej jo?\n";
            claska = 0;
    }
    }while(claska == 0);
	rozcestnik();
}
