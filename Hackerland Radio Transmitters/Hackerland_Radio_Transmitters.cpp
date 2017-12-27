#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//int count_radio_transmitters(int)

void print_array(int *ar, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << ' ';
    }
    cout << endl;
}

int less_array(int *ar, int start, int val, int n)
{
   int l;
   for (int i = start; i < n; i++) {
       if (ar[i] <= val) {
           l = i;
       } else break;
   } 
   return l;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    int k = 0;
    cin >> n;
    cin >> k;

    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    sort(ar, ar + n);

    int i = 0;
    int num_transmitters = 0;

    int mid = ar[0] + k;
    int index_middle, right = 0;


    for (int i = 0; i < n;) {

//        cout << "i = " << i << ", n = " << n << endl;

        if (i == n-1) {
//            cout << "In here!" << endl;
            num_transmitters ++;
            break;
        }
        index_middle = less_array(ar,i,  mid, n);
        num_transmitters ++;
        i = index_middle;
        right = less_array(ar, i, ar[index_middle] + k, n);
        right ++;


        // cout << "Mid_index = " << index_middle << ", Right = " << right << endl;
        // cout << "Mid = " << ar[index_middle] << ", Next = " << ar[right] << endl;
        // cout << "Num_transmitters = " << num_transmitters << endl;

        mid = ar[right] + k;
        i = right;
        
    }

    cout << num_transmitters << endl;

    return 0;
}
