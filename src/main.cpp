#include "include/repo.hpp"

int main(int argc, char **argv)
{
   std::string secondArg = argv[1];
   std::string thirdArg  = argv[2];
   // write a switch that changes with the first argument
   if((secondArg == "-H" || secondArg == "-help") && argc == 2)
   {
      ///initializes the ".dupa" directory
      std::cout << "dupa -H or -help - shows help" << std::endl;
      std::cout << "dupa -i <file> - initializes the repo" << std::endl;
      std::cout << "dupa -c <file> <commit message> - commits the file" << std::endl;
      std::cout << "dupa -h <file> - shows history of the file" << std::endl;
      std::cout << "dupa -r <file> <commit ID> - restores the file to the given commit" << std::endl;
      std::cout << "dupa -s <file> <commit ID> <new file name> - saves the given commit to file with given name" << std::endl;
      exit(0);
   }
   if(argc < 3)
   {
      std::cout << "No arguments given!" << std::endl;
      std::cout << "Usage: dupa <command> <file>" << std::endl;
      std::cout << "Commands: init, commit, history, restore" << std::endl;
      std::cout << "For help use dupa -help or -H" << std::endl;
      exit(1);
   }
   // create a string variable that stores the second argument
   if(secondArg == "-i" && argc == 3)
   {
      ///initializes the ".dupa" directory
      repo::initializeRepo(thirdArg);
      exit(0);
   }
   // if(secondArg == "-G" && argc == 3)
   // {
   //    ///initializes the ".dupa" directory
   //    std::cout<<readLastLine(thirdArg)<<std::endl;
   //    exit(0);
   // }
   if(secondArg == "-s" && argc == 5)
   {
      // create a string variable that stores the content of the file with
      // given name
      repo::copyFileToWD(thirdArg, argv[3], argv[4]);
      // create a string variable that stores the
      /// instantiates oneFileGit if it's not instantiated yet (and the given
      /// file name exists)
      exit(0);
   }
   if(secondArg == "-c" && argc == 4)
   {

      /// commits a file to the repository (if the file still exists)
      repo::commitFile(thirdArg, argv[3]);
      exit(0);
   }
   if(secondArg == "-h")
   {
      /// prints the history of the oneFileGit for the given filename
      repo::showHistory(thirdArg);
      exit(0);
   }
   if(secondArg == "-d")
   {
      /// deletes the file from the repository
      repo::deleteRepo(thirdArg);
      exit(0);
   }
   if(secondArg == "-r" && argc ==4)
   {
      repo::restoreFile(thirdArg, argv[3]);
      /// restores the file to the state it was in the given commit (if the
      /// file and the comit id exist)

      exit(0);
   }
   return 0;
}
