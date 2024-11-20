#include <iostream>
using namespace std;

int n;
int arr[100];

int end_of_array;

void remove_block(int s, int e) {
    int temp[n];
    int end_of_temp_array = 0;
    for (int i = 0; i < end_of_array; i++) {
        if (i < s - 1 || i > e - 1) {
            temp[end_of_temp_array] = arr[i];
            end_of_temp_array++;
        }
    }
    end_of_array = end_of_temp_array;
    for (int i = 0; i < end_of_temp_array; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    cin >> n;
    end_of_array = n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int s1, e1;
    cin >> s1 >> e1;
    int s2, e2;
    cin >> s2 >> e2;

    remove_block(s1, e1);
    remove_block(s2, e2);

    cout << end_of_array << "\n";
    for (int i = 0; i < end_of_array; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}