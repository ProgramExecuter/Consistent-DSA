class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++)
        {
            string temp;
            int c = 1;
            int curr = ans[0]-48;
            for(int i=1; i<ans.size(); i++)
            {
                if((ans[i]-48) != curr)
                {
                    temp += char(c+48);
                    temp += char(curr+48);
                    c = 1;
                    curr = ans[i]-48;
                }
                else
                {
                    c++;
                }
            }
            if(c > 0)
            {
                temp += char(c+48);
                temp += char(curr+48);
            }
            ans = temp;
        }
        return ans;
    }
};