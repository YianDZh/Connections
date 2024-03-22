//
// Created by YIANZ on 08/12/2023.
//

#ifndef SFML_TEMPLATE_FILEIO_H
#define SFML_TEMPLATE_FILEIO_H
#include <iostream>
#include <ctime>
#include "fstream"
#include "string"
#include "vector"
int linenumer(std::ifstream &fin, int lineNumber);
bool checking(std::ifstream &fin, const std::string filePath);
std::vector<std::vector<std::string>> solver();
#endif //SFML_TEMPLATE_FILEIO_H
