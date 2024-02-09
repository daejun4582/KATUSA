#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

void print_status(vector<int> data);

bool trial();

double get_percentage(int iter_num);

int main(void)
{
    double success_percentage, duration;

    clock_t start, end;


    start = clock();

    int iter_num = 1;

    for (int i = 0; i < 7;  i++)
    {
        success_percentage = get_percentage(iter_num);

        printf("%7d 번 실행한 결과, 성공 확률은 %.2f%% (%f)\n",iter_num,success_percentage*100,success_percentage);

        iter_num = iter_num * 10;
    }

    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;


    return 0;
}


void print_status(vector<int> data)
{
    for(int i = 0; i < data.capacity(); i++)
    {
        printf("%2d ",data[i]);
        if((i+1) % 10 == 0)
            cout << endl;
    }
    cout<<endl;
}

bool trial()
{
    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<int> dist(0,99);

    vector<int> seat(100,-1);

    int random_number;


    random_number = dist(gen);
    seat[random_number] = 1;

    for (int i = 1; i < 100; i++)
    {
        if(seat[i] == -1)
        {
            seat[i] = i+1;
        }
        else
        {
            while(true) //최적화 가능
            {
                random_number = dist(gen);

                // cout << random_number << " " << seat[random_number] << endl;

                if(seat[random_number] == -1)
                    break;
            }
            
            seat[random_number] = i +1 ;

            // cout << i <<"번째 난수 : " << random_number << endl;
        }

        // print_status(seat);
    }

    if(seat[99] == 100)
        return true;
    return false;
}

double get_percentage(int iter_num)
{
    bool result;
    int success_cnt = 0;
    double success_percentage;


    for(int i = 0; i < iter_num; i++)
    {
        result = trial();    

        if(result == true)
        {
            // cout << "성공" << endl;   
            success_cnt++;
        }
        // else
        //     cout << "실패" << endl;
        
        
    }

    
    success_percentage = success_cnt/(double)iter_num;

    return success_percentage;
}