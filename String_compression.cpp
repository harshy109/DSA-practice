//443. String Compression

class Solution {
public:
    int compress(vector<char>& chars) {

        string s = "";
        int i = 0;
        while(i<chars.size()){
            int count = 1;
            int idx=0;
            int next = i+1;

            while(next<chars.size() && chars[i]==chars[next]){
                count++;
                ++next;
            }

            if(count>1){

                s.push_back(chars[i]);
                ++idx;

                if(count>9){
                    int start  = s.size();
                    string number = "";
                    
                    //int it=start;
                    while(count){
                        int rem = count%10;
                        count = count/10;
                        char remStr = rem+'0';
                        s.push_back(remStr);
                        //++it;
                        ++idx;
                    }
                    cout<<s<<endl;
                    reverse(s.begin()+start, s.end());
                    
                }
                else{
                    char num = count + '0';
                    s.push_back(num);
                    ++idx;
                }
                
            }
            else{
                s.push_back(chars[i]);
                ++idx;
            }
            i = next;
        }
    
        for(int i = 0; i<s.length(); i++){
            chars[i]=s[i];
        }
        
        return s.size();
    }

};
