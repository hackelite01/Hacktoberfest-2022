class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>k;
        for(int i=0;i<n;i++){
            if(s[i]=='[' ||s[i]=='('||s[i]=='{' ){
                k.push(s[i]);
            }
            else{
                if(k.empty())
                    return false;
                if(s[i]==']'){
                    if(k.top()=='[')
                      k.pop();
                    else
                      return false;
                }
                if(s[i]=='}'){
                     if(k.top()=='{')
                      k.pop();
                    else
                      return false;
                }
                 if(s[i]==')'){
                    if(k.top()=='(')
                      k.pop();
                    else
                      return false;
                }
            }
        }
      if(!k.empty())
        return false;
      return true;  
    }
};
