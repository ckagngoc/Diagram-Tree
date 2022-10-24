#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Graph
{
private:
    unsigned int G[100][100];
    unsigned int v;
    unsigned int e;
public:
    Graph(unsigned int = 0, unsigned int = 0);
    void displayMatrix();

    void readFileEdge(string);
    void readFileAdj(string);
    void readFileMatrix(string);

    int rankOfVertex(int);
    void vertexAdjOf(int);
};

Graph::Graph(unsigned int m, unsigned int n)
{
    v = m;
    e = n;
}

void Graph::readFileAdj(string file) {
    ifstream in;
    string num, s;
    v = 0;
    e = 0;
    int vertex;
    in.open(file);
    while(!in.eof()) {
        getline(in, s);
        stringstream ss(s);
        ss >> num;
        v++;
        vertex = stoi(num);
        while(ss >> num) {
            G[vertex][stoi(num)] = 1;
            e++;
        }
    }
    e /= 2;
    v-=1;
} 

void Graph::readFileEdge(string file) {
    ifstream in;
    string num1, num2, s;
    v = 0;
    e = 0;
    in.open(file);
    while(!in.eof()) {
        getline(in, s);
        stringstream ss(s);
        ss >> num1 >> num2; 
        if(v < stoi(num1)) v = stoi(num1);
        if(v < stoi(num2)) v = stoi(num2);
        e++;
        G[stoi(num1)][stoi(num2)] = 1;
        G[stoi(num2)][stoi(num1)] = 1;
    }
} 

void Graph::readFileMatrix(string file) {
    ifstream in;
    string num, s;
    v = 0;
    e = 0;
    
    in.open(file);
    getline(in, s);
    v = stoi(s);
    for(int i = 1;i<=v;i++) {
        getline(in, s);
        stringstream ss(s);
        for(int j = 1;j<=v;j++) {
            ss >> num;
            G[i][j] = stoi(num);
            if(G[i][j] != 0) e++;
        }
    }
    e/=2;
} 

int Graph::rankOfVertex(int vertex) {
    int count = 0;
    for(int i = 1;i<=v;i++) if(G[vertex][i] != 0) count++;
    return count;
};

void Graph::vertexAdjOf(int vertex) {
    int *adj;
    for(int i = 1;i<=v;i++) if(G[vertex][i] != 0) 
        cout << i << " ";
};

void Graph::displayMatrix() {
    for(int i = 1;i <= v;i++) {
        for(int j = 1;j<=v;j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << "So dinh : " << v << "\t" << "So canh :" << e << endl;
    cout << "Nhap dinh muon tim bac: ";
    int n;
    cin >> n;
    cout << "Bac cua dinh "<< n <<" la: " << rankOfVertex(n) << endl;
    cout << "Cac dinh ke voi dinh "<<n<<" la: ";
    vertexAdjOf(n);
}

