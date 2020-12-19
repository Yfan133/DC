#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;

#define N 53  //带权重的n个叶子节点数,根据文件中字符种类的个数来确定 
#define M 2*N-1 //n个叶子节点的哈夫曼树具有2*n-1个节点 
typedef struct {
    float weight;//权重
    int lchild;//左儿子
    int rchild;//右儿子
    int parent;//父亲  
}node;//静态三叉链表 
typedef node huffman[M]; //哈夫曼树 
typedef char* huffmancode[N];//存储每个字符的哈夫曼编码表 
void selectmin(huffman& T, int k, int& s1, int& s2) {//选出两个权重最小的节点 
    int min = 1000000, tmp = 0;
    for (int i = 0; i <= k; i++) {
        if (T[i].parent == -1) {
            if (min > T[i].weight) {
                min = T[i].weight;
                tmp = i;
            }
        }
    }
    s1 = tmp;
    min = 100000;
    tmp = 0;
    for (int j = 0; j <= k; j++) {
        if ((T[j].parent == -1) && (j != s1)) {
            if (min > T[j].weight) {
                min = T[j].weight;
                tmp = j;
            }
        }
    }
    s2 = tmp;
}
void CreatTree(huffman& T, float* w, int n) {//构造哈夫曼树 
    if (n <= 1)
        return;
    int i;
    for (i = 0; i < n; i++) {//初始化哈夫曼树的n个叶节点并赋予权重 
        T[i].weight = w[i];
        T[i].lchild = -1;
        T[i].rchild = -1;
        T[i].parent = -1;
    }
    for (; i < M; i++) { //初始化哈夫曼树的非叶节点 
        T[i].weight = 0;
        T[i].lchild = -1;
        T[i].rchild = -1;
        T[i].parent = -1;
    }
    for (i = n; i < M; i++) {
        int s1 = 0, s2 = 0;
        selectmin(T, i - 1, s1, s2);//选出权重最小的叶节点 
        T[s1].parent = i;
        T[s2].parent = i;
        T[i].lchild = s1;
        T[i].rchild = s2;
        T[i].weight = T[s1].weight + T[s2].weight;
    }
}
void bianma(huffman T, huffmancode& HT) {//对每个叶节点进行编码 
    char cd[N];//临时保存每个节点的哈夫曼编码 
    cd[N - 1] = '\0';
    int start, c, f;
    for (int i = 0; i < N; i++) {
        start = N - 1;
        c = i;
        f = T[i].parent;
        while (f != -1) {
            if (T[f].lchild == c) {
                cd[--start] = '0';
            }
            else {
                cd[--start] = '1';
            }
            c = f;
            f = T[f].parent;//递归查找
        }
        HT[i] = (char*)malloc((N - start) * sizeof(char));
        strcpy(HT[i], &cd[start]);
    }
}
void yasuo(huffmancode HC, char ch[]) {//将英文文件压缩为哈夫曼编码文件 
    fstream in, out;
    in.open("hafuman.txt"); //打开英文文件 
    out.open("bianma.txt"); //打开要压缩的哈夫曼编码文件 
    char a[100000];
    in.getline(a, 100001);//读出英文文件的内容 
    int len1 = strlen(a);
    int len2 = strlen(ch);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (ch[j] == a[i]) {
                out << HC[j];//将每个字符的哈夫曼编码输入到哈夫曼编码文件中 
                cout << HC[j];
            }
        }
    }
    in.close();//关闭文件 
    out.close(); //关闭文件 
}
void jiema(huffman T, char* ch, char test[], char* result) {
    int p = M - 1;//根节点 
    int i = 0;//指示串的第i个字符 
    int j = 0;//解码出的第j个字符 
    int len = strlen(test);
    while (i < len) {
        if (test[i] == '0') {
            p = T[p].lchild;
        }
        if (test[i] == '1') {
            p = T[p].rchild;
        }
        if (p < N) {//说明此时为叶节点
            result[j] = ch[p];
            j++;
            p = M - 1;//重新指向根节点 
        }
        i++;
    }
    result[j] = '\0';
}
void jiemawenjian(huffman T, char* ch) {//将从文件读入的哈夫曼编码解码为英文文件 
    fstream in, out;
    in.open("bianma.txt");
    out.open("hafumanbianma.txt");
    char a[100000];
    in.getline(a, 100001);
    char c[100000];
    jiema(T, ch, a, c);
    out << c;
    // cout<<"哈夫曼编码文件中的内容为:"<<endl;
    // cout<<a<<endl;
    cout << "解压为英文文件后的内容为：" << endl;
    cout << c << endl;
    in.close();
    out.close();
}
void dayincode(huffmancode HC, char ch[]) {//打印哈夫曼树的叶节点对应的编码 
    cout << endl;
    cout << "每个字符的哈夫曼编码为：" << endl << endl;
    cout << "字符" << "\t" << "\t" << "哈夫曼编码" << "\t" << "\t" << endl;
    for (int i = 0; i < N; i++) {
        cout << ch[i] << "\t" << "\t" << HC[i] << "\t" << "\t" << endl;
    }
    cout << endl;
}
void dayinshu(huffman T, char ch[]) {
    cout << endl;
    cout << "节点" << "\t" << "\t" << "字符" << "\t" << "\t" << "权重" << "\t" << "\t" << "父亲    " << "\t" << "\t" << "左儿子" << "\t" << "\t" << "右儿子" << "\t" << "\t" << endl;
    for (int i = 0; i < M; i++) {
        if (i < N) {
            cout << i << "\t" << "\t" << ch[i] << "\t" << "\t" << setprecision(9) << T[i].weight << "\t" << "\t" << T[i].parent << "\t" << "\t" << T[i].lchild << "\t" << "\t" << T[i].rchild << "\t" << "\t" << endl;
        }
        else {
            cout << i << "\t" << "\t" << "-1" << "\t" << "\t" << T[i].weight << "\t" << "\t" << T[i].parent << "\t" << "\t" << T[i].lchild << "\t" << "\t" << T[i].rchild << "\t" << "\t" << endl;
        }
    }
}
int main() 
{
    huffman T;
    char a[10000];//读取文件中的字符个数 
    fstream in;
    in.open("hafuman.txt");//打开文件 
    if (in.fail()) {//判断是否成功打开文件 
        cout << "error" << endl;

    }
    else {
        in.getline(a, 10001);//从文件读入10000个字符 
    }
    cout << "从文件读入的字符总数为：" << strlen(a) << endl;
    int x = strlen(a);
    int len[1000] = { 0 };
    for (int i = 0; i < x; i++) {//将读入的字符频数记录下来 
        int m = int(a[i]);
        len[m]++;//字符ascall码为m的字符频数 
    }
    int g = 0;//记录字符个数 
    char ch[1000];//每个字符
    for (int i = 0; i < x; i++) {
        if (len[i] != 0) {
            ch[g] = char(i);//将字符ascall码转化为字符并保存在字符数组中 
            g++;
        }
    }

    cout << "文件中的不同的字符个数为：" << g << endl;
    int str[1000];//字符出现的频数 
    int k = 0;
    for (int i = 0; i < x; i++) {
        if (len[i] != 0) {
            str[k] = len[i];
            k++;
        }
    }
    str[k] = '\0';//字符出现的频数 
    ch[k] = '\0';
    float w[1000];//字符频率 
    int t = strlen(ch);
    cout << "字符\t" << "\t" << "频数\t" << "\t" << "权重\t" << "\t" << endl;
    for (int i = 0; i < t; i++) {
        w[i] = (float(str[i])) / x;
        cout << ch[i] << "\t" << "\t" << str[i] << "\t" << "\t" << w[i] << "\t" << "\t" << endl;
    }
    w[t] = '\0';
    in.close();
    CreatTree(T, w, N);//构建哈夫曼树
    dayinshu(T, ch); //打印哈夫曼树 
    huffmancode HC;//构建哈夫曼编码 
    bianma(T, HC);//对哈夫曼树进行编码 
    dayincode(HC, ch);//打印每个叶节点的编码 
    float sum = 0.0;//哈夫曼树平均编码长度 
    for (int i = 0; i < N; i++) {
        sum += strlen(HC[i]) * w[i];
    }
    cout << "哈夫曼树平均编码长度为" << sum << endl;
    cout << "哈夫曼树的压缩率为：" << 1 - sum / 8 << endl;
    int n = 0;
    cout << "-------------------------------------------" << endl;
    cout << "0.退出                                     |" << endl;
    cout << "1.将英文文件进行压缩为哈夫曼编码文件并显示 |" << endl;
    cout << "2.将哈夫曼编码文件解压为英文文件并显示     |" << endl;
    cout << "3.比较英文文件和解压后的英文文件           |" << endl;
    cout << "-------------------------------------------|" << endl;
    cin >> n;
    while (n) {
        switch (n) {
        case 1:
            cout << "哈夫曼编码文件为：" << endl;
            yasuo(HC, ch);//将英文文件压缩为哈夫曼编码文件 
            break;
        case 2:
            jiemawenjian(T, ch);//将从文件读入的哈夫曼编码解压为英文文件 
            break;
        case 3:
            cout << "读入的文件内容为:" << endl;
            cout << a << endl << endl << endl;
            jiemawenjian(T, ch);
        case 0:
            n = 0;
            break;
        default:
            break;
        }
        cout << "-------------------------------------------" << endl;
        cout << "0.退出                                     |" << endl;
        cout << "1.将英文文件进行压缩为哈夫曼编码文件并显示 |" << endl;
        cout << "2.将哈夫曼编码文件解压为英文文件并显示     |" << endl;
        cout << "3.比较英文文件和解压后的英文文件           |" << endl;
        cout << "-------------------------------------------|" << endl;
        cin >> n;
    }
