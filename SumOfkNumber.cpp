/*
������������n��sum��������1��2��3.......n ������ȡ��������ʹ��͵���sum��
Ҫ���������еĿ�������г�����

˼·��ע�⵽ȡn���Ͳ�ȡn�����𼴿ɣ������Ƿ�ȡ��n�����Ĳ��ԣ�
����ת��Ϊһ��ֻ��ǰn-1������ص����⡣

���ȡ��n��������ô�����ת��Ϊ��ȡǰn-1����ʹ�����ǵĺ�Ϊsum-n����
��Ӧ�Ĵ���������sumOfkNumber(sum - n, n - 1)��
�����ȡ��n��������ô�����ת��Ϊ��ȡǰn-1����ʹ�����ǵĺ�Ϊsum����
��Ӧ�Ĵ������ΪsumOfkNumber(sum, n - 1)��
*/

list<int>list1;
void SumOfkNumber(int sum, int n)
{
    // �ݹ����
    if (n <= 0 || sum <= 0)
        return;

    // ����ҵ��Ľ��
    if (sum == n)
    {
        // ��תlist
        list1.reverse();
        for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
            cout << *iter << " + ";
        cout << n << endl;
    }

    list1.push_front(n);      //���͵�01��������
    SumOfkNumber(sum - n, n - 1);   //���š�n��ǰn-1������������sum-n
    list1.pop_front();
    SumOfkNumber(sum, n - 1);     //�����š�n��n-1������������sum
}


//0-1��������
/*
0-1����������������ı������⣬���������Ϊ����N����Ʒ��һ������ΪV�ı�����
�����i����Ʒ�ķѵķ�����Ci���õ��ļ�ֵ��Wi����⽫��Щ��Ʒװ�뱳����
ʹ��ֵ�ܺ����

����������������ı������⣬�ص���ÿ����Ʒ����һ��������ѡ��Ż򲻷š�
�������ⶨ��״̬����F[i, v]��ʾǰi����Ʒǡ����һ������Ϊv
�ı������Ի�õ�����ֵ������״̬ת�Ʒ��̱��ǣ�

F[i, v] = max{F[i-1, v], F[i-1, v-Ci ] + Wi}

���̵����壺����ǰi����Ʒ��������Ϊv�ı����С���������⣬
��ֻ���ǵ�i����Ʒ�Ĳ��ԣ��Ż򲻷ţ���
��ô�Ϳ���ת��Ϊһ��ֻ��ǰ i-1 ����Ʒ��ص����⡣����

	������ŵ�i����Ʒ����ô�����ת��Ϊ��ǰi-1����Ʒ��������Ϊv�ı����С���
	��ֵΪ F[i-1, v ]��
	����ŵ�i����Ʒ����ô�����ת��Ϊ��ǰi-1����Ʒ����ʣ�µ�����Ϊv-Ci
	�ı����С�����ʱ�ܻ�õ�����ֵ����F[i-1, v-Ci]�ټ���ͨ������
	��i����Ʒ��õļ�ֵWi��
*/


/*1������ս������ƾ������Ŀ�ƪ�и����Ƶĳ�ǩ���⣬ͦ����˼����Ŀ���£�

��д�����ֵ�n��ֽƬ����һ��ֽ�����У�Ȼ�����������Ѵ�ֽ�����г�ȡ
4��ֽƬ��ÿ�μ���ֽƬ�ϵ����ֺ�Ż��������У������4�����ֵĺ���m��
������Ӯ����������������Ӯ��

���дһ�����򣬵�ֽƬ����д��������k1��k2��k3��k4��..��knʱ��
�Ƿ���ڳ�ȡ4�κ�Ϊm�ķ�����������ڣ����YES���������NO��

����������

1 <= n <= 50
1 <= m <= 10^8
1 <= ki <= 10^8

˼·���Ȱ���n��ֽƬ����ʱ�临�Ӷ�ΪO(nlogn).Ȼ������ֵn��ʼ��
����ȡ��ȡn��
���ȡn����ô�����ת��Ϊ����ǰn-1������ȡ3����ʹ���ǵĺ͵���m-n����
��һ�α��������ȶ��ֲ��ҵ�С��m-n�����ֵ����һ�ξ��ߡ�
�����ȡn����ô�����ת���ɡ���ǰn-1������ȡ3����ʹ���ǵĺ͵���m����
*/

/*
2����������a1��a2��a3��...��an���ж��Ƿ���Դ���ѡ�����ɸ�����
ʹ�����ǵĺ͵���k��k���������������-10^8 <= k <= 10^8����

��������������ڱ��ڡ�Ѱ�����������Ķ���������һ�ޣ�
��ͬ���Ǵ���ֻҪ���жϣ���Ҫ������п��ܵ���ϸ��������
��Ϊ������Ҫ���ǵ�����a[i]�Ͳ�����a[i]�������
�ʿ��Բ���������������İ취���ݹ�����
*/


/*
��n����������������к�Ϊs��k��������ϡ�
*/