#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;


vector< vector< pair<int, double> > > v;
vector<double> visit;
priority_queue<pair<double, int>, vector< pair<double, int> >, greater< pair<double, int> > > pq;

double Dijkstra() {
	visit[0] = 1;
	pq.push(make_pair(1.0, 0));

	while (!pq.empty()) {
		double cost = pq.top().first;
		int location = pq.top().second;
		pq.pop();

		if (visit[location] < cost)
			continue;
		for (int i = 0; i < v[location].size(); i++) {
			int loc = v[location][i].first;
			double wei = cost*v[location][i].second;
			if (visit[loc] > wei) {
				visit[loc] = wei;
				pq.push(make_pair(wei, loc));
			}

		}
	}
	return visit[v.size()-2];
}

int main() {
	int Testcase;
	cin >> Testcase;
	for (int i = 0; i < Testcase; i++) {
		int V, E;
		cin >> V >> E;

		v = vector<vector<pair<int, double>>>(V);

		for (int i = 0; i < V; i++) {
			vector < pair<int, double> > el;
			v.push_back(el);
		}

		int a, b;
		long double weight;
		for (int i = 0; i < E; i++) {
			cin >> a >> b >> weight;
			v[a].push_back(make_pair(b, weight));
			v[b].push_back(make_pair(a, weight));
		}
		visit = vector<double>(V, DBL_MAX);

		//for (int i = 0; i < V; i++)
		//	visit[i] = numeric_limits<int>::max();

		printf("%0.10f\n", Dijkstra());

	}

	return 0;

}