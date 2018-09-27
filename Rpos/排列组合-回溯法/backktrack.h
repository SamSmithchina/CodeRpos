﻿/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		
* Description: 

* ***********************************************************************/

/*
bool finished = FALSE; //是否获得全部解? 
backtrack(int a[], int k, data input)
{
	int c[MAXCANDIDATES]; ///这次搜索的候选 
	int ncandidates; //	 候选数目 
	int i;		// counter 
	if (is_a_solution(a, k, input))
		process_solution(a, k, input);
	else {
		k = k + 1;
		construct_candidates(a, k, input, c, &ncandidates);
		for (i = 0; i<ncandidates; i++) {
			a[k] = c[i];
			make_move(a, k, input);
			backtrack(a, k, input);
			unmake_move(a, k, input);
			if (finished) return; // 如果符合终止条件就提前退出 
		}
	}
}
is_a_solution(a, k, input)判断当前的部分解向量a[1...k]是否是一个符合条件的解

construct_candidates(a, k, input, c, ncandidates)根据目前状态，构造这一步可能的选择，存入c[]数组，其长度存入ncandidates

process_solution(a, k, input)对于符合条件的解进行处理，通常是输出、计数等

make_move(a, k, input)和unmake_move(a, k, input)前者将采取的选择更新到原始数据结构上，后者把这一行为撤销。
*/