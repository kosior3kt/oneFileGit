#include "include/repo.hpp"

void repo::initializeRepo(std::string fileName)
{
   if(!fileExists(fileName))
   {
      std::cout << "File " << fileName << " does not exist!" << std::endl;
      exit(1);
   }
   if(!checkIfInitialized(fileName))
   {
      createRepo(fileName);
   }
   else
   {
      std::cout << "Repo already initialized!" << std::endl;
      exit(1);
   }
}

void repo::commitFile(std::string fileName, std::string commitMessage)
{
   if(!checkIfInitialized(fileName))
   {
      std::cout << "Repo not initialized!" << std::endl;
      exit(1);
   }
   if(!fileExists(fileName))
   {
      std::cout << "File " << fileName << " does not exist in current working directory" << std::endl;
      exit(1);
   }
   //create file with name equal to hash of file content in the ".filename" directory 
   copyFileToRepo(fileName, commitMessage);
   /// in the ".filename" directory append the file ".history" with the hash of the file and the commit message 
}

void repo::showHistory(std::string fileName)
{
   if(!checkIfInitialized(fileName))
   {
      std::cout << "Repo not initialized!" << std::endl;
      exit(1);
   }
   if(!fileExists(fileName))
   {
      std::cout << "File " << fileName << " does not exist in current working directory" << std::endl;
      exit(1);
   }
   std::string command = "cat ." + fileName + "/" + "/.history";
   system(command.c_str());
}

void repo::restoreFile(std::string fileName, std::string ID)
{
   if(ID == "0")
   {
      std::cout << "Cannot restore initial commit! (for a reason that is beyond your understanding mortal)" << std::endl;
      exit(1);
   }
   if(!checkIfInitialized(fileName))
   {
      std::cout << "Repo not initialized!" << std::endl;
      exit(1);
   }
   if(!fileExists(fileName))
   {
      std::cout << "File " << fileName << " does not exist in current working directory" << std::endl;
      exit(1);
   }
   commitFile(fileName, "Safe save before restoring to commit number:" + ID);
   restoreFileFromRepo(fileName, ID);
}

void repo::deleteRepo(std::string fileName)
{
   if(!checkIfInitialized(fileName))
   {
      std::cout << "Repo not initialized!" << std::endl;
      exit(1);
   }
   std::string command = "rm -fr ." + fileName;
   system(command.c_str());
}

void repo::copyFileToWD(std::string fileName, std::string ID, std::string newName)
{
   if(ID == "0")
   {
      std::cout << "Cannot restore initial commit! (for a reason that is beyond your understanding mortal)" << std::endl;
      exit(1);
   }
   if(!checkIfInitialized(fileName))
   {
      std::cout << "Repo not initialized!" << std::endl;
      exit(1);
   }
   if(!fileExists(fileName))
   {
      std::cout << "File " << fileName << " does not exist in current working directory" << std::endl;
      exit(1);
   }
   copyCommitToWD(fileName, ID, newName);
}
