/*
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

�˱��ʽ��[](){}��[]���˱��ʽ���ݵĲ��� ()�������б� {}���������
*/

/*

codeĿ¼�µ�ģ��
	oj_data���ļ���Ϣ
		1.oj_config_cfg����Ŀ����
		2.ÿ����Ŀ����ϸ��Ϣ
			1.desc.txt����Ŀ������Ϣ
			2.header.cpp��ͷ�ļ���Solution
			3.tail.cpp�������û��Ĵ���
	oj_model.hpp�����ļ��ж�ȡ�������Ϣ�����ҷ��ظ��ϲ������
		1.Questions�ṹ�壺�ļ��ĸ�����Ϣ
		2.Model�ࣺ
			Load������������Ϣ
				1.��oj_�ļ�������ȡ�����ļ�������
				2.ͨ��·������ȡÿ�������ϸ��Ϣ����������һ��unordered_map��
			GetAllQuestions������ȫ������
				1.ͨ����������map��ÿ�����Ᵽ����vector��
				2.��vector�������򣬲����ظ��ϲ� vector<Questions> ����
			GetOneQues����ȡ��������
				1.
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
				tail.cpp��main�������� + ��������
			2.������ʽͨ��url�е����
			3.����GetOneQuestion��ȡ��������
			4.���ύ�Ĵ������url�и�ͽ���
				url��key=value&key1=value1��ʽ
				��˶�url���д����ʱ��Ҫ�Ȱ���&�и�зֳɲ�ͬ��key=value��ʽ
				�ٰ���=�и�зֳ� key<->value ���浽map<string,string>��
				ͨ��key�Ϳ�����map���ҵ�value
			5.����json���󣺰�code��tail.cpp����ƴ��

			�޸�makefile���ӿ�
			3.��������ģ��
				1.������ύ�Ĵ�����û��main�������õ�
					code+tail.cpp --�� src�ļ�
				2.����ģ����б���
					1.�����ӽ��̣�ʹ���ӽ��̳����滻
					2.�����滻��g++���������Դ��
				3.����
					1.�����ӽ��̣�ʹ���ӽ��̳����滻
					2.�ӽ����滻��Ϊ��������Ŀ�ִ�г���
				4.���н�������ظ��ͻ���
					�������ͣ�
						1.��������
							������ύ�Ĳ���Ϊ�ջ��߲�������							
						2.�ڲ�����
							д�ļ�ʧ��
							���̳����滻ʧ��
							�ڴ����ʧ��
						3.�������
						4.���д���
				5.�������н��
					
	tools.hpp�����ļ������ļ����ݣ��з��ַ���
		1.split
		2.
		3.��ȡʱ���
			����ֵһ����int64_t��Ϊʱ���ر��
	compile.hpp��
		1.��ö������ȥ����һ��������
		2.
		3.ʹ��ʱ�����ֹ�����ļ�ʱ�ļ�����ͬ
		4.���ɵ��̶��ļ���ȥ��./tmp_file/
		5.Compile�����������ӽ��̡�
			�ӽ��̣����̳����滻
			�����̣��ȴ��ӽ����˳�
		6.���е������
			1.�ӽ��̷������˳�
				1.���ʿ�ָ�룬�ڴ����Խ�磬double free��
				2.�������յ��ӽ����쳣���˳��źţ���status�ռ��˳��źŵĵ�7λ
			2.�ӽ��������˳�
				��������ȫ��ͨ��
				��������û��ȫ��ͨ��
			3.��sigalarm�˳��źſ�������ʱ��
			4.

	template��html��ģ��
	oj_view.hpp���ô������html��ģ��
		/////1.��template�ӵ����������У�
		1.����һ��TemplateDictionary����󣬹���Ҫ���name
		2.����vector<>�����ֵ䣬����setvalue����
		3.���htmlҳ�棬��Getҳ�棬��Expand����ֵ�����
	������չ
		����������key=value&key1=value1��ʽ
	���⣺vectorû�����������������и�����棬Ϊʲô���棿
	json���ݽṹ��
		json����a = {key:value,key1:value1}
		json����:[1,2,3,4]
	ʹ�ã�#includ <json.h>
		Json::value r;
		r["key"] = "value"
		r["key1"] = "value1"
		r ={{key:value,key1:value1}
		Դ�룺value.h



������Ϣ��ȡ��oj_model.hpp
	1.��Ŀ���������ṹ��questions
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

ע�⣺
	getline����\n�����ֵģ���������ں����\n
	��static���εĺ���������ʵ��������ֱ�ӣ���::�������е���

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
/*
����ʱ��ô������Ŀ����

����߲������⣺
	1.cpp-httplib����ʹ����select + ���߳�
	2.����������󷽷�������httplib�´������߳�ȥ������˻���ֲ��У�д�ļ�ʱʱ���һ������������������
	3.atomic_uint id(0);����C++���̰߳�ȫ�ģ���atomic����߲���ʱ�����ļ���������

�������ͣ�
	1.Req["code"]Ϊ�գ����������
	2.WriteTmpFile()���ص��ļ����ǿգ������ڲ�����
	3.������󷵻���������ķ������޸ı�׼������ļ����������ض����ļ��������С�
	  ���ļ��ж�ȡ���������Ϣ��Ȼ��ͨ��Resp���ظ������
	
�滻ʧ��Ҳ�����ڲ�����ɣ�
����������·��ʱ����ס����ҲҪ��/Ҳ���� ./·��/
��g++����ӣ� -D CompileOnline����� header.cppͷ�ļ���������
#ifndef CompileOnline
#include "header.cpp"
#endif
����ô���ɱ�������ļ��ģ�
��ֱ�����ɴ����ļ��ģ�Ϊʲô����ͨ���ж��Ƿ����ļ������ж��Ƿ����
unlink����ɾ���ļ�
�������ܣ�
	ʱ�����ƣ�alarm
	�ڴ����ƣ�
	int setrlimit(int resource��const struct rlimit *rlim)��
		resource��
			RLIMIT_AS��������������ڴ�ռ�
			RLIMIT_CORE���ڴ�ת���ļ�������С
			RLIMIT_CPU��ʹ��CPU�����ʱ��
			RLIMIT_DATA���������ݶ˵�����С
			RLIMIT_STACK�����̶�ջ��С
		struct rlimit{
			rlim_t rlim_cur;
			rlim_t rlim_max;
		}

��չ��
	1.���ÿ���ⶼ����һ����ʱ��

��ʱ��-��־�ȼ� �ļ����кš��������־��Ϣ
info��warning��error��fatal��debug
��־���Լӵ�modelģ�飬�����ļ��Ƿ�ʧ��

Makefile��
	1.���
		INCLUDE_PATH=............
		LIB_PATH=................
		BIN=../bin/svr
	2.Ȼ���ڵ��ô���
		$(INCLUDE_PATH)
		$(LIB_PATH)
		$(BIN):oj_server
	3.���
		.PHONY:clean
		clean:
			rm $(BIN)
���������/all_questions����Ĭ�Ϸ����߼���Ŀ¼��index.html

html����ҳ����
css����ҳ����
js����ҳ��̬����

<title>��
<nav>��������
ace
*/
/*
ǰ��֪ʶ��
htmlҳ�棺
<html>
	<head></head>		����htmlҳ���������Ϣ
		<meta></meta>	�ṩhtmlҳ��Ԫ���ݣ���ЩԪ���ݿ��Ա������ʶ�����ĵ�����
		<meta http-equiv="content-type" content="text/html;charset=utf-8">
			http-equiv������key
			content������value

	<body></body>		�����������չʾ�����ݣ��ĵ�����
		{{#question}}{{question}}	
		<div></div>		��htmlҳ���ж���ķֿ�
		<a></a>			������
			<a href="/question/{{id}}">{{id}}.{{title}}({{star}})</a>
		<form>			��
		<action>		Ҫִ�еĶ���
</html>
*/

/*
int setrlimit(int resourse, const struct rlimit *rlim);
	resource��
		RLIMIT_AS��������������ڴ�ռ�
		RLIMIT_CORE��
		RLIMIT_CPU��
		RLIMIT_DATA��
		RLIMIT_STACK��
	struct rlimit
	{
		rlim_t rlim_cur��������
		rlim_t rlim_max��Ӳ����
	}
��־��Ϣ��
	��20210123��
	info�ȼ���warning��error��fatal��debug
	
enum Loglevel
{
	INFO = 0,		0
	WARNING,		1
	ERROR,			2
	FATAL,			3
	DEBUG			4
};
�ַ�ָ�����飺�ֱ�ָ��ö��ֵ��ÿһ���±�
�궨�壺__FILE__��__LINE__
int Log(LogLevel lev, const char* file, int line, const std::string& logmsg)
{
	
}















*/