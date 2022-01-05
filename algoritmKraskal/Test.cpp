#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <map>
using namespace std;


//структура граней древа
struct Edge{
    char A, B;
    int Weigh;
    Edge(){}
    Edge(char a, char b, int weigh){
        A = a;
        B = b;
        Weigh = weigh;
    }
};

/*
оператор нужный для функции sort чтобы указать что именно
нужно сравнивать для сортировки
*/
bool operator < (const Edge& edge1, const Edge& edge2) {
    return edge1.Weigh < edge2.Weigh;
}

//По сути исключающий или
bool operator xor (const vector<char>& PointsFromGraph, const Edge& edge1) {
    bool FoundA = false;
    bool FoundB = false;
    for(int i = 0; i != PointsFromGraph.size(); i++) {
        if(edge1.A == PointsFromGraph[i])
            FoundA = true;
        if(edge1.B == PointsFromGraph[i])
            FoundB = true;
    }
    
    return(FoundA xor FoundB);
}

void PrintGraph(vector<Edge> InputGraph){
    for(auto iter = InputGraph.begin(); iter != InputGraph.end(); iter++){
        cout << "Edge: " << (*iter).A << " to " << (*iter).B << " weigh: " << (*iter).Weigh << endl;
    }
    cout << endl;
}

int CreateAmountOfCombination (vector <Edge> edges) {
    map<char, char> mp;

    for(auto i : edges) {
        mp[i.A] = 'P';
        mp[i.B] = 'K';
    }

    return mp.size();
}

int main() {
    vector <Edge> graph {Edge('B', 'D', 2), Edge('B', 'A', 7), 
    Edge('D', 'C', 6), Edge('B', 'C', 11), Edge('A', 'C', 8),
    Edge('D', 'E', 11), Edge('C', 'E', 9), Edge('D', 'F', 9),
    Edge('E', 'F', 11)};
    //список посещённых точек
    vector <char> points ;
    //итоговое остовное древо
    vector <Edge> tree;

    sort(graph.begin(), graph.end());

    //Добавляем первые звенья в дерево
    for(int i = 0; i != graph.size(); i++) {
        if(graph[i].A != graph[i].B){
            tree.push_back(graph[i]);
            points.push_back(graph[i].A);
            points.push_back(graph[i].B);
            break;
        }
    }

    int NumberOfPoints = CreateAmountOfCombination(graph);

    for(int i = 1; i != NumberOfPoints; i++) {
        if((graph[i].A != graph[i].B) and (points xor graph[i])){
            tree.push_back(graph[i]);
            
            auto FoundedA = find(points.begin(), points.end(), graph[i].A);
            auto FoundedB = find(points.begin(), points.end(), graph[i].B);
            if(FoundedA == points.end())
                points.push_back(graph[i].A);
            else if(FoundedB == points.end())
                points.push_back(graph[i].B);
        }
    }

    PrintGraph(tree);

    return 0;
}