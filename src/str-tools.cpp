bool is_num_c(char num)
{
    char nums[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    for (auto i : nums)
    {
        if (num == i)
        {
            return true;
        }
    }
    return false;
}

bool is_num_i(int num)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (auto i : nums)
    {
        if (num == i)
        {
            return true;
        }
    }
    return false;
}

bool is_char(int c)
{
    if ((64 < c) && (c < 91) || (96 < c) && (c < 123))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char num2char(int i) // 48 char == 0 int
{
    return i + 48;
}

int char2int(char c) // 48 char == 0 int
{
    return c - 48;
}
