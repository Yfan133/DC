/*
Ŀ�꣺����leetcode�Ľ��湦��
	1.�鿴��Ŀ�б�
	2.�����Ŀ��ת
	3.֧����д���벢�ύ����
	4.�������н��
�������
	1.cpp-httplib��Դ�⣺
		ʹ�÷�����ֱ�Ӱ���ͷ�ļ��Ϳ����ˣ�include "httplib.h"
	2.����GCC��
		1.���ظ߰汾gcc��bash��������������
			sudo yum -y install centos-release-scl
			sudo yum -y install devtoolset-7-gcc devtoolset-7-gcc-c++ devtoolset-7-binutils
		2.����Ĭ�������߰汾gcc
			���ļ�
				vim ~/.bash_profile
			�������ӣ�
				scl enable devtoolset-7 bash
			����gcc
				source ~/.bash_profile
	3.����jsoncpp
		yum install jsoncpp
		yun install jsoncpp-devel
	4.����cpp-httplib��
		��������cpp-httplib���ӣ�����httplib.hͷ�ļ�	
	5.����boost������ctemplate
		sudo yum install -y snappy-devel boost-devel zlib-devel.x86_64 python-pip
		sudo pip install BeautifulSoup4
		git clone https://gitee.com/HGtz2222/ThirdPartLibForCpp.git
		cd ./ThirdPartLibForCpp/el7.x86_64/
		sh install.sh

httplib����ܣ����԰������Ǵ���һ��http���񣬲���Ҫ����tcp��http�Ľ������̣�������http����֮�󣬻ᰴ������ķ������ҵ���Ӧע��Ļص��������д���
	Server��Ļص�������
		1.���������ǵ�ǰע��Ļص������ķ���
			�ٸ����ӣ�
			Get������
				Server &Get(const char *pattern, Handler handler);
					pattern��ע���url��Դ·��(���������·��Ҫ��ע���һ�²��ܻص�handler)
					handler������ָ��
						using Handler = std::function<void(const Request &, Response &)>;
						Request:http���������
						Response:�ظ������������Ӧ
			Response�ṹ�壺
				get_header_value()����Ӧ��ͷ
				set_header()������key:value��ʽ����Ӧ��ͷ
				set_redirect()���ض���
				set_content()��������Ӧ�壺body��һ����c���һ����C++���
����httplib-demo
	ǰ�᣺�ر�Linux����ǽ
	��chorm���������  ip:�˿ں�/·��

������ģ��
	1.����ģ�飺��������oj����
		��ʽ��
			1.д���ļ����У�����˴��ļ�����ȥ��ȡ
			2.���������ݿ⵱��
		����ʵ��(�ļ�)��
			1.�ļ������������
			2.header.cpp��ͷ�ļ�
			3.desc.txt����Ŀ��������Ϣ
			4.tai.cpp�����������������߼�Solution
		�ļ���oj_config_cfg
			���  ��Ŀ����  ��Ŀ�Ѷ� ��Ŀ·��

	2.httpģ�飺��ȡ���� + �ظ���Ӧ
		��ȡ����
			1.��ȡ���������б�http���󣬷�����Get
			2.��ȡ�������⣬http���󣬷�����Get
			3.����������ύ���룬������Post����������ύд���Ĵ���

	3.����ģ�飺
		����ģ��
			1.�ṩʱ���
			2.�ṩ��־
			3.�ṩ�ַ�������

�˱��ʽ��[](){}��[]���˴��ݵĲ��� ()�������б� {}���������
*/
/*
codeĿ¼�µ�ģ��
	oj_data���ļ���Ϣ
		1.oj_config_cfg����Ŀ����
		2.ÿ����Ŀ����ϸ��Ϣ
			1.desc.txt����Ŀ������Ϣ
			2.header.cpp��ͷ�ļ���Solution
			3.tail.cpp�������û��Ĵ���
	oj_model.hpp����ȡ�ļ���Ϣ
		1.�ļ��ṹ�壺�ļ��ĸ�����Ϣ
		2.��Model��
			1.��oj_�ļ�������ȡ�����ļ�������
			2.ͨ��·������ȡÿ�������ϸ��Ϣ
			3.���ظ��ϲ� vector<Questions> ����
			
			GetOneQues()����ȡһ������
				
	oj_server.cpp����������������������������������
		1.ע��Get_all_questions����
			1.��ȡ
			2.
		2.ע��Get_one_question����
			����Ҫ��������⣺��ô���ֲ�ͬ�����⣿
				������ʽ��R"(/question/(\d))"������'\d'ֻ��ʶ���λ�������'\d+'��ʾ��λ����
				match��
			1.���������棺������ͬ����Ŀid
				req[0]������url
				req[1]����ͬ�����
			2.����GetOneQuestion��ȡ������������

			3.��Ⱦ���������ģ��html�������ڲ���̳�����ϰ
				testarea:�ı������
				form����
				input��
		3.ע��Post����
			1.�����������
				������post
				url��/compile/[�����]
				code��url�����Ĵ���
			2.�����
				1.������ʽͨ��url�е����
				2.���ύ�Ĵ������url����
				
				

	tools.hpp�����ļ������ļ����ݣ��з��ַ���
		1.split
		2.
	template��html��ģ��
	oj_view.hpp���ô������html��ģ��
		/////1.��template�ӵ����������У�
		1.����һ��TemplateDictionary����󣬹���Ҫ���name
		2.����vector<>�����ֵ䣬����setvalue����
		3.���htmlҳ�棬��Getҳ�棬��Expand����ֵ�����
	���⣺��һ��oj_view.hpp�ĳ�����ʲô��












������Ϣ��ȡ��oj_model.hpp
	1.��Ŀ���������ṹ��questions
		1.��Ŀid
		2.��Ŀ����
		3.��Ŀ���׳̶�
		4.��Ŀ·��
		5.��Ŀ����
		6.Ԥ����ͷ�ļ�
		7.��Ŀ�Ĳ��������������߼�Solution
	2.�Ӵ����л�ȡ��Ŀ����OjModel
		������map���棺key=��ţ�value=�ṹ��questions
		1.���죺����Load��������������Ϣ
		2.������
		4.����Load��������Ŀ��Ϣ
			1.������Ŀ��·��
			2.����Ŀ����·�����ļ�
			3.��ȡÿһ�е���Ϣ����������questions�ṹ����
				����boost���е�split����ȥ�з��ļ��л�ȡ��һ������
				boost::split(); ��һ�����зֺ������
								�ڶ������зֵ�����
								������������ʲô��ʽ�з�
								���ĸ����Ƿ񽫶���ָ��ַ�����һ����Ҳ���Ƕ���ո�Ҳ����һ��Ȼ���и�
			4.�Ѷ��question��֯��unorder_map��
		5.����GetAllQuestions����ȡ
			
		6.����Get

������Ŀ��Ϣ:oj_data
	����ģ�飺���ļ��ж�ȡ

ע�⣺
	getline����\n�����ֵģ���������ں����\n
	��static���εĺ���������ʵ��������ֱ�ӣ���::�������е���

ǰ��֪ʶ��
htmlҳ�棺
<html>
<head></head>	����������Ϣ��
<body></body>	��չʾ�����ݣ��ĵ�����
<div></div>		�ֿ�
<a></a>			������
<meta>			�ṩhtmlҳ��Դ���ݣ����ĵ�����
</html>

�ȸ��ģ����뼼����ctemplate
	1.Ԥ����htmlҳ���ģ�壬ʹ��һ��ģ�����Ԥ���嵽htmlҳ�浱��
	2.��˴��뽫��ЩԤ����ģ�������ֵ�������֮��ֻ��Ҫ����htmlģ����и���
	
	explicit TemplateDictionary(const Template& name, UnsafeArena* arena=NULL);
		explicit���������캯��Ϊ��ʾ����
		name:��������ָ����
		arena:

	static Template

	����䣬���ں�

	���д����
	{{����}}��Ԥ���������{{id}}
	{{#question}}��Ƭ�α��
	{{/queation}}��Ƭ�α�ǽ�β
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string id1 = "1";
	string id2 = "123";
	if (id1 < id2)
		cout << "yes" << endl;
	return 0;
}