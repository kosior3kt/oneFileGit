#include "include/fileReader.hpp"
#include "include/hasher.hpp"


// create a function that checks if file with given name exists
bool fileExists(const std::string name)
{
   std::ifstream f(name.c_str());
   return f.good();
}

void createFile(std::string fileName)
{
   std::ofstream file(fileName);
   file.close();
}

void createFile(std::string fileName, std::string path)
{
   std::ofstream file(path + "/" + fileName);
   file.close();
}

// create a function that checks if a file with given name exists in the in the
// "." directory
bool fileExistsInRepo(std::string fileName)
{
   std::string directoryName = "." + fileName;
   std::ifstream file(directoryName + fileName);
   return file.good();
}

// write function that reads the whole content of file into one string variable
// and returns it by moving
std::string readWholeFile(std::string fileName)
{
   if(!fileExists(fileName))
   {
      std::cout << "File " << fileName << " does not exist!" << std::endl;
      exit(1);
   }

   std::ifstream file(fileName);
   std::string content(
       (std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()
   );
   return content;
}

// create a function that checks if there is a directory named ".dupa" in the
// current directory
bool checkIfInitialized(std::string fileName)
{
   std::string directoryName = "." + fileName;
   std::ifstream file(directoryName);
   return file.good();
}

///read first character from the last line of "./history" file
int readLastLine(std::string fileName)
{
   std::string command = "tail -n 1 ." + fileName + "/.history";
   FILE* pipe          = popen(command.c_str(), "r");
   if(!pipe)
   {
      exit(-1);
   }
   char buffer[128];
   std::string result = "";
   while(!feof(pipe))
   {
      if(fgets(buffer, 128, pipe) != NULL)
      {
         result += buffer;
      }
   }
   pclose(pipe);
   ///get the first word from 'result' string and then convert it to int 
   std::string firstWord = result.substr(0, result.find(" "));
   int number            = std::stoi(firstWord);
   
   return number;
}

///write a function that wil take a string and return sencond word from it (word is defined as a string of characters separated by space)
std::string getSecondWord(std::string line)
{
   std::string word = "";
   int i            = 0;
   while(line[i] != ' ')
   {
      i++;
   }
   i++;
   while(line[i] != ' ')
   {
      word += line[i];
      i++;
   }
   return word;
}

///write a function that wil take a string and return first word from it (word is defined as a string of characters separated by space)
std::string getFirstWord(std::string line)
{
   std::string word = "";
   int i            = 0;
   while(line[i] != ' ')
   {
      word += line[i];
      i++;
   }
   return word;
}

void appendHistoryFile(std::string fileName, std::string content)
{
   int no = readLastLine(fileName);
   content = std::to_string(no + 1) + " " + content;
   std::string command = "echo \'" + content + " \' >> ." + fileName + "/" + "/.history";
   system(command.c_str());
}

void appendHistoryFile(std::string fileName, std::string content, std::string hashName)
{
   int no = readLastLine(fileName);
   hashName = std::to_string(no + 1) + " " + hashName;
   hashName += " ";
   hashName += content;
   std::string command = "echo \'" + hashName + " \' >> ." + fileName + "/" + "/.history";
   system(command.c_str());
}

// create a function that creates a directory named ".dupa" in the current
// directory
void createRepo(std::string fileName)
{
   std::string directoryName = "." + fileName;
   std::string command       = "mkdir " + directoryName;
   system(command.c_str());

   std::string command2 = "echo \'0 Initial commit \' >> ." + fileName + "/" + "/.history";
   system(command2.c_str());
}

// write a function that overwritees file with a given std::string variable
void overwriteFile(std::string fileName, std::string content)
{
   std::ofstream file(fileName);
   file << content;
}


// create a function that copies a file with given name to a file with another
// name in the ".dupa" directory
void copyFileToRepo(std::string filename, std::string commitmessage)
{
   //    printf("128-bit hash: %llu %llu \n", hash128.high64, hash128.low64);
   XXH128_hash_t hash128      = stringToHash(readWholeFile(filename));
   std::string high128        = std::to_string(hash128.high64);
   std::string low128         = std::to_string(hash128.low64);
   std::string hashnameoffile = high128 + low128;
   std::string command = "cat " + filename + "> ." + filename + "/" + hashnameoffile;
   system(command.c_str());
   appendHistoryFile(filename, commitmessage, hashnameoffile);
}


///create function reading line by line from a ".history" file until first word matches the given int then it returns second word from this line. If no line matches exits with -1
std::string getHashFromHistory(std::string fileName, int number)
{
   fileName = "." + fileName + "/.history";
   std::ifstream file(fileName);
   std::string line;
   while(std::getline(file, line))
   {
      if(getFirstWord(line) == std::to_string(number))
      {
         return getSecondWord(line);
      }
   }
   std::cout << "No such commit number!" << std::endl;
   exit(-1);
}

void restoreFileFromRepo(std::string fileName, std::string ID)
{
   std::string hashFileName = getHashFromHistory(fileName, std::stoi(ID));
   std::string command = "cat ." + fileName + "/" + hashFileName + " > " + fileName;
   system(command.c_str());
}

// void copyCommitToRepo(std::string fileName, std::string ID)
// {
//    std::string hashFileName = getHashFromHistory(fileName, std::stoi(ID));
//    std::string command = "cat ." + fileName + "/" + hashFileName + " > ." + fileName + "/" + hashFileName;
//    system(command.c_str());
// }

void copyCommitToWD(std::string fileName, std::string ID, std::string newName)
{
   std::cout << "copyCommitToWD" << std::endl;
   std::string hashFileName = getHashFromHistory(fileName, std::stoi(ID));
   std::string command = "cat ." + fileName + "/" + hashFileName + " > " + newName;
   system(command.c_str());
}


// ///read first character of the given line
// std::string readFirstCharacter(std::string line)
// {
//    std::string firstCharacter = "";
//    firstCharacter += line[0];
//    return firstCharacter;
// }
