#include <iostream>
using namespace std;

int atk;
int armor;
int HP;
int XP = 1;
int MP;

int vypis(){
    cout << "Sila = " << atk << "\n";
    cout << "Zivoty = " << HP << "\n";
    cout << "Mana = " << MP << "\n";
    cout << "Armor = " << armor << "\n";
    cout << "Level = " << XP << "\n";
}

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
            HP = 10;
            MP = 20;
            break;
        case 2:
            cout << "Stal se z tebe Rogue!\n";
            atk = 5;
            armor = 2;
            HP = 15;
            MP = 0;
            break;
        case 3:
            cout << "Stal se z tebe Fighter!\n";
            atk = 3;
            armor = 3;
            HP = 20;
            MP = 0;
            break;
        case 4:
            cout << "Stal se z tebe Cleric!\n";
            atk = 1;
            armor = 5;
            HP = 10;
            MP = 20;
            break;
        default:
            cout << "Nesnaž se bejt jinej jo?\n";
            claska = 0;
    }
    }while(claska == 0);
    cout << vypis();
}
