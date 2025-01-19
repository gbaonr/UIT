#include<bits./stdc++.h>
#include<iomanip>

using namespace std;

long long giaithua(long long n)
{
    if (n==1) return 1;
    return (n)*giaithua(n-1);
};

double calculate(double time, string func)
{
    double i = 0;
    double res = 0;
    if (func == "logn")
    {
        return floor(pow(2,time));
    }
    
    if (func == "sqrt(n)")
    {
        return time*time;
    }

    if (func == "n")
    {
        return time;
    }

    if (func == "nlogn")
    {
        double left = 0;
        double right = time*pow(10,6);
        double  mid = 0;
        while (true)
        {
            if (left <= right) 
            {
                mid  = ceil((left + right)/2);
                res = (mid * log2(mid));
 
                // cout << left << ":" << mid << ":" << right << " --> " << res << "; " << time << endl;
                if (res > time)
                {
                    right = mid -1;
                }
                else if (res < time)
                {
                    left = mid + 1;
                }
            }
            else
            {
                break;
            }
        }
                     
        return mid-1;
    }

    if (func == "n^2")
    {
        return floor(sqrt(time));
    }
    
    if (func == "n^3")
    {
        i = floor(pow(time, 1.0/3.0));
        if (pow(i+1,3) <= time)
        {
            return i + 1;
        }
        else 
        return i;
    }

    if (func == "2^n")
    {
        return floor(log2(time));
    }
    if (func == "n!")
    {
        res = 1;
        i = 1;
        while (res <= time)
        {
            i++;
            res = giaithua(i);
        }
    }

    return i-1;

};

void print_(vector<double> time, string func){
    cout << "With " << func << ":" << endl;
    cout << fixed << setprecision(2);
    if (func == "logn")
    {
        cout << "    In 1 second, max n = 2^"  << (time[0]) <<  endl;
        cout << "    In 1 minute, max n = 2^"  << (time[1]) <<  endl;
        cout << "    In 1 hour, max n = 2^"  << (time[2]) <<  endl;
        cout << "    In 1 day, max n = 2^"  << (time[3]) <<  endl;
        cout << "    In 1 day, max n = 2^"  << (time[4]) <<  endl;
        cout << "    In 1 year, max n = 2^" <<  (time[5]) << endl;
        cout << "    In 1 century, max n = 2^" <<  (time[6]) << endl;
        return;
    }

    double second_n = calculate(time[0], func);
    cout << "    In 1 second, max n = "  << second_n <<  endl;

    double minute_n = calculate(time[1], func);
    cout << "    In 1 minute, max n = "  << minute_n <<  endl;

    double hour_n = calculate(time[2], func);
    cout << "    In 1 hour, max n = "  << hour_n <<  endl;

    double day = calculate(time[3], func);
    cout << "    In 1 day, max n = "  << day <<  endl;

    double month = calculate(time[4], func);
    cout << "    In 1 month, max n = "  << month <<  endl;

    double year_n = calculate(time[5], func);
    cout << "    In 1 year, max n = " <<  year_n << endl;

    double century_n = calculate(time[6], func);
    cout << "    In 1 century, max n = " <<  century_n << endl;
    
};

int main()
{
    double second = pow(10, 6)  ; // 1second = 10^6 microseconds
    double minute = second * 60;
    double hour = minute * 60;
    double day = hour * 24;
    double month = day * 30;
    double year = day * 365; // 1 year = 365 days
    double century = year * 100; // 1 century = 100 years

    vector<double> time = {second, minute, hour, day, month, year, century};

    for (auto t : time){
        cout << t << "; ";
    }
    cout << endl;
    print_(time, "logn");
    print_(time, "sqrt(n)");
    print_(time, "n");
    print_(time, "nlogn");
    print_(time, "n^2");
    print_(time, "n^3");
    print_(time, "2^n");
    print_(time, "n!");
    

    return 0;
}