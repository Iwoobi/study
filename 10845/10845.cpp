#include <iostream>
using namespace std;
typedef struct s_que
{
    int num;
    s_que *next;
} t_que;
class my_que
{
    public:

        my_que(){head = NULL; tail = NULL; m_size = 0;};
        ~my_que(){};
        void push(int a){
            t_que *tmp = new t_que;
            tmp->num = a;
            tmp->next = NULL;
            m_size++;
            if (tail == NULL)
            {
                tail = tmp;
                head = tmp;
                return;
            }
            tail->next = tmp;
            tail = tmp;
        };
        int size(){return m_size;};
        bool empty(){return (m_size == 0);};
        int pop(){
            if (empty())
                return -1;
            int res = head->num;
            if (m_size == 1)
            {
                delete head;
                head = NULL;
                tail = NULL;
                m_size--;
                return res;
            }
            t_que *head_tmp = head;
            head = head->next;
            delete head_tmp;
            m_size--;
            return res;
        };
        int front()
        {
            if (empty())
                return -1;
            return head->num;
        };
        int back()
        {
            if (empty())
                return -1;
            return tail->num;
        }
    private:
        t_que *head;
        t_que *tail;
        int m_size;
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    my_que que;
    int N;
    cin >> N;
    int aa;
    string cmd;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> aa;
            que.push(aa);
        }
        else if (cmd == "pop")
        {
            cout << que.pop() << "\n";
        }
        else if (cmd == "size")
        {
            cout << que.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << que.empty() << "\n";
        }
        else if (cmd == "front")
        {
            cout << que.front() << "\n";
        }
        else if (cmd == "back")
        {
            cout << que.back() << "\n";
        }    
    }



    
}