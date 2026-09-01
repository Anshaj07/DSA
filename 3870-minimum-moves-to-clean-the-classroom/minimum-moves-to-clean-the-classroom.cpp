class Solution {
public:
    struct State {
        int r, c;
        int energy;
        int mask;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sr = 0, sc = 0;
        int litter = 0;

        vector<vector<int>> id(n, vector<int>(m, -1));

        // Find S and assign an index to every L
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        if (litter == 0)
            return 0;

        int fullMask = (1 << litter) - 1;

        /*
            visited[r][c][energy][mask]
        */
        vector<vector<vector<vector<bool>>>> visited(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litter, false)
                )
            )
        );

        queue<State> q;

        q.push({sr, sc, energy, 0});

        visited[sr][sc][energy][0] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dx[d];
                    int nc = c + dy[d];

                    // Invalid move
                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= m ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Moving costs 1 energy
                    int ne = e - 1;

                    if (ne < 0)
                        continue;

                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Recharge
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (visited[nr][nc][ne][nmask])
                        continue;

                    visited[nr][nc][ne][nmask] = true;

                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};
