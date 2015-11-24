#include "tokenizer.h"

void Tokenizer::AddDelimiter(std::string Delimiter)
{
  mDelimiters.push_back(Delimiter);
}

void Tokenizer::ResetDelimiters()
{
  mDelimiters.clear();
}

std::vector<std::string> Tokenizer::Split(std::string Text)
{
  mTokens.clear();
  mTokens.push_back(Text);

  for(auto& Delimiter : mDelimiters)
  {
    std::vector<std::string> Tokens;

    for(auto Str : mTokens)
    {
      auto SplitString = Split(Str, Delimiter);
      Tokens.insert(Tokens.end(), SplitString.begin(), SplitString.end());
    }

    mTokens = Tokens;
  }

  return mTokens;
}

std::vector<std::string> Tokenizer::Split(std::string Str, std::string Delimiter)
{
  std::vector<std::string> Tokens;

  size_t Pos = 0;

  while ((Pos = Str.find(Delimiter)) != std::string::npos)
  {
    std::string Token = Str.substr(0, Pos);
    Str.erase(0, (Pos + Delimiter.size()));
    if(Token.size() != 0) Tokens.push_back(Token);
  }

  if(Str.size() != 0) Tokens.push_back(Str);

  return Tokens;
}
