#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "include/hasher.hpp"

std::string readWholeFile(std::string fileName);

void overwriteFile(std::string fileName, std::string content);

bool checkIfInitialized(std::string fileName);

// void createDupa();
//
void createFile(std::string fileName);

void createFile(std::string fileName, std::string path);

bool fileExistsInRepo(std::string fileName);

void createRepo(std::string fileName);

void copyFileToRepo(std::string fileName, std::string commitMessage);

void appendHistoryFile(std::string fileName, std::string content);

void appendHistoryFile(std::string fileName, std::string content, std::string hashName);

int readLastLine(std::string fileName);

bool fileExists(std::string fileName);

void restoreFileFromRepo(std::string fileName, std::string ID);

void copyCommitToWD(std::string fileName, std::string ID, std::string newFileName);
