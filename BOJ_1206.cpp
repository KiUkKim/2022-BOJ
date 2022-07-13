#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

vector<float> problem_avg;
vector<int> tmp;
int rlt;
float num = 1000;

int main()
{
    fastio;

    int case_p;

    cin >> case_p;

    for (int i = 0; i < case_p; i++)
    {
        float avg;

        cin >> avg;

        problem_avg.push_back(avg);
    }

    int person_num = 1;
    while (1)
    {
        int cnt = 0;

        for (int i = 0; i < case_p; i++)
        {
            tmp.clear();
            // 모든 사람이 0을 주면 끝나는 문제로 쉽게 판별 불가하기때문에 여러개의 케이스의 경우, 다른 케이스로 판별
            if (problem_avg[i] == 0.000)
            {
                cnt++;
                continue;
            }

            int check_sum = problem_avg[i] * 1000 * person_num;

            if (check_sum / 1000 == 0)
            {
                break;
            }

            else if (check_sum % 1000 == 0)
            {
                cnt++;
                continue;
            }

            else
            {
                // int integer_num = ceil(problem_avg[i] * person_num);
                tmp.push_back(problem_avg[i] * person_num);
                int float_num = ((float)tmp[0] / (float)person_num) * 1000;

                if (float_num == problem_avg[i] * 1000)
                {
                    cnt++;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        if (cnt == case_p)
        {
            rlt = person_num;
            break;
        }

        person_num++;
    }

    cout << rlt << '\n';

    return 0;
}