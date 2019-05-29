class Solution {
public:
    string originalDigits(string s) {
        string res;
        unordered_map<char,int>cnt;
        int digit[10]={0,0,0,0,0,0,0,0,0};
        for(char x:s) cnt[x]++;
        digit[0]=cnt['z'];
        for(char x:"zero") cnt[x]-=digit[0];
        digit[6]=cnt['x'];
        for(char x:"six") cnt[x]-=digit[6];
        digit[8]=cnt['g'];
        for(char x:"eight") cnt[x]-=digit[8];
        digit[3]=cnt['h'];
        for(char x:"three") cnt[x]-=digit[3];
        digit[2]=cnt['w'];
        for(char x:"two") cnt[x]-=digit[2];
        digit[4]=cnt['r'];
        for(char x:"four") cnt[x]-=digit[4];
        digit[7]=cnt['s'];
        for(char x:"seven") cnt[x]-=digit[7];
        digit[5]=cnt['v'];
        for(char x:"five") cnt[x]-=digit[5];
        digit[1]=cnt['o'];
        for(char x:"one") cnt[x]-=digit[1];
        digit[9]=cnt['i'];
        for(int i=0;i<10;i++) while(digit[i]--) res+=i+'0';
        return res;
    }
};
