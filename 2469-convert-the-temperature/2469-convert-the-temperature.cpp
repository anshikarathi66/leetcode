class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fah = celsius * 1.80 + 32.00;
        vector<double> vec{kelvin,fah};
        return vec;
    }
};