#ifndef __Equivalence__
#define __Equivalence__
class UFSets
{
private:
	int* parent;
	int size;
public:
	UFSets(int sz) :size(sz)//构造函数，数组值均初始为-1
	{
		parent = new int[size];
		for (int i = 0; i < size; ++i)
		{
			parent[i] = -1;
		}
	}
	void Print(int x)
	{
		printf("%3d", x);
		for (int i = 0; i < size; ++i)
		{
			if (parent[i] == x)
			{
				Print(i);
			}
		}
	}
	int Parent(int x)//寻找双亲的下标
	{
		while (parent[x] >= 0)
		{
			x = parent[x];
		}
		return x;
	}
	bool Union(int a, int b)//合并
	{
		bool res = false;
		int pa = Parent(a);
		int pb = Parent(b);
		if (pa != pb)
		{
			parent[pa] += parent[pb];
			parent[pb] = pa;
			res = true;
		}
		return res;
	}
	void Print()//打印并查集，打印分组后的数据
	{
		int num = 1;
		for (int i = 0; i < size; ++i)
		{
			if (parent[i] < 0)
			{
				printf("s%d ", num++);
				Print(i);
				printf("\n");
			}
		}
	}
};
#endif