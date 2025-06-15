
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
int endlessobtiznost = 5;
int vyberutoku;
int vyberenemakaint;
int HPenemaka1;
int atkenemaka1;
int armorenemaka1;
int poskozenienemaka;
int HPenemaka2;
int atkenemaka2;
int armorenemaka2;
int HPenemaka3;
int atkenemaka3;
int armorenemaka3;

int konec() {
return 0;
}

void vypis(){
    cout << "Sila = " << atk << "\n";
    cout << "Zivoty = " << HP << "\n";
    cout << "Mana = " << MP << "\n";
    cout << "Armor = " << armor << "\n";
    cout << "Level = " << XP << "\n";
}

void utoky(){
    cout << "Vyber si utok\n";
    cout << "1 = uhodis nepritele za " << atk << " damage (meni se na zaklade tve sily)\n";
	switch (claska){
		case 1:
			cout << "2 = poskozeni na vsechny nepratele (10 mana cost)\n";
            cout << "3 = vyblokuje plne jeden utok nepritele (4 mana cost)\n";
			break;
		case 2:
			cout << "2 = uhodis nepritele za " << atk * 2 << " damage (0 mana cost)\n";
			break;
		case 3:
		    cout << "Si Fighter a nemas specialni utoky :c\n";
			break;
		case 4:
			cout << "2 = vylecis si trochu zivotu (4 mana cost)\n";
			break;
}
    cout << "Take muzes pouzit nejake z potionu jestli mas\n";
    cout << "4 = pouzij aby sis vylecil trochu zivot(" << heal_potak << " mas u sebe)\n";
    cout << "5 = pouzij aby sis nahodil stit(" << stit_potak << " mas u sebe)\n";
    cout << "6 = pouzij aby sis doplnil trochu many(" << mana_potak << " mas u sebe)\n";
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
    cout << "nemas potky troubo\n";
    }
    else {
        heal_potak = heal_potak - 1;
    pocetheal = MAXHP - HP;
    cout << "vylecil si se o " << pocetheal/2 << " zivotu\n";
    HP = HP + pocetheal/2;
    }
}

void stit_potion(){
    if (stit1 == true){
    cout << "uz mas stit troubo\n";
    }
    else if (stit_potak < 1) {
    cout << "nemas dostatek many troubo\n";
    return;
    }
    else {
        stit_potak = stit_potak - 1;
    cout << "Zapnul si stit\n";
    stit1 = true;
    }
}

void mana_potion(){
    if (mana_potak < 1){
    cout << "nemas potky troubo\n";
    }
    else {
        mana_potak = mana_potak - 1;
    pocetmana = MAXMP - MP;
    cout << "doplnil sis " << pocetmana/2 << " many\n";
    MP = MP + pocetmana/2;
    }
}

void utok1(){
HPenemaka1 = HPenemaka1 - (atk - armorenemaka1);
}

void utok2(){
HPenemaka2 = HPenemaka2 - (atk - armorenemaka2);
}

void utok3(){
HPenemaka3 = HPenemaka3 - (atk - armorenemaka3);
}

void fireball(){
HPenemaka1 = HPenemaka1 - (atk - armorenemaka1);
HPenemaka2 = HPenemaka2 - (atk - armorenemaka2);
HPenemaka3 = HPenemaka3 - (atk - armorenemaka3);
}

void stit(){
    if (stit1 == true){
    cout << "uz mas stit troubo\n";
    return;
    }
    else if (MP < 4) {
    cout << "nemas dostatek many troubo\n";
    return;
    }
    else {
        MP -= 4;
    }
    cout << "Zapnul si stit\n";
    stit1 = true;
}

void backstab1(){
HPenemaka1 = HPenemaka1 - (atk - armorenemaka1) * 2;
}

void backstab2(){
HPenemaka2 = HPenemaka2 - (atk - armorenemaka2) * 2;
}

void backstab3(){
HPenemaka3 = HPenemaka3 - (atk - armorenemaka3) * 2;
}

