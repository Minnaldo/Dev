#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// abs( meet - now )
// meet < now --> 24:00:00 - now
// else ( meet > now ) --> jsut doing

string solution(string now, string meet)
{
    string ans = "";

    struct tm tm;
    // strptime(now.c_str(), "%T", &tm);
    // time_t t = mktime(&tm);
    // strptime(meet.c_str(), "%T", &tm);
    // time_t t2 = mktime(&tm);
    tm.tm_hour = stoi(now.substr(0, 2));
    tm.tm_min = stoi(now.substr(3, 2));
    tm.tm_sec = stoi(now.substr(7, 2));
    time_t t = mktime(&tm);
    tm.tm_hour = stoi(meet.substr(0, 2));
    tm.tm_min = stoi(meet.substr(3, 2));
    tm.tm_sec = stoi(meet.substr(7, 2));
    time_t t2 = mktime(&tm);

    double diff = difftime(t2, t);

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
    freopen("input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        string ans = "";
        string now, meet;

        // scanf("%s %s", &now, &meet);
        cin >> now >> meet;

        ans = solution(now, meet);
        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}