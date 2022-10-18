// 4.	Viết c/trình C++ đọc dữ liệu từ file input1_2.txt sau đó đưa ra: 
// Ma trận kề biểu diễn đồ thị; D/s kề của đồ thị; Bậc của từng đỉnh. (KQ lưu trong file output1_2.txt) 
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Bai4 {
    private:
        int** G;
        int V;
    public:
        Bai4() : V(0) {};
        void readFile(string);
        void writeFile(string);
};

void Bai4::readFile(string str) {
    ifstream in;
    in.open(str);
    if(!in.is_open()) {
        cout << "Can't read File " << str << endl;
        exit(1);
    }
    string num, s, num1, num2;
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
    while(in  >> num1 >> num2) {
        G[stoi(num1) - 1][stoi(num2) - 1] = 1;
        G[stoi(num2) - 1][stoi(num1) - 1] = 1;
    }
    in.close();
}

void Bai4::writeFile(string str) {
    ofstream out;
    out.open("output2.txt");
    if(!out.is_open()) {
        cout << "Can't write file " << str << endl;
        exit(1);
    }
    vector<int> adj[10000];
    int* rank;
    int counter = 0;
    rank = new int[V];
    out << V << endl;
    out << "-----------Ma tran ke----------" << endl;
    for(int i = 0;i < V; i++) {
        for(int j = 0;j < V; j++) {
            out << G[i][j] << " ";
            if(G[i][j]) {
                counter++;
                adj[i].push_back(j);   
            }
        }
        rank[i] = counter;
        counter = 0;
        out << endl;
    }
    out << "---------Danh sach ke--------" << endl;
    for(int i = 0 ;i < V;i++){
        out << i + 1 << " : ";
        for(auto it : adj[i]) {
            out << it + 1 << " ";
        }
        out << endl;
    }
    out << "-----------Rank-----------" << endl;
    for(int i = 0;i < V;i++) {
        out << i + 1 << " : " << rank[i] << endl;
    }
    out.close();
}