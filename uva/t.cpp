#include <iostream>
#include <list>

using namespace std;

int graph[100][100];
int n, x, y, steps;
list<int> path;

void walk(int pos){
    for(int i = 0; i < n; i++){
        if(graph[pos][i] > 0){
            graph[pos][i] --;
            graph[i][pos] --;
            walk(i);
        }
    }
    path.push_back(pos+1);

}

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        graph[x-1][y-1] ++; //we are using zero index 
        graph[y-1][x-1] ++;
    }
    walk(0);
    while(!path.empty()){
        cout << path.back() << ' ';
        path.pop_back();
    }
}
