class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int width=min(C,G)>max(A,E)?min(C,G)-max(A,E):0;
        int height=min(D,H)>max(B,F)?min(D,H)-max(B,F):0;
        return (G-E)*(H-F)-height*width+(C-A)*(D-B);
    }
};
