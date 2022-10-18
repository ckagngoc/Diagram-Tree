// 2.	Viết c/trình C++ đọc dữ liệu từ file input1.txt sau đó đưa ra biểu diễn 
// của đồ thị dưới dạng d/s kề và d/s cạnh (KQ lưu lần lượt trong file input1_1.txt và input1_2.txt)
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Bai2 {
    private:
        vector<pair<int, int>> edge;
        vector<int> adj[10000]; 
        int V;
        int E;
    public:
        Bai2() : V(0), E(0) {};
        void readFile(string);
        void writeFile(string, string);
};

void Bai2::readFile(string str) {
    ifstream in;
    int *G;
    in.open(str);
    in >> V;
    G = new int[V*V];
    for(int i = 0;i<V;i++) {
        for(int j = 0;j<V;j++) {
            in >> *(G + i*V + j);
            in.get();
        }
    }

    for(int i = 0;i<V;i++) {
        for(int j = 0;j<V;j++) {
            if(*(G + i*V + j) && i <= j) {
                edge.push_back({i, j});
                E++;
            }
        }
    }

    for(int i = 0;i<V;i++) {
        for(int j = 0;j<V;j++) {
            if(*(G + i*V + j)) {
                adj[i].push_back(j);
            }
        }
    }

    in.close();
}

void Bai2::writeFile(string str1, string str2) {
    ofstream out_1, out_2;
    out_1.open(str1);
    out_2.open(str2);
    out_1 << V << " " << E << endl;
    out_2 << V << " " << E << endl;
    for(auto it : edge) {
        out_1<<it.first + 1 <<" "<<it.second + 1<<endl;
    }
    for(int i = 0;i<V;i++) {
        out_2 << i + 1 << "\t";
        for(auto it : adj[i]) {
            out_2 << it + 1 << " ";
        }
        out_2 << endl;
    }
    out_1.close();
    out_2.close();
}