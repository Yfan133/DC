/*
����ʽ������Kģ�� �� K-Vģ��
	�ײ�Ϊ�����ģ�ͣ�map(key-v)��set(key)��multimap(key-v,key�����ظ�)��multiset(key���ظ�)
	��ͬ�㣺
		1.����STL�ṩ����ʽ����
		2.�ײ�ṹ�������
		3.�����������ƽ���� & ����������
			1.���ҡ����롢ɾ��---��ʱ�临�Ӷ�O(logn)
			2.����������Եõ�����Ľ��
	��ͬ�㣺��Ҫ�Ǵ洢Ԫ�ص����Ͳ�ͬ
ģ�壺
	template<>
���죺map<type1, type2> board;
	map����֮���ڲ��Ǹ���key�����������
���룺
	m.insert(make_pair("apple", "ƻ��"));
	�ײ㣺insert:<iterator, bool>
	����ֵ��first:iterator��second:bool
����[]��
	m["apple"] = "ƻ��"
	m["apple"]-->"ƻ��"
�ײ�ʵ�֣�
T& operator[](const K& x)
{
	return (*((this->insert(make_pair(x, T()))).first))
}
1.��key�Ľڵ㲻���ڣ������insert����һ����������true���´����ĵ�������Ȼ�����ص�[]�ٷ���second������
  �����ڣ������ʧ�ܷ����Ѵ��ڵ�key�ĵ�������false������[]�ٷ���second������
2.����ֵ���������ͣ���˿���ֱ�Ӹ�ֵ


















*/