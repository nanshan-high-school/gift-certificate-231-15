#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    int amount = 0;
    cout << "�n�R�X�Ӱӫ~? ";
    cin >> amount;
    
    int product[amount] = {0};
    cout << "�п�J�ӫ~������ (�ΪŮ�j�}): ";
    for (int i = 0; i < amount; i++) {
        cin >> product[i];
    }
    
    int buying[amount][(int)pow(2, amount)] = {0};
    int manA[(int)pow(2, amount)] = {0}, manB[(int)pow(2, amount)] = {0};
    int priceA[amount][(int)pow(2, amount)] = {0}, priceB[amount][(int)pow(2, amount)] = {0};
    for (int x = 0; x < amount; x++) {
        int trans = pow(2, x), insert = 1;
        for (int y = 0; y < pow(2, amount-1); y++) {
            if (y % trans == 0) {
                insert = (insert == 0) ? 1 : 0;
            }
            buying[x][y] = insert;
            
            if (buying[x][y] == 0) {
                manA[y]+=product[x];
                priceA[x][y] = product[x];
            } else {
                manB[y]+=product[x];
                priceB[x][y] = product[x];
            }
        }
    }
    
    int change = -1;
    int serialNum = 0;
    for (int i = 0; i < pow(2, amount-1); i++) {
        manA[i] = 100-(manA[i] % 100);
        manB[i] = 100-(manB[i] % 100);
        
        if (manA[i] == 100) {
            manA[i] = 0;
        } else if (manB[i] == 100) {
            manB[i] = 0;
        } 
        
        if (manA[i]+manB[i] > change) {
            change = manA[i]+manB[i];
            serialNum = i;
        }
    }
    
    int totalA = 0, totalB = 0;
    cout << "�̦h�i�H��" << change << "���ɡG" << endl;
    cout << "�һݭn�I: ";
    for (int i = 0; i < amount; i++) {
		if (priceA[i][serialNum] == 0) {
        } else if (i == amount-1 || priceA[i+1][serialNum] == 0) {
            cout << priceA[i][serialNum] << "��=";
        } else {
            cout << priceA[i][serialNum] << "��+";
        }
        totalA+=priceA[i][serialNum];
    }
    cout << totalA << "��" << endl;
    
    cout << "�A�ݭn�I: ";
    for (int i = 0; i < amount; i++) {
		if (priceB[i][serialNum] == 0) {
        } else if (i == amount-1 || priceB[i+1][serialNum] == 0) {
            cout << priceB[i][serialNum] << "��=";
        } else {
            cout << priceB[i][serialNum] << "��+";
        }
        totalB+=priceB[i][serialNum];
    }
    cout << totalB << "��";
    
    return 0;
}
