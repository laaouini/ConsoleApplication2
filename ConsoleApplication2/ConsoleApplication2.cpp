#include <iostream>
#include<vector>
#include <sstream> 
using namespace std;
#define PI 3.14 
vector<int> calculateFactorials(int nb_of_terms)
{
    vector<int> result;
    int x = 1;
    result.push_back(x);
    for (int i = 1;i <= nb_of_terms;i++) {
        x = x * i;
        result.push_back(x);
    }
    return result;
}
class TaylorExpansion {
   private: double x_;
   public: 
         static vector<int> factorials;
         static int nb_of_terms_;
         TaylorExpansion(double x);
         double calculateValueByTaylorExpansion();
         virtual double calculateCoeff(int i)=0;
};
int TaylorExpansion::nb_of_terms_ = 10;
vector<int> TaylorExpansion::factorials = calculateFactorials(2*(TaylorExpansion::nb_of_terms_+1));
TaylorExpansion::TaylorExpansion(double x):
     x_(x){
}
double TaylorExpansion::calculateValueByTaylorExpansion() {
    double result = 0;
    double x_n = 1;
    for (int i = 0;i <= nb_of_terms_;i++) {
        result = result + (calculateCoeff(i) * x_n);
        x_n = x_n * x_;
    }
    return result;
}
class TaylorExpansionExponential :public TaylorExpansion {
    public: TaylorExpansionExponential(double x);
            double calculateCoeff(int i);
};
TaylorExpansionExponential::TaylorExpansionExponential(double x):
    TaylorExpansion(x){
};
double TaylorExpansionExponential::calculateCoeff(int i) {
    double result = 0;
    result = 1.0 / TaylorExpansion::factorials[i];
    return result;
}
class TaylorExpansionSinus :public TaylorExpansion {
    public: TaylorExpansionSinus(double x);
            double calculateCoeff(int i);
};
double TaylorExpansionSinus::calculateCoeff(int i) {
    double result = 0;
    if ((i%2) == 0){
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0/ TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}
TaylorExpansionSinus::TaylorExpansionSinus(double x) :
    TaylorExpansion(x) {
};
class TaylorExpansionCosinus :public TaylorExpansion {
public: TaylorExpansionCosinus(double x);
        double calculateCoeff(int i);
};
TaylorExpansionCosinus::TaylorExpansionCosinus(double x) :
    TaylorExpansion(x) {
};
double TaylorExpansionCosinus::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    else {
        result = 0;
    }
    return result;
}
class TaylorExpansionTan :public TaylorExpansion {
public: TaylorExpansionTan(double x);
      double calculateCoeff(int i);

};
TaylorExpansionTan::TaylorExpansionTan(double x) :
    TaylorExpansion(x) {
};
double Combination(int n, int k) {
        double result = TaylorExpansion::factorials[n];
        result = result / TaylorExpansion::factorials[k];
        result = result / TaylorExpansion::factorials[n-k];
        return result;
}
double BernoulliNumber(int n) {
    static vector<double> bernoulliNumbers;
    double result = 1;
    if (n < bernoulliNumbers.size()) {
        result = bernoulliNumbers[n];
    }
    else {
        if (n == 0) {
            result = 1;
            bernoulliNumbers.push_back(result);
        }
        else if (n == 1) {
            result = -0.5;
            bernoulliNumbers.push_back(result);
        }
        else if (n % 2 != 0) {
            result = 0;
            bernoulliNumbers.push_back(result);
        }
        else {
            double result = 0;
            for(int k = 0;k < n;k++) {
                result = result - Combination(n, k) * BernoulliNumber(k) / (double)(n + 1 - k);
            }
            bernoulliNumbers.push_back(result);
        }
    }
    return result;
}
double TaylorExpansionTan::calculateCoeff(int i) {
    double result = 0;
    if (i % 2 == 0) {
        result = 0;
    }
    else {
        result = BernoulliNumber(2 * (i + 1));

        double term1 = 1;
        for (int u = 0;u < i + 1;u++) {
            term1 = term1 * (-4.0);
        }
        result = result * term1;
        double term20 = 1;
        for (int u = 0;u < i + 1;u++) {
            term20 = term20 * 4.0;
        }
        double term2 = 1 - term20;
        result = result * term2;
        result = result / ( TaylorExpansionTan::factorials[2 * (i + 1)]);
    }
    return result;
}
class TaylorExpansionCosh :public TaylorExpansion {
public: TaylorExpansionCosh(double x);
      double calculateCoeff(int i);
};
TaylorExpansionCosh::TaylorExpansionCosh(double x) :
    TaylorExpansion(x) {
};
double TaylorExpansionCosh::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}
class TaylorExpansionSinh :public TaylorExpansion {
public: TaylorExpansionSinh(double x);
      double calculateCoeff(int i);
};
TaylorExpansionSinh::TaylorExpansionSinh(double x) :
    TaylorExpansion(x) {
};
double TaylorExpansionSinh::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}
class TaylorExpansionTanh :public TaylorExpansion {
public: TaylorExpansionTanh(double x);
      double calculateCoeff(int i);
};
TaylorExpansionTanh::TaylorExpansionTanh(double x) :
    TaylorExpansion(x) {
};
double TaylorExpansionTanh::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}
class TaylorExpansionArcsinh :public TaylorExpansion {
public: TaylorExpansionArcsinh(double x);
      double calculateCoeff(int i);
};
TaylorExpansionArcsinh::TaylorExpansionArcsinh(double x) :
    TaylorExpansion(x) {
};
double TaylorExpansionArcsinh::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}
class TaylorExpansionArccosh :public TaylorExpansion {
public: TaylorExpansionArccosh(double x);
      double calculateCoeff(int i);
};
TaylorExpansionArccosh::TaylorExpansionArccosh(double x) :
    TaylorExpansion(x) {
};
double TaylorExpansionArccosh::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}
class TaylorExpansionArcth :public TaylorExpansion {
public: TaylorExpansionArcth(double x);
      double calculateCoeff(int i);
};
TaylorExpansionArcth::TaylorExpansionArcth(double x) :
    TaylorExpansion(x) {
}
double TaylorExpansionArcth::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}
class TaylorExpansionSec :public TaylorExpansion {
public: TaylorExpansionSec(double x);
      double calculateCoeff(int i);
};
TaylorExpansionSec::TaylorExpansionSec(double x) :
    TaylorExpansion(x) {
}
double TaylorExpansionSec::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}
class TaylorExpansionLambert :public TaylorExpansion {
public: TaylorExpansionLambert(double x);
      double calculateCoeff(int i);
};
TaylorExpansionLambert::TaylorExpansionLambert(double x) :
    TaylorExpansion(x) {
}
double TaylorExpansionLambert::calculateCoeff(int i) {
    double result = 0;
    if ((i % 2) == 0) {
        result = 0;
    }
    else {
        int j = (int)(i / 2);
        result = 1.0 / TaylorExpansion::factorials[i];
        for (int k = 0;k < j;k++) {
            result = (-1.0) * result;
        }
    }
    return result;
}

