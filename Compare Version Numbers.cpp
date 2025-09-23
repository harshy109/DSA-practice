class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<int> v;
        int i = 0;
        while (i < v1.length()) {
            int num = 0;
            while (v1[i] != '.' && i < v1.length()) {
                int rem = v1[i] - '0';
                num = num * 10 + rem;
                i++;
            }
            v.push_back(num);
            i++;
        }
        i = 0;
        vector<int> a;
        while (i < v2.length()) {
            int num = 0;
            while (v2[i] != '.' && i < v2.length()) {
                int rem = v2[i] - '0';
                num = num * 10 + rem;
                i++;
            }
            a.push_back(num);
            i++;
        }
        int len = v.size() > a.size() ? v.size() : a.size();
        for (int i = 0; i < len; i++) {
            int x = i<v.size() ? v[i] : 0;
            int y = i<a.size() ? a[i] : 0;

            if(x<y) return -1;
            else if(x>y) return 1;
        }

        return 0;
    }
};
