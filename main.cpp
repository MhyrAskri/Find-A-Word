#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

bool findWord(const string &wordToFind , const string target) {

    size_t found = target.find(wordToFind);
    if (found == string::npos) {

        return false;

    } else {

        return true;

    }

}

int main() {

    ifstream inFile;
    string wordToFind;
    string wordRead;
    int wordCount {0};
    int matchCount {0};

    inFile.open("../romeoandjuliet.txt");
    if (!inFile) {

        cerr << "Problem opening file." << endl;
        return 1;

    }

    cout << "Enter a word to search for: ";
    cin >> wordToFind;

    while (inFile >> wordRead) {

        ++wordCount;
        if (findWord(wordToFind , wordRead)) {

            ++matchCount;

        }

    }

    cout << wordCount << " words were searched..." << endl;
    cout << "The " << wordToFind << " word was found " << matchCount << " times" << endl;

    inFile.close();

    getch();
    return 0;
}
