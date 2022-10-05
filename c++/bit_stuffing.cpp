#include <bits/stdc++.h>
using namespace std;
#define Fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long
#define endl "\n"

int32_t main()
{
    Fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int i = 0, count = 0;
        char databits[80];
        printf("Enter Data Bits: ");
        scanf("%s", databits);
        printf("Data Bits Before Bit Stuffing: %s", databits);
        printf("\nData Bits After Bit stuffing: ");
        for (i = 0; i < strlen(databits); i++)
        {
            if (databits[i] == '1')
                count++;
            else
                count = 0;
            printf("%c\n", databits[i]);
            if (count == 5)
            {
                printf("0");
                count = 0;
            }
        }
            // cout<<endl;
    }

    return 0;
}