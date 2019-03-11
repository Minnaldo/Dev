#include <iostream>
#include <string>

using namespace std;

int next[99999]; // idx :: 1~m

void preproccess(string text, string pattern, int test_size, int pat_size)
{
    //preproccess
    next[0] = -1;
    int i = 0, j = -1;

    while (i < pat_size)
    {
        while (j >= 0 && pattern[j] != pattern[i])
        {
            j = next[j];
        }

        i++;
        j++;
        next[i] = j;
    }
}

int matching(string text, string pattern, int text_size, int pat_size)
{
    int i = 0, j = 0;

    while (j < text_size)
    {
        while (j >= 0 && pattern[j] != text[i])
        {
            j = next[j];
        }

        i++;
        j++;

        if (j == pat_size)
        {
            return i - j;
        }
    }
}

int main(int argc, char const *argv[])
{
    string text = "";
    string pattern = "";
    int txt_size = text.size();
    int pat_size = pattern.size();

    preproccess(text, pattern, txt_size, pat_size);

    int ret = matching(text, pattern, txt_size, pat_size);

    return 0;
}