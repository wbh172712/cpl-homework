//
// Created by wbh17 on 2023/11/19.
//
/*
    \section{内存分配器(buddy.c)}
    \begin{quote}
        本题知识点：整数和字符（串）的输入，循环，条件分支，数组模拟链表。
    \end{quote}
    \par 强烈建议结合视频提示阅读本题题解，本题题解将会结合视频里给出的代码框架讲解。
    \par 在视频里面，我们已经讲解了“操作”类型的题目如何进行读入以及使用函数来进行一些分解和抽象。
    我们在本题中的任务仅剩下了填写我们留下的 query、fit\_size、get\_best、allocate 函数。
    \par 不妨从简单的入手，对于 query ，我们可以直接利用已有的信息输出。
\begin{lstlisting}[language = {C}]
void query() {
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) {
        printf("%d", id[i]);
        printf(i != tot ? " " : "\n");
    }
}
\end{lstlisting}
    \par 只需要回头看看 id、tot 等变量的定义就可以完成 query 。
    \par 然后就是 fit\_size 了，这个函数只需要求出“恰好”能够放得下 $m$ 的 $2^k$ 的结果就行，我们可以从小到大遍历尝试。
\begin{lstlisting}[language = {C}]
int fit_size(int m) {
    for (int i = 0; i <= n; i++) {
        if ((1 << i) >= m) return i;
    }
    assert(0);
}
\end{lstlisting}
    \par 如果数据完全符合要求的话，这个函数在循环过程中一定会返回。
    另外一点可能需要强调的就是浮点数的精度误差问题。pow 在本题中是可接受的，但 log 和 log2 在本题中是不可接受的。
    \par 然后是 get\_best ，按照我们给出的定义，这个函数将会按照分裂的规则返回当前“最好”的空间节点，这一块既有可能直接用于分配也有可能用于分裂。
\begin{lstlisting}[language = {C}]
int get_best(int m) {
    for (int i = 1; i <= tot; i++) {
        if (id[i] != 0) continue;
        if (siz[i] == m) return i;
    }
    for (int i = 1; i <= tot; i++) {
        if (id[i] != 0) continue;
        if (siz[i] > m) return i;
    }
    assert(0);
}
\end{lstlisting}
    \par 上面两个 for 循环分别对应了寻找大小恰好的块和寻找需要分裂的块两个步骤。但其实下面的写法也是正确的。
\begin{lstlisting}[language = {C}]
int get_best(int m) {
    for (int i = 1; i <= tot; i++) {
        if (id[i] != 0) continue;
        if (siz[i] >= m) return i;
    }
    assert(0);
}
\end{lstlisting}
    \par 我个人（czh）认为这样的写法的正确性并不显然，但是确实是可以证明的，这里留作一个小小的 bonus ，感兴趣的同学可以来证明一下。
    \par 那么最后就还剩下 allocate 函数啦。
\begin{lstlisting}[language = {C}]
void allocate(int cur_id, int m) {
    while (1) {
        int pos = get_best(m);
        if (siz[pos] == m) {
            id[pos] = cur_id;
            break;
        } else {
            for (int i = tot + 1; i > pos + 1; i--) {
                id[i] = id[i - 1];
                siz[i] = siz[i - 1];
            }
            ++tot;
            --siz[pos];
            siz[pos + 1] = siz[pos];
            id[pos + 1] = 0;
        }
    }
}
\end{lstlisting}
    \par 这个函数剩下的部分在于如何完成“区间后移”，当然有很多种方法，我认为最简单的方法就是从后往前遍历（想一想，为什么是从后往前而不是从前往后），然后“一路”把相应数组的值复制过来。
    在后移完成之后，我们需要谨慎地处理 pos 和 pos + 1 两个位置的 id 和 siz ，尤其是不要忘记将 id[pos + 1] 设为 0。
    \par 由于本题的核心代码已经全部给出，此处不再给出完整的标程。
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define N (400000 + 100)

int n, qn, m = 0, siz[N], bel[N];

void query() {
    printf("%d\n", m);
    for (int i = 1; i <= m; i++) {
        printf("%d%c", bel[i], " \n"[i == m]);
    }
}

int fit_size(int t) {
    int ret = 0;
    for (; (1 << ret) < t; ++ret);
    return ret;
}

int get_best(int cur_siz) {
    for (int i = 1; i <= m; i++) {
        if (bel[i]) continue;
        if (siz[i] >= cur_siz) return i;
    }
    for (int i = 1; i <= m; i++) {
        if (bel[i]) continue;
        assert(siz[i] != cur_siz);
        if (siz[i] > cur_siz) return i;
    }
    assert(0);
}

void ins(int id, int cur_size) {
    for (; ; ) {
        int pos = get_best(cur_size);
        if (siz[pos] == cur_size) {
            // allocate
            bel[pos] = id;
            break;
        } else {
            // split
            assert(siz[pos] > cur_size);
            ++m;
            for (int i = m; i > pos + 1; i--) {
                bel[i] = bel[i - 1];
                siz[i] = siz[i - 1];
            }
            bel[pos + 1] = 0;
            --siz[pos];
            siz[pos + 1] = siz[pos];
        }
    }
}



int main() {
    scanf("%d%d", &n, &qn);
    volatile bool vis[1 << n];
    ++m;
    siz[m] = n, bel[m] = 0; // 0 means free
    for (char op[3]; qn--; ) {
        scanf("%s", op);
        if (op[0] == 'A') {
            int id, t;
            scanf("%d%d", &id, &t);
            ins(id, fit_size(t));
        } else if (op[0] == 'Q') {
            query();
        } else {
            assert(0);
        }
    }
    return 0;
}
