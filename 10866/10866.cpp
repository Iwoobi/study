#include <iostream>
using namespace std;
typedef struct s_deq
{
    int n;
    s_deq *next;
    s_deq *before;
} t_deq;
class my_deque
{
    public:
        my_deque(){m_size = 0; m_front = NULL; m_back = NULL;};
        ~my_deque(){};
        int size(){return m_size;};
        bool empty() {return (m_size == 0);};
        int front(){
            if (empty())
                return -1;
            return m_front->n;
        };
        int back(){
            if (empty())
                return -1;
            return m_back->n;
        };
        void push_front(int a)
        {
            t_deq *tmp = new t_deq;
            tmp->n = a;
            tmp->before = NULL;
            tmp->next = NULL;
            if (empty())
            {
                m_size++;
                m_front = tmp;
                m_back = tmp;
                return;
            }
            m_size++;
            m_front->before = tmp;
            tmp->next = m_front;
            m_front = tmp;
        };
        void push_back(int a)
        {

            t_deq *tmp = new t_deq;
            tmp->n = a;

            tmp->before = NULL;
            tmp->next = NULL;


            if (empty())
            {
                m_size++;
                m_front = tmp;
                m_back = tmp;
                return;
            }
             m_size++;
            tmp->before = m_back;
            m_back->next = tmp;
            m_back = tmp;
        };
        int pop_front()
        {
            if (empty())
                return -1;
            t_deq *tmp = m_front;
            m_size--;
            int res = tmp->n;
            if (m_front->next)
                m_front->next->before = NULL;
            m_front = m_front->next;
            delete tmp;
            return res;
        };
        int pop_back()
        {
            if (empty())
                return -1;
            t_deq *tmp = m_back;
            m_size--;
            int res = tmp->n;
            if (m_back->before)
                m_back->before->next =NULL;
            m_back = m_back->before;
            delete tmp;
            return res;
        };
        t_deq *m_front;
        t_deq *m_back;

    private:
        int m_size;
        // t_deq *m_front;
        // t_deq *m_back;
        
};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    int aa;
    string cmd;
    my_deque deq;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            cin >> aa;
            deq.push_front(aa);
            // t_deq *tmp1 = deq.m_front;
            // while (tmp1)
            // {
            //     cout << tmp1->n << "|" << endl;
            //     tmp1 = tmp1->next;
            // }
            // cout << "\n";
            // tmp1 = deq.m_back;
            // while (tmp1)
            // {
            //     cout << tmp1->n << "|" << endl;
            //     tmp1 = tmp1->before;
            // }
            // cout << "\n";
        }
        else if (cmd == "push_back")
        {
     
            cin >> aa;
            deq.push_back(aa);
            // t_deq *tmp1 = deq.m_front;
            // while (tmp1)
            // {
            //     cout << tmp1->n << "|" << endl;
            //     tmp1 = tmp1->next;
            // }
            // cout << "\n";
            // tmp1 = deq.m_back;
            // while (tmp1)
            // {
            //     cout << tmp1->n << "|" << endl;
            //     tmp1 = tmp1->before;
            // }
            // cout << "\n";
        }
        else if (cmd == "pop_front")
        {
            cout << deq.pop_front() << "\n";
        }
        else if (cmd == "pop_back")
        {
            cout << deq.pop_back() << "\n";
        }
        else if (cmd == "size")
        {
            cout << deq.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << deq.empty() << "\n";
        }
        else if (cmd == "front")
        {
            cout << deq.front() << "\n";
        }
        else if (cmd == "back")
        {
            cout << deq.back() << "\n";
        }


    }
}