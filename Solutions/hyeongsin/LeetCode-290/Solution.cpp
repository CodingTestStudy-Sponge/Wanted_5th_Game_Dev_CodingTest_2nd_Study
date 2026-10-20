class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<int, string> animalPattern;
        stringstream ss(s);
        vector<string> words;
        string word;

        while(ss >> word)
        {
            words.push_back(word);
        }

        if(pattern.length() != words.size())
        {
            return false;
        }

        for(int ix = 0; ix < pattern.length(); ++ix)
        {
           auto iterator = animalPattern.find(pattern[ix]);
           if(iterator != animalPattern.end())
           {
               if(iterator->second != words[ix])
               {
                  return false;
               }
           }
           else
           {
               for(const auto& [key, value] : animalPattern)
               {
                   if(value == words[ix])
                   {
                       return false;
                   }
               }

               animalPattern.insert({pattern[ix], words[ix]});
           }
        }
        return true;
    }
};