int main()
{
    int c=0;
    double x = 0,y=0;
    bool quit = false;
    int nb_offsetof_terms=0;
    do
    {
        std::cout << "Calculating some function using Taylor expansion!\n";
        std::cout << "Press 1 to calculate exp(x) for a given number x using Taylor expansion " << std::endl;
        std::cout << "Press 2 to calculate sin(x) for a given number x using Taylor expansion " << std::endl;
        std::cout << "Press 3 to calculate cos(x) for a given number x using Taylor expansion " << std::endl;
        std::cout << "Press 4 to calculate tan(x) for a given number x between -1.57 and 1.57 (pi/2) using Taylor expansion " << std::endl;
        std::cout << "Press 5 to calculate sinh(x) for a given number x using Taylor expansion " << std::endl;
        std::cout << "Press 6 to calculate cosh(x) for a given number x using Taylor expansion " << std::endl;
        std::cout << "Press 7 to calculate tanh(x) for a given number x between -1.57 and 1.57 (pi/2) using Taylor expansion " << std::endl;
        std::cout << "Press 8 to calculate arcsinh(x) for a given number x between -1 and 1 using Taylor expansion " << std::endl;
        std::cout << "Press 9 to calculate arcth(x) for a given number x between -1 and 1 using Taylor expansion " << std::endl;
        std::cout << "Press 10 to calculate sec(x) for a given number x between -1.57 and 1.57 (pi/2) using Taylor expansion " << std::endl;
        std::cout << "Press 11 to calculate the function W of Lambert(x) for a given number x " << std::endl;
        std::cout << "Press 0 to quit" << std::endl;
        string input;
        std::cin >> input;
        std::cout <<  "Input string="<<input<< std::endl;
        std::istringstream iss(input);
        // Extract the integer from the string 
        iss >> c;

        if (iss.fail()) {
            std::cout << "Conversion failed: Invalid input number." << std::endl;
        }
        else {
            std::cout << "The code of the operation is: " << c << std::endl;
        }
        switch (c) {
            case 0: quit = true;
               break;
            case 1:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                std::cin >> x;
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionExponential te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value exp_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                std::cin >> x;
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionSinus te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value sinus_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                std::cin >> x;
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionCosinus te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value sinus_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 4:
            {
                std::cout << "c=" << c << std::endl;
                x = 0;
                do {
                    std::cout << "the input value x should be comprised between -1.57 and 1.57" << std::endl;
                    std::cout << "Enter the input value for x" << std::endl;
                    std::cin >> x;
                } while ((x <= (((-1) * PI) / 2.0)) || ((PI / 2.0) <= x));
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionTan te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value sinus_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 5:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                std::cin >> x;
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionSinh te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value exp_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 6:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                std::cin >> x;
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionCosh te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value exp_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 7:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                std::cin >> x;
                std::cout << "Input value x = " << x << std::endl;
                x = 0;
                do {
                    std::cout << "the input value x should be comprised between -1.57 and 1.57" << std::endl;
                    std::cout << "Enter the input value for x" << std::endl;
                    std::cin >> x;
                } while ((x <= (((-1) * PI) / 2.0)) || ((PI / 2.0) <= x));
                TaylorExpansionTanh te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value exp_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 8:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                x = 0;
                do {
                    std::cout << "the input value x should be comprised between -1 and 1" << std::endl;
                    std::cout << "Enter the input value for x" << std::endl;
                    std::cin >> x;
                } while ((x <= -1) || (1 <= x));
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionArcsinh te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value exp_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 9:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                x = 0;
                do {
                    std::cout << "the input value x should be comprised between -1 and 1" << std::endl;
                    std::cout << "Enter the input value for x" << std::endl;
                    std::cin >> x;
                } while ((x <= -1) || (1 <= x));
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionArcth te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value exp_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 10:
            {
                std::cout << "c=" << c << std::endl;
                x = 0;
                do {
                    std::cout << "the input value x should be comprised between -1.57 and 1.57" << std::endl;
                    std::cout << "Enter the input value for x" << std::endl;
                    std::cin >> x;
                } while ((x <= (((-1) * PI) / 2.0)) || ((PI / 2.0) <= x));
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionSec te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value sinus_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
            case 11:
            {
                std::cout << "c=" << c << std::endl;
                std::cout << "Enter the input value for x" << std::endl;
                x = 0;
                std::cin >> x;
                std::cout << "Input value x = " << x << std::endl;
                TaylorExpansionLambert te(x);
                y = te.calculateValueByTaylorExpansion();
                std::cout << "Output value exp_by_Tailor_Expansion(" << x << ")=" << y << std::endl;
                break;
            }
        }
    }
    while (!quit);
    std::cout << "Goodbye" << std::endl;
    std::cin >> c;
    return -1;
}