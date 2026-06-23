class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        int a,b,c;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                s1.push(stoi(tokens[i]));
            }else if(tokens[i]=="+"){
                a=s1.top();
                s1.pop();
                b=s1.top();
                s1.pop();
                c=a+b;
                s1.push(c);
            }else if(tokens[i]=="-"){
                a=s1.top();
                s1.pop();
                b=s1.top();
                s1.pop();
                c=b-a;
                s1.push(c);
            }else if(tokens[i]=="*"){
                a=s1.top();
                s1.pop();
                b=s1.top();
                s1.pop();
                c=a*b;
                s1.push(c);
            }else if(tokens[i]=="/"){
                a=s1.top();
                s1.pop();
                b=s1.top();
                s1.pop();
                c=b/a;
                s1.push(c);
            }
        }
        return s1.top();
    }
};
