// 1.	Tạo 2 file input1.txt và input2.txt để lưu ma trận kề biểu diễn cho 2 đồ thị hình bên.
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Bai2.h"
#include "Bai3.h"
#include "Bai4.h"
#include "Bai5.h"
#include "Bai6.h"
using namespace std;


int main(int argc, char const *argv[]) {
    Bai2 handle2;
    handle2.readFile("input1.txt");
    handle2.writeFile("input1_2.txt", "input1_1.txt");
    Bai3 handle3;
    handle3.readFile("input1_1.txt");
    handle3.writeFile("output1.txt");
    Bai4 handle4;
    handle4.readFile("input1_2.txt");
    handle4.writeFile("output2.txt");
    Bai5 handle5;
    handle5.readFile("input2.txt");
    handle5.writeFile("input2_2.txt", "input2_1.txt");
    Bai6 handle6;
    handle6.readFile("input2_1.txt");
    handle6.writeFile("output2_1.txt");
    return 0;
}
