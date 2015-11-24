#include "tokenizer.h"
#include <iostream>

int main(int, char**)
{
  Tokenizer tokenizer;
  tokenizer.AddDelimiter("?");
  tokenizer.AddDelimiter("!");
  std::vector<std::string> Tokens = tokenizer.Split("1!12!x?ab c!");

  for(unsigned int i = 0; i < Tokens.size(); i++)
  {
    std::cout << "Tokens [" << std::to_string(i) << "]: " << Tokens.at(i) << std::endl;
  }

  std::cout << "Press enter to continue ...";
  std::cin.get();

  return 0;
}

