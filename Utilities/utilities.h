/*************************************************
 *                                               *
 *   Author: Danilo Carrabino                    *
 *                                               *
 *************************************************/


#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <map>

namespace dstd {
    void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ");

    std::string trimleft(const std::string& str, const std::string& whitespace = " \t\r\n");
    std::string trimright(const std::string& str, const std::string& whitespace = " \t\r\n");
    std::string trim(const std::string& str, const std::string& whitespace = " \t\r\n");

    std::string strreverse(const std::string& str);

    std::string lltostr(long long val);

    std::vector<int> getAnagramsOccurrences(const std::string& haystack, const std::string& needle);
}

#endif // UTILITIES_H
