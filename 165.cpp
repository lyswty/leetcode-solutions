class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size()&&j<version2.size()){
            int I=i,J=j;
            while(I<version1.size()&&version1[I]!='.') I++;
            while(J<version2.size()&&version2[J]!='.') J++;
            if(stoi(version1.substr(i,I-i))<stoi(version2.substr(j,J-j))) return -1;
            else if(stoi(version1.substr(i,I-i))>stoi(version2.substr(j,J-j))) return 1;
            i=I+1,j=J+1;
        }
        while(i<version1.size()){
            if(version1[i]!='0'&&version1[i]!='.') return 1;
            i++;
        }
        while(j<version2.size()){
            if(version2[j]!='0'&&version2[j]!='.') return -1;
            j++;
        }
        return 0;
    }
};
