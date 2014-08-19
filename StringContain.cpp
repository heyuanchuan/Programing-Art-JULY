/*
���������ֱ�����ĸ��ɵ��ַ���A���ַ���B���ַ���B�ĳ��ȱ��ַ���A�̡�
���ʣ���������ж��ַ���B��������ĸ�Ƿ����ַ���A�
*/

//����һ��������Ӧ��
/*
��ÿ����ĸ��һ��������Ӧ����2��ʼ���������ƣ�A��Ӧ2��B��Ӧ3��C��Ӧ5��......��
������һ���ִ�����ÿ����ĸ��Ӧ������ˡ����ջ�õ�һ��������
����õ�һ���ַ�������������������ڶ����ַ�����������˵���ڶ����ַ����ǵ�һ�����Ӽ�
*/
//�˷���ֻ���������壬��Ϊ�����˻��ܴ����������
bool StringContain(string &a,string &b)
{
    const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,61, 67, 71, 73, 79, 83, 89, 97, 101};
    int f = 1;
    for (int i = 0; i < a.length(); ++i)
    {
        int x = p[a[i] - 'A'];
        if (f % x)
        {
            f *= x;
        }
    }
    for (int i = 0; i < b.length(); ++i)
    {
        int x = p[b[i] - 'A'];
        if (f % x)
        {
            return false;
        }
    }
    return true;
}


//������
/*
��26����ĸ��һ��32λ������hash�е�26λ����ʶ��
��������C����i�����еĵ�('C'-'A')λΪ1������Ϊ0��
Ȼ���õڶ����ַ����е�ÿһλȥ��&hash�������Ϊ0���򲻺���
*/
// ʱ�临�Ӷ�O(n + m)���ռ临�Ӷ�O(1)
bool StringContain(string &a,string &b)
{
    int hash = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        hash |= (1 << (a[i] - 'A'));
    }
    for (int i = 0; i < b.length(); ++i)
    {
        if ((hash & (1 << (b[i] - 'A'))) == 0)
        {
            return false;
        }
    }
    return true;
}