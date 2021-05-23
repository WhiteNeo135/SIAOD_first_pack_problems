#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> generate(int rows, int min, int max)
{
    std::vector<int> ans;
    int el;
    for (int i = 0; i < rows; ++i)
    {
        el=min+ rand()%max;
        ans.push_back(el);
    }
    return ans;
}

int** generate(int rows, int cols, int min, int max)
{
    int** matrix= new int*[rows];
    for(int i=0; i<rows; ++i)
        matrix[i]=new int[cols];

    for(int i=0; i<rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j]=min+rand()% max;
        }
    }
    return matrix;
}


int triangle(vector<int> arr)
{
    if (arr.size()<3)
        return 0;

    vector<int>::iterator iterator= arr.end();
    int sides[3];


    for (int & side : sides)
    {
        iterator--;
        side=*iterator;
    }

    while (sides[0]>=sides[1]+sides[2])
    {
        if (iterator == arr.begin())
        {
            return 0;
        }
        else
        {
            iterator--;
            sides[0] = sides[1];
            sides[1] = sides[2];
            sides[2] = *iterator;
        }
    }
    return (sides[0]+sides[1]+sides[2]);
}


std::string maxNumber (std::vector<int> arr) // 3 39 9 9393
{
    std::vector<std::string> strings;

    for (auto num:arr)
    {
        strings.emplace_back(std::to_string(num));
    }

    std::sort(
            strings.begin(),
            strings.end(),
            [](auto const &L, auto const &R)
            {
                return R + L  < L + R ;
            }
    );
    std::string res_str;
    for (auto const &str: strings)
    {
        res_str += str;
    }

    return res_str;
}


int** sort_matrix(int** matrix, int n, int m)
{
    int j=0;
    int i;
    std::vector<int> arr;
    std::vector<int>::iterator iterator;

    for (int rows=0; rows<m; rows++)
    {
        i=rows;
        arr.erase(arr.begin(), arr.end());

        while (i-j<n && i<m)
        {
            arr.push_back(matrix[i-j][i]);
            i++;
        }

        sort(arr.begin(),arr.end());

        i=rows;
        iterator =arr.begin();

        while (i-j<n && i<m)
        {
            matrix[i-j][i]=*iterator;
            i++;
            iterator++;
        }
        j++;
    }

    i=0;

    for (int line=0; line<n; line++)
    {
        j=line;
        arr.erase(arr.begin(), arr.end());

        while (j<n && j-i<m)
        {
            arr.push_back(matrix[j][j-i]);
            j++;
        }

        sort(arr.begin(),arr.end());

        iterator =arr.begin();
        j=line;

        while (j<n && j-i<m)
        {
            matrix[j][j-i]=*iterator;
            j++;
            iterator++;
        }
        i++;
    }


    return matrix;
}

int main()
{
    cout << "Первая задача" << endl;
    int n;
    int m;
    int len;
    int temp;
    int min;
    int max;
    vector<int> arr;

    cout << "Введите кол-во элементов" << endl;
    cin >> len;
    cout << "Введите элементы массива" << endl;
    for (int i = 0; i < len; ++i)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    cout << triangle(arr) << endl;


    cout << "Вторая задача" << endl;

    arr.erase(arr.begin(), arr.end());

    cout << "Введите кол-во элементов" << endl;
    cin >> len;
    cout << "Введите минимальное возможное положительное значение" << endl;
    cin>> min;
    cout << "Введите максимальное возможное положительное значение" << endl;
    cin>>max;
    arr=generate(len, min, max);

    cout << "Сгенерированный массив:";
    for (auto i: arr)
        cout << i<< " ";
    cout<< endl;

    std::cout<< maxNumber(arr)<< endl;


    cout << "Третья задача" << endl;
    cout << "Введите количество строк" << endl;
    cin >> n;
    cout << "Введите количество столбцов" << endl;
    cin >> m;
    cout << "Введите минимальное возможное значение" << endl;
    cin>> min;
    cout << "Введите максимальное возможное значение" << endl;
    cin>>max;

    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    matrix=generate(n, m, min, max);

    matrix = sort_matrix(matrix, n, m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
