#pragma once
#include "HuffmanTree.hpp"
#include <iostream>
#include <string>
#include <vector>

typedef unsigned long long ulg;
typedef unsigned char uch;
struct CharInf
{
	CharInf(const ulg& times);
	CharInf operator+(const CharInf& ch)const;
	bool operator>(const CharInf& ch)const;
	bool operator!=(const CharInf& ch)const;
	
	uch _ch;				// 字符类型
	ulg _times;				// 出现频率
	std::string _encode;	// 字符对应二进制编码
};

class HuffmanZip
{
public:
	HuffmanZip();
	void Reduce(const std::string& filePath);
	void WriteHeadInf(FILE* fpout, const std::string& filePath);
	void UnReduce(const std::string& filePath);
	void GetLine(FILE* fpin, std::string& buf);
	void CheckVec()
	{
		for (auto ch : ch_vec)
			if (ch._times != 0)
				std::cout << ch._ch << "：" << ch._times << "  编码：" << ch._encode << std::endl;
	}
private:
	void HuffmanEncode(HuffmanNode<CharInf>* root, std::string& str);
private:
	std::vector<CharInf> ch_vec;
};