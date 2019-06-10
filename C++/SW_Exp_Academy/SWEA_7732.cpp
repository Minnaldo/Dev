#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// abs( meet - now )
// meet < now --> 24:00:00 - now
// else ( meet > now ) --> jsut doing
int conv(string str)
{
    int ret = 0;
    try
    {
        ret += stoi(str.substr(0, 2)) * 3600;
        ret += stoi(str.substr(3, 2)) * 60;
        ret += stoi(str.substr(6, 2));
    }
    catch (exception e)
    {
    }
    return ret;
}

string solution(string now, string meet)
{
    string ans = "";
    int nTime = conv(now);
    int mTime = conv(meet);

    int diff = mTime - nTime;

    if (diff < 0)
        diff += (24 * 3600);

    int hour, min, sec;
    hour = diff / (3600);
    diff = diff - (hour * 3600);
    min = diff / (60);
    diff = diff - (min * 60);
    sec = diff;

    stringstream str;
    str << setw(2) << setfill('0') << hour;
    str << ":";
    str << setw(2) << setfill('0') << min;
    str << ":";
    str << setw(2) << setfill('0') << sec;

    ans = str.str();
    return ans;
}

int main(int argc, char const *argv[])
{
    int t = 1;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        string now, meet;
        cin >> now >> meet;

        cout << "#" << tc << " " << solution(now, meet) << endl;
    }
    return 0;
}