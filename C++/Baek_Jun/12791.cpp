#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string arr[25][2] = {{"1967", "DavidBowie"}, {"1969", "SpaceOddity"}, {"1970", "TheManWhoSoldTheWorld"}, {"1971", "HunkyDory"}, {"1972", "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"}, {"1973", "AladdinSane"}, {"1973", "PinUps"}, {"1974", "DiamondDogs"}, {"1975", "YoungAmericans"}, {"1976", "StationToStation"}, {"1977", "Low"}, {"1977", "Heroes"}, {"1979", "Lodger"}, {"1980", "ScaryMonstersAndSuperCreeps"}, {"1983", "LetsDance"}, {"1984", "Tonight"}, {"1987", "NeverLetMeDown"}, {"1993", "BlackTieWhiteNoise"}, {"1995", "1.Outside"}, {"1997", "Earthling"}, {"1999", "Hours"}, {"2002", "Heathen"}, {"2003", "Reality"}, {"2013", "TheNextDay"}, {"2016", "BlackStar"}};

    int Q;
    // scanf("%d", &Q);
    cin >> Q;
    string ans[25];
    for (int i = 0; i < Q; i++)
    {
        int S, E;
        // scanf("%d %d", &S, &E);
        cin >> S >> E;

        int cnt = 0, idx = 0;
        for (int j = 0; j < 25; j++)
        {
            if (arr[j][0] == to_string(S))
            {
                cnt++;
                ans[idx] = arr[j][0] + " " + arr[j][1];
            }
        }

        cout << cnt << endl;
        for (int a = 0; a < idx; a++)
        {
            cout << ans[a] << endl;
        }
    }
    return 0;
}