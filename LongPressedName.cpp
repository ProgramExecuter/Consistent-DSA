class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        int m = typed.size();
        
        // Start with first CHAR of both strings
        int i = 0, j = 0;
        
        while(i < n  &&  j < m) {
            cout<<i<<name[i]<<"  "<<j<<typed[j]<<endl;
            // If the CHARS of positions don't match
            if(name[i] != typed[j]) {
                
                // If 'typed' string position matches prev CHAR of 'name'
                if(i-1 >= 0  &&  name[i-1] == typed[j]) {
                    ;
                }
                else {
                    return false;
                }
            }
            // If both CHAR matches then both pos ++
            else {
                ++i;
            }
            ++j;
        }
        
        // If end of 'name' not reached  -  FALSE
        if(i != n) {
            return false;
        }
        
        // If the remaining of 'typed' is not same as last CHAR of 'name'  -   FALSE
        while(j < m) {
            if (name[n-1] != typed[j]) {
                return false;
            }
            ++j;
        }
        
        return true;
    }
};