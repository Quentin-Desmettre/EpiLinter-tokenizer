/*
** EPITECH PROJECT, 2022
** EpiLinter-tokenizer
** File description:
** Tokenizer.hpp
*/

#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <vector>

struct Token
{
    Token(const std::string & v, int ln, int cl, const std::string & n)
        : value_(v), line_(ln), column_(cl), name_(n) {}

    Token()
        : value_(""), line_(0), column_(0), name_("") {}

    bool operator==(Token const& t) const
    {
      return value_ == t.value_
          && line_ == t.line_
          && column_ == t.column_
          && name_ == t.name_;
    }

    std::string value_;
    int line_;
    int column_;
    std::string name_;
};

class Tokenizer {
public:
    static std::string getTokens(const std::string &file_content);
private:
    static std::vector<Token> getEveryTokenInFile(std::string const &file);
    static std::string generatedUid(int depth = 1);
};

#endif // TOKENIZER_H
