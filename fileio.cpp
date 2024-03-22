//
// Created by YIANZ on 08/12/2023.
//

#include "fileio.h"


bool checking(std::ifstream &fin, const std::string filePath) {
    fin.open(filePath);
    return fin.is_open();
}

int linenumer(std::ifstream &fin, int lineNumber) {
    std::string line;
    for (int i = 0; i < lineNumber; ++i) {
        if (!getline(fin, line)) {
            std::cerr << "Line not found" << std::endl;
            return 7;
        }
    }
    return 0;
}

std::vector<std::vector<std::string>> solver() {
    srand(time(0));
    std::vector<std::vector<std::string>> key(4, std::vector<std::string>(4, ""));
    std::ifstream fin;
    int moder = (rand()%10)+1;
    char temp='/';
    std::string choice;
    bool test= checking(fin, "ATTEMPTING.txt");

    if (test){
        if (linenumer(fin, moder)) {
            std::cerr << "Error in linenumer function." << std::endl;
            exit (12);
        }

        for (int i = 0; i < key.size(); i++) {
            for (int j = 0; j < key[i].size();  j++) {
                while (temp!=' '&&temp!='\n'&&temp!=','){
                    fin.get(temp);
                    if (temp==' '||temp==','){
                        key[i][j]=choice;
                        choice="";
                        temp='/';
                        break;
                    }
                    else if (fin.peek() == '\n')
                        break;
                    else{
                        choice+=temp;
                    }
                }
                if (temp == '\n')
                    break;
            }
            if (temp == '\n')
                break;
        }
    } else {
        std::cout << "fail";
    }
    return key;
}
