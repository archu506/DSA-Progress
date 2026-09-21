/*
Problem: Reorganize String
LeetCode: 767
Topic: Frequency Counting / Greedy
Time: O(n)
Space: O(n)
*/

char* reorganizeString(char* s)
{
    int freq[26] = {0};
    int n = strlen(s);

    char *result = malloc((n + 1) * sizeof(char));

    int max = 0, maxChar = 0;

    for(int i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(freq[i] > max)
        {
            max = freq[i];
            maxChar = i;
        }
    }

    if(max > (n + 1) / 2)
    {
        free(result);
        return "";
    }

    int position = 0;

    while(freq[maxChar] > 0)
    {
        result[position] = 'a' + maxChar;
        freq[maxChar]--;

        position += 2;

        if(position >= n)
        {
            position = 1;
            break;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        while(freq[i] > 0)
        {
            result[position] = 'a' + i;
            freq[i]--;

            position += 2;

            if(position >= n)
            {
                position = 1;
            }
        }
    }

    result[n] = '\0';

    return result;
}