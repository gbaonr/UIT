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
    void find_path()
    {
        int cost = 0;
        pair<int, int> last_action = make_pair(sx, sy);
        while (sx != ex && sy != ey)
        {
            cout << "Lap voi cost = " << cost << "\n";
            // find legal actions
            vector<pair<int, int>> actions = legal_actions(make_pair(sx, sy));

            cout << "Actions:";
            for (auto action : actions)
            {
                cout << "   (" << action.first << ", " << action.second << ", " << map[action.first][action.second] << ")";
            }
            cout << "\n";

            if (actions.size() == 0)
            {
                cout << "-unreachable-";
                return;
            }

            // choose the best action
            pair<int, int> best_action;
            int min_dist = 99999;
            for (auto &action : actions)
            {
                if (action.first == last_action.first && action.second == last_action.second)
                    continue;
                int current_dist = dist(action);
                if (current_dist <= min_dist)
                {
                    min_dist = current_dist;
                    best_action = action;
                }
            }
            if (min_dist > dist(make_pair(sx, sy)))
            {
                cout << "cant decrease dist";
                break;
            }
            cout << "\tChose: (" << best_action.first << ", " << best_action.second << "), dist = " << min_dist << "\n";

            // implement the best_action

            last_action = make_pair(sx, sy);
            sx = best_action.first;
            sy = best_action.second;
            cost += 1;
        }

        // da tim duoc duong di
        cout << cost;
    }
};

int main()
{
    kenre K;
    K.create();
    cout << "\n";
    K.find_path();
    return 0;
}