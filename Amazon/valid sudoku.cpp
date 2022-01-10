class Solution{
public:
    int isValid(vector<vector<int>> mat){
       int n = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        vector<int> colm(9, 0);
        vector<int> row(9, 0);
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                if (colm[mat[i][j] - 1] == 0)
                    colm[mat[i][j] - 1] += 1;
                else
                    return 0;
            }
            if (mat[j][i] != 0)
            {
                if (row[mat[j][i] - 1] == 0)
                    row[mat[j][i] - 1] += 1;
                else
                    return 0;
            }
            if (i % 3 == 0 && j % 3 == 0)
            {
                vector<int> box(9, 0);
                for (int k = i; k < (i + 3); k++)
                {
                    for (int l = j; l < (j + 3); l++)
                    {
                        if (mat[k][l] != 0)
                        {
                            if (box[mat[k][l] - 1] == 0)
                                box[mat[k][l] - 1] += 1;
                            else
                                return 0;
                        }
                    }
                }
            }
        }
    }

    return 1;
    }
};
