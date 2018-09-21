#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string answer = "";
    string sentence = "cHaEaLaLaOcbWORLDb";
    vector<string> wordV;

    // for (int i = 0; i < sentence.size(); i++)
    int strIdx = 0;
    while (!sentence.empty())
    {
        
        int ctoi = (int)(sentence.at(strIdx));
        if (ctoi > 96 && ctoi < 123)
        {
            cout<<"Find Special Character!!"<<endl;
            //특수문자
            if (strIdx == 0) //FIXME: Wrong condition
            {           //규칙2
                string tmpstr;
                
                auto itr = find(sentence.begin() + 1, sentence.end(), sentence.at(strIdx));
                for (auto it = sentence.begin(); it <= itr; it++)
                {
                    tmpstr += *it;
                }
                sentence.erase(sentence.begin(), itr + 1);
                wordV.push_back(tmpstr);
                strIdx = 0;     //FIXME:
            }
            else
            { //규칙1
                auto itrRule1 = find(sentence.begin(), sentence.end(), sentence.at(strIdx));
            }
        }

        strIdx++;
    }

    for (int j = 0; j < wordV.size(); j++)
    {
        cout << wordV.at(j) << endl;
    }

    cout << "Answer : " << answer << endl;

    return 0;
}
