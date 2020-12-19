#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;

#define N 53  //��Ȩ�ص�n��Ҷ�ӽڵ���,�����ļ����ַ�����ĸ�����ȷ�� 
#define M 2*N-1 //n��Ҷ�ӽڵ�Ĺ�����������2*n-1���ڵ� 
typedef struct {
    float weight;//Ȩ��
    int lchild;//�����
    int rchild;//�Ҷ���
    int parent;//����  
}node;//��̬�������� 
typedef node huffman[M]; //�������� 
typedef char* huffmancode[N];//�洢ÿ���ַ��Ĺ���������� 
void selectmin(huffman& T, int k, int& s1, int& s2) {//ѡ������Ȩ����С�Ľڵ� 
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
void CreatTree(huffman& T, float* w, int n) {//����������� 
    if (n <= 1)
        return;
    int i;
    for (i = 0; i < n; i++) {//��ʼ������������n��Ҷ�ڵ㲢����Ȩ�� 
        T[i].weight = w[i];
        T[i].lchild = -1;
        T[i].rchild = -1;
        T[i].parent = -1;
    }
    for (; i < M; i++) { //��ʼ�����������ķ�Ҷ�ڵ� 
        T[i].weight = 0;
        T[i].lchild = -1;
        T[i].rchild = -1;
        T[i].parent = -1;
    }
    for (i = n; i < M; i++) {
        int s1 = 0, s2 = 0;
        selectmin(T, i - 1, s1, s2);//ѡ��Ȩ����С��Ҷ�ڵ� 
        T[s1].parent = i;
        T[s2].parent = i;
        T[i].lchild = s1;
        T[i].rchild = s2;
        T[i].weight = T[s1].weight + T[s2].weight;
    }
}
void bianma(huffman T, huffmancode& HT) {//��ÿ��Ҷ�ڵ���б��� 
    char cd[N];//��ʱ����ÿ���ڵ�Ĺ��������� 
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
            f = T[f].parent;//�ݹ����
        }
        HT[i] = (char*)malloc((N - start) * sizeof(char));
        strcpy(HT[i], &cd[start]);
    }
}
void yasuo(huffmancode HC, char ch[]) {//��Ӣ���ļ�ѹ��Ϊ�����������ļ� 
    fstream in, out;
    in.open("hafuman.txt"); //��Ӣ���ļ� 
    out.open("bianma.txt"); //��Ҫѹ���Ĺ����������ļ� 
    char a[100000];
    in.getline(a, 100001);//����Ӣ���ļ������� 
    int len1 = strlen(a);
    int len2 = strlen(ch);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (ch[j] == a[i]) {
                out << HC[j];//��ÿ���ַ��Ĺ������������뵽�����������ļ��� 
                cout << HC[j];
            }
        }
    }
    in.close();//�ر��ļ� 
    out.close(); //�ر��ļ� 
}
void jiema(huffman T, char* ch, char test[], char* result) {
    int p = M - 1;//���ڵ� 
    int i = 0;//ָʾ���ĵ�i���ַ� 
    int j = 0;//������ĵ�j���ַ� 
    int len = strlen(test);
    while (i < len) {
        if (test[i] == '0') {
            p = T[p].lchild;
        }
        if (test[i] == '1') {
            p = T[p].rchild;
        }
        if (p < N) {//˵����ʱΪҶ�ڵ�
            result[j] = ch[p];
            j++;
            p = M - 1;//����ָ����ڵ� 
        }
        i++;
    }
    result[j] = '\0';
}
void jiemawenjian(huffman T, char* ch) {//�����ļ�����Ĺ������������ΪӢ���ļ� 
    fstream in, out;
    in.open("bianma.txt");
    out.open("hafumanbianma.txt");
    char a[100000];
    in.getline(a, 100001);
    char c[100000];
    jiema(T, ch, a, c);
    out << c;
    // cout<<"�����������ļ��е�����Ϊ:"<<endl;
    // cout<<a<<endl;
    cout << "��ѹΪӢ���ļ��������Ϊ��" << endl;
    cout << c << endl;
    in.close();
    out.close();
}
void dayincode(huffmancode HC, char ch[]) {//��ӡ����������Ҷ�ڵ��Ӧ�ı��� 
    cout << endl;
    cout << "ÿ���ַ��Ĺ���������Ϊ��" << endl << endl;
    cout << "�ַ�" << "\t" << "\t" << "����������" << "\t" << "\t" << endl;
    for (int i = 0; i < N; i++) {
        cout << ch[i] << "\t" << "\t" << HC[i] << "\t" << "\t" << endl;
    }
    cout << endl;
}
void dayinshu(huffman T, char ch[]) {
    cout << endl;
    cout << "�ڵ�" << "\t" << "\t" << "�ַ�" << "\t" << "\t" << "Ȩ��" << "\t" << "\t" << "����    " << "\t" << "\t" << "�����" << "\t" << "\t" << "�Ҷ���" << "\t" << "\t" << endl;
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
    char a[10000];//��ȡ�ļ��е��ַ����� 
    fstream in;
    in.open("hafuman.txt");//���ļ� 
    if (in.fail()) {//�ж��Ƿ�ɹ����ļ� 
        cout << "error" << endl;

    }
    else {
        in.getline(a, 10001);//���ļ�����10000���ַ� 
    }
    cout << "���ļ�������ַ�����Ϊ��" << strlen(a) << endl;
    int x = strlen(a);
    int len[1000] = { 0 };
    for (int i = 0; i < x; i++) {//��������ַ�Ƶ����¼���� 
        int m = int(a[i]);
        len[m]++;//�ַ�ascall��Ϊm���ַ�Ƶ�� 
    }
    int g = 0;//��¼�ַ����� 
    char ch[1000];//ÿ���ַ�
    for (int i = 0; i < x; i++) {
        if (len[i] != 0) {
            ch[g] = char(i);//���ַ�ascall��ת��Ϊ�ַ����������ַ������� 
            g++;
        }
    }

    cout << "�ļ��еĲ�ͬ���ַ�����Ϊ��" << g << endl;
    int str[1000];//�ַ����ֵ�Ƶ�� 
    int k = 0;
    for (int i = 0; i < x; i++) {
        if (len[i] != 0) {
            str[k] = len[i];
            k++;
        }
    }
    str[k] = '\0';//�ַ����ֵ�Ƶ�� 
    ch[k] = '\0';
    float w[1000];//�ַ�Ƶ�� 
    int t = strlen(ch);
    cout << "�ַ�\t" << "\t" << "Ƶ��\t" << "\t" << "Ȩ��\t" << "\t" << endl;
    for (int i = 0; i < t; i++) {
        w[i] = (float(str[i])) / x;
        cout << ch[i] << "\t" << "\t" << str[i] << "\t" << "\t" << w[i] << "\t" << "\t" << endl;
    }
    w[t] = '\0';
    in.close();
    CreatTree(T, w, N);//������������
    dayinshu(T, ch); //��ӡ�������� 
    huffmancode HC;//�������������� 
    bianma(T, HC);//�Թ����������б��� 
    dayincode(HC, ch);//��ӡÿ��Ҷ�ڵ�ı��� 
    float sum = 0.0;//��������ƽ�����볤�� 
    for (int i = 0; i < N; i++) {
        sum += strlen(HC[i]) * w[i];
    }
    cout << "��������ƽ�����볤��Ϊ" << sum << endl;
    cout << "����������ѹ����Ϊ��" << 1 - sum / 8 << endl;
    int n = 0;
    cout << "-------------------------------------------" << endl;
    cout << "0.�˳�                                     |" << endl;
    cout << "1.��Ӣ���ļ�����ѹ��Ϊ�����������ļ�����ʾ |" << endl;
    cout << "2.�������������ļ���ѹΪӢ���ļ�����ʾ     |" << endl;
    cout << "3.�Ƚ�Ӣ���ļ��ͽ�ѹ���Ӣ���ļ�           |" << endl;
    cout << "-------------------------------------------|" << endl;
    cin >> n;
    while (n) {
        switch (n) {
        case 1:
            cout << "�����������ļ�Ϊ��" << endl;
            yasuo(HC, ch);//��Ӣ���ļ�ѹ��Ϊ�����������ļ� 
            break;
        case 2:
            jiemawenjian(T, ch);//�����ļ�����Ĺ����������ѹΪӢ���ļ� 
            break;
        case 3:
            cout << "������ļ�����Ϊ:" << endl;
            cout << a << endl << endl << endl;
            jiemawenjian(T, ch);
        case 0:
            n = 0;
            break;
        default:
            break;
        }
        cout << "-------------------------------------------" << endl;
        cout << "0.�˳�                                     |" << endl;
        cout << "1.��Ӣ���ļ�����ѹ��Ϊ�����������ļ�����ʾ |" << endl;
        cout << "2.�������������ļ���ѹΪӢ���ļ�����ʾ     |" << endl;
        cout << "3.�Ƚ�Ӣ���ļ��ͽ�ѹ���Ӣ���ļ�           |" << endl;
        cout << "-------------------------------------------|" << endl;
        cin >> n;
    }