void heal(){
    if (MP < 4){
    cout << "nemas dostatek many troubo\n";
    return;
    }
    else {
        MP -= 4;
    pocetheal = MAXHP - HP;
    cout << "vylecil si se o " << pocetheal/2 << " zivotu\n";
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

void vyberenemaka(){
    switch (pozice){
    case 3:
    case 7:
    case 8:
    case 11:
    case 12:
        vyberenemakaint = 2;
        break;
    case 13:
        vyberenemakaint = 3;
        break;
    }
}

void boj(){
    cin >> vyberutoku;
    switch(vyberenemakaint){
    case 1:
        switch(vyberutoku){
        case 1:
            utok1();
            break;
        case 2:
            switch(claska){
                case 1:
                    fireball();
                    break;
                case 2:
                    backstab1();
                    break;
                case 4:
                    heal();
                    break;
            }
        case 3:
            switch(claska){
                case 1:
                    stit();
                    break;
            }
            break;
        case 4:
            heal_potion();
            break;
        case 5:
            stit_potion();
            break;
        case 6:
            mana_potion();
            break;
        }
        break;
    case 2:
        switch(vyberutoku){
        case 1:
            utok2();
            break;
        case 2:
            switch(claska){
                case 1:
                    fireball();
                    break;
                case 2:
                    backstab2();
                    break;
                case 4:
                    heal();
                    break;
            }
        case 3:
            switch(claska){
                case 1:
                    stit();
                    break;
            }
            break;
        case 4:
            heal_potion();
            break;
        case 5:
            stit_potion();
            break;
        case 6:
            mana_potion();
            break;
        }
        break;
    case 3:
        switch(vyberutoku){
        case 1:
            utok3();
            break;
        case 2:
            switch(claska){
                case 1:
                    fireball();
                    break;
                case 2:
                    backstab3();
                    break;
                case 4:
                    heal();
                    break;
            }
        case 3:
            switch(claska){
                case 1:
                    stit();
                    break;
            }
            break;
        case 4:
            heal_potion();
            break;
        case 5:
            stit_potion();
            break;
        case 6:
            mana_potion();
            break;
        }
        break;
    }
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
HPenemaka1 = 2 + XP * 4;
atkenemaka1 = XP * 2;
armorenemaka1 = XP - 1;
cout << "Stoji pred tebou nepritel\n";
cout << "Divas se na jeho zbroj a vidis ze ma tak " << HPenemaka1 << " HP a tak " << atkenemaka1 << " damage\n";
do{
if (HP <= 0){
    cout << "chcipls bracho je to jover\n";
    konec();
} else {
vyberenemakaint = 1;
utoky();
boj();
cout << "tvuj nepritel ma nyni " << HPenemaka1 << " zivotu\n";
poskozenienemaka = atkenemaka1 - armor;
if (poskozenienemaka <= 0) {
    poskozenienemaka = 0;
}
if (stit1 == true){
    cout << "nepritel se po tobe ohnal ale vsechen damage vzal tvuj stit\n";
    stit1 = false;
} else {
HP = HP - poskozenienemaka;
cout << "Vrhne se na tebe a uderi te za " << poskozenienemaka << " damage AU!\n";
cout << "mas nyni " << HP << " zivotu\n";
}
}
}while(HPenemaka1 > 0);
gold = gold + 15 + XP * 10;
cout << "Vylootil si vsechen loot a nasel si zlato a vybaveni o cenne " << 15 + XP * 10 << " mas tedy celkove " << gold << " zlata\n";
lvlup();
cout << "Jsi nyni level " << XP << " GJ bro\n";
pozice++;
rozcestnik();
}

void dvamonstrum(){
HPenemaka1 = 2 + XP * 4;
atkenemaka1 = XP * 2;
armorenemaka1 = XP - 1;
HPenemaka2 = 2 + XP * 2;
atkenemaka2 = XP;
armorenemaka2 = XP - 3;
cout << "Stoji pred tebou dva nepratele jeden silnejsi a jeden slabsi\n";
cout << "Divas se tak na ne a vidis ze ma silnejsi tak " << HPenemaka1 << " HP a tak " << atkenemaka1 << " damage a ten slabsi tak " << HPenemaka2 << " HP a tak " << atkenemaka2 << " damage \n";
do{
if (HP <= 0){
    cout << "chcipls bracho je to jover\n";
    konec();
} else {
cout << "vyber na koho chces utocit\n1 = silnejsi\n2 = slabsi\n";
cin >> vyberenemakaint;
utoky();
boj();
cout << "tvuj silnejsi nepritel ma nyni " << HPenemaka1 << " zivotu\n";
cout << "tvuj slabsi nepritel ma nyni " << HPenemaka2 << " zivotu\n";
poskozenienemaka = (atkenemaka1 - armor) + (atkenemaka2 - armor);
if (poskozenienemaka <= 0) {
    poskozenienemaka = 0;
}
if (stit1 == true){
    cout << "nepritele se po tobe ohnali ale vsechen damage vzal tvuj stit\n";
    stit1 = false;
} else {
HP = HP - poskozenienemaka;
cout << "Vrhnou se na tebe a uderi te za " << poskozenienemaka << " damage AU!\n";
cout << "mas nyni " << HP << " zivotu\n";
}
}
}while(HPenemaka1 > 0 || HPenemaka2 > 0);
gold = gold + 15 + XP * 10;
cout << "Vylootil si vsechen loot a nasel si zlato a vybaveni o cenne " << 15 + XP * 10 << " mas tedy celkove " << gold << " zlata\n";
lvlup();
cout << "Jsi nyni level " << XP << " GJ bro\n";
pozice++;
rozcestnik();
}

void trimonstrum(){
HPenemaka1 = 2 + XP * 3;
atkenemaka1 = XP * 2;
armorenemaka1 = XP - 1;
HPenemaka2 = 2 + XP * 2;
atkenemaka2 = XP;
armorenemaka2 = XP - 3;
HPenemaka3 = 2 + XP * 2;
atkenemaka3 = XP;
armorenemaka3 = XP - 5;
cout << "Stoji pred tebou 3 nepratele vsichni jsou to docela paratka ale proste je to ciganska ferovka no\n";
cout << "Divas se tak na ne a vidis ze ma jeden ma tak " << HPenemaka1 << " HP a tak " << atkenemaka1 << " damage, druhej tak " << HPenemaka2 << " HP a tak " << atkenemaka2 << " damage a treti " << HPenemaka3 << " HP a tak " << atkenemaka3 << " damage\n";
do{
if (HP <= 0){
    cout << "chcipls bracho je to jover\n";
    konec();
} else {
cout << "vyber na koho chces utocit\n1 = silnejsi\n2 = slabsi\n";
cin >> vyberenemakaint;
utoky();
boj();
cout << "tvuj prvni nepritel ma nyni " << HPenemaka1 << " zivotu\n";
cout << "tvuj druhej nepritel ma nyni " << HPenemaka2 << " zivotu\n";
cout << "tvuj treti nepritel ma nyni " << HPenemaka3 << " zivotu\n";
poskozenienemaka = (atkenemaka1 - armor) + (atkenemaka2 - armor) + (atkenemaka3 - armor);
if (poskozenienemaka <= 0) {
    poskozenienemaka = 0;
}
if (stit1 == true){
    cout << "nepritele se po tobe ohnali ale vsechen damage vzal tvuj stit\n";
    stit1 = false;
} else {
HP = HP - poskozenienemaka;
cout << "Vrhnou se na tebe a uderi te za " << poskozenienemaka << " damage AU!\n";
cout << "mas nyni " << HP << " zivotu\n";
}
}
}while(HPenemaka1 > 0 || HPenemaka2 > 0 || HPenemaka3 > 0);
gold = gold + 15 + XP * 10;
cout << "Vylootil si vsechen loot a nasel si zlato a vybaveni o cenne " << 15 + XP * 10 << " mas tedy celkove " << gold << " zlata\n";
lvlup();
cout << "Jsi nyni level " << XP << " GJ bro\n";
pozice++;
rozcestnik();
}

void miniboss(){
HPenemaka1 = 2 + XP * 12;
atkenemaka1 = XP * 3;
armorenemaka1 = XP - 1;
cout << "Stoji pred tebou super nepritel\n";
cout << "Divas se na jeho zbroj a vidis ze ma tak " << HPenemaka1 << " HP a tak " << atkenemaka1 << " damage\n";
do{
if (HP <= 0){
    cout << "chcipls bracho je to jover\n";
    konec();
} else {
vyberenemakaint = 1;
utoky();
boj();
cout << "tvuj nepritel ma nyni " << HPenemaka1 << " zivotu\n";
poskozenienemaka = atkenemaka1 - armor;
if (poskozenienemaka <= 0) {
    poskozenienemaka = 0;
}
if (stit1 == true){
    cout << "nepritel se po tobe ohnal ale vsechen damage vzal tvuj stit\n";
    stit1 = false;
} else {
HP = HP - poskozenienemaka;
cout << "Vrhne se na tebe a uderi te za " << poskozenienemaka << " damage AU!\n";
cout << "mas nyni " << HP << " zivotu\n";
}
}
}while(HPenemaka1 >= 0);
gold = gold + 15 + XP * 10;
cout << "Vylootil si vsechen loot a nasel si zlato a vybaveni o cenne " << 15 + XP * 10 << " mas tedy celkove " << gold << " zlata\n";
lvlup();
cout << "Jsi nyni level " << XP << " GJ bro\n";
pozice++;
rozcestnik();
}

void druhejminiboss(){
HPenemaka1 = 2 + XP * 24;
atkenemaka1 = XP * 1;
armorenemaka1 = XP - 1;
cout << "Stoji pred tebou enemak jako skala jakoze je fakt doslova z kamene xd\n";
cout << "Divas se na jeho zbroj a vidis ze ma tak " << HPenemaka1 << " HP a tak " << atkenemaka1 << " damage\n";
do{
if (HP <= 0){
    cout << "chcipls bracho je to jover\n";
    konec();
} else {
vyberenemakaint = 1;
utoky();
boj();
cout << "tvuj nepritel ma nyni " << HPenemaka1 << " zivotu\n";
poskozenienemaka = atkenemaka1 - armor;
if (poskozenienemaka <= 0) {
    poskozenienemaka = 0;
}
if (stit1 == true){
    cout << "nepritel se po tobe ohnal ale vsechen damage vzal tvuj stit\n";
    stit1 = false;
} else {
HP = HP - poskozenienemaka;
cout << "Vrhne se na tebe a uderi te za " << poskozenienemaka << " damage AU!\n";
cout << "mas nyni " << HP << " zivotu\n";
}
}
}while(HPenemaka1 >= 0);
gold = gold + 15 + XP * 10;
cout << "Vylootil si vsechen loot a nasel si zlato a vybaveni o cenne " << 15 + XP * 10 << " mas tedy celkove " << gold << " zlata\n";
lvlup();
cout << "Jsi nyni level " << XP << " GJ bro\n";
pozice++;
rozcestnik();
}

void Glacithorn(){

}

void endless(){
HPenemaka1 = 2 + XP * 12;
atkenemaka1 = XP * 3;
armorenemaka1 = XP - 1;
cout << "Stoji pred tebou nepritel\n";
cout << "Divas se na jeho zbroj a vidis ze ma tak " << HPenemaka1 << " HP a tak " << atkenemaka1 << " damage\n";
do{
if (HP <= 0){
    cout << "chcipls bracho je to jover\n";
    konec();
} else {
vyberenemakaint = 1;
utoky();
boj();
cout << "tvuj nepritel ma nyni " << HPenemaka1 << " zivotu\n";
poskozenienemaka = atkenemaka1 - armor;
if (poskozenienemaka <= 0) {
    poskozenienemaka = 0;
}
if (stit1 == true){
    cout << "nepritel se po tobe ohnal ale vsechen damage vzal tvuj stit\n";
    stit1 = false;
} else {
HP = HP - poskozenienemaka;
cout << "Vrhne se na tebe a uderi te za " << poskozenienemaka << " damage AU!\n";
cout << "mas nyni " << HP << " zivotu\n";
}
}
}while(HPenemaka1 >= 0);
gold = gold + 15 + XP * 10;
cout << "Vylootil si vsechen loot a nasel si zlato a vybaveni o cenne " << 15 + XP * 10 << " mas tedy celkove " << gold << " zlata\n";
lvlup();
cout << "Jsi nyni level " << XP << " GJ bro\n";
endlessobtiznost++;
rozcestnik();
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
    case 16:
        endless();
        break;
        default:
        cout << "Vyhral si hru (asi) blahopreju si GOAT\n";
        konec();
    }
}

int main(){
    cout << "Vitej v skibidi svete\n;
    do {
    cout << "Vyber si class\n;
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
            armor = 1;
			MAXHP = 15;
            HP = 15;
            MAXMP = 0;
            MP = 0;
            break;
        case 3:
            cout << "Stal se z tebe Fighter!\n";
            atk = 3;
            armor = 2;
			MAXHP = 20;
            HP = 20;
            MAXMP = 0;
            MP = 0;
            break;
        case 4:
            cout << "Stal se z tebe Cleric!\n";
            atk = 1;
            armor = 3;
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
