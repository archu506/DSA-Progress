#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t)
{
    int left = 0, start = 0;
    int min = INT_MAX;
    int right = 0;

    int freqt[128] = {0};
    int freqs[128] = {0};

    int required = 0, formed = 0;

    // Count required characters in t
    for(int i = 0; t[i] != '\0'; i++)
    {
        if(freqt[t[i]] == 0)
        {
            required++;
        }

        freqt[t[i]]++;
    }

    // Sliding window
    for(right = 0; right < strlen(s); right++)
    {
        freqs[s[right]]++;

        if(freqs[s[right]] == freqt[s[right]])
        {
            formed++;
        }

        // Shrink window while it is valid
        while(formed == required)
        {
            int len = right - left + 1;

            if(min > len)
            {
                min = len;
                start = left;
            }

            freqs[s[left]]--;

            if(freqs[s[left]] < freqt[s[left]])
            {
                formed--;
            }

            left++;
        }
    }

    // No valid window
    if(min == INT_MAX)
    {
        return "";
    }

    // Create result string
    char *result = malloc((min + 1) * sizeof(char));

    strncpy(result, s + start, min);
    result[min] = '\0';

    return result;
}