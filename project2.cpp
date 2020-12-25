#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Cheese type: "; // cheese type input
    string typeCheese;
    getline(cin, typeCheese);
    
    if (typeCheese == "") { // checks for empty string
        cout << "---" << endl;
        cout << "You must enter a cheese type" << endl;
        return 1;
    }
    
    cout << "Value: "; // value input
    double initialValue;
    cin >> initialValue;
    cin.ignore(10000, '\n');
    
    if (initialValue <= 0) { // checks value greater than zero
        cout << "---" << endl;
        cout << "The value must be positive" << endl;
        return 1;
    }
    
    cout << "Importer: "; // importer input
    string cheeseImporter;
    getline(cin, cheeseImporter);
    
    if (cheeseImporter == "") { // checks for empty string
        cout << "---" << endl;
        cout << "You must enter an importer" << endl;
        return 1;
    }
    
    double finalValue;
    double maxValue; // amount that exceeds 13000
    
    // checks if value greater than 1000. if yes, checks if greater than 13000
    if (initialValue > 1000) {
            if (initialValue > 13000) {
                if (typeCheese == "cheshire" || typeCheese == "stilton") { // calculates if greater than 13000
                    maxValue = initialValue - 13000;
                    finalValue = (maxValue * 0.029) + ((initialValue - 1000 - maxValue) * 0.014) + 11; // 11 is value of first $1000
                }
                else {
                    maxValue = initialValue - 13000;
                    finalValue = (maxValue * 0.029) + ((initialValue - 1000 - maxValue) * 0.02) + 11;
                }
            }
            else { // calculates if value greater than 1000 but less than 13000
                if (typeCheese == "cheshire" || typeCheese == "stilton") {
                    finalValue = ((initialValue - 1000) * 0.014) + 11;
                }
                else {
                    finalValue = ((initialValue - 1000) * 0.02) + 11;
            }
        }
    }
    else { // calculates final value if input not greater than 1000
        finalValue = initialValue * 0.011;
    }
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "---" << endl;
    cout << "The import duty for " << cheeseImporter << " is $" << finalValue << endl;
}



