#include<stdio.h>
#include<string.h>

char keypad[12][5] = {{'0', '\0', '\0', '\0', '\0'}, {'_', ',', '@', '1', '\0'},    {'A', 'B', 'C', '2', '\0'},
                      {'D', 'E', 'F', '3', '\0'},    {'G', 'H', 'I', '4', '\0'},    {'J', 'K', 'L', '5', '\0'},
                      {'M', 'N', 'O', '6', '\0'},    {'P', 'Q', 'R', 'S', '7'},     {'T', 'U', 'V', '8', '\0'},
                      {'W', 'X', 'Y', 'Z', '9'},     {'*', '\t', '\0', '\0', '\0'}, {'#', '\0', '\0', '\0', '\0'}};

int main(){
    char input[1000], output[1000];
    scanf(" %s", input);
    int length = strlen(input), c=0;

    //i is input counter
    //c is output counter

    for(int i=0; i<length; ++i){
        int row, col=0;
        if(input[i]=='*') row=10;
        else if(input[i]=='#') row=11;
        else row=input[i]-48;

        while(input[i] == input[i+1]){
            if(col==4)
                col=0;
            if(keypad[row][col] == '\n')
                col=0;
            col++;
            i++;
        }

        output[c] = keypad[row][col];
        c++;
    }
    printf(" %s", output);
}
//4433555555666110966677755531111
