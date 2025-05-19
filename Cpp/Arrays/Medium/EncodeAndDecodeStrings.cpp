/*
Intuition
    So the first thing that comes to mind is we need to find a delimiter to be able to be recognized from the decoder when implemented within the encoder.
    As all asci characters are legal, I think I need to have more than 1 character being the delimiter to be able to distinguish between a real char and a delimiter.
    So, i will try to have my delimiter set to "##" and see if that works.
    Another thing is we cannot pass the delimiter, so we will need to find a subtle way to do so. Thinking of passing it at the start of the encoded string (unecessary).
    Now thinking of how parsing it would work from the decoder. We would basically tell it if the delimiter has been seen (aka ## was read), extract whatever is in between
    the current delimiter and the next one.

Approach
    So after careful examination, having a fixed delimiter would not work, as there would be cases where it just is not detectable and wouldnt work. So the best next case would
    be to set the delimiter to a character of your choice with the length of the string we are encoding/decoding. This way, we would always know exactly how many characters to 
    extract every time. 

Complexity
- Time complexity: O(N) + O(N) for each encode/decode function

- Space complexity: O(N) for allocation of vectors

*/

#include <string>
#include <vector>

//UNOPTIMAL SOLUTION
/*
    * @param strs: a list of strings
    * @return: encodes a list of strings to a single string.
    */
std::string encode(std::vector<std::string> &strs) {
    // write your code here
    std::string delimiter = "#%";
    std::string encodedString;

    for(int i = 0; i < strs.size(); i++){
        encodedString += strs[i].size();
        if (i + 1 < strs.size()) 
            encodedString += delimiter;
    }
    return encodedString;
}

/*
    * @param str: A string
    * @return: decodes a single string to a list of strings
    */
std::vector<std::string> decode(std::string &str) {
    // write your code here
    std::vector<std::string> decodedString;
    std::string tempString;
    int i = 0, j = 0;
    for(i; i < str.size()-1; i++){
        if(str[i] == '#' && str[i+1] == '%'){
            i += 2;
            decodedString.push_back(tempString);
            continue;
        }
        tempString += str[i];
    }
    return decodedString;
}

// OPTIMAL SOLUTION

/*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    std::string encode(std::vector<std::string> &strs) {
        // write your code here
        std::string encodedString;
        for(int i = 0; i < strs.size(); i++){
            encodedString += std::to_string(strs[i].size()) + '@' + strs[i];
        }
        return encodedString;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    std::vector<std::string> decode(std::string &str) {
        // write your code here
        std::vector<std::string> decodedString;
        int i = 0;
        while (i < str.size()){
            int j = i;
            while(str[j] != '@')
                j++;
            std::string substringLength = str.substr(i, j - i);
            int length = std::stoi(substringLength);
            i = j + 1;
            decodedString.push_back(str.substr(i, length));
            i += length;
        }
        return decodedString;
    }