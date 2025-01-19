
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

class kenre
{
public:
    int m, n, sx, sy, ex, ey;
    vector<vector<int>> map;
    int cost = 0;
    int min_dist = 99999;

    void create()
    {
        cin >> m >> n >> sx >> sy >> ex >> ey;

        // create kingdom map
        int tmp;
        for (int i = 0; i < m; i++)
        {
            vector<int> i_row;
            for (int j = 0; j < n; j++)
            {
                cin >> tmp;
                i_row.push_back(tmp);
            }
            map.push_back(i_row);
        }
    }

    int dist(pair<int, int> s)
    {
        int x = abs(s.first - ex);
        int y = abs(s.second - ey);
        return x + y;
    }

    vector<pair<int, int>> legal_actions(pair<int, int> s)
    {
        vector<pair<int, int>> res;
        // pair<int, int> up = make_pair(s.first, s.second + 1);
        // pair<int, int> down = make_pair(s.first, s.second - 1);
        // pair<int, int> left = make_pair(s.first - 1, s.second);
        // pair<int, int> right = make_pair(s.first + 1, s.second);

        // pair<int, int> up_right = make_pair(s.first + 1, s.second+1);
        // pair<int, int> up_left = make_pair(s.first - 1, s.second+1);
        // pair<int, int> down_right = make_pair(s.first + 1, s.second - 1);
        // pair<int, int> down_left = make_pair(s.first - 1, s.second - 1);

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (map[s.first + i][s.second + j] == 0)
                {
                    res.push_back(make_pair(s.first + i, s.second + j));
                }
            }
        }
        return res;
    }

    // chay thuat toan tim kiem
    void find_path(int min_distance, pair<int, int> s)
    {
        vector<pair<int, int>> actions = legal_actions(s);

        for (auto action : actions)
        {
            pair<int, int> last_action = s;
            cost += 1;

            if (dist(action) < min_distance && action.first != ex && action.second != ey)
            {
                find_path(dist(action), action);
            }
            else if (action.first == ex && action.second == ey)
            {
                cout << cost << " \n";
                return;
            }
            cost -= 1;
        }
    }
};

int main()
{
    kenre K;
    K.create();
    cout << "\n";
    K.find_path(K.min_dist, make_pair(K.sx, K.sy));
    return 0;
}