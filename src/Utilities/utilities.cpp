/*************************************************
 *                                               *
 *   Author: Danilo Carrabino                    *
 *                                               *
 *************************************************/


#include "utilities.h"

using namespace dstd;

void dstd::tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters)
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos) {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}


std::string dstd::trimleft(const std::string& str, const std::string& whitespace)
{
    const std::string::size_type strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos) {
        return ""; // no content
    }

    return str.substr(strBegin);
}


std::string dstd::trimright(const std::string& str, const std::string& whitespace)
{
    const std::string::size_type strEnd = str.find_last_not_of(whitespace);

    return str.substr(0, strEnd + 1);
}


std::string dstd::trim(const std::string& str, const std::string& whitespace)
{
    const std::string::size_type strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos) {
        return ""; // no content
    }

    const std::string::size_type strEnd = str.find_last_not_of(whitespace);
    const std::string::size_type strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}


std::string dstd::strreverse(const std::string& str)
{
    std::stringstream mySStream;

    for (std::string::const_reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit) {
        mySStream << *rit;
    }

    return mySStream.str();
}


std::string dstd::lltostr(long long val)
{
    std::stringstream mySStream;

    mySStream << val;

    return mySStream.str();
}

std::vector<int> dstd::getAnagramsOccurrences(const std::string& haystack, const std::string& needle)
{
    std::vector<int> occurrences;

    if((haystack.size() == 0) || (needle.size() == 0) || (haystack.size() < needle.size())) {
        return occurrences;
    }

    /// needle chars map //////////////////////////////////
    std::map<char, int> needleCharsMap;
    std::map<char, int>::iterator it;

    for(unsigned int i = 0; i < needle.size(); i++) {
        it = needleCharsMap.find( needle.at(i) );
        // found
        if( it != needleCharsMap.end() ) {
            it->second++;
        }
        // not found
        else {
            needleCharsMap[ needle.at(i) ] = 1;
        }
    }
    ///////////////////////////////////////////////////////

    unsigned int startWindow = 0;
    unsigned int endWindow = startWindow + (needle.size() - 1);

    while(endWindow < haystack.size()) {
        /// compute window chars map //////////////////////
        std::map<char, int> windowCharsMap;
        std::map<char, int>::iterator wit;

        for(unsigned int i = startWindow; i <= endWindow; i++) {
            wit = windowCharsMap.find( haystack.at(i) );
            // found
            if( wit != windowCharsMap.end() ) {
                wit->second++;
            }
            // not found
            else {
                windowCharsMap[ haystack.at(i) ] = 1;
            }
        }
        ///////////////////////////////////////////////////////

        // anagram match!!!
        if(windowCharsMap == needleCharsMap) {
            occurrences.push_back(startWindow);
        }

        startWindow++;
        endWindow++;
    }

    return occurrences;
}
