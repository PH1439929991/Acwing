#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid(vector<int>& permutation, int num, int position) {
    if (position == 0) {
        return true;  // 第一个数字可以是任意数字
    }

    int diff = abs(permutation[position - 1] - num);
    return diff == 2 || diff == 3;
}

void generate_permutation(int n) {
    vector<int> permutation(n);
    int left = 0;  // 左边起始位置
    int right = n - 1;  // 右边起始位置

    for (int num = n; num >= 1; num--) {
        // 从左边添加数字
        if (is_valid(permutation, num, left)) {
            permutation[left] = num;
            left++;
        } else if (is_valid(permutation, num, right)) {
            // 如果左边不符合条件，尝试从右边添加数字
            permutation[right] = num;
            right--;
        } else {
            // 如果无法添加数字，排列不存在
            cout << "无法生成满足条件的排列。" << endl;
            return;
        }
    }

    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "请输入n的值：";
    cin >> n;

    if (n < 1) {
        cout << "n必须大于等于1" << endl;
    } else {
        generate_permutation(n);
    }

    return 0;
}