class Solution {
public:
    bool isValid(string str)
    {
        bool ok = true;
		//var to store indexes of hyphen and punctuation
        int hypos = -1 , punpos = -1;
        int idx = 0;
        for(auto &ch : str)
        {
		//for ascii code of curr char
            int val = ch;
			//check for hyphen
            if(val == 45)
            {
			//if first hyphen then store its idx
                if(hypos == -1) hypos = idx;
				// else there are more than 1 hyphen so false
                else return false;
            }
            else if(ch == '!' or ch=='.' or ch==',')
            {
			//if first punctutation then store its idx
                if(punpos == -1) punpos = idx;
				//else multiple punc so not valid word
                else return false;
            }
			// else not in a-z then false
            else if(ch<'a' or ch>'z') return false;
            idx++;
        }
		//check for punc is at last or not(if any)
        if(punpos != -1 and punpos != str.size()-1) return false;
		
		//check if hyphen surrounde by lowercase alphabets
        if(hypos != -1)
        {
            if(hypos == 0 or hypos == str.size()-1) return false;
            if(str[hypos-1]<'a' or str[hypos-1]>'z') return false;
            if(str[hypos+1]<'a' or str[hypos+1]>'z') return false;
        }
		
		//finally if all true then word valid
        return true;
    }
	
	int countValidWords(string sentence) {
	// we split each word with spae as delimeter
        stringstream ss(sentence);
        string word;
        int cnt = 0;
        while(ss >> word)
        {
            cnt += isValid(word);
        }
        
        return cnt;
    }
};