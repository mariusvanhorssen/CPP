#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>

class Tokenizer
{
public:  
  void AddDelimiter(std::string Delimiter);
  void ResetDelimiters();

  std::vector<std::string> Split(std::string Text);

private:
  std::vector<std::string> mDelimiters;
  std::vector<std::string> mTokens;

  std::vector<std::string> Split(std::string Str, std::string Delimiter);
};

#endif // TOKENIZER_H
