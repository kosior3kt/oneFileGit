#include "include/fileReader.hpp"
#include "include/hasher.hpp"

namespace repo
{
   void initializeRepo(std::string fileName);
   void commitFile(std::string fileName, std::string commitMessage);
   void showHistory(std::string fileName);
   void restoreFile(std::string fileName, std::string ID);
   void deleteRepo(std::string fileName);
   void copyFileToWD(std::string fileName, std::string ID, std::string newFileName);
}
