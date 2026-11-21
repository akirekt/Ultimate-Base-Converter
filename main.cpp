#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <limits>
#include <algorithm>

using namespace std;

int main() {

    bool codeEnded = false;

    while (true) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif   

        string numbersystem;
        string Base2 = "", Base4 = "", Base8 = "", Base16 = "";
        int Base10 = 0;

        while (true) {
            
            while (true) {
                cout << "Enter the number system you want to convert from [2/4/8/10/16] ";
                getline(cin, numbersystem);
                cout << endl;
                
                if (numbersystem == "exit") {
                    return 0;
                } else if (numbersystem == "2" || numbersystem == "4" || numbersystem == "8" || numbersystem == "10" || numbersystem == "16") {
                    break;
                }

                cout << "!!Wrong system!!\n" << endl;
            }

            if (numbersystem == "2") {
                while (true) {
                    cout << "Enter number in base2: ";
                    getline(cin, Base2);
                    cout << endl;
                    
                    if (Base2.find_first_not_of("01") != string::npos) {
                        cout << "DO NOT PUT others chars than 0 or 1!!!\n" << endl;
                    } else if (Base2.empty()) {
                        cout << "Base2 number cannot be empty!\n" << endl;
                    } else {
                        break;
                    }
                }
            } else if (numbersystem == "4") {
                while (true) {
                    cout << "Enter number in base4: ";
                    getline(cin, Base4);
                    cout << endl;
                    
                    if (Base4.find_first_not_of("0123") != string::npos) {
                        cout << "DO NOT PUT others chars than 0, 1, 2, 3!!!\n" << endl;
                    } else if (Base4.empty()) {
                        cout << "Base4 number cannot be empty!\n" << endl;
                    } else {
                        break;
                    }
                }
            } else if (numbersystem == "8") {
                while (true) {
                    cout << "Enter number in base8: ";
                    getline(cin, Base8);
                    cout << endl;
                    
                    if (Base8.find_first_not_of("01234567") != string::npos) {
                        cout << "DO NOT PUT others chars than 0, 1, 2, 3, 4, 5 ,6 or 7!!!\n" << endl;
                    }  else {
                        break;
                    }
                }
            } else if (numbersystem == "10") {
                string input;

                while (true) {
                    cout << "Enter number in base10: ";
                    getline(cin, input);

                    if (input.empty()) {
                        cout << "Base10 number cannot be empty!\n\n";
                        continue;
                    }

                    try {
                        Base10 = stoi(input);
                        break;
                    } catch (...) {
                        cout << "Enter a valid number!\n\n";
                    }
                }
            } else if (numbersystem == "16") {
                while (true) {
                    cout << "Enter number in base16: ";
                    getline(cin, Base16);
                    cout << endl;
                    
                    if (Base16.find_first_not_of("0123456789ABCDEFabcdef") != string::npos) {
                        cout << "DO NOT PUT others chars than 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E or F!!!\n" << endl;
                    } else if (Base16.empty()) {
                        cout << "Base16 number cannot be empty!\n" << endl;
                    } else {
                        break;
                    }
                }
            }

            break;

        }

        if(numbersystem == "2") {
            if (all_of(Base2.begin(), Base2.end(), [](char c) {
                return c == '0';
            })) {
                cout << "Your number in: \n";
                cout << "Base2 --> 0\n";
                cout << "Base4 --> 0\n";
                cout << "Base8 --> 0\n";
                cout << "Base10 -> 0\n";
                cout << "Base16 -> 0\n";

                codeEnded = true;
            }
        } else if (numbersystem == "4") {
            if (all_of(Base4.begin(), Base4.end(), [](char c) {
                return c == '0';
            })) {
                cout << "Your number in: \n";
                cout << "Base2 --> 0\n";
                cout << "Base4 --> 0\n";
                cout << "Base8 --> 0\n";
                cout << "Base10 -> 0\n";
                cout << "Base16 -> 0\n";

                codeEnded = true;
            }
        } else if (numbersystem == "8") {
            if (all_of(Base8.begin(), Base8.end(), [](char c) {
                return c == '0';
            })) {
                cout << "Your number in: \n";
                cout << "Base2 --> 0\n";
                cout << "Base4 --> 0\n";
                cout << "Base8 --> 0\n";
                cout << "Base10 -> 0\n";
                cout << "Base16 -> 0\n";

                codeEnded = true;
            }
        } else if (numbersystem == "10") {
            if (Base10 == 0) {
                cout << "Your number in: \n";
                cout << "Base2 --> 0\n";
                cout << "Base4 --> 0\n";
                cout << "Base8 --> 0\n";
                cout << "Base10 -> 0\n";
                cout << "Base16 -> 0\n";

                codeEnded = true;
            }
        } else if (numbersystem == "16") {
            if (all_of(Base16.begin(), Base16.end(), [](char c) {
                return c == '0';
            })) {
                cout << "Your number in: \n";
                cout << "Base2 --> 0\n";
                cout << "Base4 --> 0\n";
                cout << "Base8 --> 0\n";
                cout << "Base10 -> 0\n";
                cout << "Base16 -> 0\n";
                
                codeEnded = true;
            }
        }

        if (!codeEnded) {
            if (numbersystem == "2") {

                cout << "Your number in:\n";
                cout << "Base2 --> " << Base2 << "\n";

                int length = Base2.length();

                // To base4
                if (length % 2 != 0) {
                    Base2 = "0" + Base2;
                    length++;
                }

                for (int i = 0; i < length; i += 2) {
                    string bits = Base2.substr(i, 2);

                    if (bits == "00") {
                        Base4 += "0";
                    } else if (bits == "01") {
                        Base4 += "1";
                    } else if (bits == "10") {
                        Base4 += "2";
                    } else if (bits == "11") {
                        Base4 += "3";
                    }
                }

                // To base8
                while(length % 3 != 0) {
                    Base2 = "0" + Base2;
                    length++;
                }

                for (int i = 0; i < length; i += 3) {
                    string bits = Base2.substr(i, 3);

                    if (bits == "000") {
                        Base8 += "0";
                    } else if (bits == "001") {
                        Base8 += "1";
                    } else if (bits == "010") {
                        Base8 += "2";
                    } else if (bits == "011") {
                        Base8 += "3";
                    } else if (bits == "100") {
                        Base8 += "4";
                    } else if (bits == "101") {
                        Base8 += "5";
                    } else if (bits == "110") {
                        Base8 += "6";
                    } else if (bits == "111") {
                        Base8 += "7";
                    }
                }

                // To base10
                int temp = 0;

                for(int i = length; i > 0; i--) {
                    Base10 += (Base2[i - 1] - '0') * pow(2, temp);
                    temp++;
                }


                // To base 16
                while(length % 4 != 0) {
                    Base2 = "0" + Base2;
                    length++;
                }

                for (int i = 0; i < length; i += 4) {
                    string bits = Base2.substr(i, 4);

                    if (bits == "0000") {
                        Base16 += "0";
                    } else if (bits == "0001") {
                        Base16 += "1";
                    } else if (bits == "0010") {
                        Base16 += "2";
                    } else if (bits == "0011") {
                        Base16 += "3";
                    } else if (bits == "0100") {
                        Base16 += "4";
                    } else if (bits == "0101") {
                        Base16 += "5";
                    } else if (bits == "0110") {
                        Base16 += "6";
                    } else if (bits == "0111") {
                        Base16 += "7";
                    } else if (bits == "1000") {
                        Base16 += "8";
                    } else if (bits == "1001") {
                        Base16 += "9";
                    } else if (bits == "1010") {
                        Base16 += "A";
                    } else if (bits == "1011") {
                        Base16 += "B";
                    } else if (bits == "1100") {
                        Base16 += "C";
                    } else if (bits == "1101") {
                        Base16 += "D";
                    } else if (bits == "1110") {
                        Base16 += "E";
                    } else if (bits == "1111") {
                        Base16 += "F";
                    }
                }

                
                cout << "Base4 --> " << Base4 << "\n";
                cout << "Base8 --> " << Base8 << "\n";
                cout << "Base10 -> " << Base10 << "\n";
                cout << "Base16 -> " << Base16 << "\n";

            }



            if (numbersystem == "4") {

                cout << "Your number in:\n";

                int length = Base4.length();
                
                // To base2
                for(int i = 0; i < length; i++) {
                    string bit = Base4.substr(i, 1);

                    if (bit == "0") {
                        if (i == 0) {
                            Base2 += "";
                        } else {
                            Base2 += "00";
                        }
                    } else if (bit == "1") {
                        if (i == 0) {
                            Base2 += "1";
                        } else {
                            Base2 += "01";
                        }
                    } else if (bit == "2") {
                        Base2 += "10";
                    } else if (bit == "3") {
                        Base2 += "11";
                    }
                }
                cout << "Base2 --> " << Base2 << "\n";

                // To base4
                cout << "Base4 --> " << Base4 << "\n";

                // To base10
                int temp = 0;

                for(int i = length; i > 0; i--) {
                    Base10 += (Base4[i - 1] - '0') * pow(4, temp);
                    temp++;
                }

                //To base8

                int rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 8;
                    Base8 += to_string(rest);
                    result = result / 8;
                }

                reverse(Base8.begin(), Base8.end());

                // To base 16
                rest = 0; 
                result = Base10;

                while (result > 0) {
                    rest = result % 16;

                    if (rest == 10) {
                        Base16 += 'A';
                    } else if (rest == 11) {
                        Base16 += 'B';
                    } else if (rest == 12) {
                        Base16 += 'C';
                    } else if (rest == 13) {
                        Base16 += 'D';
                    } else if (rest == 14) {
                        Base16 += 'E';
                    } else if (rest == 15) {
                        Base16 += 'F';
                    } else {
                        Base16 += to_string(rest);
                    }
                    
                    result = result / 16;
                }

                reverse(Base16.begin(), Base16.end());

                
                cout << "Base8 --> " << Base8 << "\n";
                cout << "Base10 -> " << Base10 << "\n";
                cout << "Base16 -> " << Base16 << "\n";

            }

            if (numbersystem == "8") {

                cout << "Your number in:\n";
                
                int length = Base8.length();

                // To base10
                int temp = 0;

                for(int i = length; i > 0; i--) {
                    Base10 += (Base8[i - 1] - '0') * pow(8, temp);
                    temp++;
                }

                // To base2
                int rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 2;
                    Base2 += to_string(rest);
                    result = result / 2;
                }

                reverse(Base2.begin(), Base2.end());

                //To base4
                rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 4;
                    Base4 += to_string(rest);
                    result = result / 4;
                }

                reverse(Base4.begin(), Base4.end());

                // To base8
                // cout below

                // To base 16
                rest = 0; 
                result = Base10;

                while (result > 0) {
                    rest = result % 16;

                    if (rest == 10) {
                        Base16 += 'A';
                    } else if (rest == 11) {
                        Base16 += 'B';
                    } else if (rest == 12) {
                        Base16 += 'C';
                    } else if (rest == 13) {
                        Base16 += 'D';
                    } else if (rest == 14) {
                        Base16 += 'E';
                    } else if (rest == 15) {
                        Base16 += 'F';
                    } else {
                        Base16 += to_string(rest);
                    }
                    
                    result = result / 16;
                }

                reverse(Base16.begin(), Base16.end());
                
                cout << "Base2 --> " << Base2 << "\n";
                cout << "Base4 --> " << Base4 << "\n";
                cout << "Base8 --> " << Base8 << "\n";
                cout << "Base10 -> " << Base10 << "\n";
                cout << "Base16 -> " << Base16 << "\n";

            }

            if (numbersystem == "10") {

                cout << "Your number in:\n";

                // To base10
                // cout below

                // To base2
                int rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 2;
                    Base2 += to_string(rest);
                    result = result / 2;
                }

                reverse(Base2.begin(), Base2.end());

                //To base4
                rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 4;
                    Base4 += to_string(rest);
                    result = result / 4;
                }

                reverse(Base4.begin(), Base4.end());

                // To base8
                rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 8;
                    Base8 += to_string(rest);
                    result = result / 8;
                }

                reverse(Base8.begin(), Base8.end());

                // To base 16
                rest = 0; 
                result = Base10;

                while (result > 0) {
                    rest = result % 16;

                    if (rest == 10) {
                        Base16 += 'A';
                    } else if (rest == 11) {
                        Base16 += 'B';
                    } else if (rest == 12) {
                        Base16 += 'C';
                    } else if (rest == 13) {
                        Base16 += 'D';
                    } else if (rest == 14) {
                        Base16 += 'E';
                    } else if (rest == 15) {
                        Base16 += 'F';
                    } else {
                        Base16 += to_string(rest);
                    }
                    
                    result = result / 16;
                }

                reverse(Base16.begin(), Base16.end());
                
                cout << "Base2 --> " << Base2 << "\n";
                cout << "Base4 --> " << Base4 << "\n";
                cout << "Base8 --> " << Base8 << "\n";
                cout << "Base10 -> " << Base10 << "\n";
                cout << "Base16 -> " << Base16 << "\n";

            }

            if (numbersystem == "16") {

                cout << "Your number in:\n";
                
                int length = Base16.length();

                for(int i = 0; i < length; i++) {
                    Base16[i] = toupper(Base16[i]);
                }

                // To base10
                int tempsq = 0, tempst;

                for(int i = length; i > 0; i--) {
                    if (Base16[i - 1] == 'A') {
                        tempst = 10;
                    } else if (Base16[i - 1] == 'B') {
                        tempst = 11;
                    } else if (Base16[i - 1] == 'C') {
                        tempst = 12;
                    } else if (Base16[i - 1] == 'D') {
                        tempst = 13;
                    } else if (Base16[i - 1] == 'E') {
                        tempst = 14;
                    } else if (Base16[i - 1] == 'F') {
                        tempst = 15;
                    } else {
                        tempst = Base16[i - 1] - '0';
                    }
                    Base10 += tempst * pow(16, tempsq);
                    tempsq++;
                }

                // To base2
                int rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 2;
                    Base2 += to_string(rest);
                    result = result / 2;
                }

                reverse(Base2.begin(), Base2.end());

                //To base4
                rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 4;
                    Base4 += to_string(rest);
                    result = result / 4;
                }

                reverse(Base4.begin(), Base4.end());

                // To base8
                rest = 0, result = Base10;

                while (result > 0) {
                    rest = result % 8;
                    Base8 += to_string(rest);
                    result = result / 8;
                }

                reverse(Base8.begin(), Base8.end());

                // To base 16
                // cout below
                
                cout << "Base2 --> " << Base2 << "\n";
                cout << "Base4 --> " << Base4 << "\n";
                cout << "Base8 --> " << Base8 << "\n";
                cout << "Base10 -> " << Base10 << "\n";
                cout << "Base16 -> " << Base16 << "\n";

            }
        }

        char answer = 'A';

        do {
            cout << endl << "Do you want to convert another number? (Y/n]: ";
            cin >> answer;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            answer = toupper(answer);
        } while (answer != 'Y' && answer != 'N');

        if (answer == 'N') {
            break;
        }

        codeEnded = false;

    }
}