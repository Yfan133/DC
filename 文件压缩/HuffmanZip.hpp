#pragma once
#include "HuffmanTree.hpp"
#include <iostream>
#include <string>
#include <vector>

typedef unsigned long long ulg;
struct CharInf
{
	CharInf(const ulg& times);
	CharInf operator+(const CharInf& ch)const;
	bool operator>(const CharInf& ch)const;
	bool operator!();
	
	char _ch;				// �ַ�����
	ulg _times;				// ����Ƶ��
	std::string _encode;	// �ַ���Ӧ�����Ʊ���
};

class HuffmanZip
{
public:
	HuffmanZip();
	void Reduce(const std::string& filePath);
	void CheckVec()
	{
		for (auto ch : ch_vec)
			if (ch._times != 0)
				std::cout << ch._ch << "��" << ch._times << "  ���룺" << ch._encode << std::endl;
	}
private:
	void HuffmanEncode(HuffmanNode<CharInf>* root, std::string& str);
private:
	std::vector<CharInf> ch_vec;
};