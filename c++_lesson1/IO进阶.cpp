/*
C���Եı�׼���룺
	gets(char* );������֮ǰ�����Ƚ������ú�����
	scanf();	 ����ֵ���ɹ����յ�"����"
	get();
	getchar();	 �����������տո���߻س�
C���Եı�׼�����
	printf();				����ֵ���ɹ������"����"
	printf("%s ", "hello"); ����ֵ��6
	puts();
	putchar();
C++��IO����
	cin�� �ײ���istream
	cout���ײ���ostream�����������е���������
	cerr����׼����
	clog����־��Ϣ
	geline(cin, )����һ��cin��geline�ķ���ֵ
C�����ļ�IO��
	fopen("�ļ���"�� "�򿪸�ʽ")
	fread(buf, Ԫ�ظ���, Ԫ�����ʹ�С, �ļ�ָ��fp)	�Զ����Ʒ�ʽ��ȡ
	fscanf()
	fgets()
	fgetc()

	fwrite(buf, Ԫ�ظ���, Ԫ�����ʹ�С, �ļ�ָ��fp)
	fwrite(buf, 1, sizeof(buf), fp);һ�㶼��Ԫ�ظ�����Ϊ1����СΪsizeof(buf)
	ftell(FILE* fp); �����ļ�ָ�����ļ��е�λ��
	fseek(FILE* fp, ƫ����, ƫ�Ʒ�ʽ);
		fseek(fp, 0, SEEK_END)
	feof(fp)  ����ļ�ָ���Ƿ����ļ���ĩβ

�����⣺
1.ʲô���ı��ļ���ʲô�Ƕ������ļ���
	�ٸ����ӣ���������� a = 5�������ı��ļ���5 �������ļ���101
2.��μ��һ���ļ�ָ���Ƿ����ļ�ĩβ��
	�ı��ļ���ֻҪ����ֵ��ΪEOF��EOF�ı�����-1
	�������ļ�����feof(fp)��⣬��Ϊ-1�ö��������ڴ�����ȫF��һ�ֽڣ�FF�ᱻ����EOF

C++�ļ�IO����ͷ�ļ� <fstream>
	ifstream ifile  == FILE
	ofstream ofile
	fstream  ffile

C++������ת����string���ͣ�ͷ�ļ�<sstream>
	stringstream ss;
	ss << a;
	ss >> buf;
	ע��ÿ��ת��֮ǰ��Ҫ
	ss.str("")	���stringstream�ڲ����ַ���
	ss.clear()	���stringstream�ڲ���״̬�������´β������ת����ע��ֻ�������״̬�������ڲ�������ַ���û�����
*/