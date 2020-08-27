ii go(int cur, int t_left) {
// returns a pair (tollpaid, timeneeded)
if (t_left < 0) return ii(INF, INF);
// invalid state, prune
if (cur == n - 1) return ii(0, 0); // at market, tollpaid=0, timeneeded=0
if (memo[cur][t_left] != ii(-1, -1)) return memo[cur][t_left];
ii ans = ii(INF, INF);
for (int X = 0; X < n; X++) if (cur != X) {
// go to another city
ii nextCity = go(X, t_left - travelTime[cur][X]);
// recursive step
if (nextCity.first + toll[cur][X] < ans.first) {
// pick the min cost
ans.first = nextCity.first + toll[cur][X];
ans.second = nextCity.second + travelTime[cur][X];
} }
return memo[cur][t_left] = ans; }
