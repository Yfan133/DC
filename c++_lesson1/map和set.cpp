/*
关联式容器：K模型 和 K-V模型
	底层为红黑树模型：map(key-v)，set(key)，multimap(key-v,key可以重复)，multiset(key可重复)
	共同点：
		1.都是STL提供关联式容器
		2.底层结构：红黑树
		3.红黑树：二叉平衡树 & 二叉搜索树
			1.查找、插入、删除---》时间复杂度O(logn)
			2.中序遍历可以得到有序的结果
	不同点：主要是存储元素的类型不同
模板：
	template<>
构造：map<type1, type2> board;
	map构造之后，内部是根据key来进行排序的
插入：
	m.insert(make_pair("apple", "苹果"));
	底层：insert:<iterator, bool>
	返回值：first:iterator，second:bool
重载[]：
	m["apple"] = "苹果"
	m["apple"]-->"苹果"
底层实现：
T& operator[](const K& x)
{
	return (*((this->insert(make_pair(x, T()))).first))
}
1.若key的节点不存在，则调用insert创建一个，并返回true和新创建的迭代器，然后重载的[]再返回second的引用
  若存在，则插入失败返回已存在的key的迭代器和false，重载[]再返回second的引用
2.返回值是引用类型，因此可以直接赋值


















*/