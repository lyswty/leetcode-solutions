class Solution {
private:
    double r,x,y;
public:
    Solution(double radius, double x_center, double y_center):r(radius),x(x_center),y(y_center) {
        
    }
    
    vector<double> randPoint() {
        double theta=2*M_PI*rand()/RAND_MAX,R=sqrt(rand()/(double)RAND_MAX*r*r);
        vector<double>res(2);
        res[0]=R*sin(theta)+x;
        res[1]=R*cos(theta)+y;
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
