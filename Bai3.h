// 3.	Viết c/trình C++ đọc dữ liệu từ file input1_1.txt sau đó đưa ra:
// Ma trận kề biểu diễn đồ thị; D/s cạnh  của đồ thị; Bậc của từng đỉnh.(KQ lưu trong file output1_1.txt): 
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class Bai3 {
    private:
        int** G;
        int V;
    public:
        Bai3() : V(0) {};
        void readFile(string);
        void writeFile(string);
};

void Bai3::readFile(string str) {
    ifstream in;
    in.open(str);
    if(!in.is_open()) {
        cout << "Can't read File " << str << endl;
        exit(1);
    }
    string num, s;
    in >> num;
    V = stoi(num);
    G = new int*[V];
    for(int i = 0;i < V; i++) {
        G[i] = new int[V];
    }
    for(int i = 0;i < V; i++) {
        for(int j = 0;j < V; j++) {
            G[i][j] = 0;
        }
    }
    in >> num;
    int i = 0;
    while(!in.eof()) {
        getline(in, s);
        stringstream ss(s);
        ss >> num;
        while (ss >> num) {
            G[i-1][stoi(num)-1] = 1;
        }
        i++;
    }
    in.close();
}

void Bai3::writeFile(string str) {
    ofstream out;
    out.open(str);
    if(!out.is_open()) {
        cout << "Can't write file " << str << endl;
        exit(1);
    }
    vector<pair<int, int>> edge;
    int* rank;
    int counter = 0;
    rank = new int[V];
    out << V << endl;
    out << "-----------Ma tran ke----------" << endl;
    for(int i = 0;i < V; i++) {
        for(int j = 0;j < V; j++) {
            out << G[i][j] << " ";
            if(G[i][j]) counter++;
            if(G[i][j] && i < j) edge.push_back({i, j});
        }
        rank[i] = counter;
        counter = 0;
        out << endl;
    }
    out << "---------Danh sach canh--------" << endl;
    for(auto it : edge) {
        out << it.first + 1 << " " << it.second + 1 << endl;
    }
    out << "-----------Rank-----------" << endl;
    for(int i = 0;i < V;i++) {
        out << i + 1 << " : " << rank[i] << endl;
    }
    out.close();
}