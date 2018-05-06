#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    int amount;
    cout << "要買幾個商品? ";
    cin >> amount;
	
    int product[amount], total;
    cout << "請輸入商品的價錢 (用空格隔開): ";
    for (int i = 0; i < amount; i++) {
        cin >> product[i];
        total+=product[i];
    }
	
    int buying[amount][(int)pow(2, amount)] = {0};
	int manA[(int)pow(2, amount)] = {0}, manB[(int)pow(2, amount)] = {0};
    for (int x = 0; x < amount; x++) {
        int trans = pow(2, x), insert = 1;
        for (int y = 0; y < pow(2, amount-1); y++) {
            if (y % trans == 0) {
                insert = (insert == 0) ? 1 : 0;
            }
            buying[x][y] = insert;
	    	
			if (buying[x][y] == 0) {
	    		manA[y]+=product[x];
			} else {
				manB[y]+=product[x];
			}
			
			cout << buying[x][y] << "/" << manA[y] << "/" << manB[y] << " ";
        }
        cout << endl;
    }
    
    int change = -1;
	int personA[(int)pow(2, amount)], personB[(int)pow(2, amount)];
	int priceA, priceB;
	for (int i = 0; i < pow(2, amount-1); i++) {
		personA[i] = 100-(manA[i] % 100);
		personB[i] = 100-(manB[i] % 100);
		
		if (personA[i] == 100) {
			personA[i] = 0;
		} else if (personB[i] == 100) {
			personB[i] = 0;
		} 
		
		if (personA[i]+personB[i] > change) {
			change = personA[i]+personB[i];
			priceA = manA[i];
			priceB = manB[i];
		}
	}
	
	cout << "最多可以找" << change << "元時->" << endl;
	cout << "甲需要付: " << priceA << "元" << endl;
	cout << "乙需要付: " << priceB << "元" << endl;
	
	return 0;
}
